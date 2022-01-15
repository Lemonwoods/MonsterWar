#include"MPlayerTop.h"

MPlayerTop::MPlayerTop()
{

}
MPlayerTop::MPlayerTop(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	shoot = false;
}
void MPlayerTop::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{	
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	shoot = false;
}
MPlayerTop::~MPlayerTop()
{

}
void MPlayerTop::Initial()
{
	MAnimationSprite::Initial();

	shoot = false;
}

void MPlayerTop::Play()
{
	MAnimationSprite::Play();
	CanShoot();
}

void MPlayerTop::CanShoot()
{
	shoot = true;
}
void MPlayerTop::NotShoot()
{
	shoot = false;
}
bool MPlayerTop::GetShoot()const
{
	return shoot;
}