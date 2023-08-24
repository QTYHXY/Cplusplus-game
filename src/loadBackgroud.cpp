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
	//对战界面加载
	loadimage(&res->against, "../images/backgroud/against.png");

}
	