//ͷ�ļ�
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "../inc/operation.h"
#include "../inc/mouse.h"
#include "../src/tool.hpp"
extern "C" {
#include <string.h>
}
//�ж�����
#include "Pipi.hpp"
#include "Ray.hpp"
#include "SawShark.hpp"
//�ҷ�����
#include "SmallMonkey.hpp"
#include "Eva.hpp"
#include "BritneySeeds.hpp"

using namespace std;

extern struct resource res;

SmallMonkey smallmonkey;
Eva eva;
BritneySeeds britneyseeds;

//��ҳ�����
int myOperation(int num)
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
				cout << "�򿪳��ﱳ��" << endl;
				int ret;
				if (num == 1)
				{
					ret = petBackpack(smallmonkey);
				}
				else if (num == 2)
				{
					ret = petBackpack(eva);
				}
				else if (num == 3)
				{
					ret = petBackpack(britneyseeds);
				}

				if (ret == 2)
				{
					goto map;
				}
			}
			else if (inArea(msg.x, msg.y, 320, 95, 115, 130))
			{
				cout << "�򿪵��߱���" << endl;
				int ret;
				if (num == 1)
				{
					ret = mypropBackpack(smallmonkey);
				}
				else if (num == 2)
				{
					ret = mypropBackpack(eva);
				}
				else if (num == 3)
				{
					ret = mypropBackpack(britneyseeds);
				}
				if (ret == 2)
				{
					goto map;
				}
			}
			else if (inArea(msg.x, msg.y, 560, 95, 115, 130))
			{
				cout << "�򿪳����̵�" << endl;
				int ret;
				if (num == 1)
				{
					ret = petStore(smallmonkey);
				}
				else if (num == 2)
				{
					ret = petStore(eva);
				}
				else if (num == 3)
				{
					ret = petStore(britneyseeds);
				}
				if (ret == 2)
				{
					goto map;
				}
			}
			else if (inArea(msg.x, msg.y, 90, 280, 115, 130))
			{
				cout << "��ͼ̽��" << endl;
				int ret;
				if (num == 1)
				{
					ret = mapExploration(smallmonkey);
				}
				else if (num == 2)
				{
					ret = mapExploration(eva);
				}
				else if (num == 3)
				{
					ret = mapExploration(britneyseeds);
				}
				if (ret == 2)
				{
					goto map;
				}
			}
			else if (inArea(msg.x, msg.y, 320, 280, 115, 130))
			{
				cout << "����ҽԺ" << endl;
				int ret;
				if (num == 1)
				{
					ret = fairyHospital(smallmonkey);
				}
				else if (num == 2)
				{
					ret = fairyHospital(eva);
				}
				else if (num == 3)
				{
					ret = fairyHospital(britneyseeds);
				}
				if (ret == 2)
				{
					goto map;
				}
			}
			else if (inArea(msg.x, msg.y, 560, 280, 115, 130))
			{
				cleardevice();
				//putimage(0, 0, res.resourceBK + 8);
				if (num == 1)
				{
					archive(smallmonkey, 1);
				}
				else if (num == 2)
				{
					archive(eva, 2);
				}
				else if (num == 3)
				{
					archive(britneyseeds, 3);
				}
				cout << "�˳�" << endl;
				return 0;
			}
		}
		}
		//cout << "operation pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//ҽԺ
template <class T1>
int fairyHospital(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 7);

	//�ҵ�����
	string tmpMyStr = my._name;
	char* tmpMyChar = (char*)tmpMyStr.data();
	//�������ִ�С
	settextstyle(30, 0, "΢���ź�");
	//����������ɫ
	settextcolor(WHITE);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��ʾ����
	outtextxy(320, 120, "����ָ�����ֵ");

	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 290, 85, 210, 170))
		{
			my._curHp = my._fullHp;
			cout << my._name << "�ѻָ�ȫ������ֵ" << endl;
			char tmpStr[50];
			memset(tmpStr, 0, sizeof(tmpStr));
			Sleep(1000);
			sprintf_s(tmpStr, "%s�ѻָ�ȫ������ֵ", tmpMyChar);
			outtextxy(290, 290, tmpStr);
			outtextxy(320, 360, "������Զ��˳�");
			Sleep(2000);
			return 2;
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "fairyHospital  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//��ͼ̽��
template <class T1>
int mapExploration(T1& my)
{
mapchoose:
	ExMessage msg = { 0 };
	cleardevice();
	putimage(0, 0, res.map + 0);
	while (true)
	{
		mapDescribe(msg.x, msg.y);
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ ���
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 70, 115, 150, 150))
		{
			msg.message = WM_LBUTTONUP;
			cout << "������" << endl;
			int ret = againstChooseMap1(my);
			if (ret == 2)
			{
				goto mapchoose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 325, 115, 150, 150))
		{
			cout << "������" << endl;
			int ret = againstChooseMap2(my);
			if (ret == 2)
			{
				goto mapchoose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 590, 115, 160, 150))
		{
			cout << "������" << endl;
			int ret = againstChooseMap3(my);
			if (ret == 2)
			{
				goto mapchoose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "map  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//���ﱳ��
template <class T1>
int petBackpack(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 5);
	ExMessage msg = { 0 };
	//�ҵ�����
	string tmpMyStr = my._name;
	char* tmpMyChar = (char*)tmpMyStr.data();
	//�������ִ�С
	settextstyle(48, 0, "΢���ź�");
	//����������ɫ
	settextcolor(RED);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��ʾ����
	outtextxy(150, 120, tmpMyChar);
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 85, 140, 140))
		{
			msg.message = WM_LBUTTONUP;
			cout << "��Ʒ1" << endl;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 505, 80, 140, 140))
		{
			msg.message = WM_LBUTTONUP;
			cout << "��Ʒ2" << endl;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 45, 285, 140, 140))
		{
			msg.message = WM_LBUTTONUP;
			cout << "��Ʒ3" << endl;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 235, 285, 140, 140))
		{
			msg.message = WM_LBUTTONUP;
			cout << "��Ʒ4" << endl;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 435, 285, 140, 140))
		{
			msg.message = WM_LBUTTONUP;
			cout << "��Ʒ5" << endl;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 640, 285, 140, 140))
		{
			msg.message = WM_LBUTTONUP;
			cout << "��Ʒ6" << endl;
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "petBackpack  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//�����̵�
template <class T1>
int petStore(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 4);


	ExMessage msg = { 0 };
	while (true)
	{
		myDrawImgSingle(120, 170, res.tool + 0);
		myDrawImgSingle(540, 170, res.tool + 1);
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 90, 150, 130, 165))
		{
			msg.message = WM_LBUTTONUP;
			cout << "�󱦽�" << endl;
			//�������ִ�С
			settextstyle(30, 0, "΢���ź�");
			//����������ɫ
			settextcolor(WHITE);
			//���ñ���ģʽ
			setbkmode(TRANSPARENT);
			//��ʾ����
			outtextxy(320, 120, "�󱦽�����ɹ�");
			myDrawImgSingle(120, 170, res.tool + 0);
			my._isAttack = 1;
			Sleep(1000);
			cleardevice();
			putimage(0, 0, res.resourceBK + 4);
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 520, 140, 130, 165))
		{
			msg.message = WM_LBUTTONUP;
			cout << "�����" << endl;
			//�������ִ�С
			settextstyle(30, 0, "΢���ź�");
			//����������ɫ
			settextcolor(WHITE);
			//���ñ���ģʽ
			setbkmode(TRANSPARENT);
			//��ʾ����
			outtextxy(320, 120, "����ƹ���ɹ�");
			myDrawImgSingle(540, 170, res.tool + 1);

			my._isDefensive = 1;
			Sleep(1000);
			cleardevice();
			putimage(0, 0, res.resourceBK + 4);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "petStore  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//���߱���
template <class T1>
int mypropBackpack(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 3);
	ExMessage msg = { 0 };
	//�������ִ�С
	settextstyle(25, 0, "΢���ź�");
	//����������ɫ
	settextcolor(WHITE);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);

	if (my._isAttack == 1 && my._isDefensive == 0)
	{
		//outtextxy(160, 100, "�󱦽�");
		myDrawImgSingle(160, 100, res.tool + 0);
	}
	else if (my._isAttack == 0 && my._isDefensive == 1)
	{
		//outtextxy(160, 100, "�����");
		myDrawImgSingle(160, 100, res.tool + 1);
	}
	else if (my._isAttack == 1 && my._isDefensive == 1)
	{
		//outtextxy(160, 100, "�󱦽�");
		//outtextxy(490, 100, "�����");
		myDrawImgSingle(160, 100, res.tool + 0);
		myDrawImgSingle(490, 100, res.tool + 1);
	}
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 145, 80, 140, 130))
		{
			msg.message = WM_LBUTTONUP;
			cout << "����1" << endl;
			//if (my._isAttack == 1&&my._isDefensive ==0)
			//{
			//	outtextxy(160, 100, "�󱦽�");
			//}
			//else if (my._isAttack == 0 && my._isDefensive == 1)
			//{
			//	outtextxy(160, 100, "�����");
			//}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 490, 75, 140, 130))
		{
			msg.message = WM_LBUTTONUP;
			cout << "����2" << endl;
			//if (my._isAttack == 1 && my._isDefensive == 1)
			//{
			//	outtextxy(490, 100, "�����");
			//}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 20, 285, 140, 130))
		{
			msg.message = WM_LBUTTONUP;
			cout << "����3" << endl;

		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 220, 285, 140, 130))
		{
			msg.message = WM_LBUTTONUP;
			cout << "����4" << endl;

		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 450, 285, 140, 130))
		{
			msg.message = WM_LBUTTONUP;
			cout << "����5" << endl;

		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 655, 285, 140, 130))
		{
			msg.message = WM_LBUTTONUP;
			cout << "����6" << endl;

		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			msg.message = WM_LBUTTONUP;
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "mypropBackpack  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//������
template <class T1>
int againstChooseMap1(T1& my)
{
choose:
	cleardevice();
	//putimage(0, 0, res.map + 3);
	putimage(0, 0, res.map + 4);
	//�������ִ�С
	settextstyle(30, 0, "΢���ź�");
	//����������ɫ
	settextcolor(BLACK);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��ʾ����
	outtextxy(20, 20, "����");
	ExMessage msg = { 0 };
	while (true)
	{
		myDrawImgSingle(140, 110, res.role + 12);
		myDrawImgSingle(480, 45, res.role + 12);
		myDrawImgSingle(120, 270, res.role + 12);
		myDrawImgSingle(480, 280, res.role + 12);
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 110, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			Pipi pipi;
			if (against(my, pipi))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 480, 45, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			Pipi pipi;
			if (against(my, pipi))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 270, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			Pipi pipi;
			if (against(my, pipi))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 480, 280, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			Pipi pipi;
			if (against(my, pipi))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "againstChooseMap1  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//������
template <class T1>
int againstChooseMap2(T1& my)
{
choose:
	cleardevice();
	//putimage(0, 0, res.map + 1);
	putimage(0, 0, res.map + 5);
	//�������ִ�С
	settextstyle(30, 0, "΢���ź�");
	//����������ɫ
	settextcolor(WHITE);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��ʾ����
	outtextxy(20, 20, "����");
	ExMessage msg = { 0 };
	while (true)
	{
		myDrawImgSingle(190, 110, res.role + 9);
		myDrawImgSingle(550, 80, res.role + 9);
		myDrawImgSingle(80, 305, res.role + 9);
		myDrawImgSingle(580, 320, res.role + 9);
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 190, 100, 120, 110))
		{
			cout << "��ʼ��ս" << endl;
			SawShark sawshark;
			if (against(my, sawshark))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 550, 80, 120, 110))
		{
			cout << "��ʼ��ս" << endl;
			SawShark sawshark;
			if (against(my, sawshark))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 80, 305, 120, 110))
		{
			cout << "��ʼ��ս" << endl;
			SawShark sawshark;
			if (against(my, sawshark))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 580, 320, 120, 110))
		{
			cout << "��ʼ��ս" << endl;
			SawShark sawshark;
			if (against(my, sawshark))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "againstChooseMap2  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//������
template <class T1>
int againstChooseMap3(T1& my)
{
choose:
	cleardevice();
	//putimage(0, 0, res.map + 2);
	putimage(0, 0, res.map + 6);
	//�������ִ�С
	settextstyle(30, 0, "΢���ź�");
	//����������ɫ
	settextcolor(WHITE);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��ʾ����
	outtextxy(20, 20, "����");
	ExMessage msg = { 0 };
	while (true)
	{
		myDrawImgSingle(345, 60, res.role + 15);
		myDrawImgSingle(165, 275, res.role + 15);
		myDrawImgSingle(530, 295, res.role + 15);
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 345, 60, 120, 120))
		{
			cout << "��ʼ��ս" << endl;
			Ray ray;
			if (against(my, ray))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 165, 275, 120, 120))
		{
			cout << "��ʼ��ս" << endl;
			Ray ray;
			if (against(my, ray))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 530, 295, 120, 120))
		{
			cout << "��ʼ��ս" << endl;
			Ray ray;
			if (against(my, ray))
			{
				cout << "ս������" << endl;
				goto choose;
			}
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "againstChooseMap3  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//��ʼս��
template <typename T1, typename T2>
int against(T1& my, T2& other)
{
	if (other._curHp <= 0)
	{
		other._curHp = other._fullHp;
	}
	cleardevice();
	putimage(0, 0, &res.against);
	showInfo(my, 150, 10);
	showInfo(other, 670, 10);
	
	if (my._name == "С���")
	{
		myDrawImgSingle(145, 175, res.role + 6);
	}
	else if (my._name == "����")
	{
		myDrawImgSingle(145, 175, res.role + 3);
	}
	else if (my._name == "��������")
	{
		myDrawImgSingle(145, 175, res.role + 0);
	}

	if (other._name == "����")
	{
		myDrawImgSingle(555, 80, res.role + 15);
	}
	else if (other._name == "ƤƤ")
	{
		myDrawImgSingle(550, 80, res.role + 12);
	}
	else if (other._name == "С����")
	{
		myDrawImgSingle(550, 80, res.role + 9);
	}

	if (my._isAttack == 1 && my._isDefensive == 1)
	{
		myDrawImgSingle(0, 160, res.tool +0);
		myDrawImgSingle(0, 250, res.tool + 1);
	}
	else if (my._isDefensive == 1)
	{
		myDrawImgSingle(0, 250, res.tool + 1);
	}
	else if(my._isAttack == 1)
	{
		myDrawImgSingle(0, 160, res.tool + 0);
	}


	if (my._curHp <= 0)
	{
		cout << "����ֵ�ѿգ��޷��μ�ս��" << endl;
		//�ҵ�����
		string tmpMyStr = my._name;
		char* tmpMyChar = (char*)tmpMyStr.data();
		char tmpStr[50];
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s������ֵ�ѿ�", tmpMyChar);
		outtextxy(300, 100, tmpStr);
		sprintf_s(tmpStr, "%s�޷��μ�ս��", tmpMyChar);
		outtextxy(300, 115, tmpStr);
		outtextxy(300, 130, " ������Զ��˳�");
		Sleep(2000);
		return 1;
	}


	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		//һ����λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 35, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			int harmOther = my.firstSkill(other);
			int harmMe = other.firstSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other._curHp <= 0)
			{
				cout << other._name << "������" << endl;
				my._curExpValue += 10;
				my.upGrade();
				return 1;
			}
			else if (my._curHp <= 0)
			{
				cout << my._name << "������" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 1);
			showInfo(my, 150, 10);
			showInfo(other, 670, 10);
			EndBatchDraw();
		}
		//������λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 230, 360, 145, 70))
		{

			msg.message = WM_LBUTTONUP;
			int harmOther = my.SecondSkill(other);
			int harmMe = other.SecondSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "������" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << my._name << "������" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 2);
			showInfo(my, 150, 10);
			showInfo(other, 670, 10);
			EndBatchDraw();
		}
		//������λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 430, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			//cout << "ʹ��һ����" << endl;
			int harmOther = my.ThirdSkill(other);
			int harmMe = other.ThirdSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "������" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << my._name << "������" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 3);
			showInfo(my, 150, 10);
			showInfo(other, 670, 10);
			EndBatchDraw();
		}
		//�ļ���λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 630, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			//cout << "ʹ��һ����" << endl;
			int harmOther = my.fourthSkill(other);
			int harmMe = other.fourthSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "������" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << my._name << "������" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 4);
			showInfo(my, 150, 10);
			showInfo(other, 670, 10);
			EndBatchDraw();
		}
		//������λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 160, 80, 80))
		{
			msg.message = WM_LBUTTONUP;
			if (my._isAttack == 0)
			{
				cout << "û����������" << endl;
			}
			else
			{
				int harmOther = my.firstSwordSkill(my);
				other._curHp -= harmOther;
				if (other.isEmptyHp())
				{
					cout << other._name << "������" << endl;
					my._curExpValue += 5;
					my.upGrade();
					return 1;
				}
				else if (my.isEmptyHp())
				{
					cout << my._name << "������" << endl;
					other._curExpValue += 5;
					other.upGrade();
					return 1;
				}
				BeginBatchDraw();
				cleardevice();
				putimage(0, 0, &res.against);
				againstInfo(my, other, 300, 100, 5);
				showInfo(my, 150, 10);
				showInfo(other, 670, 10);
				EndBatchDraw();
			}
			cout << "����1" << endl;
		}
		//������λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 250, 80, 80))
		{
			msg.message = WM_LBUTTONUP;
			if (my._isDefensive == 0)
			{
				cout << "û�з��߷���" << endl;
			}
			else
			{
				int upDefensive = my.firstShieldSkill(my);
				my._defense += upDefensive;
				if (other.isEmptyHp())
				{
					cout << other._name << "������" << endl;
					my._curExpValue += 5;
					my.upGrade();
					return 1;
				}
				else if (my.isEmptyHp())
				{
					cout << my._name << "������" << endl;
					other._curExpValue += 5;
					other.upGrade();
					return 1;
				}
				BeginBatchDraw();
				cleardevice();
				putimage(0, 0, &res.against);
				againstInfo(my, other, 300, 100, 6);
				showInfo(my, 150, 10);
				showInfo(other, 670, 10);
				EndBatchDraw();
			}
			cout << "����2" << endl;
		}
		//�˳�
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 1;
		}
		cout << "against  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
//˫����Ϣ��ʾ
template <typename T1>
void showInfo(T1& obj, int x, int y, string str)
{
	//�������ִ�С
	settextstyle(20, 0, "΢���ź�");
	//����������ɫ
	settextcolor(RED);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);

	char petName[50];

	string tmpStr = obj._name;
	char* tmpChar = (char*)tmpStr.data();
	//��ʾ����
	sprintf_s(petName, "��������  :  %s", tmpChar);
	outtextxy(x, y, petName);
	//��ʾ�ȼ�
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "�ȼ�  :  %d", obj._grade);
	outtextxy(x, y + 15, petName);
	//��ʾ����ֵ
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "����ֵ  :  %d / %d", obj._curHp, obj._fullHp);
	outtextxy(x, y + 30, petName);
	//��ʾ������
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "������  :  %d", obj._aggressivity);
	outtextxy(x, y + 45, petName);
	//��ʾ������
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "������  :  %d", obj._defense);
	outtextxy(x, y + 60, petName);
	//��ʾ�ٶ�
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "�ٶ�ֵ  :  %d", obj._speed);
	outtextxy(x, y + 75, petName);
	//��ʾ����ֵ
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "����ֵ  :  %d / %d", obj._curExpValue, obj._fullExpValue);
	outtextxy(x, y + 90, petName);
}
//��ս������ʾ
template <typename T1, typename T2>
void againstInfo(T1& my, T2& other, int x, int y, int option)
{
	char tmpStr[60];
	//�ҵ�����
	string tmpMyStr = my._name;
	char* tmpMyChar = (char*)tmpMyStr.data();
	//��������
	string tmpOtherStr = other._name;
	char* tmpOtherChar = (char*)tmpOtherStr.data();
	//��������
	string tmpToolAStr = my.Sword::_eName;
	char* tmpToolAChar = (char*)tmpToolAStr.data();
	//��������
	string tmpToolDStr = my.Shield::_eName;
	char* tmpToolDChar = (char*)tmpToolDStr.data();
	if (option == 1)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ����һ����", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ����һ����", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 2 && my._grade >= 4)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ���˶�����", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ���˶�����", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 3 && my._grade >= 8)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ����������", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ����������", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 4 && my._grade >= 12)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ�����ļ���", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ�����ļ���", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 5)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%sʹ��%s��%s����˺�", tmpMyChar, tmpToolAChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
	}
	else if (option == 6)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%sʹ��%s�����˷�����", tmpMyChar, tmpToolDChar);
		outtextxy(x, y, tmpStr);
	}
	else
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s�ȼ�δ����Ҫ��", tmpMyChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s�޷�ʹ�øü���", tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}

	if (my._name == "С���")
	{
		myDrawImgSingle(145, 175, res.role + 6);
	}
	else if (my._name == "����")
	{
		myDrawImgSingle(145, 175, res.role + 3);
	}
	else if (my._name == "��������")
	{
		myDrawImgSingle(145, 175, res.role + 0);
	}

	if (other._name == "����")
	{
		myDrawImgSingle(555, 80, res.role + 15);
	}
	else if (other._name == "ƤƤ")
	{
		myDrawImgSingle(550, 80, res.role + 12);
	}
	else if (other._name == "С����")
	{
		myDrawImgSingle(550, 80, res.role + 9);
	}
	if (my._isAttack == 1 && my._isDefensive == 1)
	{
		myDrawImgSingle(0, 160, res.tool + 0);
		myDrawImgSingle(0, 250, res.tool + 1);
	}
	else if (my._isDefensive == 1)
	{
		myDrawImgSingle(0, 250, res.tool + 1);
	}
	else if (my._isAttack == 1)
	{
		myDrawImgSingle(0, 160, res.tool + 0);
	}
}
//�浵
template <class T1>
void archive(T1& my, int num)
{
	ofstream outputFile("../info/info.txt");
	if (outputFile.is_open()) {
		outputFile << num << endl;
		outputFile << my._name << endl;
		outputFile << my._fullHp << endl;
		outputFile << my._curHp << endl;
		outputFile << my._aggressivity << endl;
		outputFile << my._defense << endl;
		outputFile << my._fullMp << endl;
		outputFile << my._curMp << endl;
		outputFile << my._fullExpValue << endl;
		outputFile << my._curExpValue << endl;
		outputFile << my._grade << endl;
		outputFile << my._speed << endl;
		outputFile << my._isAttack << endl;
		outputFile << my._isDefensive << endl;
		outputFile.close();
	}
	else {
		// �ļ���ʧ�ܣ����д�����
		std::cout << "�޷����ļ�����д�������" << std::endl;
	}
}
//��ȡ�浵
int readData()
{
	ifstream inputFile("../info/info.txt");
	int num = 0;
	if (inputFile.is_open()) {
		string line;
		int i=0;
		
		// ���ж�ȡ�ļ�����
		while (getline(inputFile, line)) {
			//cout << line << endl;
			if (i == 0)
			{
				cout << "num = " << line << endl;
				num = atoi(line.c_str());
			}
			else if (i == 1)
			{
				cout << "name = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setName(line);
				}
				else if (num == 2)
				{
					eva.setName(line);
				}
				else if (num == 3)
				{
					britneyseeds.setName(line);
				}
			}
			else if (i == 2)
			{
				cout << "fullHp = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setFullHp(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setFullHp(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setFullHp(atoi(line.c_str()));
				}
			}
			else if (i == 3)
			{
				cout << "curHp = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setCurHp(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setCurHp(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setCurHp(atoi(line.c_str()));
				}
			}
			else if (i == 4)
			{
				cout << "aggressivity = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setAggressivity(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setAggressivity(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setAggressivity(atoi(line.c_str()));
				}
			}
			else if (i == 5)
			{
				cout << "defense = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setDefense(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setDefense(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setDefense(atoi(line.c_str()));
				}
			}
			else if (i == 6)
			{
				cout << "fullMp = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setFullMp(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setFullMp(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setFullMp(atoi(line.c_str()));
				}
			}
			else if (i == 7)
			{
				cout << "curMp = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setCurMp(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setCurMp(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setCurMp(atoi(line.c_str()));
				}
			}
			else if (i == 8)
			{
				cout << "fullExpValue = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setFullExpValue(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setFullExpValue(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setFullExpValue(atoi(line.c_str()));
				}
			}
			else if (i == 9)
			{
				cout << "curExpValue = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setCurExpvalue(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setCurExpvalue(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setCurExpvalue(atoi(line.c_str()));
				}
			}
			else if (i == 10)
			{
				cout << "grade = " << line << endl;
				if (num == 1)                     
				{
					smallmonkey.setGrade(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setGrade(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setGrade(atoi(line.c_str()));
				}
			}
			else if (i == 11)
			{
				cout << "speed = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setSpeed(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setSpeed(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setSpeed(atoi(line.c_str()));
				}
			}
			else if (i == 12)
			{
				cout << "isAttack = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setIsAttack(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setIsAttack(atoi(line.c_str()));
				}
				else if (num == 3)
				{ 
					britneyseeds.setIsAttack(atoi(line.c_str()));
				}
			}
			else if (i == 13)
			{
				cout << "isDefensive = " << line << endl;
				if (num == 1)
				{
					smallmonkey.setIsDenfensive(atoi(line.c_str()));
				}
				else if (num == 2)
				{
					eva.setIsDenfensive(atoi(line.c_str()));
				}
				else if (num == 3)
				{
					britneyseeds.setIsDenfensive(atoi(line.c_str()));
				}
			}
			i++;
		}
		//cout << "i = " << i << endl;
		inputFile.close();
	}
	else {
		// �ļ���ʧ�ܣ����д�����
		cout << "�޷����ļ����ж�ȡ������" << endl;
	}
	myOperation(num);
	return 0;
}                                        