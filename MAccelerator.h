#pragma once

#include"MPlayer.h"
#include"MDefine.h"
#include"MAnimationSprite.h"

class MAccelerator:public MAnimationSprite
{
public:
	MAccelerator();
	MAccelerator(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MPlayer& mPlayer, double deltaTime);

	void AddSpeed(MPlayer& mPlayer);
	void MinuseSpeed(MPlayer& mPlayer);
	bool Update(double deltaTime);

	void SetWorking(bool mWorking);
	bool GetWorking()const;

private:
	int effect;
	double duration;
	double sinceStart;

	bool working;
};