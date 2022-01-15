#include<qpainter.h>
#include<qimage.h>
#include<qpixmap.h>
#include<qdebug.h>
#include<qtimer.h>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//主窗口和程序初始化
	{
		srand(time(0));

		move(0, 0);
		setFixedSize(1920, 1080);

		ButtonLayout();
		LabelLayout();

		frontPixmap = new QPixmap(1920, 1080);
		backgroundPixmap.load(":/UI/UIDocuments/MainWindow/background.png");

		QPixmap windowIcon;
		windowIcon.load(":/UI/UIDocuments/MapEditer/monster.png");
		setWindowIcon(windowIcon);

		musicPlayer.backgroundMusic->play();

		monsterArrayWorking = false;

		gameTimer.stop();
		hide();

		//加载按钮图片
		{
			QPixmap pix;
			pix.load(":/UI/UIDocuments/MainWindow/home.png");
			HomeButton.setIcon(pix);

			pix.load(":/UI/UIDocuments/MainWindow/resume.png");
			ResumeButton.setIcon(pix);

			pix.load(":/UI/UIDocuments/MainWindow/pause.png");
			PauseButton.setIcon(pix);
		}
	}

	//初始化窗体和菜单对象
	{
		fileReader.ReadFile(gameMap, monsterArray, player);

		startWindow.Construct(QString(":/UI/UIDocuments/StartWindow/createNewMap.png"), QString(":/UI/UIDocuments/StartWindow/mapArchive.png"),
			QString(":/UI/UIDocuments/StartWindow/defaultMap.png"), QString(":/UI/UIDocuments/StartWindow/background.png"),
			QString(":/UI/UIDocuments/StartWindow/finish.png"), QString(":/UI/UIDocuments/StartWindow/back.png"));
		startWindow.show();
		
		endWindow.Construct(QString(":/UI/UIDocuments/EndWindow/resume.png"),
			QString(":/UI/UIDocuments/EndWindow/exit.png"), QString(":/UI/UIDocuments/EndWindow/lose.png"),
			QString(":/UI/UIDocuments/EndWindow/win.png"));
		endWindow.hide();

		mapEditer.Construct(QString(":/UI/UIDocuments/MapEditer/brick.png"), QString(":/UI/UIDocuments/MapEditer/ice.png"),
			QString(":/UI/UIDocuments/MapEditer/jelly.png"), QString(":/UI/UIDocuments/MapEditer/spikerock.png"),
			QString(":/UI/UIDocuments/MapEditer/monster.png"), QString(":/UI/UIDocuments/MapEditer/player.png"),
			QString(":/UI/UIDocuments/MapEditer/background.png"), QString(":/UI/UIDocuments/MapEditer/saveAndBack.png"),
			QString(":/UI/UIDocuments/MapEditer/saveAndPlay.png"), QString(":/UI/UIDocuments/MapEditer/back.png"),
			QString(":/UI/UIDocuments/MapEditer/initial.png"));
		mapEditer.hide();
	}

	//信号连接
	{
		connect(&startWindow, &MStartWindow::createNewMapSignal, this, &MainWindow::CreateNewMapFunction);
		connect(&startWindow, &MStartWindow::mapArchiveSignal, this, &MainWindow::MapArchiveFunction);
		connect(&startWindow, &MStartWindow::defaultMapSignal, this, &MainWindow::DefaultMapFunction);

		connect(this, &MainWindow::gameOver, this, &MainWindow::GameOverFunction);
		//connect(&endWindow, &MEndWindow::homeSignal, this, &MainWindow::EndAndHome);
		connect(&endWindow, &MEndWindow::resumeSignal, this, &MainWindow::EndAndResume);
		connect(&endWindow, &MEndWindow::exitSignal, this, &MainWindow::EndAndExit);

		connect(&mapEditer, &MMapEditer::finishAndBack, this, &MainWindow::MapEditerFinishAndBack);
		connect(&mapEditer, &MMapEditer::finishAndPlay, this, &MainWindow::MapEditerFinishAndPlay);
		connect(&mapEditer, &MMapEditer::back, this, &MainWindow::MapEditerBack);

		connect(&ResumeButton, &QPushButton::clicked, this, &MainWindow::ResumeButtonFunction);
		connect(&PauseButton, &QPushButton::clicked, this, &MainWindow::PauseButtonFunction);
		connect(&HomeButton, &QPushButton::clicked, this, &MainWindow::HomeButtonFunction);
	}

	//设置鼠标的追踪模式
	{
		setMouseTracking(true);
		ui.centralWidget->setMouseTracking(true);
	}

	//游戏对象初始化
	{
		player.playerTop.Construct(0, 0, 10, 1,25, 10, 5, QPoint(960, 540), QString(":/UI/UIDocuments/MainWindow/playerTop.png"), 110, 110, 0, 25);
		player.playerButtom.Construct(0, 0, 10,1, 25, 10, 1, QPoint(960, 540), QString(":/UI/UIDocuments/MainWindow/playerButtom.png"), 90, 90, 0, 35);
		player.Construct(PLAYER_HP, PLAYER_ARMOR, QPoint(960, 540), QString(":/UI/UIDocuments/MainWindow/playerButtom.png"), 60, 60, PLAYER_SPEED,20);

		player.bulletTemp.Construct(0, 0, 40,1, 75, 40, 1, QPoint(500, 500), QString(":/UI/UIDocuments/MainWindow/bullet.png"), 30, 30, 10, 12);

		gameMap.SetLeft(MAP_LEFT);
		gameMap.SetTop(MAP_TOP);
		gameMap.SetRight(MAP_RIGHT);
		gameMap.SetButtom(MAP_BUTTOM);
		gameMap.brickTemp.Construct(0, 0, 1, 1, 1, 1, 1, QPoint(0, 0), QString(":/UI/UIDocuments/MainWindow/brick.png"), 120, 120, 0, 30);
		gameMap.iceTemp.Construct(0, 0, 25, 1, 75, 25, 2, QPoint(0, 0), QString(":/UI/UIDocuments/MainWindow/ice.png"), 120, 120, 0, 30);
		gameMap.jellyTemp.Construct(0, 0, 50, 4, 175, 200, 6, QPoint(0, 0), QString(":/UI/UIDocuments/MainWindow/jelly.png"), 120, 120, 0, 30);
		gameMap.spikerockTemp.Construct(15, 1, 0, 0, 1, 1, 3, 1, 1, QPoint(0, 0), QString(":/UI/UIDocuments/MainWindow/spikerock.png"), 70, 70, 0, 30);

		monsterArray.monsterTemp.Construct(500, MONSTER_ATTACK, 2, 0, 0, 44, 1, 75, 44, 1, QPoint(550, 700), QString(":/UI/UIDocuments/MainWindow/monster.png"), 100, 100,  MONSTER_SPEED, 25);
		monsterArray.monsterTemp.frozen.Construct(1, 1, 1, 1, 1, 1, 1, QPoint(600, 300), QString(":UI/UIDocuments/MainWindow/frozenAfter.png"), 100, 100, 0, 40);

		propArray.Construct(0, 0, 1, 1, 1, 1, 1, QPoint(600, 300), QString(":/Test/Image/Test/Brick.jpg"), 40, 40, 0, 20);
		propArray.LoadImage(QString(":/UI/UIDocuments/MainWindow/medicine.png"), QString(":UI/UIDocuments/MainWindow/accelerator.png"),
			QString(":UI/UIDocuments/MainWindow/frozen.png"), QString(":UI/UIDocuments/MainWindow/bomb.png"));

		special.Construct();
		special.medicineTemp.Construct(1, 1, 1, 1, 1, 1, 1, QPoint(600, 300), QString(":UI/UIDocuments/MainWindow/medicineAfter.png"), 70, 70, 0, 50);
		special.acceleratorTemp.Construct(1,1,1,1,1,11,1,QPoint(600,300),QString(":UI/UIDocuments/MainWindow/acceleratorAfter.png"),70,70,0,50);
		special.bombTemp.Construct(1, 1, 1, 1, 1, 1, 1, QPoint(600, 300), QString(":UI/UIDocuments/MainWindow/bombAfter.png"), 400, 400, 0, BOMB_MAX_REDIUS);
	}

	//定时器设置
	{
		gameTimer.setParent(this);
		gameTimer.start(15);
		gameTimerWork = true;
		connect(&gameTimer, &QTimer::timeout, this, &MainWindow::Execute);
	}
	
	gameTimer.stop();
}
MainWindow::~MainWindow()
{
	delete frontPixmap;
}

void MainWindow::paintEvent(QPaintEvent*event)
{
	painter.begin(frontPixmap);
	painter.setPen(Qt::white);
	painter.setBrush(Qt::white);
	painter.drawRect(0, 0, 1920, 1080);
	painter.end();

	painter.begin(frontPixmap);
	painter.drawPixmap(0, 0, backgroundPixmap);
	painter.end();

	UpdateHPLabel(painter, frontPixmap);

	gameMap.RenderCube(painter, frontPixmap);
	player.playerButtom.MAnimationSprite::RotateRender(painter, frontPixmap);
	player.RenderBullet(painter, frontPixmap);
	player.playerTop.MAnimationSprite::RotateRender(painter, frontPixmap);
	monsterArray.RenderMonster(painter, frontPixmap);
	propArray.Render(painter, frontPixmap);
	special.Render(painter, frontPixmap);

	painter.begin(this);
	painter.drawPixmap(0, 0, *frontPixmap);
	painter.end();
}
void MainWindow::mouseMoveEvent(QMouseEvent*event)
{
	player.playerTop.CalculateAngle(event->pos().x(), event->pos().y());
}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
	player.Execute(event->key());
}
void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
	///玩家底部的动画播放
	player.playerButtom.Stop();
	player.SetDirection(STOP);
}

void MainWindow::Execute()
{
	//游戏主体执行部分
	
	//玩家部分
	{
		player.Move();
		if ((!gameMap.IsCrashedWithCube(player.GetNextHotPoint(), player.GetWidth(), player.GetHeight()))
			&& (player.IsHotPointValid(gameMap.GetLeft(), gameMap.GetTop(), gameMap.GetRight(), gameMap.GetButtom())))
			player.UpdateHotPoint();

		player.ShootBullet(musicPlayer,gameMap.GetLeft(), gameMap.GetTop(), gameMap.GetRight(), gameMap.GetButtom());
	}

	gameMap.ExecuteCube(musicPlayer,player, player.bullet, 0.015);

	monsterArray.Execute(musicPlayer,gameMap, player, 0.015);

	propArray.Execute(gameMap, player, 0.015);

	special.Execute(musicPlayer,monsterArray, propArray, player, 0.015);

	//动画时间同步
	{
		player.playerTop.Update(0.015);
		player.playerButtom.Update(0.015);
		player.UpdateBullet(0.015);

		gameMap.Update(0.015);
		gameMap.UpdateCube(0.015);

		monsterArray.Update(0.015);

		propArray.UpdateProp(0.015);
	}

	//判断游戏是否胜利
	{
		if (monsterArrayWorking)
		{
			if (monsterArray.monster.size()==0)
			{
				emit gameOver();
			}
		}
	}

	update();
}

void MainWindow::UpdateHPLabel(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	mPainter.begin(mPaintDevice);
	pen.setColor(QColor(241, 67, 101));
	pen.setWidth(32);
	pen.setCapStyle(Qt::RoundCap);
	brush.setColor(QColor(241, 67, 101));
	mPainter.setPen(pen);
	mPainter.setBrush(brush);

	if (player.GetHP() < 0)
	{
		player.SetHP(0);
	}

	mPainter.drawLine(1500+22, 430-2-1, 1500+22 + 3.55 * player.GetHP(), 430-2-1);

	mPainter.end();

	if (player.GetHP() <= 0)
	{
		emit gameOver();
	}
}

void MainWindow::ButtonLayout()
{
	ResumeButton.setParent(this);
	ResumeButton.move(200, 300);
	ResumeButton.resize(133,61);
	ResumeButton.setStyleSheet("QPushButton{border:Opx}");
	ResumeButton.setIconSize(QSize(133, 61));
	ResumeButton.show();

	PauseButton.setParent(this);
	PauseButton.move(200, 400);
	PauseButton.resize(133, 61);
	PauseButton.setStyleSheet("QPushButton{border:Opx}");
	PauseButton.setIconSize(QSize(133, 61));
	PauseButton.show();

	HomeButton.setParent(this);
	HomeButton.move(200, 500);
	HomeButton.resize(133, 61);
	HomeButton.setStyleSheet("QPushButton{border:Opx}");
	HomeButton.setIconSize(QSize(133, 61));
	HomeButton.show();
}
void MainWindow::LabelLayout()
{
	font.setPointSize(20);

	timeInfo.setParent(this);
	timeInfo.move(1600, 300);
	timeInfo.resize(400, 100);
	timeInfo.show();

	HPInfo.setParent(this);
	HPInfo.setFont(font);
	HPInfo.move(1600, 500);
	HPInfo.resize(400, 100);
	HPInfo.show();
}

void MainWindow::CreateNewMapFunction()
{
	startWindow.hide();
	endWindow.hide();
	this->hide();
	gameTimer.stop();
	mapEditer.show();
}
void MainWindow::MapArchiveFunction()
{
	fileReader.Construct(startWindow.GetMapFilePath());
	if (fileReader.ReadFile(gameMap, monsterArray, player) == -1)
	{
		QMessageBox::information(NULL, QString("warning"), QString("the file is not valid map archive, please try again"), QMessageBox::Yes , QMessageBox::Yes);
		/*if (gameTimerWork)
		{
			gameTimer.stop();
			gameTimerWork = false;
		}

		startWindow.show();
		endWindow.hide();
		mapEditer.hide();
		this->hide();*/

		return;
	}
	if (!gameTimerWork)
	{
		gameTimer.start();
		gameTimerWork = true;
	}

	startWindow.hide();
	endWindow.hide();
	mapEditer.hide();
	this->show();
	gameTimer.start();
	monsterArrayWorking = true;
	
	gameMode = MAP_ARCHIVE;
}
void MainWindow::DefaultMapFunction()
{
	if (!gameTimerWork)
	{
		gameTimerWork = true;
		gameTimer.start();
	}

	startWindow.hide();
	endWindow.hide();	
	mapEditer.hide();
	this->show();
	gameTimer.start();

	gameMap.DefaultMap();
	monsterArray.DefaultMonsterArray();
	monsterArrayWorking = true;

	player.SetHotPoint(QPoint(960, 540));
	player.SetNextHotPoint(QPoint(960, 540));

	gameMode = DEFAULT_MAP;
}

void MainWindow::GameOverFunction()
{
	if (player.GetHP() <= 0)
	{
		endWindow.SetEndMode(LOSE);
		musicPlayer.lose->play();
	}
	else
	{
		endWindow.SetEndMode(WIN);
		musicPlayer.win->play();
	}

	this->show();
	gameTimer.start();
	startWindow.hide();
	mapEditer.hide();
	endWindow.show();

	PauseButtonFunction();
}
void MainWindow::EndAndHome()
{
	endWindow.hide();
	HomeButtonFunction();
}
void MainWindow::EndAndResume()
{
	endWindow.hide();
	ResumeButtonFunction();
}
void MainWindow::EndAndExit()
{
	endWindow.close();

	this->close();
}

void MainWindow::ResumeButtonFunction()
{

	if (!gameTimerWork)
	{
		gameTimer.start();
		gameTimerWork = true;
	}

	player.Initial();
	gameMap.Initial();
	monsterArray.Initial();

	propArray.Initial();
	special.Initial();

	monsterArray.Clear();
	gameMap.Clear();

	switch (gameMode)
	{
	case MAP_ARCHIVE:
		fileReader.Construct(startWindow.GetMapFilePath());
		fileReader.ReadFile(gameMap, monsterArray, player);
		monsterArrayWorking = true;
		break;
	case DEFAULT_MAP:
		player.SetHotPoint(QPoint(960, 540));
		player.SetNextHotPoint(QPoint(960, 540));
		gameMap.DefaultMap();
		monsterArray.DefaultMonsterArray();
		monsterArrayWorking = true;
		break;
	}
}
void MainWindow::PauseButtonFunction()
{
	if (gameTimerWork)
	{
		gameTimerWork = false;
		gameTimer.stop();
	}
	else
	{
		gameTimerWork = true;
		gameTimer.start();
	}
}
void MainWindow::HomeButtonFunction()
{
	monsterArray.Clear();
	gameMap.Clear();

	startWindow.show();
	endWindow.hide();	
	mapEditer.hide();
	this->hide();
	gameTimer.stop();
}

void MainWindow::MapEditerFinishAndBack()
{
	startWindow.show();
	endWindow.hide();
	mapEditer.hide();
	this->hide();
	gameTimer.stop();
}
void MainWindow::MapEditerFinishAndPlay()
{
	startWindow.hide();
	endWindow.hide();
	mapEditer.hide();
	this->show();
	gameTimer.start();

	gameMode = MAP_ARCHIVE;
	startWindow.SetMapFilePath(mapEditer.GetFilePath());
	fileReader.Construct(mapEditer.GetFilePath());
	fileReader.ReadFile(gameMap, monsterArray, player);

}
void MainWindow::MapEditerBack()
{
	this->hide();
	gameTimer.stop();
	startWindow.show();
	endWindow.hide();
	mapEditer.hide();
}