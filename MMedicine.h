#pragma once

#include"MPlayer.h"
#include"MDefine.h"
#include"MAnimationSprite.h"

class MMedicine:public MAnimationSprite
{
public:
	MMedicine();
	MMedicine(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);

	void Initial();

	void Execute(MPlayer&mPlayer,double deltaTime);

	bool UpdateWorkingTime(double deltaTime);

	void AddHP(MPlayer&mPlayer);

	bool GetWorking()const;

private:
	int effect;
	double duration;
	double sinceStart;

	bool addOnce;

	bool working;
};