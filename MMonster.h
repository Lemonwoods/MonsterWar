#pragma once

#include<stdlib.h>
#include<qlabel.h>

#include"MAnimationSprite.h"
#include"MDefine.h"
#include"MMap.h"
#include"MPlayer.h"
#include"MMusicPlayer.h"

class MMonster;

class MFrozen:public MAnimationSprite
{
public:
	MFrozen();
	MFrozen(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMonster& mMonster, double deltaTime);

	void MinuseSpeed(MMonster& mMonster);
	void AddSpeed(MMonster& mMonster);

	bool Update(double deltaTime);

	void SetWorking(bool mWorking);
	bool GetWorking()const;

private:
	int effect;
	double duration;
	double sinceStart;

	bool working;
};

class MMonster :public MAnimationSprite
{
public:
	MMonster();
	MMonster(int mDistance,int mAttack,int mAttackInterval,int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MMonster();

	void Construct(int mDistance, int mAttack, int mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMusicPlayer&mMusicPlayer,MMap& mMap, MPlayer& mPlayer,double deltaTime);
	void Move(MMap& mMap);
	void BeenShot(MMusicPlayer&mMusicPlayer,vector < MBullet>& mBullet);
	void RandomDirection();
	bool IsHotPointValid(MMap&mMap);
	void AttackPlayer(MMusicPlayer& mMusicPlayer, MPlayer& mPlayer, double deltaTime);

	void RenderHPLabel(QPainter&mPainter,QPaintDevice*mPaintDevice);

	void SetDistance(int mDistance);
	int GetDistance()const;

	void MovedDistancePlus(int mDistance);
	void SetMovedDistance(int mMovedDistance);
	int GetMovedDistance()const;

	void SetHP(int mHP);
	int GetHP()const;
	void HPMinuse(MMusicPlayer&mMusicPlayer,int m);

	void SetChangeDirection(bool mChangeDirection);
	bool GetChangeDirection()const;

	void SetAttack(double mAttack);
	double GetAttack()const;

	void SetAttackInterval(double mAttackInterval);
	double GetAttackInterval()const;

	void SetSinceLastAttack(double mSinceLastAttack);
	double GetSinceLastAttack()const;

	void SetMonsterMode(int mMonsterMode);
	int GetMonsterMode()const;

	void SetExistence(bool mExistence);
	bool GetExistence()const;

	MFrozen frozen;

private:

	int HP;

	int distance;
	int movedDistance;

	bool changeDirection;

	double attack;
	double attackInterval;
	double sinceLastAttack;

	int monsterMode;

	bool existence;
};
