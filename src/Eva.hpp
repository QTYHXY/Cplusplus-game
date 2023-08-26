#pragma once
#ifndef _EVA_H_
#define _EVA_H_
#include "../inc/pet.h"
#include "../inc/Equipment.h"
#include "../src/Attack.hpp"
#include "../src/Defensive.hpp"

class Eva :public Pokemon,public Sword,public Shield
{
public:
	Eva()
	{
		this->_name = "伊娃";
		this->_fullHp = 20;
		this->_curHp = this->_fullHp;
		this->_aggressivity = 10;
		this->_defense = 10;
		this->_fullMp = 15;
		this->_curMp = this->_fullMp;
		this->_fullExpValue = 20;
		this->_curExpValue = 0;
		this->_grade = 1;
		this->_speed = 9;
		this->_isAttack = 0;
		this->_isDefensive = 0;
	}
	void upGrade();
	template <class T1>
	int firstSkill(const T1& other);
	template <class T1>
	int SecondSkill(const T1& other);
	template <class T1>
	int ThirdSkill(const T1& other);
	template <class T1>
	int fourthSkill(const T1& other);

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
	void setIsAttack(int num);//武器
	void setIsDenfensive(int num);//防具
};


void Eva::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "伊娃升级成功" << endl;
		this->_fullHp += 5;
		this->_fullHp = this->_fullHp;

		this->_fullMp += 4;
		this->_fullMp = this->_fullMp;

		this->_aggressivity += 3;
		this->_defense += 2;

		this->_grade += 1;

		this->_curExpValue -= this->_fullExpValue;
		this->_fullExpValue *= 1.2;
	}
	else if (this->_grade >= 100)
	{
		cout << "已经满级，无法升级" << endl;
	}
}
template <class T1>
int Eva::firstSkill(const T1& other)
{
	//if (this->_grade < 4)
	//{
		//return -1;
	//}
	cout << "伊娃使用了一技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Eva::SecondSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		return 0;
	}
	cout << "伊娃使用了二技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Eva::ThirdSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		return 0;
	}
	cout << "伊娃使用了三技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Eva::fourthSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		return 0;
	}
	cout << "伊娃使用了四技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}


void Eva::setName(string name)
{
	this->_name = name;
}
void Eva::setFullHp(int num)
{
	this->_fullHp = num;
}
void Eva::setCurHp(int num)
{
	this->_curHp = num;
}
void Eva::setAggressivity(int num)
{
	this->_aggressivity = num;
}
void Eva::setDefense(int num)
{
	this->_defense = num;
}
void Eva::setFullMp(int num)
{
	this->_fullMp = num;
}
void Eva::setCurMp(int num)
{
	this->_curMp = num;
}
void Eva::setFullExpValue(int num)
{
	this->_fullExpValue = num;
}
void Eva::setCurExpvalue(int num)
{
	this->_curExpValue = num;
}

void Eva::setGrade(int num)
{
	this->_grade = num;
}
void Eva::setSpeed(int num)
{
	this->_speed = num;
}
void Eva::setIsAttack(int num)
{
	this->_isAttack = num;
}
void Eva::setIsDenfensive(int num)
{
	this->_isDefensive = num;
}
#endif // !_EVA_H_
