//���⣺��ô���ƶ���̣߳�

//#include "pthread.h"
//#define DEBUG

#include <iostream>
#include <stdio.h>					//Ϊ�˿������߳� �� include һЩͷ�ļ�
#include <process.h>   


 
#include "communicate.h"
#include "head_for_main.h"				//main���� ��Ҫ���õ�һЩ����
#include "teamstyle18-my-1.h"

#include <windows.h> 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
using namespace std;
//����ط�Ӧ����ô����˫������Ϣ��
bool team_id = false; //����id    //Ҳ������true Ҫ����Ӧ������
//������ʶ�ǿ��ַ��ѡ���ã��ǿ��ַ�����µ�����
bool flag_info;						//false ʱѡ��ȡ�õ�һ���ַ���µ����ݷ���ڶ����ַ��trueʱ��֮
//��־��Ϸ�غϡ��ܵ��Ƿ��������
bool flag_of_round;	
bool flag_of_gameOver;


//��ָ�����
queue <Instr> q_instruction;

//�����ݵ���
resourse allResourse;
//��ά���鲻�÷��أ�����Ϊ����
double buff[40] = { 0.0 }; //buffȫ�ֱ��� ǰ20�� ��Ӫ1[��λ����][buff����] ��20�� ��Ӫ2[��λ����][buff����]  2*5*5?

Unit * all_unit= new Unit[1];	 //��� ���е�unit (��Ϣ��˫������͸����)
int all_unit_size=0;	
/*
Unit * all_unit_1= new Unit[1];			  //����֪�������е���Ӫ1��unit      //��� ���е�unit (��Ϣ��˫������͸����)
int all_unit_size_1=0;				//��¼��Ӫ1����unit�ĸ���
Unit * all_unit_2= new Unit[1];			  //����֪�������е���Ӫ2��unit 
int all_unit_size_2=0;				//��¼��Ӫ2����unit�ĸ���
*/
//��ʵӦ�ÿ��Բ�����Ϊȫ�ֱ���
recv_send_socket  * p_sock_receive_send = new recv_send_socket;			//ͨ�ŵ�socket

int main()
{
	
	init_global_vars();		//����������Ҫ�����ȫ�ֱ���
	//������socket
	
	p_sock_receive_send->create_recv_socket();
	send_client_hello();	//�����߼�������ѡ���Ѿ���������Ϸ						//����ط���ַҪ����Ӧ��Э�̣�
	//recv_server_hello();	//��ȡ�߼�����pythonͨ��socket�������������ݣ���������Ǯ����λ�ȣ�

	//���������߳�//������2��������ѡ��ai���߳���ʵ�ַ���ָ��
	HANDLE   hth_receive_send,hth_player;				
    unsigned  ui_thread_recive_sendID,ui_thread_playerID;	
	//�߳�1��������������
	hth_receive_send = (HANDLE)_beginthreadex( NULL,0,recv_send_socket::static_recv_data,p_sock_receive_send,CREATE_SUSPENDED,&ui_thread_recive_sendID );			//����ط�����д���е����⣬��Ӧ�ð�����߳�һֱ���ž͹���
	//����Ӧ��������������֮ǰ��һ����Ҫ�� ����һ�������ݸ�����        ��ѡ�֡����ֵ���Ϣ��ô���֣���Ҫ��һ����ż��������
	//�߳�2������ ���Ƶ���ѡ��1��ai ���߳�
	hth_player = (HANDLE)_beginthreadex( NULL,0,start_player,NULL,CREATE_SUSPENDED,&ui_thread_playerID );
	
     
	//���������߳�
	//���һ��   hth_receive1   hth_receive2	
	ResumeThread(hth_receive_send);					//�Ͱ�������һֱ��������
	ResumeThread(hth_player);						//����ʵ��̫�����ˣ��϶�����Ҫ�ĵ�
	
	WaitForSingleObject(hth_receive_send,INFINITE);
	WaitForSingleObject(hth_player,INFINITE);
	
	CloseHandle(hth_receive_send);
	CloseHandle(hth_player);
	
	p_sock_receive_send->close_recv_socket();
	
	//�����߼���úø��Ӱ�						//����߼��䵽�� ��ѡ�ֵ��߳���ֱ�ʵ��
	/*while(game_not_end())		//ֻҪ��Ϸû�н���
	{
		player_main();			//����ִ��ѡ�ֵ�playermain����
		wait_till_next_round();		//��ִ����playermain֮�����һ�غϡ��ٽ���whileѭ��
	}*/
	delete [] all_unit;
	/*
	delete [] all_unit_1;					//�ͷſռ�
	delete [] all_unit_2;	
	*/
	cout<<"1"<<endl;
	return 0;
}  