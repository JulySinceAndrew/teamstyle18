#pragma once
#include <stdio.h>  
#include <Winsock2.h>  
#pragma comment( lib, "ws2_32.lib" )  

#include "teamstyle18-my-1.h"
class recv_send_socket							//����ֻ���������ܹ���main������ʵ��
{
public:
	//recv_send_socket(bool team);				//false��ʾ��һ��Ӫ��true��ʾ�ڶ���Ӫ
	void create_recv_socket(void);
	void InitialSocketClient(void);
	static unsigned __stdcall static_recv_data(void * pThis);
	void recv_data(void);
	void send_data(void);
	void close_recv_socket(void);
private:
	WORD wVersionRequested;  
    WSADATA wsaData;  
    int err;  
	SOCKET sockClient;					//����˵�socket
};




//SkillInstr * p_all_1 = new SkillInstr[10000];
