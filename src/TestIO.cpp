/*
 * TestIO.cpp
 *
 *  Created on: 2016��4��10��
 *      Author: j
 */

#include <stdio.h>
// libeventͷ�ļ�
#include <event.h>
#include <iostream>
using namespace std;

// ��ʱ�¼��ص�����
//void onTime(int sock, short event, void *arg) {
//	cout << "Hello, IO!" << endl;
//
//	struct timeval tv;
//	tv.tv_sec = 1;
//	tv.tv_usec = 0;
//	// ������Ӷ�ʱ�¼�����ʱ�¼�������Ĭ���Զ�ɾ����
//	event_add((struct event*) arg, &tv);
//}

//int main() {
//	// ��ʼ��
//	event_init();
//
//	struct event evTime;
//	// ���ö�ʱ�¼�
//	evtimer_set(&evTime, onTime, &evTime);
//
//	struct timeval tv;
//	tv.tv_sec = 1;
//	tv.tv_usec = 0;
//	// ��Ӷ�ʱ�¼�
//	event_add(&evTime, &tv);
//
//	// �¼�ѭ��
//	event_dispatch();
//
//	return 0;
//}

