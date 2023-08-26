#ifndef _BRITNEYSEEDS_HPP_
#define _BRITNEYSEEDS_HPP_
#include "../inc/pet.h"
#include "../inc/Equipment.h"
#include "../src/Attack.hpp"
#include "../src/Defensive.hpp"
#include <iostream>

//布布种子-》生命值：20   攻击力：7  防御力：7 魔法值：10 升级要的经验：20 速度：4  等级：1
class BritneySeeds : public Pokemon, public Sword, public Shield
{
private:

public:
	BritneySeeds()
	{
		this->_name = "布布种子";
		this->_fullHp = 20;
		this->_curHp = this->_fullHp;
		this->_aggressivity = 7;
		this->_defense = 7;
		this->_fullMp = 10;
		this->_curMp = this->_fullMp;
		this->_fullExpValue = 20;
		this->_curExpValue = 0;
		this->_grade = 1;
		this->_speed = 4;
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


void BritneySeeds::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "布布种子升级成功" << endl;
		this->_fullHp += 4;
		this->_curHp = this->_fullHp;

		this->_fullMp += 4;
		this->_curMp = this->_fullMp;

		this->_aggressivity += 2;
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
int BritneySeeds::firstSkill(const T1& other)
{
	cout << "布布种子使用了一技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int BritneySeeds::SecondSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		cout << "4级开启" << endl;
		return 0;
	}
	cout << "布布种子使用二技能" << endl;
	return (this->_aggressivity * 2.5) / (other._defense * 1.2);

}
template <class T1>
int BritneySeeds::ThirdSkill(const T1& other)
{
	if (this->_grade < 8)
	{
		cout << "8级开启" << endl;
		return 0;
	}
	cout << "布布种子使用三技能" << endl;
	return (this->_aggressivity * 3.5) / (other._defense * 1.5);
}
template <class T1>
int BritneySeeds::fourthSkill(const T1& other)
{
	if (this->_grade < 12)
	{
		cout << "12级开启" << endl;
		return 0;
	}
	cout << "布布种子使用四技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 0.5);
}


void BritneySeeds::setName(string name)
{
	this->_name = name;
}
void BritneySeeds::setFullHp(int num)
{
	this->_fullHp = num;
}
void BritneySeeds::setCurHp(int num)
{
	this->_curHp = num;
}
void BritneySeeds::setAggressivity(int num)
{
	this->_aggressivity = num;
}
void BritneySeeds::setDefense(int num)
{
	this->_defense = num;
}
void BritneySeeds::setFullMp(int num)
{
	this->_fullMp = num;
}
void BritneySeeds::setCurMp(int num)
{
	this->_curMp = num;
}
void BritneySeeds::setFullExpValue(int num)
{
	this->_fullExpValue = num;
}
void BritneySeeds::setCurExpvalue(int num)
{
	this->_curExpValue = num;
}

void BritneySeeds::setGrade(int num)
{
	this->_grade = num;
}
void BritneySeeds::setSpeed(int num)
{
	this->_speed = num;
}
void BritneySeeds::setIsAttack(int num)
{
	this->_isAttack = num;
}
void BritneySeeds::setIsDenfensive(int num)
{
	this->_isDefensive = num;
}



#endif