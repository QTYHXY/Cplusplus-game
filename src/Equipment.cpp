#include "../inc/Equipment.h"
//构造方法
Equipment::Equipment()
{

}
Equipment::Equipment(string name, int upHp, int upMp, int upAggresivity, int upDefense, int upSpeed)
{
	this->_eName = name;
	this->_upHp = upHp;
	this->_upMp = upMp;
	this->_upAggresivity = upAggresivity;
	this->_upDefense = upDefense;
	this->_upSpeed = upSpeed;
}
Equipment::~Equipment()
{

}
//set方法
void Equipment::setName(string name)
{
	this->_eName = name;
}
void Equipment::setUpHp(int num)
{
	this->_upHp = num;
}
void Equipment::setUpMp(int num)
{
	this->_upMp = num;
}
void Equipment::setUpAggresivity(int num)
{
	this->_upAggresivity = num;
}
void Equipment::setUpDefense(int num)
{
	this->_upDefense = num;
}
void Equipment::setUpSpeed(int num)
{
	this->_upSpeed = num;
}
//get方法
string Equipment::getName(string name)
{
	return this->_eName;
}
int Equipment::getUpHp()
{
	return this->_upHp;
}
int Equipment::getUpMp()
{
	return this->_upMp;
}
int Equipment::getUpAggresivity()
{
	return this->_upAggresivity;
}
int Equipment::getUpDefense()
{
	return this->_upDefense;
}
int Equipment::getUpSpeed()
{
	return this->_upSpeed;
}