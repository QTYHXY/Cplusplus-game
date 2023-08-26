#include "../inc/loadBackgroud.h"

#include <easyx.h>

void loadingBK(struct resource* res)
{
	//背景加载
	loadimage(res->resourceBK + 0, "../images/backgroud/start.png");
	loadimage(res->resourceBK + 1, "../images/backgroud/bk1.png");
	loadimage(res->resourceBK + 2, "../images/backgroud/bk2.png");
	loadimage(res->resourceBK + 3, "../images/backgroud/propBackpack.png");
	loadimage(res->resourceBK + 4, "../images/backgroud/petStore.png");
	loadimage(res->resourceBK + 5, "../images/backgroud/petBackpack.png");
	loadimage(res->resourceBK + 6, "../images/backgroud/mapExploration.png");
	loadimage(res->resourceBK + 7, "../images/backgroud/fairyHospital.png");
	loadimage(res->resourceBK + 8, "../images/backgroud/exit.png");
	//描述加载
	loadimage(res->describe + 0, "../images/backgroud/describe1.png");
	loadimage(res->describe + 1, "../images/backgroud/describe2.png");
	loadimage(res->describe + 2, "../images/backgroud/describe3.png");
	loadimage(res->describe + 3, "../images/backgroud/describe4.png");
	loadimage(res->describe + 4, "../images/backgroud/describe5.png");
	loadimage(res->describe + 5, "../images/backgroud/describe6.png");
	//地图加载
	loadimage(res->map + 0, "../images/backgroud/map.png");
	loadimage(res->map + 1, "../images/backgroud/map1.png");
	loadimage(res->map + 2, "../images/backgroud/map2.png");
	loadimage(res->map + 3, "../images/backgroud/map3.png");
	loadimage(res->map + 4, "../images/backgroud/map4.png",800,480);
	loadimage(res->map + 5, "../images/backgroud/map5.png",800,480);
	loadimage(res->map + 6, "../images/backgroud/map6.png",800,480);
	//对战界面加载
	loadimage(&res->against, "../images/backgroud/against.png");
	//角色加载
	//布布种子
	loadimage(res->role + 0, "../assert/bbzz1.png",100,100);
	loadimage(res->role + 1, "../assert/bbzz2.png",100,100);
	loadimage(res->role + 2, "../assert/bbzz3.png",100,100);
	//伊布
	loadimage(res->role + 3, "../assert/yb1.png",100,100);
	loadimage(res->role + 4, "../assert/yb2.png",100,100);
	loadimage(res->role + 5, "../assert/yb3.png",100,100);
	//小火猴
	loadimage(res->role + 6, "../assert/xhh1.png",100,100);
	loadimage(res->role + 7, "../assert/xhh1.png",100,100);
	loadimage(res->role + 8, "../assert/xhh1.png",100,100);
	//小老鼠
	loadimage(res->role + 9, "../assert/ls1.png",100,100);
	loadimage(res->role + 10, "../assert/ls2.png",100,100);
	loadimage(res->role + 11, "../assert/ls3.png",100,100);
	//皮皮
	loadimage(res->role + 12, "../assert/pp1.png",100,100);
	loadimage(res->role + 13, "../assert/pp2.png",100,100);
	loadimage(res->role + 14, "../assert/pp3.png",100,100);
	//盖亚
	loadimage(res->role + 15, "../assert/gy.png",100,100);
	//卡修斯
	loadimage(res->role + 16, "../assert/kxs1.png",100,100);
	//工具加载
	loadimage(res->tool + 0, "../assert/bj.png", 80, 80); 
	loadimage(res->tool + 1, "../assert/dp.png", 70, 70);


}
	