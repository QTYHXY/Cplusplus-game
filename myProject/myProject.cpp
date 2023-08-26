#include <iostream>
#include "../inc/loadBackgroud.h"
#include "../inc/mouse.h"
#include "../inc/operation.h"
//#include "../src/tool.hpp"

using namespace std;
struct resource res;
int main()
{
	initgraph(800, 480, EX_SHOWCONSOLE| EX_NOCLOSE| EX_NOMINIMIZE| EX_DBLCLKS);
	loadingBK(&res);
again:
	putimage(0, 0, res.resourceBK + 0);

	while (true) {
		ExMessage msg = { 0 };
		peekmessage(&msg, EX_MOUSE);//获取消息 鼠标

		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (inArea(msg.x, msg.y, 330, 100, 115, 25))
			{
				msg.x = 0;
				msg.y = 0;
				cleardevice();
				putimage(0, 0, res.resourceBK + 1);
				//drawImg(120, 150, res.role + 0);
				//drawImg(350, 150, res.role + 3);
				//drawImg(590, 150,res.role + 6);
				while(true)
				{
					peekmessage(&msg, EX_MOUSE);//获取消息 鼠标
					describe(msg.x,msg.y);
					if (msg.message== WM_LBUTTONDOWN && inArea(msg.x, msg.y, 70, 110, 160, 190))
					{
						cout << "小火猴" << endl;
						//SmallMonkey smallmonkey;
						int ret = myOperation(1);
						if (ret == 0)
						{
							goto again;
						}
						break;
					}
					if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 310, 110, 160, 190))
					{
						cout << "伊娃" << endl;
						//Eva eva;
						int ret = myOperation(2);
						if (ret == 0)
						{
							goto again;
						}
						break;
					}
					if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 550, 110, 160, 190))
					{
						cout << "布布种子" << endl;
						//BritneySeeds britneyseeds;
						int ret =myOperation(3);
						if (ret == 0)
						{
							goto again;
						}
						break;
					}
					//cout << "角色选择 pos(" << msg.x << "," << msg.y << ")" << endl;
				}
			}
			else if (inArea(msg.x, msg.y, 330, 190, 115, 25))
			{
				cout << "读取存档" << endl;
				readData();
			}
			else if (inArea(msg.x, msg.y, 330, 270, 115, 25))
			{
				cout << "退出程序" << endl;
				exit(0);
			}
			//cout << "开始菜单 pos(" << msg.x << "," << msg.y << ")" << endl;
			break;
		default:
			break;
		}
	}

}

