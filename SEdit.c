#include "SEdit.h"
#include"SPainter.h"
void init_edit(Edit* pthis, int x, int y)
{
	pthis->dst = (SDL_Rect){ x,y,100,25 };
	pthis->isInput = false;
	pthis->inputText = (char*)calloc(1, 1024);
	pthis->viewText = (char*)calloc(1, 1024);
	pthis->preView = false;
	pthis->font = TTF_OpenFont("./1.ttf", 20);

}

void render_edit(SDL_Renderer* render, Edit* pthis)
{
	//处理框的颜色
	if (pthis->isInput)
	{
		SDL_SetRenderDrawColor(render,255,255,255,0 );
	}
	else
	{
		SDL_SetRenderDrawColor(render,204,213,240 ,0);

	}

	SDL_RenderFillRect(render, &pthis->dst);
	SDL_Color black = { 0,0,0,0 };
	if (strlen(pthis->inputText) > 0)
	{
		SDL_Surface* temp = TTF_RenderUTF8_Blended(pthis->font, pthis->inputText, black);
		SDL_Rect rect = { pthis->dst.x,pthis->dst.y,temp->w,temp->h };
		Painter paint;
		init_painter(&paint, render, temp);
		render_surface(&paint, NULL, &rect);
		SDL_FreeSurface(temp);
	}
	if (pthis->preView)
	{
		if (strlen(pthis->viewText) > 0)
		{
			SDL_Surface* temp = TTF_RenderUTF8_Blended(pthis->font, pthis->viewText, black);
			//预览的文字显示
			SDL_Rect rect = { pthis->dst.x+20,pthis->dst.y+temp->h,temp->w,temp->h };
			Painter paint;
			init_painter(&paint, render, temp);
			render_surface(&paint, NULL, &rect);
			SDL_FreeSurface(temp);
		}
	}

}

void event_edit(Edit* pthis, SDL_Event* msg)
{
	int x = msg->motion.x;
	int y = msg->motion.y;
	int editx = pthis->dst.x;
	int edity = pthis->dst.y;
	int editw = pthis->dst.w;
	int edith = pthis->dst.h;
	//判断点击了编辑框
	if (x >= editx && x <= editx + editw && y >= edity && y <= edity + edith)
	{
		//在框内并且点击了框
		if (msg->type == SDL_MOUSEBUTTONDOWN && msg->button.button == SDL_BUTTON_LEFT)
		{
			pthis->isInput = true;
		}
	}
	else
	{
		//不在框内点击了别处，退出输入状态
		if (msg->type == SDL_MOUSEBUTTONDOWN && msg->button.button == SDL_BUTTON_LEFT)
		{
			pthis->isInput = false;
		}
	}
	if (msg->type == SDL_TEXTINPUT && pthis->isInput)
	{
		//SDL_Log("1: %s", msg->text.text);
		strcat_s(pthis->inputText, 1024, msg->text.text);
	}
	else if(msg->type==SDL_TEXTEDITING&&pthis->isInput)
	{
		//SDL_Log("2: %s", msg->edit.text);
		strcpy_s(pthis->viewText, 1024, msg->edit.text);
		pthis->preView = true;
	}
	else
	{
		pthis->preView = false;
	}
}
