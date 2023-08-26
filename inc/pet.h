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
	int _isAttack;//是否装备武器
	int _isDefensive;//是否装备防具

public:
	//构造方法
	Pokemon();
	Pokemon(string name, int fullHp, int curHp, int aggressivity, int defense, int fullMp, int curMp, int fullExpValue, int curExpValue, int grade,int speed,bool isAttack,bool isDefensive);
	virtual ~Pokemon();
	//set方法
	virtual void setName(string name);
	virtual void setFullHp(int num);
	virtual void setCurHp(int num);//当前血量
	virtual void setAggressivity(int num);//攻击力
	virtual void setDefense(int num);//防御力
	virtual void setFullMp(int num);//满魔力
	virtual void setCurMp(int num);//当前魔力
	virtual void setFullExpValue(int num);//升级要的经验值
	virtual void setCurExpvalue(int num);//当前经验值
	virtual void setGrade(int num);//等级
	virtual void setSpeed(int num);//速度
	virtual void setIsAttack(int num);//武器
	virtual void setIsDenfensive(int num);//防具
	//get方法
	virtual string getName();
	virtual int getFullHp();
	virtual int getCurHp();//当前血量
	virtual int getAggressivity();//攻击力
	virtual int getDefense();//防御力
	virtual int getFullMp();//满魔力
	virtual int getCurMp();//当前魔力
	virtual int getFullExpValue();//升级要的经验值
	virtual int getCurExpvalue();//当前经验值
	virtual int getGrade();//等级
	virtual int getSpeed();//速度
	virtual int getIsAttack();//武器
	virtual int getIsDenfensive();//防具

	//show
	void showAll();
	//empty
	int isEmptyHp();
	int isEmptyMp();

};


#endif // !_PET_H_
