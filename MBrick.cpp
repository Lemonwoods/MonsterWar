#include"MBrick.h"

MBrick::MBrick()
{

}
MBrick::MBrick(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MCube(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{

}
MBrick::~MBrick()
{

}

void MBrick::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MCube::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
}
void MBrick::Initial()
{
	MCube::Initial();
}

void MBrick::Execute(MMusicPlayer&mMusicPlayer,vector<MBullet>& mBullet)
{
	for (int i = 0; i < mBullet.size(); i++)
	{
		if (MCube::IsCrashed(mBullet[i].GetHotPoint(), mBullet[i].GetWidth(), mBullet[i].GetHeight()))
		{
			mMusicPlayer.brick->play();
			mBullet[i].SetFly(false);
		}
	}
}