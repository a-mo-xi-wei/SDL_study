#pragma once
#include"Global.h"
typedef struct SEdit
{
	SDL_Rect dst;
	bool isInput;
	char* inputText;
	char* viewText;
	bool preView;
	TTF_Font* font;

}Edit;

//初始化
void init_edit(Edit* pthis, int x, int y);
//渲染
void render_edit(SDL_Renderer* render, Edit* pthis);
//事件
void event_edit(Edit* pthis, SDL_Event* msg);