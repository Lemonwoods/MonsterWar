#include"MIce.h"

MIce::MIce()
{

}
MIce::MIce(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MCube(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	play = false;
	existence = true;
}
MIce::~MIce()
{

}

void MIce::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MCube::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
}
void MIce::Initial()
{
	MCube::Initial();
}

void MIce::Execute(MMusicPlayer&mMusicPlayer,vector<MBullet>&mBullet)
{
	for (int i = 0; i < mBullet.size(); i++)
	{
		if (MCube::IsCrashed(mBullet[i].GetHotPoint(), mBullet[i].GetWidth(), mBullet[i].GetHeight()))
		{
			mMusicPlayer.ice->play();
			mBullet[i].SetFly(false);
			Broke();
		}
	}
	Invisible();
}

void MIce::Broke()
{
	play = true;
	existence = false;
}
void MIce::Invisible()
{
	if (currentFrame == frames - 1)
		visibility = false;
}