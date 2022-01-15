#pragma once

#include"MAnimationSprite.h"

class MPlayerTop :public MAnimationSprite
{
public:
	MPlayerTop();
	MPlayerTop(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MPlayerTop();
	void Initial();

	void Play();

	void CanShoot();
	void NotShoot();
	bool GetShoot()const;

private:
	bool shoot;//标识当前是否可以发射子弹
};