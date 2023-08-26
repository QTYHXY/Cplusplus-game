#include "../inc/pet.h"

Pokemon::Pokemon()
{

}
Pokemon::Pokemon(string name, int fullHp, int curHp, int aggressivity, int defense, int fullMp, int curMp, int fullExpValue, int curExpValue, int grade, int speed,bool isAttack, bool isDefensive)
	:_name(name), _fullHp(fullHp), _curHp(curHp), _aggressivity(aggressivity), _defense(defense), _fullMp(fullMp), _curMp(curMp), _fullExpValue(fullExpValue), _curExpValue(curExpValue), _grade(grade), _speed(speed),_isAttack(isAttack),_isDefensive(isDefensive)
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
void Pokemon::setSpeed(int num)
{
	this->_speed = num;
}
void Pokemon::setIsAttack(int num)
{
	this->_isAttack = num;
}
void Pokemon::setIsDenfensive(int num)
{
	this->_isDefensive = num;
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
int Pokemon::getSpeed()
{
	return _speed;
}
int Pokemon::getIsAttack()
{
	return _isAttack;
}
int Pokemon::getIsDenfensive()
{
	return _isDefensive;
}



void Pokemon::showAll()
{
	cout << "精灵名称 : " << this->_name << endl;
	cout << "等级   : " << this->_grade << endl;
	cout << "生命值 : " << this->_curHp << "/" << this->_fullHp << endl;
	cout << "攻击力 : " << this->_aggressivity << endl;
	cout << "防御力 : " << this->_defense << endl;
	cout << "速度值 : " << this->_speed << endl;
	cout << "经验值 : " << this->_curExpValue << "/" << this->_fullExpValue << endl;
}

int Pokemon::isEmptyHp()
{
	if (this->_curHp <= 0)
	{
		cout << this->_name << "已经战死" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}
int Pokemon::isEmptyMp()
{
	if (this->_curMp <= 0)
	{
		cout << this->_name << "已经没有魔力值" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

