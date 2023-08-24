#pragma once
#ifndef _PET_H_
#define _PET_H_

#include <iostream>
using namespace std;

class Pokemon
{
//private:
public:
	string _name;//����
	int _fullHp;//��Ѫ
	int _curHp;//��ǰѪ��
	int _aggressivity;//������
	int _defense;//������
	int _fullMp;//��ħ��
	int _curMp;//��ǰħ��
	int _fullExpValue;//����Ҫ�ľ���ֵ
	int _curExpValue;//��ǰ����ֵ
	int _grade;//�ȼ�
	int _speed;//�ٶ�

public:
	//���췽��
	Pokemon();
	Pokemon(string name, int fullHp, int curHp, int aggressivity, int defense, int fullMp, int curMp, int fullExpValue, int curExpValue, int grade,int speed);
	virtual ~Pokemon();
	//set����
	void setName(string name);
	void setFullHp(int num);
	void setCurHp(int num);//��ǰѪ��
	void setAggressivity(int num);//������
	void setDefense(int num);//������
	void setFullMp(int num);//��ħ��
	void setCurMp(int num);//��ǰħ��
	void setFullExpValue(int num);//����Ҫ�ľ���ֵ
	void setCurExpvalue(int num);//��ǰ����ֵ
	void setGrade(int num);//�ȼ�
	void setSpeed(int num);//�ٶ�
	//get����
	string getName();
	int getFullHp();
	int getCurHp();//��ǰѪ��
	int getAggressivity();//������
	int getDefense();//������
	int getFullMp();//��ħ��
	int getCurMp();//��ǰħ��
	int getFullExpValue();//����Ҫ�ľ���ֵ
	int getCurExpvalue();//��ǰ����ֵ
	int getGrade();//�ȼ�
	int getSpeed();//�ٶ�

	//show
	void showAll();
	//empty
	int isEmptyHp();
	int isEmptyMp();

};


#endif // !_PET_H_
