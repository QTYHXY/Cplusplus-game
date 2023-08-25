#pragma once
#ifndef _ATTACK_HPP_
#define _ATTACK_HPP_

#include "../inc/Equipment.h"

//±¦½£Àà
class Sword : public Equipment
{
public:
	Sword()
	{
		this->_name = "´ó±¦½£";
		this->_upHp = 10;
		this->_upMp = 5;
		this->_upAggresivity = 10;
		this->_upDefense = 3;
		this->_upSpeed = 1;
	}

	template <class T1>
	int firstSkill(const T1& my);
	template <class T1>
	int SecondSkill(const T1& my);
};


template <class T1>
int Sword::firstSkill(const T1& my)
{
	return my._aggressivity * 1.5;
}
template <class T1>
int Sword::SecondSkill(const T1& my)
{
	return my._aggressivity * 3;
}

#endif // !_ATTACK_HPP



