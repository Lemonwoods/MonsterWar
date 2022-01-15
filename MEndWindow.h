#pragma once

#include<qwidget.h>
#include<qpushbutton.h>
#include<qlabel.h>
#include<qfont.h>
#include<qpalette.h>
#include<qpixmap.h>
#include<qevent.h>
#include<qpainter.h>

#include"MMusicButton.h"
#include"MDefine.h"

class MEndWindow :public QWidget
{
	Q_OBJECT

public:
	MEndWindow();

	void paintEvent(QPaintEvent* event);

	void Construct(QString resumePath,
		QString exitPath, QString loseBackgroundPath,
		QString winBackgroundPath);

	void LoadPixmap(QString resumePath,
		QString exitPath,QString loseBackgroundPath,
		QString winBackgroundPath);

	void ButtonLayout();

	void SetEndMode(int mEndMode);
	int GetEndMode()const;

signals:
	void homeSignal();
	void resumeSignal();
	void exitSignal();

private:
	QPushButton homeButton;
	MMusicButton resumeButton;
	MMusicButton exitButton;
	
	QLabel HPInfo;

	QPainter painter;
	QFont font;
	QPalette palette;

	QPixmap loseBackgroundPixmap;
	QPixmap winBackgroundPixmap;

	int endMode;
};