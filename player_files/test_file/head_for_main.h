//functions for "main"

#pragma once


void init_global_vars();	

void send_client_hello();
void recv_server_hello();
bool game_not_end();

unsigned int __stdcall start_player(void* arg);					//����ѡ�ֵ��߳�

void wait_till_next_round();				//�����������������һ��ѡ�ֵ�flag 1��ʾѡ�֣�2��ʾѡ��2

//��ΪҪʹѡ�ֺ���һ�غ�����ֻ�ܱ�ִ��һ�Σ�����һ����־��¼�µ�һ�غ��Ƿ�ʼ�ˣ�ѡ����غϺ����Ƿ񱻵��ù���
//�������  �غ��Ƿ�ʼ�����߼���֪ͨ�ң��ҾͲ����ˡ��ӵ�֪ͨ��flag=true;ѡ�ֺ����������flag=false;


const float time_round=0.1;		//����ʱ�ٶ�ÿ�غ�0.01s



//�����ö��д洢����ָ�
