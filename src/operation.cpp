#include "../inc/operation.h"
#include "../inc/mouse.h"
#include "Pipi.hpp"
#include "SmallMonkey.hpp"
#include <iostream>
using namespace std;

extern struct resource res;

int myOperation()
{
	ExMessage msg = { 0 };
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
				cleardevice();
				putimage(0, 0, res.map + 0);
				mapExploration();
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
		cout << "operation pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}
void fairyHospital()
{

}
void mapExploration()
{
	ExMessage msg = { 0 };
	while (true)
	{
		mapDescribe(msg.x,msg.y);
		peekmessage(&msg, EX_MOUSE);//获取消息 鼠标
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 70, 115, 150, 150))
		{
			cout << "云霄星" << endl;
			cleardevice();
			putimage(0, 0, res.map + 3);
			againstChoose();

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


void againstChoose()
{
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//获取消息 鼠标
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 140, 110, 125, 110))
		{
			cout << "开始对战" << endl;
			cleardevice();
			putimage(0, 0, &res.against);
//			SmallMonkey smallmonkey;
//			Pipi pipi;
//			against(smallmonkey, pipi);
		}
	}
}

void against(const Pokemon& my, const Pokemon& other)
{
	ExMessage msg = { 0 };
	while (true)
	{
		peekmessage(&msg, EX_MOUSE);//获取消息 鼠标
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 35, 110, 125, 110))
		{

		}
		cout << "against  pos(" << msg.x << "," << msg.y << ")" << endl;
	}
}



