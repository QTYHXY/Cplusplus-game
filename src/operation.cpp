#include "../inc/operation.h"
#include "../inc/mouse.h"
#include "Pipi.hpp"
#include "SmallMonkey.hpp"
#include <iostream>
extern "C" {
#include <string.h>
}
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
		peekmessage(&msg, EX_MOUSE);//获取消息 鼠标
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
		{
			if (inArea(msg.x, msg.y, 90, 95, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 5);
				cout << "打开宠物背包" << endl;
			}
			else if (inArea(msg.x, msg.y, 320, 95, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 3);
				cout << "打开道具背包" << endl;
			}
			else if (inArea(msg.x, msg.y, 560, 95, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 4);
				cout << "打开宠物商店" << endl;
			}
			else if (inArea(msg.x, msg.y, 90, 280, 115, 130))
			{

				int ret = mapExploration();
				if (ret == 2)
				{
					goto map;
				}
				cout << "地图探索" << endl;
			}
			else if (inArea(msg.x, msg.y, 320, 280, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 7);
				cout << "精灵医院" << endl;
			}
			else if (inArea(msg.x, msg.y, 560, 280, 115, 130))
			{
				cleardevice();
				putimage(0, 0, res.resourceBK + 8);
				cout << "退出" << endl;
				return 0;
			}
		}
		}
		//cout << "operation pos(" << msg.x << "," << msg.y << ")" << endl;
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
		mapDescribe(msg.x, msg.y);
		peekmessage(&msg, EX_MOUSE);//获取消息 鼠标
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 70, 115, 150, 150))
		{
			msg.message = WM_LBUTTONUP;
			cout << "云霄星" << endl;
			int ret = againstChoose();
			if (ret == 2)
			{
				goto mapchoose;
			}

		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 325, 115, 150, 150))
		{
			cout << "海洋星" << endl;
			cleardevice();
			putimage(0, 0, res.map + 1);
			againstChoose();
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 590, 115, 160, 150))
		{
			cout << "雷神星" << endl;
			cleardevice();
			putimage(0, 0, res.map + 2);
			againstChoose();
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "退出" << endl;
			return 2;
		}
		//cout << "map  pos(" << msg.x << "," << msg.y << ")" << endl;
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
choose:
	cleardevice();
	putimage(0, 0, res.map + 3);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//获取消息 
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 110, 125, 110))
		{
			cout << "开始对战" << endl;
			//cleardevice();
			//putimage(0, 0, &res.against);
			if (against(smallmonkey, pipi))
			{
				cout << "战斗结束" << endl;
				goto choose;
			}
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 0, 95, 70))
		{
			cout << "退出" << endl;
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
		//cout <<"生命值已空，无法参加战斗" << endl;
		my._curHp = my._fullHp;
	}
	cleardevice();
	putimage(0, 0, &res.against);
	showInfo(my, 10, 100);
	showInfo(other, 690, 10);
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//获取消息
		//一技能位置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 35, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			//cout << "使用一技能" << endl;
			int harmOther = my.firstSkill(other);
			int harmMe = other.firstSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
				other._curExpValue += 5;
				other.upGrade();
				return 1;
			}
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &res.against);
			againstInfo(my, other, 300, 100,1);
			showInfo(my, 10, 100);
			showInfo(other, 690, 10);
			EndBatchDraw();
		}
		//二技能位置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 230, 360, 145, 70))
		{

			msg.message = WM_LBUTTONUP;
			//cout << "使用一技能" << endl;
			int harmOther = my.SecondSkill(other);
			int harmMe = other.SecondSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
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
		//三技能位置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 430, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			//cout << "使用一技能" << endl;
			int harmOther = my.ThirdSkill(other);
			int harmMe = other.ThirdSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
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
		//四技能位置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 630, 360, 145, 70))
		{
			msg.message = WM_LBUTTONUP;
			//cout << "使用一技能" << endl;
			int harmOther = my.fourthSkill(other);
			int harmMe = other.fourthSkill(my);
			other._curHp -= harmOther;
			my._curHp -= harmMe;
			if (other.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
				my._curExpValue += 5;
				my.upGrade();
				return 1;
			}
			else if (my.isEmptyHp())
			{
				cout << other._name << "也死亡" << endl;
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
			cout << "退出" << endl;
			return 1;
		}
		//cout << "against  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
template <typename T1>
void showInfo(T1& obj, int x, int y, string str)
{
	//设置文字大小
	settextstyle(20, 0, "微软雅黑");
	//设置文字颜色
	settextcolor(RED);
	//设置背景模式
	setbkmode(TRANSPARENT);

	char petName[20];

	string tmpStr = obj._name;
	char* tmpChar = (char*)tmpStr.data();
	//显示名称
	sprintf_s(petName, "精灵名称  :  %s", tmpChar);
	outtextxy(x, y, petName);
	//显示等级
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "等级  :  %d", obj._grade);
	outtextxy(x, y + 15, petName);
	//显示生命值
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "生命值  :  %d / %d", obj._curHp, obj._fullHp);
	outtextxy(x, y + 30, petName);
	//显示攻击力
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "攻击力  :  %d", obj._aggressivity);
	outtextxy(x, y + 45, petName);
	//显示防御力
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "防御力  :  %d", obj._defense);
	outtextxy(x, y + 60, petName);
	//显示速度
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "速度值  :  %d", obj._speed);
	outtextxy(x, y + 75, petName);
	//显示经验值
	memset(petName, 0, sizeof(petName));
	sprintf_s(petName, "经验值  :  %d / %d", obj._curExpValue, obj._fullExpValue);
	outtextxy(x, y + 90, petName);
}

template <typename T1, typename T2>
void againstInfo(T1& my, T2& other, int x, int y, int option)
{
	char tmpStr[50];
	//我的名字
	string tmpMyStr = my._name;
	char* tmpMyChar = (char*)tmpMyStr.data();
	//其他名字
	string tmpOtherStr = other._name;
	char* tmpOtherChar = (char*)tmpOtherStr.data();

	if (option == 1)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s对%s使用了一技能", tmpMyChar,tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s对%s使用了一技能", tmpOtherChar, tmpMyChar);
		outtextxy(x, y+15, tmpStr);
	}
	else if (option == 2)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s对%s使用了二技能", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s对%s使用了二技能", tmpOtherChar, tmpMyChar);
		outtextxy(x, y+15, tmpStr);
	}
	else if (option == 3)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s对%s使用了三技能", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s对%s使用了三技能", tmpOtherChar, tmpMyChar);
		outtextxy(x, y+15, tmpStr);
	}
	else if (option == 4)
	{
		memset(tmpStr, 0, sizeof(tmpStr));
		sprintf_s(tmpStr, "%s对%s使用了四技能", tmpMyChar, tmpOtherChar);
		outtextxy(x, y, tmpStr);
		sprintf_s(tmpStr, "%s对%s使用了四技能", tmpOtherChar, tmpMyChar);
		outtextxy(x, y+15, tmpStr);
	}
}
