#ifndef _SMALLMONKEY_HPP_
#define _SMALLMONKEY_HPP_
#include "../inc/pet.h"
#include "../inc/Equipment.h"
#include <iostream>

//С���-������ֵ��20   ��������7  ��������7 ħ��ֵ��10 ����Ҫ�ľ��飺20 �ٶȣ�4  �ȼ���1
class SmallMonkey : public Pokemon,public Equipment
{
private:

public:
	SmallMonkey()
	{
		this->_name = "С���";
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


void SmallMonkey::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "С��������ɹ�" << endl;
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
		cout << "�Ѿ��������޷�����" << endl;
	}
}
template <class T1>
int SmallMonkey::firstSkill(const T1& other)
{
	cout << "С���ʹ����צ" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int SmallMonkey::SecondSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		cout << "4������" << endl;
		return 0;
	}
	cout << "С���ʹ�ö�����" << endl;
	return (this->_aggressivity * 2.5) / (other._defense * 1.2);

}
template <class T1>
int SmallMonkey::ThirdSkill(const T1& other)
{
	if (this->_grade < 8)
	{
		cout << "8������" << endl;
		return 0;
	}
	cout << "С���ʹ��������" << endl;
	return (this->_aggressivity * 3.5) / (other._defense * 1.5);
}
template <class T1>
int SmallMonkey::fourthSkill(const T1& other)
{
	if (this->_grade < 12)
	{
		cout << "12������" << endl;
		return 0;
	}
	cout << "С���ʹ���ļ���" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 0.5);
}






#endif