#include"MMusicButton.h"

MMusicPlayer MMusicButton::musicPlayer;

void MMusicButton::enterEvent(QEvent*mEvent)
{
	musicPlayer.mouseEnter->play();
}