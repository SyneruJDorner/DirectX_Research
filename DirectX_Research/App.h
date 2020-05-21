#pragma once
#include "Window.h"
#include "LoopTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	LoopTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};