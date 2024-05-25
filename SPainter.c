﻿#include "SPainter.h"

void init_painter(Painter* pthis, SDL_Renderer* render, SDL_Surface* surface)
{
	pthis->render = render;
	pthis->surface = surface;
}

void render_surface(Painter* pthis, SDL_Rect* src, SDL_Rect* dst)
{
	SDL_Texture* temp = SDL_CreateTextureFromSurface(pthis->render, pthis->surface);
	SDL_RenderCopy(pthis->render, temp, src, dst);
	SDL_DestroyTexture(temp);
}
