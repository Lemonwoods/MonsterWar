#include"MStartWindow.h"

MStartWindow::MStartWindow()
{
	
}

void MStartWindow::Construct(QString mCreateNewMapPath, QString mMapArchivePath, QString mDefaultMapPath, QString mBackgroundPath, QString mFinishPixmapPath, QString mBackPixmapPath)
{
	LoadImage(mCreateNewMapPath, mMapArchivePath, mDefaultMapPath,mBackgroundPath,mFinishPixmapPath,mBackPixmapPath);

	//窗口的初始化工作
	{
		setFixedSize(600, 800);
		update();
		
		QPixmap windowIcon;
		windowIcon.load(":/UI/UIDocuments/MapEditer/monster.png");
		setWindowIcon(windowIcon);
	}

	//按钮初始化和布局
	ButtonLayout();

	//LineEdit初始化和布局
	LineEditLayout();

	//信号连接
	{
		connect(&createNewMap, &QPushButton::clicked, this, &MStartWindow::createNewMapSignal);
		connect(&defaultMap, &QPushButton::clicked, this, &MStartWindow::defaultMapSignal);
		connect(&mapArchive, &QPushButton::clicked, this, &MStartWindow::LineEditShow);
		connect(&back, &QPushButton::clicked, this, &MStartWindow::LineEditHide);
		connect(&finish, &QPushButton::clicked, this, &MStartWindow::mapArchiveInitial);

	}
	
}

void MStartWindow::paintEvent(QPaintEvent* event)
{
	painter.begin(this);
	painter.drawImage(0,0,backgroundImage);
	painter.end();
}

void MStartWindow::LoadImage(QString mCreateNewMapPath, QString mMapArchivePath, QString mDefaultMapPath,QString mBackgroundPath, QString mFinishPixmapPath, QString mBackPixmapPath)
{
	createNewMapImage.load(mCreateNewMapPath);
	mapArchiveImage.load(mMapArchivePath);
	defaultMapImage.load(mDefaultMapPath);
	backgroundImage.load(mBackgroundPath);
	finishPixmap.load(mFinishPixmapPath);
	backPixmap.load(mBackPixmapPath);
}
void MStartWindow::ButtonLayout()
{
	createNewMap.setParent(this);
	mapArchive.setParent(this);
	defaultMap.setParent(this);

	createNewMap.resize(210, 60);
	mapArchive.resize(210, 60);
	defaultMap.resize(210, 60);

	createNewMap.move(195, 340);
	mapArchive.move(195, 410);
	defaultMap.move(195, 480);

	//给按钮贴图
	{
		createNewMap.setStyleSheet("QPushButton{border:Opx}");
		createNewMap.setIcon(createNewMapImage);
		createNewMap.setIconSize(QSize(210, 60));

		mapArchive.setStyleSheet("QPushButton{border:Opx}");
		mapArchive.setIcon(mapArchiveImage);
		mapArchive.setIconSize(QSize(210, 60));

		defaultMap.setStyleSheet("QPushButton{border:Opx}");
		defaultMap.setIcon(defaultMapImage);
		defaultMap.setIconSize(QSize(210, 60));
	}
}
void MStartWindow::LineEditLayout()
{
	QFont font;
	font.setPointSize(15);
	font.setBold(true);

	lineEdit.setFont(font);
	lineEdit.setParent(this);
	lineEdit.move(135, 350);
	lineEdit.resize(312, 50);

	lineEdit.hide();

	finish.setParent(this);
	finish.resize(130, 60);
	finish.move(322, 467);

	finish.hide();

	back.setParent(this);
	back.resize(130, 60);
	back.move(133, 467);

	back.hide();

	{
		finish.setStyleSheet("QPushButton{border:Opx}");
		finish.setIcon(finishPixmap);
		finish.setIconSize(QSize(210, 60));

		back.setStyleSheet("QPushButton{border:Opx}");
		back.setIcon(backPixmap);
		back.setIconSize(QSize(210, 60));
	}

}

void MStartWindow::LineEditShow()
{
	lineEdit.show();
	finish.show();
	back.show();

	createNewMap.hide();
	mapArchive.hide();
	defaultMap.hide();
}
void MStartWindow::LineEditHide()
{
	lineEdit.hide();
	finish.hide();
	back.hide();

	createNewMap.show();
	mapArchive.show();
	defaultMap.show();
}

void MStartWindow::mapArchiveInitial()
{
	SetMapFilePath(lineEdit.text());
	emit mapArchiveSignal();
}
void MStartWindow::SetMapFilePath(QString mMapFilePath)
{
	mapFilePath = mMapFilePath;
}
QString MStartWindow::GetMapFilePath()const
{
	return mapFilePath;
}