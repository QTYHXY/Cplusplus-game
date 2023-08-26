#ifndef _BRITNEYSEEDS_HPP_
#define _BRITNEYSEEDS_HPP_
#include "../inc/pet.h"
#include "../inc/Equipment.h"
#include <iostream>

//布布种子-》生命值：20   攻击力：7  防御力：7 魔法值：10 升级要的经验：20 速度：4  等级：1
class BritneySeeds : public Pokemon,public Equipment
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






#endif