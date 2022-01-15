#pragma once

#include<qwidget.h>
#include<qpushbutton.h>
#include<qimage.h>
#include<qpixmap.h>
#include<qevent.h>
#include<qpainter.h>
#include<qlineedit.h>

#include"MMusicButton.h"

class MStartWindow :public QWidget
{
	Q_OBJECT

public:
	MStartWindow();
	
	void paintEvent(QPaintEvent* event);
	
	void Construct(QString mCreateNewMapPath,QString mMapArchivePath,QString mDefaultMapPath, QString mBackgroundPath,
					QString mFinishPixmapPath,QString mBackPixmapPath);

	void LoadImage(QString mCreateNewMapPath, QString mMapArchivePath, QString mDefaultMapPath,QString mBackgroundPath,
					QString mFinishPixmapPath, QString mBackPixmapPath);
	void ButtonLayout();
	void LineEditLayout();

	void LineEditShow();
	void LineEditHide();

	void mapArchiveInitial();
	void SetMapFilePath(QString mMapFilePath);
	QString GetMapFilePath()const;

	MMusicButton createNewMap;
	MMusicButton mapArchive;
	MMusicButton defaultMap;

	MMusicButton finish;
	MMusicButton back;

signals:
	void createNewMapSignal();
	void mapArchiveSignal();
	void defaultMapSignal();
	 
private:
	QPainter painter;

	QLineEdit lineEdit;

	QPixmap createNewMapImage;
	QPixmap mapArchiveImage;
	QPixmap defaultMapImage;
	QPixmap finishPixmap;
	QPixmap backPixmap;

	QImage backgroundImage;

	QString mapFilePath;
	 
};