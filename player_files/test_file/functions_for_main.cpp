#include "communicate.h"
#include "head_for_main.h"
//#define WIN32_LEAN_AND_MEAN   // Exclude rarely-used stuff from Windows headers
 
// #include <windows.h>
 
extern bool flag_of_round;	
extern bool flag_of_gameOver;
extern recv_send_socket  * p_sock_receive_send;
extern int all_received;
extern bool receiveable = true;
extern bool runAI = false;
extern int turn=0;
void player_main(void);				//ѡ�ֵ��߳�Ҫ����     д��playerMain.cpp��


void init_global_vars()					//���ݴ������ȵ��ӵ���Ϣʱ��תΪtrue
{
	flag_of_round=false;	
	flag_of_gameOver=false;				//��Ϸ����ʱ����Ϊtrue
}

void send_client_hello()				//�����߼��ˣ� ѡ�����׼������
{
	p_sock_receive_send->InitialSocketClient();					//��ʼ��socket������ �߼��˷�����ʼ��������
	
}

bool game_not_end()						//�ô��߼��˻�ȡ��Ϸ�Ƿ��������Ϣ
{
	if (flag_of_gameOver==true)
		return false;
	else
#ifdef DEBUG
		return true;
#else 
		return true;
#endif
}

unsigned int __stdcall start_player(void* arg)					//����ѡ��1���߳�
{
	while (!flag_of_gameOver)
	{
		if (runAI)
		{
		cout<<"turns��"<<turn<<endl;
		player_main();
		turn++;
		runAI = false;
		p_sock_receive_send->send_data();
		}	

	}
	return 0;
}


void wait_till_next_round()					//֮���һ��ʱ��ļ��  �����ת
{
	while (true)
	{
		if (flag_of_round == true)					//���Խ�����һ�ε��ú���
			return;
		else if (all_received >= 3)
		{
			flag_of_round = true;
			return;
		}
		else 
		{
			Sleep(1000*time_round/1000);
		}//����ȴ�   ֱ���߼��˸�������һ�غϿ�ʼ��
				//			//��ʱ��Ϣ1/100�غ���ÿ�ת			//��֪�����̻߳᲻���кܴ�Ӱ�죿
	}
}
