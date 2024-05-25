#include "SWindow.h"

void init_window(Window* pthis, const char* imgURL)
{
	//SDL初始化
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_JPG);
	TTF_Init();
	pthis->background = IMG_Load(imgURL);
	pthis->w = pthis->background->w;
	pthis->h = pthis->background->h;
}

void create_window(Window* pthis,const char* title)
{
	pthis->window = SDL_CreateWindow(title,100,100,pthis->w,pthis->h,SDL_WINDOW_SHOWN);
	pthis->render = SDL_CreateRenderer(pthis->window, -1, SDL_RENDERER_SOFTWARE);

}

void render_window(Window* pthis)
{
	Painter painter;
	init_painter(&painter, pthis->render, pthis->background);
	SDL_Rect dst = { 0,0,pthis->w,pthis->h };
	render_surface(&painter, NULL,&dst );
}

void event_loop(Window* pthis)
{
	Button b1,b2;
	init_button(&b1, 310, 350, "wei sang");
	init_button(&b2, 310, 150, "wei ye");
	Edit edit;
	init_edit(&edit, 100, 200);
;

	bool isRunning = true;
	while (isRunning)
	{
		SDL_Event msg;
		if (SDL_WaitEvent(&msg) != 0)
		{
			switch (msg.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			}
			//hover_button(&b1, &msg);
			clicked_button(&b1, &msg);
			//hover_button(&b2, &msg);
			clicked_button(&b2, &msg);
			event_edit(&edit, &msg);
		}
		SDL_RenderClear(pthis->render);
		//绘制
		render_window(pthis);
		render_button(pthis->render, &b1);
		render_button(pthis->render, &b2);
		render_edit(pthis->render, &edit);
		SDL_RenderPresent(pthis->render);
		//动作
		if (b1.isClicked||b2.isClicked)
		{
			//SDL_Log(u8"鼠标左键按下。。。\n");
			mciSendString(L"open ./1.mp3",0,0,0);
			mciSendString(L"play ./1.mp3 repeat",0,0,0);

		}
	}
}

void destory_window(Window* pthis)
{
	SDL_FreeSurface(pthis->background);
	SDL_DestroyRenderer(pthis->render);
	SDL_DestroyWindow(pthis->window);
}
