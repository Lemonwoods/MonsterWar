#pragma once


#include"MAnimationSprite.h"
#include"MDefine.h"

class MBullet :public MAnimationSprite
{
public:
	MBullet();
    MBullet(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MBullet();
	void Initial();

	void CalculateNextHotPoint();

	void IsInWindow(int mLeft,int mTop, int mRight,int mButtom);

	void SetAttack(int mAttack);
	int GetAttack()const;

	void SetDirection(double);
	double GetDirection()const;

	void SetFly(bool);
	bool GetFly()const;

	void SetBulletMode(int mBulletMode);
	int GetBulletMode()const;

	void SetBounce(int mBounce);
	void BouncePlus(int p);
	int GetBounce()const;

private:
	int attack;

	int bounce;
	double direction;
	bool fly;

	int bulletMode;
};