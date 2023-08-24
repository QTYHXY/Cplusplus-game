#pragma once
#ifndef _PET_H_
#define _PET_H_

#include <iostream>
using namespace std;

class Pokemon
{
//private:
public:
	string _name;//名字
	int _fullHp;//满血
	int _curHp;//当前血量
	int _aggressivity;//攻击力
	int _defense;//防御力
	int _fullMp;//满魔力
	int _curMp;//当前魔力
	int _fullExpValue;//升级要的经验值
	int _curExpValue;//当前经验值
	int _grade;//等级
	int _speed;//速度

public:
	//构造方法
	Pokemon();
	Pokemon(string name, int fullHp, int curHp, int aggressivity, int defense, int fullMp, int curMp, int fullExpValue, int curExpValue, int grade,int speed);
	virtual ~Pokemon();
	//set方法
	void setName(string name);
	void setFullHp(int num);
	void setCurHp(int num);//当前血量
	void setAggressivity(int num);//攻击力
	void setDefense(int num);//防御力
	void setFullMp(int num);//满魔力
	void setCurMp(int num);//当前魔力
	void setFullExpValue(int num);//升级要的经验值
	void setCurExpvalue(int num);//当前经验值
	void setGrade(int num);//等级
	void setSpeed(int num);//速度
	//get方法
	string getName();
	int getFullHp();
	int getCurHp();//当前血量
	int getAggressivity();//攻击力
	int getDefense();//防御力
	int getFullMp();//满魔力
	int getCurMp();//当前魔力
	int getFullExpValue();//升级要的经验值
	int getCurExpvalue();//当前经验值
	int getGrade();//等级
	int getSpeed();//速度

	//show
	void showAll();
	//empty
	int isEmptyHp();
	int isEmptyMp();

};


#endif // !_PET_H_
