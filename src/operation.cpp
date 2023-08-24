#include "../inc/operation.h"
#include "../inc/mouse.h"
#include "Pipi.hpp"
#include "SmallMonkey.hpp"
#include <iostream>
#include <string>
using namespace std;

extern struct resource res;
SmallMonkey smallmonkey;
Pipi pipi;
int myOperation()
{
	
map:
	ExMessage msg = { 0 };
	cleardevice();
	putimage(0, 0, res.resourceBK + 2);
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ ���
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
		{
			if (inArea(msg.x, msg.y, 90, 95, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 5);
				cout << "�򿪳��ﱳ��" << endl;
			}
			else if (inArea(msg.x, msg.y, 320, 95, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 3);
				cout << "�򿪵��߱���" << endl;
			}
			else if (inArea(msg.x, msg.y, 560, 95, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 4);
				cout << "�򿪳����̵�" << endl;
			}
			else if (inArea(msg.x, msg.y, 90, 280, 115, 130))
			{
				
				int ret = mapExploration();
				if (ret == 2) 
				{
					goto map;
				}
				cout << "��ͼ̽��" << endl;
			}
			else if (inArea(msg.x, msg.y, 320, 280, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 7);
				cout << "����ҽԺ" << endl;
			}
			else if (inArea(msg.x, msg.y, 560, 280, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 8);
				cout << "�˳�" << endl;
				return 0;
			}
		}
		}
		cout << "operation pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
void fairyHospital()
{

}
int mapExploration()
{
mapchoose:
	ExMessage msg = { 0 };
	cleardevice();
	putimage(0, 0, res.map + 0);
	while (true)
	{
		mapDescribe(msg.x,msg.y);
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ ���
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 70, 115, 150, 150))
		{
			msg.message == WM_LBUTTONUP;
			cout << "������" << endl;
			cleardevice();
			putimage(0, 0, res.map + 3);
			int ret = againstChoose();
			if (ret==2)
			{
				goto mapchoose;
			}
			
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 325, 115, 150, 150))
		{
			cout << "������" << endl;
			cleardevice();
			putimage(0, 0, res.map + 1);
			againstChoose();
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 590, 115, 160, 150))
		{
			cout << "������" << endl;
			cleardevice();
			putimage(0, 0, res.map + 2);
			againstChoose();
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		cout << "map  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
void petBackpack()
{

}
void petStore()
{

}
void propBackpack()
{

}


int againstChoose()
{
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 110, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			cleardevice();
			putimage(0, 0, &res.against);
			if (against(smallmonkey, pipi))
			{
				cout << "ս������" << endl;
				return 1;
			}
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			//cleardevice();
			//putimage(0, 0, res.map + 0);
			return 2;
		}
		cout << "againstChoose  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <typename T1,typename T2>
int against(T1 &my, T2 &other)
{
	if (other._curHp <= 0)
	{
		other._curHp = other._fullHp;
	}
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		//һ����λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 35, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			//cout << "ʹ��һ����" << endl;
			int harmOther = my.firstSkill(other);
			int harmMe=other.firstSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			showInfo(my,other);
			//my.showAll();
			//other.showAll();
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			//cleardevice();
			//putimage(0, 0, res.map + 0);
			return 1;
		}
		//cout << "against  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <typename T1, typename T2>
void showInfo(T1& my, T2& other)
{
	//�������ִ�С
	settextstyle(20, 0, "΢���ź�");
	//����������ɫ
	settextcolor(RED);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);

	char petName[20];
	string tmpStr = my._name;
	char* tmpChar = (char *)tmpStr.data();
	sprintf_s(petName, "��������:%s", tmpChar);
	//��ʾ����
	outtextxy(10, 100, petName);
}


