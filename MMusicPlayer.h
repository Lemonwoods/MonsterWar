#pragma once

#include<qsound.h>

class MMusicPlayer
{
public:
	MMusicPlayer();
	~MMusicPlayer();

	void Initial();

	QSound* backgroundMusic;
	QSound* shootBullet;

	QSound* brick;
	QSound* ice;
	QSound* jelly;

	QSound* mouseEnter;
	QSound* mouseClick;

	QSound* medicine;
	QSound* accelerator;
	QSound* bomb;

	QSound* playerHurt;
	QSound* monsterHurt;

	QSound* win;
	QSound* lose;
private:

};