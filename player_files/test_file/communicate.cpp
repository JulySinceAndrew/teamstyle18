#include "communicate.h"
#include "head_for_main.h"				//Ϊ�˸ı�flag,ҲΪ��֪����Ϸ�Ƿ������
#include <queue>
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

using namespace std;
extern bool team_id ;
extern bool flag_of_round;	
extern resourse resourse_of_1;
extern resourse resourse_of_2;
extern double buff[40]; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
extern Unit * all_unit;			  //���е�unit
extern int all_unit_size;				//��¼����unit�ĸ���
/*
//extern double buff1[4][5]; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
//extern double buff2[4][5]; //buffȫ�ֱ��� ��Ӫ2[��λ����][buff����]
extern double buff_1[20]; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
extern double buff_2[20]; //buffȫ�ֱ��� ��Ӫ2[��λ����][buff����]
extern Unit * all_unit_1;			  //��Ӫ1������֪�������е�unit
extern int all_unit_size_1;				//��¼��Ӫ1����unit�ĸ���
extern Unit * all_unit_2;			  //��Ӫ2������֪�������е�unit
extern int all_unit_size_2;				//��¼��Ӫ1����unit�ĸ���
*/
extern queue <Instr>  q_instruction;

void recv_send_socket::create_recv_socket(void)  
{  
	//����ͨ�ŵĶ˿ڵ�һЩ׼��
    wVersionRequested = MAKEWORD( 1, 1 );//��һ������Ϊ��λ�ֽڣ��ڶ�������Ϊ��λ�ֽ�  
  
    err = WSAStartup( wVersionRequested, &wsaData );//��winsock DLL����̬���ӿ��ļ������г�ʼ����Э��Winsock�İ汾֧�֣��������Ҫ����Դ��  
    if ( err != 0 )  
    {  
        return;  
    }  
  
    if ( LOBYTE( wsaData.wVersion ) != 1 ||HIBYTE( wsaData.wVersion ) != 1 )//LOBYTE����ȡ��16���������λ��HIBYTE����ȡ��16��������ߣ�����ߣ��Ǹ��ֽڵ�����        
    {  
        WSACleanup( );  
        return;  
    }  
  
}  
void recv_send_socket::InitialSocketClient(void)				//��python�˽������ӡ���ʼ��Ϸ
{
	sockClient=socket(AF_INET,SOCK_STREAM,0);  
  
        SOCKADDR_IN addrClt;//��Ҫ���������IP��Ϣ  
        addrClt.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");// inet_addr��IP��ַ�ӵ�����ʽת���������ֽڸ�ʽ���͡�		//Ϊʲô�������ַ����
        addrClt.sin_family=AF_INET;   
        addrClt.sin_port=htons(18223);  
  
        connect(sockClient,(SOCKADDR*)&addrClt,sizeof(SOCKADDR));//�ͻ���������������������� 
		int team_id_temp;
		recv(sockClient,(char*)&team_id_temp,sizeof(int),0);
		cout << team_id_temp;
		team_id=bool(team_id_temp);
}
unsigned __stdcall recv_send_socket::static_recv_data(void * pThis)  
{  
	recv_send_socket * pthX = (recv_send_socket*)pThis;   // the tricky cast  
	cout << "Receiving";
	pthX->recv_data();           // now call the true entry-point-function 
	return 1;                           // the thread exit code  
}  

void recv_send_socket::recv_data(void)
{
	while (game_not_end())						//
	{
		//��ֻ��0��1��2����3��
		int recvType=0;				//���»�����������͵�����
		recv(sockClient,(char*)&recvType,sizeof(int),0);
		bool Team=0;
		cout << "Received" << recvType <<endl;
		switch (recvType)
		{
		case 2:						//��Դ
			//recv(sockClient,(char*)&Team,sizeof(bool),0);
			recv(sockClient,(char*)&resourse_of_1,sizeof(resourse),0);
			recv(sockClient,(char*)&resourse_of_2,sizeof(resourse),0);
			break;
		case 1:						//�ĸ����ֵ�buff
			//recv(sockClient,(char*)&Team,sizeof(bool),0);
			//if (Team==false)
				recv(sockClient,(char*)&buff,2*3*5*sizeof(double),0);
			//else
			//	recv(sockClient,(char*)&buff_2,4*5*sizeof(double),0);
			break;
		case 0:						//˫�����Կ��Ի�õĵ�ͼ�ϵ�unit����Ϣ
			/*recv(sockClient,(char*)&Team,sizeof(bool),0);
			if (Team==false)
			{
				recv(sockClient,(char*)&all_unit_size_1,sizeof(int),0);
				delete [] all_unit_1;							//��֮ǰ����Ϣȫ��ɾ��
				all_unit_1 = new Unit[all_unit_size_1];
				recv(sockClient,(char*)&all_unit_1,all_unit_size_1*sizeof(Unit),0);
			}
			else
			{
				recv(sockClient,(char*)&all_unit_size_2,sizeof(int),0);
				delete [] all_unit_2;							//��֮ǰ����Ϣȫ��ɾ��
				all_unit_1 = new Unit[all_unit_size_2];
				recv(sockClient,(char*)&all_unit_2,all_unit_size_2*sizeof(Unit),0);
			}*/
			recv(sockClient,(char*)&all_unit_size,sizeof(int),0);
			delete [] all_unit;							//��֮ǰ����Ϣȫ��ɾ��
			all_unit = new Unit[all_unit_size];
			cout << all_unit_size;
			recv(sockClient,(char*)&all_unit,all_unit_size*sizeof(Unit),0);
			break;
		default:
			break;
		}
		/*
		//������ܵĸ�ʽ ����
		int num;										//����
		//unit U;
		recv(sockClient,(char*)&num,sizeof(int),0);
		//recv(sockClient,(char*)&U,sizeof(unit),0);
		closesocket(sockClient);  */

		flag_of_round=true;	
		//ѡ�����̫����ϸ�ڣ�ͳͳ��û�п���
        Sleep(20);						//����ط�  ͬ�����д���ȶ    //ΪʲôҪsleep��ô��ʱ�䣿����//ѹ������Ҫsleep????????
	}
	
}
void recv_send_socket::send_data(void)
{
	int sizeQueue;
	sizeQueue=q_instruction.size();
	Instr * allInstr = new Instr[sizeQueue];
	for (int i=0;i<sizeQueue;i++)
	{
		allInstr[i]=q_instruction.front();
		q_instruction.pop();
	}
	//send(sockClient,(char*)team_id,sizeof(bool),0);					//��֪���ĸ������ָ��
	cout << q_instruction.size();
	if (sizeQueue!=0)
		send(sockClient,(char*)allInstr,sizeQueue*sizeof(Instr),0);		//��ָ��ȫ�����͹�ȥ
	delete [] allInstr;
}

void recv_send_socket::close_recv_socket(void)
{
	WSACleanup();  
}

