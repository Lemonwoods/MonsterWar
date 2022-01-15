#include"MSpikerock.h"

MSpikerock::MSpikerock()
{

}
MSpikerock::MSpikerock(int mAttack, double mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MCube(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	attack = mAttack;
	attackInterval = mAttackInterval;
	sinceLastAttack = 0;
}
MSpikerock::~MSpikerock()
{

}

void MSpikerock::Construct(int mAttack, double mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MCube::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	attack = mAttack;
	attackInterval = mAttackInterval;
	sinceLastAttack = 0;
}
void MSpikerock::Initial()
{
	MCube::Initial();

	sinceLastAttack = 0;
}

void MSpikerock::Execute(MMusicPlayer&mMusicPlayer,MPlayer& mPlayer,double deltaTime)
{
	sinceLastAttack += deltaTime;
	if (sinceLastAttack >= attackInterval)
	{		
		if (MCube::IsCrashed(mPlayer.GetHotPoint(), mPlayer.GetWidth(), mPlayer.GetHeight()))
		{
			sinceLastAttack = 0;
			mPlayer.HPMinuse(mMusicPlayer,attack);
		}
	}
}

void MSpikerock::SetAttack(int mAttack)
{
	attack = mAttack;
}
int MSpikerock::GetAttack()const
{
	return attack;
}

void MSpikerock::SetAttackInterval(double mAttackInterval)
{
	attackInterval = mAttackInterval;
}
double MSpikerock::GetAttackInterval()const
{
	return attackInterval;
}

void MSpikerock::SetSinceLastAttack(double mSinceLastAttack)
{
	sinceLastAttack = mSinceLastAttack;
}
double MSpikerock::GetSinceLastInterval()const
{
	return sinceLastAttack;
}
