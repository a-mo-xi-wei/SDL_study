#include "SButton.h"
#include"SPainter.h"
void init_button(Button* pthis, int x, int y, const char* text)
{
	pthis->isClicked = false;
	pthis->isHover = false;
	pthis->isVisible = true;
	pthis->dst.x = x;
	pthis->dst.y = y;
	pthis->curColor=pthis->bkColor = (SDL_Color){ 255,255,255 };
	pthis->hoverColor = (SDL_Color){ 33,81,87 };
	pthis->font = TTF_OpenFont("./1.ttf",25); 
	pthis->textColor = (SDL_Color){ 0,0,0,0 };
	pthis->text = TTF_RenderText_Blended(pthis->font, text, pthis->textColor);
	pthis->dst.w = pthis->text->w + 40;
	pthis->dst.h = pthis->text->h + 8;

}

void render_button(SDL_Renderer* render, Button* pthis)
{
	if (pthis->isVisible)
	{
		if (pthis->isHover)pthis->curColor = pthis->hoverColor;
		else pthis->curColor = pthis->bkColor;
		//绘制填充矩形
		Uint8 r = pthis->curColor.r;
		Uint8 g = pthis->curColor.g;
		Uint8 b = pthis->curColor.b;
		SDL_SetRenderDrawColor(render, r, g, b, 0);
		SDL_RenderFillRect(render, &pthis->dst);

		//画文字
		Painter painter;
		init_painter(&painter, render, pthis->text);
		//居中
		SDL_Rect temp = { pthis->dst.x + 20,pthis->dst.y + 4,pthis->text->w,pthis->text->h };
		render_surface(&painter, NULL, &temp);

	}

}

bool hover_button(Button* pthis, SDL_Event* msg)
{
	//判断是否在矩形范围
	int x = msg->motion.x;
	int y = msg->motion.y;
	if (x >= pthis->dst.x && x <= pthis->dst.x + pthis->dst.w && y >= pthis->dst.y && y <= pthis->dst.y + pthis->dst.h)
	{
		pthis->isHover = true;
		
		return true;
	}
	pthis->isHover = false;
	return false;
}

bool clicked_button(Button* pthis, SDL_Event* msg)
{
	if (hover_button(pthis, msg))
	{
		//按下
		if (msg->type == SDL_MOUSEBUTTONDOWN&&msg->button.button==SDL_BUTTON_LEFT)
		{
			pthis->isClicked = true;
			return true;
		} 
		//弹起
		if (msg->type == SDL_MOUSEBUTTONUP&&msg->button.button==SDL_BUTTON_LEFT)
		{
			pthis->isClicked = false;
			return false;
		}
	}
	return false;
}
