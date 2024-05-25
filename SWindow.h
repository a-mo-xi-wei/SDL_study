#pragma once
#include"Global.h"
#include"SPainter.h"
#include"SButton.h"
#include"SEdit.h"
//窗口
typedef struct SWindow
{
	SDL_Window*		window;
	SDL_Renderer*	render;
	SDL_Surface*	background;
	int				w;
	int				h;
}Window;
//初始化过程
void init_window(Window* pthis, const char* imgURL);
//创建过程
void create_window(Window* pthis,const char* title);
//渲染过程
void render_window(Window* pthis);
//消息循环
void event_loop(Window* pthis);
//销毁窗口
void destory_window(Window* pthis);



