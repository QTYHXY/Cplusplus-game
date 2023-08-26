#pragma once
#ifndef _OPERTION_H_
#define _OPERTION_H_

#include <easyx.h>
#include "../inc/loadBackgroud.h"
#include "../inc/pet.h"
//#include "../src/Pipi.hpp"
//#include "../src/SmallMonkey.hpp"

int myOperation(int num);

template <class T1>
int fairyHospital(T1 &my);
template <class T1>
int mapExploration(T1& my);
template <class T1>
int petBackpack(T1& my);
template <class T1>
int petStore(T1& my);
template <class T1>
int mypropBackpack(T1& my);
template <class T1>
int againstChooseMap1(T1 &my);
template <class T1>
int againstChooseMap2(T1 &my);
template <class T1>
int againstChooseMap3(T1 &my);

template <class T1, class T2>
int against(T1 &my, T2 &other);

template <class T1>
void showInfo(T1& obj,int x,int y,string str="нч");

template <class T1,class T2>
void againstInfo(T1 &my,T2 &other ,int x, int y, int option = 0);

template <class T1>
void archive(T1 &my,int num);

int readData();
#endif // !_OPERTION_H_
