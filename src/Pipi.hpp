#ifndef _PIPI_HPP_
#define _PIPI_HPP_
#include "../inc/pet.h"
#include <iostream>

//ƤƤ ������ֵ��12   ��������5  ��������8  ħ��ֵ��10 ����Ҫ�ľ��飺20  �ٶȣ�7  �ȼ���1
class Pipi : public Pokemon
{
private:

public:
	Pipi()
	{
		this->_name = "ƤƤ";
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
		cout << "ƤƤ�����ɹ�" << endl;
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
		cout << "�Ѿ��������޷�����" << endl;
	}
}
int Pipi::firstSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "ƤƤʹ����һ����" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int Pipi::SecondSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "ƤƤʹ���˶�����" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int Pipi::ThirdSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "ƤƤʹ����������" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
int Pipi::fourthSkill(const Pokemon& other)
{
	//if (this->_grade < 4)
//{
//	return -1;
//}
	cout << "ƤƤʹ�����ļ���" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}

#endif // !_PIPI_HPP_
