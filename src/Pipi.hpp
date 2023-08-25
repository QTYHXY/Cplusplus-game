#ifndef _PIPI_HPP_
#define _PIPI_HPP_
#include "../inc/pet.h"
#include <iostream>

//皮皮 ：生命值：12   攻击力：5  防御力：8  魔法值：10 升级要的经验：20  速度：7  等级：1
class Pipi : public Pokemon
{
private:

public:
	Pipi()
	{
		this->_name = "皮皮";
		this->_fullHp = 12;
		this->_curHp = this->_fullHp;
		this->_aggressivity = 9;
		this->_defense = 8;
		this->_fullMp = 10;
		this->_curMp = this->_fullMp;
		this->_fullExpValue = 20;
		this->_curExpValue = 0;
		this->_grade = 1;
		this->_speed = 7;
	}
	void upGrade();
	int firstSkill(const Pokemon& other);
	int SecondSkill(const Pokemon& other);
	int ThirdSkill(const Pokemon& other);
	int fourthSkill(const Pokemon& other);
};

void Pipi::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "皮皮升级成功" << endl;
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
int Pipi::firstSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "皮皮使用了一技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int Pipi::SecondSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "皮皮使用了二技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int Pipi::ThirdSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "皮皮使用了三技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int Pipi::fourthSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "皮皮使用了四技能" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}

#endif // !_PIPI_HPP_
