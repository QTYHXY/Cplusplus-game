#pragma once
#ifndef _DEFENSIVE_HPP_
#define _DEFENSIVE_HPP_

#include "../inc/Equipment.h"

//防具类
class Shield : public Equipment
{
public:
	Shield()
	{
		this->_eName = "大盾牌";
		this->_upHp = 10;
		this->_upMp = 5;
		this->_upAggresivity = 3;
		this->_upDefense = 15;
		this->_upSpeed = 1;
	}

	template <class T1>
	int firstShieldSkill(const T1& my);
	template <class T1>
	int SecondShieldSkill(const T1& my);
};

//防御提升
template <class T1>
int Shield::firstShieldSkill(const T1& my)
{
	return my._defense * 1.5;
}
template <class T1>
int Shield::SecondShieldSkill(const T1& my)
{
	return my._defense * 3;
}

#endif // !_ATTACK_HPP



