#include"MMonsterArray.h"

MFrozen::MFrozen()
{

}
MFrozen::MFrozen(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	effect = FROZEN_EFFECT;
	duration = FROZEN_DURATION;
	sinceStart = 0;
	SetWorking(false);
	SetVisibility(false);
}

void MFrozen::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);

	effect = FROZEN_EFFECT;
	duration = FROZEN_DURATION;
	sinceStart = 0;
	SetWorking(false);
	SetVisibility(false);
}
void MFrozen::Initial()
{
	effect = FROZEN_EFFECT;
	duration = FROZEN_DURATION;
	sinceStart = 0;
	SetWorking(false);
	SetVisibility(false);
}

void MFrozen::Execute(MMonster& mMonster, double deltaTime)
{
	if (!working)
		return;

	MinuseSpeed(mMonster);
	SetHotPoint(mMonster.GetHotPoint());
	if (Update(deltaTime))
	{
		AddSpeed(mMonster);
		sinceStart = 0;
		SetWorking(false);
		SetVisibility(false);
	}
}

void MFrozen::MinuseSpeed(MMonster& mMonster)
{
	mMonster.SetSpeed(MONSTER_SPEED - FROZEN_EFFECT);
}
void MFrozen::AddSpeed(MMonster& mMonster)
{
	mMonster.SetSpeed(MONSTER_SPEED);
}

bool MFrozen::Update(double deltaTime)
{
	sinceStart += deltaTime;
	if (sinceStart >= duration)
	{
		sinceStart = 0;
		return true;
	}

	return false;
}

void MFrozen::SetWorking(bool mWorking)
{
	working = mWorking;
}
bool MFrozen::GetWorking()const
{
	return working;
}