#include"MMedicine.h"

MMedicine::MMedicine()
{

}
MMedicine::MMedicine(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	effect = MEDICINE_EFFECT;
	duration = MEDICINE_DURATION;
	addOnce = true;
	sinceStart = 0;
	working = true;
}
void MMedicine::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	effect = MEDICINE_EFFECT;
	duration = MEDICINE_DURATION;
	addOnce = true;
	sinceStart = 0;
	working = true;
}

void MMedicine::Initial()
{
	effect = MEDICINE_EFFECT;
	duration = MEDICINE_DURATION;
	addOnce = true;
	sinceStart = 0;
	working = true;
}

void MMedicine::Execute(MPlayer&mPlayer,double deltaTime)
{
	if (!working)
		return;

	if (addOnce)
	{
		AddHP(mPlayer);
		addOnce = false;
	}

	SetHotPoint(mPlayer.GetHotPoint());

	if (UpdateWorkingTime(deltaTime))
	{
		working = false;
		addOnce = true;
	}

}

bool MMedicine::UpdateWorkingTime(double deltaTime)
{
	sinceStart += deltaTime;
	if (sinceStart >= duration)
	{
		return true;
	}
	
	return false;
}

void MMedicine::AddHP(MPlayer& mPlayer)
{
	mPlayer.HPAdd(effect);
}

bool MMedicine::GetWorking()const
{
	return working;
}