#include"MCube.h"
#include<math.h>

MCube::MCube()
{
	existence = true;
	realWidth = REAL_WIDTH;
	realHeight = REAL_HEIGHT;
}
MCube::MCube(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	existence = true;
	realWidth = REAL_WIDTH;
	realHeight = REAL_HEIGHT;
}
MCube::~MCube()
{

}

void MCube::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	existence = true;
}
void MCube::Initial()
{
	MAnimationSprite::Initial();

	existence = true;
}

bool MCube::IsCrashed(QPoint point,int wid,int hei)
{
	if (!existence)
		return false;
	int dx = abs(hotPoint.x() - point.x());
	int dy = abs(hotPoint.y() - point.y());

	if ((dx <= 0.5*(realWidth + wid)) && (dy <=0.5*( realHeight + hei)))
	{
		return true;
	}
	else
		return false;
}

void MCube::SetExistence(bool e)
{
	existence = e;
}
bool MCube::GetExistence()const
{
	return existence;
}