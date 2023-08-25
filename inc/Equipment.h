#pragma once
#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_
#include <iostream>
using namespace std;
class Equipment
{
public:
	string _name;//����
	int _upHp;//���Ѫ��
	int _upMp;//�������
	int _upAggresivity;//��߹�����
	int _upDefense;//��߷�����
	int _upSpeed;//����ٶ�

public:
	//���췽��
	Equipment();
	Equipment(string name, int upHp, int upMp,int upAggresivity,int upDefense,int upSpeed);
	~Equipment();
	//set����
	void setName(string name);
	void setUpHp(int num);
	void setUpMp(int num);
	void setUpAggresivity(int num);
	void setUpDefense(int num);
	void setUpSpeed(int num);
	//get����
	string getName(string name);
	int getUpHp();
	int getUpMp();
	int getUpAggresivity();
	int getUpDefense();
	int getUpSpeed();
};
#endif // !_EQUIPMENT_H_
