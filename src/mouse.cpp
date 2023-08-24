#include "../inc/mouse.h"
#include "../inc/global.h"
#include "../inc/loadBackgroud.h"
#include <iostream>
extern struct resource res;
using namespace std;
//判断是否在区域内
bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
	{
		return true;
	}
	return false;
}
//宠物描述
void describe(int x,int y)
{
	//集中显示
	if (inArea(x, y, 70, 110, 160, 190))
	{
		putimage(162, 325, res.describe + 0);
	}
	if (inArea(x, y, 310, 110, 160, 190))
	{
		putimage(162, 325, res.describe + 1);
	}
	if (inArea(x, y, 550, 110, 160, 190))
	{
		putimage(162, 325, res.describe + 2);
	}
}
//地图描述
void mapDescribe(int x, int y)
{
	//集中显示
	if (inArea(x, y, 70, 115, 150, 150))
	{
		putimage(162, 325, res.describe + 3);
	}
	if (inArea(x, y, 325, 115, 150, 150))
	{
		putimage(162, 325, res.describe + 4);
	}
	if (inArea(x, y, 590, 115, 150, 150))
	{
		putimage(162, 325, res.describe + 5);
	}
}

