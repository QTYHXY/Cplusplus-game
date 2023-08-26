#pragma once
#ifndef _SAWSHARK_H_
#define _SAWSHARK_H_
#include "../inc/pet.h"

class SawShark :public Pokemon
{
public:
	SawShark()
	{
		this->_name = "小鲨鱼";
		this->_fullHp = 50;
		this->_curHp = this->_fullHp;
		this->_aggressivity = 15;
		this->_defense = 10;
		this->_fullMp = 15;
		this->_curMp = this->_fullMp;
		this->_fullExpValue = 20;
		this->_curExpValue = 0;
		this->_grade = 5;
		this->_speed = 7;
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


void SawShark::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "小鲨鱼升级成功" << endl;
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
int SawShark::firstSkill(const T1& other)
{
	//if (this->_grade < 4)
	//{
		//return 0;
	//}
	cout << "小鲨鱼使用了一技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int SawShark::SecondSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		cout << "4级开启" << endl;
		return 0;
	}
	cout << "小鲨鱼使用了二技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int SawShark::ThirdSkill(const T1& other)
{
	if (this->_grade < 8)
	{
		cout << "8级开启" << endl;
		return 0;
	}
	cout << "小鲨鱼使用了三技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int SawShark::fourthSkill(const T1& other)
{
	if (this->_grade < 12)
	{
		cout << "12级开启" << endl;
		return 0;
	}
	cout << "小鲨鱼使用了四技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}

#endif // !_SawShark_H_
