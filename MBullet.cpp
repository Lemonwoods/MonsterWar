#include"MBullet.h"

MBullet::MBullet()
{
	
}
MBullet::MBullet(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	play = true;
	fly = false;
	direction = 0;
	bulletMode = BULLET_NORMAL;
	bounce = 0;
}
void MBullet::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	play = true;
	fly = false;
	direction = 0;
	SetAttack(BULLET_ATTACK);
	bulletMode = BULLET_NORMAL;
	bounce = 0;
}
MBullet::~MBullet()
{

}
void MBullet::Initial()
{
	MAnimationSprite::Initial();

	play = true;
	fly = false;
	direction = 0;
	SetAttack(BULLET_ATTACK);
	bulletMode = BULLET_NORMAL;
	bounce = 0;
}

void MBullet::CalculateNextHotPoint()
{
	MSprite::CalculateNextHotPoint(direction);
}

void MBullet::IsInWindow(int mLeft, int mTop, int mRight, int mButtom)
{
	if ((hotPoint.x() < mLeft) 
		|| (hotPoint.y() < mTop) 
		|| (currentPoint.x() >mRight) 
		|| (currentPoint.y() >mButtom))
	{
		fly=false;
	}
}

void MBullet::SetAttack(int mAttack)
{
	attack = mAttack;
}
int MBullet::GetAttack()const
{
	return attack;
}

void MBullet::SetDirection(double d)
{
	direction = d;
}
double MBullet::GetDirection()const
{
	return direction;
}

void MBullet::SetFly(bool f)
{
	fly = f;
}
bool MBullet::GetFly()const
{
	return fly;
}

void MBullet::SetBulletMode(int mBulletMode)
{
	bulletMode = mBulletMode;
}
int MBullet::GetBulletMode()const
{
	return bulletMode;
}

void MBullet::SetBounce(int mBounce)
{
	bounce = mBounce;
}
void MBullet::BouncePlus(int p)
{
	bounce += p;
}
int MBullet::GetBounce()const
{
	return bounce;
}