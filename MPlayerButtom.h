#pragma once


#include"MAnimationSprite.h"



class MPlayerButtom :public MAnimationSprite
{
public:
	MPlayerButtom();
	MPlayerButtom(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MPlayerButtom();
	void Initial();

	

private:

};