#pragma once

#include"MCube.h"
#include"MPlayer.h"
#include"MMusicPlayer.h"

class MSpikerock :public MCube
{
public:
	MSpikerock();
	MSpikerock(int mAttack, double mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MSpikerock();

	void Construct(int mAttack, double mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMusicPlayer&mMusicPlayer,MPlayer&,double deltaTime);

	void SetAttack(int);
	int GetAttack()const;

	void SetAttackInterval(double);
	double GetAttackInterval()const;

	void SetSinceLastAttack(double);
	double GetSinceLastInterval()const;
private:
	int attack;
	double attackInterval;
	double sinceLastAttack;
};