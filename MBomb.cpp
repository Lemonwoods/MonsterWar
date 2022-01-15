#include"MBomb.h"

MBomb::MBomb()
{

}
MBomb::MBomb(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	maxRedius = BOMB_MAX_REDIUS;
	duration = BOMB_DURATION;
	sinceStart = 0;
	SetWorking(true);
	playMusic = true;
}

void MBomb::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	maxRedius = BOMB_MAX_REDIUS;
	duration = BOMB_DURATION;
	sinceStart = 0;
	SetWorking(true);
	playMusic = true;
}
void MBomb::Initial()
{
	maxRedius = BOMB_MAX_REDIUS;
	duration = BOMB_DURATION;
	sinceStart = 0;
	SetWorking(true);
	playMusic = true;
}

void MBomb::Execute(MMusicPlayer&mMusicPlayer,MMonsterArray& mMonsterArray,double deltaTime)
{
	if (!working)
		return;

	if (playMusic)
	{
		mMusicPlayer.bomb->play();
		playMusic = false;
	}

	IsCrashed(mMonsterArray);
	//EnlargeRedius();

	if (Update(deltaTime))
	{
		working = false;
	}
}

void MBomb::IsCrashed(MMonsterArray& mMonsterArray)
{
	for (int i = 0; i < mMonsterArray.monster.size(); i++)
	{
		if (MAnimationSprite::IsCrashed(mMonsterArray.monster[i].GetHotPoint(),
			mMonsterArray.monster[i].GetRedius()))
		{
			mMonsterArray.monster[i].SetExistence(false);
		}
	}
}
void MBomb::EnlargeRedius()
{
	int rate = 2 * sinceStart;
	if (rate > 1)
	{
		rate = 1;
	}

	SetRedius((double)rate * (double)maxRedius);
}

bool MBomb::Update(double deltaTime)
{
	sinceStart += deltaTime;

	if (sinceStart >= duration)
	{
		sinceStart = 0;
		return true;
	}
	
	return false;
}

void MBomb::SetWorking(bool mWorking)
{
	working = mWorking;
}
bool MBomb::GetWorking()const
{
	return working;
}