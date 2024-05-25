#pragma once
#include"Global.h"
//  画家  ---》 负责所有平面绘制
//  图像
//  文字

typedef struct SPainter
{
	SDL_Renderer*	render;
	SDL_Surface*	surface;

}Painter;
//初始化
void init_painter(Painter* pthis, SDL_Renderer* render, SDL_Surface* surface);
//渲染过程
void render_surface(Painter* pthis, SDL_Rect* src, SDL_Rect* dst);





