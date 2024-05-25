#include"SWindow.h"
int main(int argc, char* argv[])
{
	Window w;
	init_window(&w,"./1.jpg");
	create_window(&w, "GUI");
	event_loop(&w);
	destory_window(&w);
	return 0;
}




