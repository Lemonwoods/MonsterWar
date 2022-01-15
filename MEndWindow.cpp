#include"MEndWindow.h"

MEndWindow::MEndWindow()
{

}

void MEndWindow::paintEvent(QPaintEvent* event)
{
	painter.begin(this);
	if (endMode == LOSE)
	{
		painter.drawPixmap(0, 0, loseBackgroundPixmap);
	}
	else
	{
		painter.drawPixmap(0, 0, winBackgroundPixmap);
	}
	painter.end();
}

void MEndWindow::Construct(QString resumePath,
	QString exitPath, QString loseBackgroundPath,QString winBackgroundPath)
{

	LoadPixmap(resumePath, exitPath, loseBackgroundPath,winBackgroundPath);
	ButtonLayout();

	//窗口属性的初始化
	{
		hide();

		setFixedSize(600, 800);
		move(660, 165);

		setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
		setWindowModality(Qt::ApplicationModal);
	}

	//信号连接
	{
		connect(&homeButton, &QPushButton::clicked, this, &MEndWindow::homeSignal);
		connect(&resumeButton, &QPushButton::clicked, this, &MEndWindow::resumeSignal);
		connect(&exitButton, &QPushButton::clicked, this, &MEndWindow::exitSignal);
	}

}

void MEndWindow::LoadPixmap(QString resumePath,
	QString exitPath, QString loseBackgroundPath,QString winBackgroundPath)
{
	QPixmap pixmap;

	pixmap.load(resumePath);
	resumeButton.setIcon(pixmap);

	pixmap.load(exitPath);
	exitButton.setIcon(pixmap);

	loseBackgroundPixmap.load(loseBackgroundPath);
	winBackgroundPixmap.load(winBackgroundPath);
}

void MEndWindow::ButtonLayout()
{
	/*homeButton.setParent(this);
	homeButton.move(100, 300);
	homeButton.resize(400, 50);
	homeButton.setStyleSheet("QPushButton{border:Opx}");
	homeButton.setIconSize(QSize(400, 50));
	homeButton.show();*/

	resumeButton.setParent(this);
	resumeButton.move(90, 585);
	resumeButton.resize(133, 61);
	resumeButton.setStyleSheet("QPushButton{border:Opx}");
	resumeButton.setIconSize(QSize(133, 61));
	resumeButton.show();

	exitButton.setParent(this);
	exitButton.move(384, 585);
	exitButton.resize(133, 61);
	exitButton.setStyleSheet("QPushButton{border:Opx}");
	exitButton.setIconSize(QSize(133, 61));
	exitButton.show();
}

void MEndWindow::SetEndMode(int mEndMode)
{
	endMode = mEndMode;
}
int MEndWindow::GetEndMode()const
{
	return endMode;
}