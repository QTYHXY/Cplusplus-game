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
	int _isAttack;//�Ƿ�װ������
	int _isDefensive;//�Ƿ�װ������

public:
	//���췽��
	Pokemon();
	Pokemon(string name, int fullHp, int curHp, int aggressivity, int defense, int fullMp, int curMp, int fullExpValue, int curExpValue, int grade,int speed,bool isAttack,bool isDefensive);
	virtual ~Pokemon();
	//set����
	virtual void setName(string name);
	virtual void setFullHp(int num);
	virtual void setCurHp(int num);//��ǰѪ��
	virtual void setAggressivity(int num);//������
	virtual void setDefense(int num);//������
	virtual void setFullMp(int num);//��ħ��
	virtual void setCurMp(int num);//��ǰħ��
	virtual void setFullExpValue(int num);//����Ҫ�ľ���ֵ
	virtual void setCurExpvalue(int num);//��ǰ����ֵ
	virtual void setGrade(int num);//�ȼ�
	virtual void setSpeed(int num);//�ٶ�
	virtual void setIsAttack(int num);//����
	virtual void setIsDenfensive(int num);//����
	//get����
	virtual string getName();
	virtual int getFullHp();
	virtual int getCurHp();//��ǰѪ��
	virtual int getAggressivity();//������
	virtual int getDefense();//������
	virtual int getFullMp();//��ħ��
	virtual int getCurMp();//��ǰħ��
	virtual int getFullExpValue();//����Ҫ�ľ���ֵ
	virtual int getCurExpvalue();//��ǰ����ֵ
	virtual int getGrade();//�ȼ�
	virtual int getSpeed();//�ٶ�
	virtual int getIsAttack();//����
	virtual int getIsDenfensive();//����

	//show
	void showAll();
	//empty
	int isEmptyHp();
	int isEmptyMp();

};


#endif // !_PET_H_
