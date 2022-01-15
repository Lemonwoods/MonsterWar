#include"MAccelerator.h"

MAccelerator::MAccelerator()
{

}
MAccelerator::MAccelerator(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	effect = ACCELERATOR_EFFECT;
	duration = ACCELERATOR_DURATION;
	sinceStart = 0;
	SetWorking(true);
}

void MAccelerator::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);

	effect = ACCELERATOR_EFFECT;
	duration = ACCELERATOR_DURATION;
	sinceStart = 0;
	SetWorking(true);
}
void MAccelerator::Initial()
{
	effect = ACCELERATOR_EFFECT;
	duration = ACCELERATOR_DURATION;
	sinceStart = 0;
	SetWorking(true);
}

void MAccelerator::Execute(MPlayer& mPlayer, double deltaTime)
{
	if (!working)
		return;

	AddSpeed(mPlayer);
	SetHotPoint(mPlayer.GetHotPoint());
	if (Update(deltaTime))
	{
		MinuseSpeed(mPlayer);
		SetWorking(false);
	}
}

void MAccelerator::AddSpeed(MPlayer& mPlayer)
{
	mPlayer.SetSpeed(PLAYER_SPEED + ACCELERATOR_EFFECT);
}
void MAccelerator::MinuseSpeed(MPlayer& mPlayer)
{
	mPlayer.SetSpeed(PLAYER_SPEED);
}
bool MAccelerator::Update(double deltaTime)
{
	sinceStart += deltaTime;
	if (sinceStart >= duration)
	{
		sinceStart = 0;
		return true;
	}
	return false;
}

void MAccelerator::SetWorking(bool mWorking)
{
	working = mWorking;
}
bool MAccelerator::GetWorking()const
{
	return working;
}