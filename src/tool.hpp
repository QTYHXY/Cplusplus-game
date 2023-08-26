//#pragma once
#ifndef _TOOL_H_
#define _TOOL_H_
#include <easyx.h>
void myDrawImgSingle(int x, int y, IMAGE *src)
{

    DWORD *pwin = GetImageBuffer();
    DWORD *psrc = GetImageBuffer(src);
    int win_w = getwidth();
    int win_h = getheight();
    int src_w = src->getwidth();
    int src_h = src->getheight();

    int real_w = (x + src_w > win_w) ? win_w - x : src_w;
    int real_h = (y + src_h > win_h) ? win_h - y : src_h;
    if (x < 0)
    {
        psrc += -x;
        real_w -= -x;
        x = 0;
    }
    if (y < 0)
    {
        psrc += (src_w * -y);
        real_h -= -y;
        y = 0;
    }
    pwin += (win_w * y + x);
    // 实现透明贴图
    for (int iy = 0; iy < real_h; iy++)
    {
        for (int ix = 0; ix < real_w; ix++)
        {
            byte a = (byte)(psrc[ix] >> 24); // 计
            if (a != 0)
            {
                pwin[ix] = psrc[ix];
            }
        }
        // 换到下一行
        pwin += win_w;
        psrc += src_w;
    }
}
void myDrawImgMore(int x, int y,  IMAGE *src, int srcX , int srcY ,int dstW, int dstH)
{
    // 变量初始化
    DWORD *pwin = GetImageBuffer();
    DWORD *psrc = GetImageBuffer(src);
    int win_w = getwidth();
    int win_h = getheight();
    int src_w = src->getwidth();
    int src_h = src->getheight();

    int real_w = (x + dstW > win_w) ? win_w - x : dstW;
    int real_h = (y + dstH > win_h) ? win_h - y : dstH;
    if (x < 0)
    {
        psrc += -x;
        real_w -= -x;
        x = 0;
    }
    if (y < 0)
    {
        psrc += (dstW * -y);
        // 处理起
        real_h -= -y;
        y = 0;
    }
    // 修正贴图起始位置
    pwin += (win_w * y + x);
    // 实现透明贴图
    for (int iy = 0; iy < real_h; iy++)
    {
        for (int ix = 0; ix < real_w; ix++)
        {
            byte a = (byte)(psrc[ix + srcX + srcY * src_w] >> 24); //
            if (a > 100)
            {
                pwin[ix] = psrc[ix + srcX + srcY * src_w];
            }
        }
        // 换到下一行
        pwin += win_w;
        psrc += src_w;
    }
}

#endif