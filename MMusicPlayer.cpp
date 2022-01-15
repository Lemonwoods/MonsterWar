#include"MMusicPlayer.h"

MMusicPlayer::MMusicPlayer()
{
	{
		backgroundMusic = new QSound("Music\\backgroundMusic.wav");
		backgroundMusic->setLoops(1000);
	}

	{
		shootBullet = new QSound("Music\\shootBullet.wav");
	}

	{
		brick = new QSound("Music\\brick.wav");
		ice = new QSound("Music\\ice.wav");
		jelly = new QSound("Music\\jelly.wav");
	}

	{
		mouseEnter = new QSound("Music\\mouseEnter.wav");
		mouseClick = new QSound("Music\\mouseClick.wav");
	}

	{
		medicine = new QSound("Music\\medicine.wav");
		accelerator = new QSound("Music\\accelerator.wav");
		bomb = new QSound("Music\\bomb.wav");
	}

	{
		playerHurt = new QSound("Music\\playerHurt.wav");
		monsterHurt = new QSound("Music\\monsterHurt.wav");
	}

	{
		win = new QSound("Music\\win.wav");
		lose = new QSound("Music\\lose.wav");
	}
}

void MMusicPlayer::Initial()
{

}

MMusicPlayer::~MMusicPlayer()
{
	delete backgroundMusic;
	delete shootBullet;
	delete brick;
	delete ice;
	delete jelly;

	delete mouseEnter;
	delete mouseClick;

	delete medicine;
	delete accelerator;
	delete bomb;

	delete playerHurt;
	delete monsterHurt;

	delete win;
	delete lose;
}