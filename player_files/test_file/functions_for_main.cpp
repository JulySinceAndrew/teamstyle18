#include "communicate.h"
#include "head_for_main.h"
//#define WIN32_LEAN_AND_MEAN   // Exclude rarely-used stuff from Windows headers
 
// #include <windows.h>
 
extern bool flag_of_round;	
extern bool flag_of_gameOver;
extern recv_send_socket  * p_sock_receive_send;
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
//��ʱԼ������helloֱ�ӿ�ʼ��
/*void recv_server_hello()				//���߼��˽���һЩ���ܳ�ʼ��Ҫ�����ݣ�������������ǲ���Ҫ�ģ�				
{
	;									//������Ϣ
	flag1_of_round=true;
	flag2_of_round=true;				//�غϿ�ʼ��������
}*/
//������
//��ʵ��ȫû�б�Ҫ��������������Կ���ɾȥ
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
	while (game_not_end())
	{
		player_main();
		flag_of_round=false;									//�ȵ���һ�غ�flag���ͷ�
		wait_till_next_round();								//�ȵ���һ�غ�ʱ��flag���Ϊtrue
		//������Ӧ���һ�Ѷ������ȷ���
		p_sock_receive_send->send_data();						//�����е�ָ��ͳ�ȥ
																//��仰Ӧ�ð�������ã�����  ������϶��ǲ��Ե��ǲ���Ҫ�ٿ�һ���̣߳�
		//Sleep(5);
	}
	
	return 0;
}


void wait_till_next_round()					//֮���һ��ʱ��ļ��  �����ת
{
	while (true)
	{
		if (flag_of_round==true)					//���Խ�����һ�ε��ú���
			return;
		else                                        //����ȴ�   ֱ���߼��˸�������һ�غϿ�ʼ��
			Sleep(1000*time_round/1000);	//			//��ʱ��Ϣ1/100�غ���ÿ�ת			//��֪�����̻߳᲻���кܴ�Ӱ�죿
	}
}
