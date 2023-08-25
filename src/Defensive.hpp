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
		this->_name = "大盾牌";
		this->_upHp = 10;
		this->_upMp = 5;
		this->_upAggresivity = 3;
		this->_upDefense = 15;
		this->_upSpeed = 1;
	}

	template <class T1>
	int firstSkill(const T1& my);
	template <class T1>
	int SecondSkill(const T1& my);
};

//防御提升
template <class T1>
int Shield::firstSkill(const T1& my)
{
	return my._defense * 1.5;
}
template <class T1>
int Shield::SecondSkill(const T1& my)
{
	return my._defense * 3;
}

#endif // !_ATTACK_HPP



