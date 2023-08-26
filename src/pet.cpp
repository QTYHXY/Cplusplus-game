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
void Pokemon::setCurHp(int num)//��ǰѪ��
{
	this->_curHp = num;
}
void Pokemon::setAggressivity(int num)//������
{
	this->_aggressivity = num;
}
void Pokemon::setDefense(int num)//������
{
	this->_defense = num;
}
void Pokemon::setFullMp(int num)//��ħ��
{
	this->_fullMp = num;
}
void Pokemon::setCurMp(int num)//��ǰħ��
{
	this->_curMp = num;
}
void Pokemon::setFullExpValue(int num)//����Ҫ�ľ���ֵ
{
	this->_fullExpValue = num;
}
void Pokemon::setCurExpvalue(int num)//��ǰ����ֵ
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
int Pokemon::getCurHp()//��ǰѪ��
{
	return _curHp;
}
int Pokemon::getAggressivity()//������
{
	return _aggressivity;
}
int Pokemon::getDefense()//������
{
	return _defense;
}
int Pokemon::getFullMp()//��ħ��
{
	return _fullMp;
}
int Pokemon::getCurMp()//��ǰħ��
{
	return _curMp;
}
int Pokemon::getFullExpValue()//����Ҫ�ľ���ֵ
{
	return _fullExpValue;
}
int Pokemon::getCurExpvalue()//��ǰ����ֵ
{
	return _curExpValue;
}
int Pokemon::getGrade()//�ȼ�
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
	cout << "�������� : " << this->_name << endl;
	cout << "�ȼ�   : " << this->_grade << endl;
	cout << "����ֵ : " << this->_curHp << "/" << this->_fullHp << endl;
	cout << "������ : " << this->_aggressivity << endl;
	cout << "������ : " << this->_defense << endl;
	cout << "�ٶ�ֵ : " << this->_speed << endl;
	cout << "����ֵ : " << this->_curExpValue << "/" << this->_fullExpValue << endl;
}

int Pokemon::isEmptyHp()
{
	if (this->_curHp <= 0)
	{
		cout << this->_name << "�Ѿ�ս��" << endl;
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
		cout << this->_name << "�Ѿ�û��ħ��ֵ" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

