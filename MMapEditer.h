#pragma once

#include<qwidget.h>
#include<qpushbutton.h>
#include<qpixmap.h>
#include<vector>
#include<qevent.h>
#include<qfile.h>
#include<qdatastream.h>
#include<qmessagebox.h>
#include<qlineedit.h>
#include<qpainter.h>
#include<qfont.h>

#include"MDefine.h"
#include"MMoveButton.h"
#include"MMusicButton.h"

using namespace std;

class MMapEditer :public QWidget
{
	Q_OBJECT

public:
	MMapEditer();

	void Construct(QString mBrickPath, QString mIcePath,
		QString mJellyPath, QString mSpikerockPath,
		QString mMonsterPath, QString mPlayerPath,
		QString mBackgroundPath, QString mSaveAndBackPath,
		QString mSaveAndPlayPath, QString mBackPath,
		QString mInitialPath);
	void Initial();
	
	void mouseMoveEvent(QMouseEvent*);
	void paintEvent(QPaintEvent*);
	
	bool IsNextCubePointValid();

	int WriteIntoFile();

	void SaveMapFileAndBack();
	void SaveMapFileAndPlay();
	void InitialButtonFunction();
	
	void SetFilePath(QString mFilePath);
	QString GetFilePath()const;

	void LoadPixmap(QString mBrickPath, QString mIcePath,
		QString mJellyPath, QString mSpikerockPath,
		QString mMonsterPath, QString mPlayerPath,
		QString mBackgroundPath,QString mSaveAndBackPath,
		QString mSaveAndPlayPath,QString mBackPath,
		QString mInitialPath);
	void ButtonLayout();
	void ConstrutPlayerButtonTemp();
	void FirstMonster();
	void SearchForMoveButton();//用于寻找当前哪一个按钮是可以移动的

	void AddBrick();
	void AddIce();
	void AddJelly();
	void AddSpikerock();
	void AddMonster();
	void SetPlayerButtonTemp();	

signals:
	void back();
	void finishAndBack();
	void finishAndPlay();

private:
	MMoveButton* moveButton;//用于指向当前正在移动的按钮
	QPoint nextCubePoint;

	QPainter painter;

	QPushButton brickButton;
	QPushButton iceButton;
	QPushButton jellyButton;
	QPushButton spikerockButton;
	QPushButton monsterButton;
	QPushButton playerButton;

	QLineEdit filePathInput;
	MMusicButton saveAndBackButton;
	MMusicButton saveAndPlayButton;
	MMusicButton backButton;
	MMusicButton initialButton;

	MMoveButton playerButtonTemp;

	MMoveButton brickArray[200];
	MMoveButton iceArray[200];
	MMoveButton jellyArray[200];
	MMoveButton spikerockArray[200];
	MMoveButton monsterArray[200];

	qint32 brickArrayNum;
	qint32 iceArrayNum;
	qint32 jellyArrayNum;
	qint32 spikerockArrayNum;
	qint32 monsterArrayNum;

	QPixmap brickPixmap;
	QPixmap icePixmap;
	QPixmap jellyPixmap;
	QPixmap spikerockPixmap;
	QPixmap monsterPixmap;
	QPixmap playerPixmap;
	QPixmap background;
	QPixmap saveAndBackPixmap;
	QPixmap saveAndPlayPixmap;
	QPixmap backPixmap;
	QPixmap initialPixmap;

	qint32 mode;

	QString filePath;
};