#include"MMapEditer.h"
#include<qdebug.h>

MMapEditer::MMapEditer()
{
	

	

}

void MMapEditer::Construct(QString mBrickPath, QString mIcePath,
	QString mJellyPath, QString mSpikerockPath,
	QString mMonsterPath, QString mPlayerPath,
	QString mBackgroundPath, QString mSaveAndBackPath,
	QString mSaveAndPlayPath, QString mBackPath,
	QString mInitialPath)
{
	LoadPixmap(mBrickPath, mIcePath,
		mJellyPath, mSpikerockPath,
		mMonsterPath, mPlayerPath,
		mBackgroundPath,mSaveAndBackPath,
		mSaveAndPlayPath,mBackPath,mInitialPath);
	
	//窗口初始化
	{
		setMouseTracking(true);
		move(0, 0);
		setFixedSize(1920, 1080);

		QPixmap windowIcon;
		windowIcon.load(":/UI/UIDocuments/MapEditer/monster.png");
		setWindowIcon(windowIcon);
	}
	
	//初始化工作
	{
		for (int i = 0; i < 200; i++)
		{
			brickArray[i].hide();
			iceArray[i].hide();
			jellyArray[i].hide();
			spikerockArray[i].hide();
			monsterArray[i].hide();
		}

		playerButtonTemp.hide();

		moveButton = NULL;
		brickArrayNum = 0;
		iceArrayNum = 0;
		jellyArrayNum = 0;
		spikerockArrayNum = 0;
		monsterArrayNum = 0;

		ConstrutPlayerButtonTemp();
		FirstMonster();
	}

	ButtonLayout();

	//信号连接
	{
		connect(&brickButton, &QPushButton::clicked, this, &MMapEditer::AddBrick);
		connect(&iceButton, &QPushButton::clicked, this, &MMapEditer::AddIce);
		connect(&jellyButton, &QPushButton::clicked, this, &MMapEditer::AddJelly);
		connect(&spikerockButton, &QPushButton::clicked, this, &MMapEditer::AddSpikerock);
		connect(&monsterButton, &QPushButton::clicked, this, &MMapEditer::AddMonster);
		connect(&playerButton, &QPushButton::clicked, this, &MMapEditer::SetPlayerButtonTemp);
		
		connect(&saveAndBackButton, &QPushButton::clicked, this, &MMapEditer::SaveMapFileAndBack);
		connect(&saveAndPlayButton, &QPushButton::clicked, this, &MMapEditer::SaveMapFileAndPlay);
		connect(&backButton, &QPushButton::clicked, this, &MMapEditer::back);
		connect(&initialButton, &QPushButton::clicked, this, &MMapEditer::InitialButtonFunction);
	}

}
void MMapEditer::Initial()
{
	for (int i = 0; i < 200; i++)
	{
		brickArray[i].hide();
		iceArray[i].hide();
		jellyArray[i].hide();
		spikerockArray[i].hide();
		monsterArray[i].hide();

		brickArray[i].Initial();
		iceArray[i].Initial();
		jellyArray[i].Initial();
		spikerockArray[i].Initial();
		monsterArray[i].Initial();
	}

	playerButtonTemp.show();
	playerButtonTemp.move(930, 840);
	playerButtonTemp.Initial();

	moveButton = NULL;
	brickArrayNum = 0;
	iceArrayNum = 0;
	jellyArrayNum = 0;
	spikerockArrayNum = 0;
	monsterArrayNum = 0;

	FirstMonster();
}

void MMapEditer::mouseMoveEvent(QMouseEvent* event)
{
	SearchForMoveButton();

	if (moveButton == NULL)
		return;
	
	nextCubePoint = QPoint(event->pos().x() - moveButton->width() * 0.5, event->pos().y() - moveButton->height() * 0.5);
	if (IsNextCubePointValid())
	{
		moveButton->move(nextCubePoint);
	}
}
void MMapEditer::paintEvent(QPaintEvent* event)
{
	painter.begin(this);
	painter.drawPixmap(0, 0, background);
	painter.end();
}

bool MMapEditer::IsNextCubePointValid()
{
	if (nextCubePoint.x() < MAP_LEFT  + 1
		|| nextCubePoint.x() > MAP_RIGHT -moveButton->width() - 1
		|| nextCubePoint.y() < MAP_TOP + 1
		|| nextCubePoint.y() > MAP_BUTTOM -moveButton->height() - 1)
	{
		return false;
	}
	return true;
}

int MMapEditer::WriteIntoFile()
{
	QFile file(filePath);
	if(file.open(QIODevice::WriteOnly))
	{	
		QDataStream out(&file);

		out << (qint32)FILE_CODE;

		for (int i = 0; i < brickArrayNum; i++)
		{
			out << (qint32)BRICK;
			out << brickArray[i].pos();
		}
		for (int i = 0; i < iceArrayNum; i++)
		{
			out << (qint32)ICE;
			out << iceArray[i].pos();
		}
		for (int i = 0; i < jellyArrayNum; i++)
		{
			out << (qint32)JELLY;
			out << jellyArray[i].pos();
		}
		for (int i = 0; i < spikerockArrayNum; i++)
		{
			out << (qint32)SPIKEROCK;
			out << spikerockArray[i].pos();
		}
		for (int i = 0; i < monsterArrayNum; i++)
		{
			out << (qint32)MONSTER;
			out << monsterArray[i].pos();
		}
		
		out << (qint32)PLAYER;
		out << playerButtonTemp.pos();
		out << (qint32)END;
	}
	/*else
	{
		QMessageBox::about(NULL, QString("错误"),
			QString("地图文件打开错误，请检查输入文件地址是否正确"));
		return -1;
	}*/
	return 0;
}

void MMapEditer::SaveMapFileAndBack()
{
	SetFilePath(filePathInput.text());
	WriteIntoFile();

	emit finishAndBack();
}
void MMapEditer::SaveMapFileAndPlay()
{
	SetFilePath(filePathInput.text());
	WriteIntoFile();

	emit finishAndPlay();
}
void MMapEditer::InitialButtonFunction()
{
	for (int i = 0; i < 200; i++)
	{
		brickArray[i].hide();
		iceArray[i].hide();
		jellyArray[i].hide();
		spikerockArray[i].hide();
		monsterArray[i].hide();
	}

	playerButtonTemp.show();
	playerButtonTemp.move(930, 840);

	moveButton = NULL;
	brickArrayNum = 0;
	iceArrayNum = 0;
	jellyArrayNum = 0;
	spikerockArrayNum = 0;
	monsterArrayNum = 0;

	FirstMonster();
}

void MMapEditer::SetFilePath(QString mFilePath)
{
	filePath = mFilePath;
}
QString MMapEditer::GetFilePath()const
{
	return filePath;
}

void MMapEditer::LoadPixmap(QString mBrickPath, QString mIcePath,
	QString mJellyPath, QString mSpikerockPath,
	QString mMonsterPath, QString mPlayerPath,
	QString mBackgroundPath, QString mSaveAndBackPath,
	QString mSaveAndPlayPath, QString mBackPath,
	QString mInitialPath)
{
	brickPixmap.load(mBrickPath);
	icePixmap.load(mIcePath);
	jellyPixmap.load(mJellyPath);
	spikerockPixmap.load(mSpikerockPath);
	monsterPixmap.load(mMonsterPath);
	playerPixmap.load(mPlayerPath);
	background.load(mBackgroundPath);

	saveAndBackPixmap.load(mSaveAndBackPath);
	saveAndPlayPixmap.load(mSaveAndPlayPath);
	backPixmap.load(mBackPath);
	initialPixmap.load(mInitialPath);
}
void MMapEditer::ButtonLayout()
{
	//编辑方块的按钮布局
	{
		brickButton.setParent(this);
		iceButton.setParent(this);
		jellyButton.setParent(this);
		spikerockButton.setParent(this);
		monsterButton.setParent(this);
		playerButton.setParent(this);

		brickButton.show();
		iceButton.show();
		jellyButton.show();
		spikerockButton.show();
		monsterButton.show();
		playerButton.show();

		brickButton.resize(118, 119);
		iceButton.resize(118, 119);
		jellyButton.resize(118, 119);
		spikerockButton.resize(118, 119);
		monsterButton.resize(118, 119);
		playerButton.resize(118, 119);

		brickButton.move(258, 127);
		iceButton.move(258, 268);
		jellyButton.move(258, 411);
		spikerockButton.move(258, 552);
		monsterButton.move(258, 693);
		playerButton.move(258, 830);

		brickButton.setStyleSheet("QPushButton{border:Opx}");
		iceButton.setStyleSheet("QPushButton{border:Opx}");
		jellyButton.setStyleSheet("QPushButton{border:Opx}");
		spikerockButton.setStyleSheet("QPushButton{border:Opx}");
		monsterButton.setStyleSheet("QPushButton{border:Opx}");
		playerButton.setStyleSheet("QPushButton{border:Opx}");

		brickButton.setIcon(brickPixmap);
		iceButton.setIcon(icePixmap);
		jellyButton.setIcon(jellyPixmap);
		spikerockButton.setIcon(spikerockPixmap);
		monsterButton.setIcon(monsterPixmap);
		playerButton.setIcon(playerPixmap);

		brickButton.setIconSize(QSize(118, 119));
		iceButton.setIconSize(QSize(118, 119));
		jellyButton.setIconSize(QSize(118, 119));
		spikerockButton.setIconSize(QSize(118, 119));
		monsterButton.setIconSize(QSize(118, 119));
		playerButton.setIconSize(QSize(118, 119));
	}

	//文件地址输入的布局
	{
		QFont font;
		font.setPointSize(15);
		font.setBold(true);

		filePathInput.setFont(font);
		filePathInput.setParent(this);
		filePathInput.move(1526, 226);
		filePathInput.resize(312, 50);
		filePathInput.setText("newMap.dat");
		filePathInput.setClearButtonEnabled(true);
		filePathInput.show();

		saveAndBackButton.setParent(this);
		saveAndBackButton.move(1506, 316);
		saveAndBackButton.resize(133, 61);
		saveAndBackButton.setStyleSheet("QPushButton{border:Opx}");
		saveAndBackButton.setIcon(saveAndBackPixmap);
		saveAndBackButton.setIconSize(QSize(133,61));
		saveAndBackButton.show();

		saveAndPlayButton.setParent(this);
		saveAndPlayButton.move(1732, 316);
		saveAndPlayButton.resize(133, 61);
		saveAndPlayButton.setStyleSheet("QPushButton{border:Opx}");
		saveAndPlayButton.setIcon(saveAndPlayPixmap);
		saveAndPlayButton.setIconSize(QSize(133, 61));
		saveAndPlayButton.show();
	}

	//菜单按钮布局
	{
		backButton.setParent(this);
		backButton.move(1506, 411);
		backButton.resize(133,61);
		backButton.setStyleSheet("QPushButton{border:Opx}");
		backButton.setIcon(backPixmap);
		backButton.setIconSize(QSize(133, 61));
		backButton.show();

		initialButton.setParent(this);
		initialButton.move(1732, 411);
		initialButton.resize(133,61);
		initialButton.setStyleSheet("QPushButton{border:Opx}");
		initialButton.setIcon(initialPixmap);
		initialButton.setIconSize(QSize(133, 61));
		initialButton.show();
	}
}
void MMapEditer::ConstrutPlayerButtonTemp()
{
	playerButtonTemp.setParent(this);
	playerButtonTemp.move(930, 840);
	
	playerButtonTemp.resize(70, 70);
	playerButtonTemp.setStyleSheet("QPushButton{border:Opx}");
	playerButtonTemp.setIcon(playerPixmap);
	playerButtonTemp.setIconSize(QSize(70, 70));

	playerButtonTemp.show();
}
void MMapEditer::FirstMonster()
{
	if (monsterArrayNum < CUBE_ACOUNT)
	{
		monsterArrayNum++;
	}

	monsterArray[monsterArrayNum - 1].setParent(this);
	monsterArray[monsterArrayNum - 1].move(930,200);
	monsterArray[monsterArrayNum - 1].SetMoveState(true);
	monsterArray[monsterArrayNum - 1].resize(70, 70);
	monsterArray[monsterArrayNum - 1].setStyleSheet("QPushButton{border:Opx}");
	monsterArray[monsterArrayNum - 1].setIcon(monsterPixmap);
	monsterArray[monsterArrayNum - 1].setIconSize(QSize(70, 70));
	monsterArray[monsterArrayNum - 1].show();
	monsterArray[monsterArrayNum - 1].SetMoveState(false);
}
void MMapEditer::SearchForMoveButton()
{
	for (int i = 0; i < brickArrayNum; i++)
	{
		if (brickArray[i].GetMoveState())
		{
			moveButton = &brickArray[i];
			return;
		}
	}
	for (int i = 0; i < iceArrayNum; i++)
	{
		if (iceArray[i].GetMoveState())
		{
			moveButton = &iceArray[i];
			return;
		}
	}
	for (int i = 0; i < jellyArrayNum; i++)
	{
		if (jellyArray[i].GetMoveState())
		{
			moveButton = &jellyArray[i];
			return;
		}
	}
	for (int i = 0; i < spikerockArrayNum; i++)
	{
		if (spikerockArray[i].GetMoveState())
		{
			moveButton = &spikerockArray[i];
			return;
		}
	}
	for (int i = 0; i < monsterArrayNum; i++)
	{
		if (monsterArray[i].GetMoveState())
		{
			moveButton = &monsterArray[i];
			return;
		}
	}
	if (playerButtonTemp.GetMoveState())
	{
		moveButton = &playerButtonTemp;
		return;
	}
	moveButton = NULL;
	return;
}

void MMapEditer::AddBrick()
{	
	if (brickArrayNum < CUBE_ACOUNT)
	{
		brickArrayNum++;
	}

	brickArray[brickArrayNum - 1].setParent(this);
	brickArray[brickArrayNum - 1].move(brickButton.pos());
	brickArray[brickArrayNum - 1].SetMoveState(true);
	brickArray[brickArrayNum - 1].resize(70,70);
	brickArray[brickArrayNum - 1].setStyleSheet("QPushButton{border:Opx}");
	brickArray[brickArrayNum - 1].setIcon(brickPixmap);
	brickArray[brickArrayNum - 1].setIconSize(QSize(70, 70));
	brickArray[brickArrayNum - 1].show();

}
void MMapEditer::AddIce()
{
	if (iceArrayNum < CUBE_ACOUNT)
	{
		iceArrayNum++;
	}

	iceArray[iceArrayNum - 1].setParent(this);
	iceArray[iceArrayNum - 1].move(iceButton.pos());
	iceArray[iceArrayNum - 1].SetMoveState(true);
	iceArray[iceArrayNum - 1].resize(70, 70);
	iceArray[iceArrayNum - 1].setStyleSheet("QPushButton{border:Opx}");
	iceArray[iceArrayNum - 1].setIcon(icePixmap);
	iceArray[iceArrayNum - 1].setIconSize(QSize(70, 70));
	iceArray[iceArrayNum - 1].show();
	
}
void MMapEditer::AddJelly()
{	
	if (jellyArrayNum < CUBE_ACOUNT)
	{
		jellyArrayNum++;
	}

	jellyArray[jellyArrayNum - 1].setParent(this);
	jellyArray[jellyArrayNum - 1].move(jellyButton.pos());
	jellyArray[jellyArrayNum - 1].SetMoveState(true);
	jellyArray[jellyArrayNum - 1].resize(70, 70);
	jellyArray[jellyArrayNum - 1].setStyleSheet("QPushButton{border:Opx}");
	jellyArray[jellyArrayNum - 1].setIcon(jellyPixmap);
	jellyArray[jellyArrayNum - 1].setIconSize(QSize(70, 70));
	jellyArray[jellyArrayNum - 1].show();
}
void MMapEditer::AddSpikerock()
{	
	if (spikerockArrayNum < CUBE_ACOUNT)
	{
		spikerockArrayNum++;
	}

	spikerockArray[spikerockArrayNum - 1].setParent(this);
	spikerockArray[spikerockArrayNum - 1].move(spikerockButton.pos());
	spikerockArray[spikerockArrayNum - 1].SetMoveState(true);
	spikerockArray[spikerockArrayNum - 1].resize(70, 70);
	spikerockArray[spikerockArrayNum - 1].setStyleSheet("QPushButton{border:Opx}");
	spikerockArray[spikerockArrayNum - 1].setIcon(spikerockPixmap);
	spikerockArray[spikerockArrayNum - 1].setIconSize(QSize(70, 70));
	spikerockArray[spikerockArrayNum - 1].show();

	
}
void MMapEditer::AddMonster()
{	
	if (monsterArrayNum < CUBE_ACOUNT)
	{
		monsterArrayNum++;
	}

	monsterArray[monsterArrayNum - 1].setParent(this);
	monsterArray[monsterArrayNum - 1].move(monsterButton.pos());
	monsterArray[monsterArrayNum - 1].SetMoveState(true);
	monsterArray[monsterArrayNum - 1].resize(70, 70);
	monsterArray[monsterArrayNum - 1].setStyleSheet("QPushButton{border:Opx}");
	monsterArray[monsterArrayNum - 1].setIcon(monsterPixmap);
	monsterArray[monsterArrayNum - 1].setIconSize(QSize(70, 70));
	monsterArray[monsterArrayNum - 1].show();
}
void MMapEditer::SetPlayerButtonTemp()
{
	playerButtonTemp.show();
	playerButtonTemp.move(playerButton.pos());
	playerButtonTemp.SetMoveState(true);
}