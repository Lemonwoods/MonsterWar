#pragma once

#include<vector>
#include<qimage.h>
#include<qpainter.h>

#include"MProp.h"
#include"MDefine.h"
#include"MMap.h"
#include"MPlayer.h"

using namespace std;

class MPropArray
{
public:

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMap&mMap,MPlayer&mPlayer,double deltaTime);
	void Render(QPainter& mPainter, QPaintDevice* mPaintDevice);
	void UpdateProp(double deltaTime);

	void LoadImage(QString mMedicine, QString mAccelerator, 
		QString mFrozen, QString mBomb);
	bool Update(double deltaTime);
	void AddNewProp(MMap&mMap,MPlayer&mPlayer);
	void IsCrashed(MPlayer& mPlayer);

	void SetWorkingMode(int mWorkingMode);
	int GetWorkingMode()const;

	MProp propTemp;
	vector<MProp>prop;
	vector<MProp>::iterator itProp;
private:
	double interval;
	double sinceLastProp;
	int workingMode;

	QImage propImage[4];
};