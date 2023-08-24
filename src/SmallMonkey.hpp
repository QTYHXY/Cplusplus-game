#ifndef _SMALLMONKEY_HPP_
#define _SMALLMONKEY_HPP_
#include "../inc/pet.h"
#include <iostream>

//小火猴-》生命值：20   攻击力：7  防御力：7 魔法值：10 升级要的经验：20 速度：4  等级：1
class SmallMonkey : public Pokemon
{
private:

public:
	SmallMonkey()
	{
		this->_name = "小火猴";
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

	}
	void upGrade();
	int firstSkill(const Pokemon& other);
	int SecondSkill(const Pokemon& other);
	int ThirdSkill(const Pokemon& other);
	int fourthSkill(const Pokemon& other);
};


void SmallMonkey::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "小火猴升级成功" << endl;
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

int SmallMonkey::firstSkill(const Pokemon& other)
{
	cout << "小火猴使用了爪" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int SmallMonkey::SecondSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
	//{
	//	return -1;
	//}
	cout << "小火猴使用二技能" << endl;
	return (this->_aggressivity * 2.5) / (other._defense * 1.2);

}
int SmallMonkey::ThirdSkill(const Pokemon& other)
{
	//if (this->_grade < 8)
	//{
	//	return -1;
	//}
	cout << "小火猴使用三技能" << endl;
	return (this->_aggressivity * 3.5) / (other._defense * 1.5);
}
int SmallMonkey::fourthSkill(const Pokemon& other)
{
	//if (this->_grade < 12)
	//{
	//	return -1;
	//}
	cout << "小火猴使用四技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 0.5);
}






#endif