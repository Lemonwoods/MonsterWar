#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MonsterWarM.h"

#include<QMouseEvent>
#include<qpainter.h>
#include<qpixmap.h>
#include<time.h>
#include<qtimer.h>
#include<qlabel.h>
#include<qfont.h>
#include<qpalette.h>

#include"MSprite.h"
#include"MAnimationSprite.h"
#include"MPlayer.h"
#include"MBullet.h"
#include"MBrick.h"
#include"MIce.h"
#include"MJelly.h"
#include"MMap.h"
#include"MMonsterArray.h"
#include"MStartWindow.h"
#include"MMapEditer.h"
#include"MFileReader.h"
#include"MEndWindow.h"
#include"MPropArray.h"
#include"MSpecial.h"
#include"MMusicPlayer.h"
#include"MMusicButton.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

	void paintEvent(QPaintEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);

	void Execute();

	void UpdateHPLabel(QPainter&mPainter,QPaintDevice*mPaintDevice);//更新玩家血量的显示

	void ButtonLayout();
	void LabelLayout();

	void CreateNewMapFunction();
	void MapArchiveFunction();
	void DefaultMapFunction();

	void GameOverFunction();
	void EndAndHome();
	void EndAndResume();
	void EndAndExit();

	void ResumeButtonFunction();
	void PauseButtonFunction();
	void HomeButtonFunction();

	void MapEditerFinishAndBack();
	void MapEditerFinishAndPlay();
	void MapEditerBack();

signals:
	void gameOver();

private:
	Ui::MonsterWarMClass ui;

	MMusicPlayer musicPlayer;

	MPlayer player;
	MMap gameMap;
	MMonsterArray monsterArray;

	MStartWindow startWindow;
	MMapEditer mapEditer;
	MEndWindow endWindow;
	MFileReader fileReader;

	MPropArray propArray;
	MSpecial special;

	QPixmap* frontPixmap;
	QPixmap backgroundPixmap;

	MMusicButton ResumeButton;
	MMusicButton PauseButton;
	MMusicButton HomeButton;

	QLabel timeInfo;
	QLabel HPInfo;

	QTimer gameTimer;
	QPainter painter;

	QPen pen;
	QBrush brush;
	QFont font;
	QPalette palette;

	bool monsterArrayWorking;
	bool gameTimerWork;
	int gameMode;
};
