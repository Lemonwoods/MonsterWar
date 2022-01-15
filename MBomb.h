#pragma once

#include"MDefine.h"
#include"MMonsterArray.h"
#include"MMusicPlayer.h"

class MBomb:public MAnimationSprite
{
public:
	MBomb();
	MBomb(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMusicPlayer&mMusicPlayer,MMonsterArray& mMonsterArray,double deltaTime);

	void IsCrashed(MMonsterArray& mMonsterArray);
	void EnlargeRedius();

	bool Update(double deltaTime);//返回true代表时间到了

	void SetWorking(bool mWorking);
	bool GetWorking()const;

private:
	int maxRedius;
	double duration;
	double sinceStart;

	bool working;

	bool playMusic;
};