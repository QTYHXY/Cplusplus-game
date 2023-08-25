#include "../inc/operation.h"
#include "../inc/mouse.h"
#include "Pipi.hpp"
#include "SmallMonkey.hpp"
#include "Eva.hpp"
#include "BritneySeeds.hpp"
#include <iostream>
#include <windows.h>
extern "C" {
#include <string.h>
}
using namespace std;

extern struct resource res;
SmallMonkey smallmonkey;
Eva eva;
BritneySeeds britneyseeds;

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
				cout << "�򿪵��߱���" << endl;
			}
			else if (inArea(msg.x, msg.y, 560, 95, 115, 130))
			{

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
				cout << "�򿪳����̵�" << endl;
			}
			else if (inArea(msg.x, msg.y, 90, 280, 115, 130))
			{
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
				cout << "��ͼ̽��" << endl;
			}
			else if (inArea(msg.x, msg.y, 320, 280, 115, 130))
			{

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
		//cout << "operation pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <class T1>
int fairyHospital(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 7);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "fairyHospital  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
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
			cleardevice();
			putimage(0, 0, res.map + 1);
			//againstChoose(my);
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 590, 115, 160, 150))
		{
			cout << "������" << endl;
			cleardevice();
			putimage(0, 0, res.map + 2);
			//againstChoose(my);
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "map  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <class T1>
int petBackpack(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 5);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "petBackpack  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <class T1>
int petStore(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 4);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "petStore  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <class T1>
int mypropBackpack(T1& my)
{
	cleardevice();
	putimage(0, 0, res.resourceBK + 3);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "mypropBackpack  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}


template <class T1>
int againstChooseMap1(T1& my)
{
choose:
	cleardevice();
	putimage(0, 0, res.map + 3);
	ExMessage msg = { 0 };
	while (true)
	{
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
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 2;
		}
		//cout << "againstChoose  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}

template <class T1>
int againstChooseMap2(T1& my)
{
choose:
	cleardevice();
	putimage(0, 0, res.map + 3);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 110, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			Pipi pipi;
			if (against(smallmonkey, pipi))
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
		//cout << "againstChoose  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}

template <class T1>
int againstChooseMap3(T1& my)
{
choose:
	cleardevice();
	putimage(0, 0, res.map + 3);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//��ȡ��Ϣ 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 110, 125, 110))
		{
			cout << "��ʼ��ս" << endl;
			Pipi pipi;
			if (against(smallmonkey, pipi))
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
		//cout << "againstChoose  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <typename T1, typename T2>
int against(T1& my, T2& other)
{
	if (other._curHp <= 0)
	{
		other._curHp = other._fullHp;
	}
	if (my._curHp <= 0)
	{
		//cout <<"����ֵ�ѿգ��޷��μ�ս��" << endl;
		my._curHp = my._fullHp;
	}
	cleardevice();
	putimage(0, 0, &res.against);
	showInfo(my, 10, 100);
	showInfo(other, 690, 10);
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
			int harmMe = other.firstSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 1);
			showInfo(my, 10, 100);
			showInfo(other, 690, 10);
			EndBatchDraw();
		}
		//������λ��
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 230, 360, 145, 70))
		{

			msg.message = WM_LBUTTONUP;
			//cout << "ʹ��һ����" << endl;
			int harmOther = my.SecondSkill(other);
			int harmMe = other.SecondSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 2);
			showInfo(my, 10, 100);
			showInfo(other, 690, 10);
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
				cout << other._name << "Ҳ����" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 3);
			showInfo(my, 10, 100);
			showInfo(other, 690, 10);
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
				cout << other._name << "Ҳ����" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "Ҳ����" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100, 4);
			showInfo(my, 10, 100);
			showInfo(other, 690, 10);
			EndBatchDraw();
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "�˳�" << endl;
			return 1;
		}
		//cout << "against  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
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

	if (option == 1)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ����һ����", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ����һ����", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 2)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ���˶�����", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ���˶�����", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 3)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ����������", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ����������", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
	else if (option == 4)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s��%sʹ�����ļ���", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s��%sʹ�����ļ���", tmpOtherChar, tmpMyChar);
		outtextxy(x, y + 15, tmpStr);
	}
}
