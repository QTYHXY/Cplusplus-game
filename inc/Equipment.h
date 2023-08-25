#pragma once
#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_
#include <iostream>
using namespace std;
class Equipment
{
public:
	string _name;//名字
	int _upHp;//提高血量
	int _upMp;//提高蓝量
	int _upAggresivity;//提高攻击力
	int _upDefense;//提高防御力
	int _upSpeed;//提高速度

public:
	//构造方法
	Equipment();
	Equipment(string name, int upHp, int upMp,int upAggresivity,int upDefense,int upSpeed);
	~Equipment();
	//set方法
	void setName(string name);
	void setUpHp(int num);
	void setUpMp(int num);
	void setUpAggresivity(int num);
	void setUpDefense(int num);
	void setUpSpeed(int num);
	//get方法
	string getName(string name);
	int getUpHp();
	int getUpMp();
	int getUpAggresivity();
	int getUpDefense();
	int getUpSpeed();
};
#endif // !_EQUIPMENT_H_
