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
template <class T1>
int Pipi::firstSkill(const T1& other)
{
	cout << "ƤƤʹ����һ����" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Pipi::SecondSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		cout << "4������" << endl;
		return 0;
	}
	cout << "ƤƤʹ���˶�����" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Pipi::ThirdSkill(const T1& other)
{
	if (this->_grade < 8)
	{
		cout << "8������" << endl;
		return 0;
	}
	cout << "ƤƤʹ����������" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Pipi::fourthSkill(const T1& other)
{
	if (this->_grade < 12)
	{
		cout << "12������" << endl;
		return 0;
	}
	cout << "ƤƤʹ�����ļ���" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}

#endif // !_PIPI_HPP_
