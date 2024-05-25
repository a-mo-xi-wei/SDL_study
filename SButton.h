#pragma once
#include"Global.h"
typedef struct SButton
{
	SDL_Rect dst;
	//按钮颜色属性
	SDL_Color curColor;//当前颜色
	SDL_Color hoverColor;//鼠标停靠颜色
	SDL_Color bkColor;//鼠标离开颜色
	//字体属性
	TTF_Font* font;
	SDL_Surface* text;
	SDL_Color textColor;
	//状态描述---->应用操作
	bool isClicked;
	bool isVisible;
	bool isHover;
}Button;

//初始化
void init_button(Button* pthis, int x, int y, const char* text);
//渲染过程
void render_button(SDL_Renderer* render, Button* pthis);
//事件处理
bool hover_button(Button* pthis, SDL_Event* msg);
bool clicked_button(Button* pthis, SDL_Event* msg);
