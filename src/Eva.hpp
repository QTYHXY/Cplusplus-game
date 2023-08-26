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

#endif // !_EVA_H_
