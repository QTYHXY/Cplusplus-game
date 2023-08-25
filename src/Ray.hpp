#pragma once
#ifndef _RAY_H_
#define _RAY_H_
#include "../inc/pet.h"

class Ray :public Pokemon
{
public:
	Ray()
	{
		this->_name = "����";
		this->_fullHp = 999;
		this->_curHp = this->_fullHp;
		this->_aggressivity = 999;
		this->_defense = 999;
		this->_fullMp = 999;
		this->_curMp = this->_fullMp;
		this->_fullExpValue = 0;
		this->_curExpValue = 0;
		this->_grade = 100;
		this->_speed = 99;
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


void Ray::upGrade()
{
	if (this->_curExpValue >= this->_fullExpValue && this->_grade < 100)
	{
		cout << "���������ɹ�" << endl;
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
int Ray::firstSkill(const T1& other)
{
	//if (this->_grade < 4)
	//{
		//return 0;
	//}
	cout << "����ʹ����һ����" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Ray::SecondSkill(const T1& other)
{
	if (this->_grade < 4)
	{
		cout << "4������" << endl;
		return 0;
	}
	cout << "����ʹ���˶�����" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Ray::ThirdSkill(const T1& other)
{
	if (this->_grade < 8)
	{
		cout << "8������" << endl;
		return 0;
	}
	cout << "����ʹ����������" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}
template <class T1>
int Ray::fourthSkill(const T1& other)
{
	if (this->_grade < 12)
	{
		cout << "12������" << endl;
		return 0;
	}
	cout << "����ʹ�����ļ���" << endl;
	return (this->_aggressivity * 1.5) / (other._defense * 1.2);
}

#endif // !_Ray_H_
