#include "../inc/pet.h"

Pokemon::Pokemon()
{

}
Pokemon::Pokemon(string name, int fullHp, int curHp, int aggressivity, int defense, int fullMp, int curMp, int fullExpValue, int curExpValue, int grade,int speed)
	:_name(name),_fullHp(fullHp),_curHp(curHp),_aggressivity(aggressivity),_defense(defense),_fullMp(fullMp),_curMp(curMp),_fullExpValue(fullExpValue),_curExpValue(curExpValue),_grade(grade),_speed(speed)
{

}
Pokemon::~Pokemon()
{

}

void Pokemon::setName(string name)
{
	this->_name = name;
}
void Pokemon::setFullHp(int num)
{
	this->_fullHp = num;
}
void Pokemon::setCurHp(int num)//当前血量
{
	this->_curHp = num;
}
void Pokemon::setAggressivity(int num)//攻击力
{
	this->_aggressivity = num;
}
void Pokemon::setDefense(int num)//防御力
{
	this->_defense = num;
}
void Pokemon::setFullMp(int num)//满魔力
{
	this->_fullMp = num;
}
void Pokemon::setCurMp(int num)//当前魔力
{
	this->_curMp = num;
}
void Pokemon::setFullExpValue(int num)//升级要的经验值
{
	this->_fullExpValue = num;
}
void Pokemon::setCurExpvalue(int num)//当前经验值
{
	this->_curExpValue = num;
}
void Pokemon::setGrade(int num)
{
	this->_grade = num;
}


string Pokemon::getName()
{
	return _name;
}
int Pokemon::getFullHp()
{
	return _fullHp;
}
int Pokemon::getCurHp()//当前血量
{
	return _curHp;
}
int Pokemon::getAggressivity()//攻击力
{
	return _aggressivity;
}
int Pokemon::getDefense()//防御力
{
	return _defense;
}
int Pokemon::getFullMp()//满魔力
{
	return _fullMp;
}
int Pokemon::getCurMp()//当前魔力
{
	return _curMp;
}
int Pokemon::getFullExpValue()//升级要的经验值
{
	return _fullExpValue;
}
int Pokemon::getCurExpvalue()//当前经验值
{
	return _curExpValue;
}
int Pokemon::getGrade()//等级
{
	return _grade;
}