#pragma once

#include<qpushbutton.h>
#include"qevent.h"

#include"MMusicPlayer.h"

class MMusicButton :public QPushButton
{
	void enterEvent(QEvent* mEvent);
	static MMusicPlayer musicPlayer;
};