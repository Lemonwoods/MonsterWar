#pragma once
#include"MAnimationSprite.h"
#include"MDefine.h"

class MCube :public MAnimationSprite
{
public:
	MCube();
	MCube(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MCube();

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	bool IsCrashed(QPoint,int, int);

	void SetExistence(bool);
	bool GetExistence()const;

protected:
	bool existence;

	int realWidth;
	int realHeight;
};