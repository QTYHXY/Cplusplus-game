#pragma once

#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <easyx.h>
bool inArea(int mx, int my, int x, int y, int w, int h);
void describe(int x, int y);
void mapDescribe(int x, int y);

#endif // !_MOUSE_H_
