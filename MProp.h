#pragma once

#include"MAnimationSprite.h"
#include"MMap.h"
#include"MPlayer.h"

class MProp :public MAnimationSprite
{

public:
	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void RandomHotPoint(MMap&mMap,MPlayer&mPlayer);
	bool IsHotPointValid(MMap&mMap,MPlayer&mPlayer);

	void SetMode(int mMode);
	int GetMode()const;

private:

	int mode;
};