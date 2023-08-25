#pragma once
#ifndef _OPERTION_H_
#define _OPERTION_H_

#include <easyx.h>
#include "../inc/loadBackgroud.h"
#include "../inc/pet.h"
//#include "../src/Pipi.hpp"
//#include "../src/SmallMonkey.hpp"
int myOperation();
void fairyHospital();
int mapExploration();
void petBackpack();
void petStore();
void propBackpack();
int againstChoose();
template <typename T1, typename T2>
int against(T1 &my, T2 &other);
template <typename T1>
void showInfo(T1& obj,int x,int y,string str="нч");
template <typename T1,typename T2>
void againstInfo(T1 &my,T2 &other ,int x, int y, int option = 0);
#endif // !_OPERTION_H_
