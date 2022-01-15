#include"MMonster.h"

MMonster::MMonster()
{
	Play();
}
MMonster::MMonster(int mDistance, int mAttack, int mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	SetMovedDistance(0);
	SetSinceLastAttack(0);
	SetDistance(mDistance);
	SetAttack(mAttack);
	SetAttackInterval(mAttackInterval);
	SetExistence(true);
	Play();
}
MMonster::~MMonster()
{

}

void MMonster::Construct(int mDistance, int mAttack, int mAttackInterval, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{


	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	RandomDirection();
	SetSinceLastAttack(0);
	SetDistance(mDistance);
	SetAttack(mAttack);
	SetAttackInterval(mAttackInterval);
	SetExistence(true);
	SetHP(MONSTER_HP);
	Play();
}
void MMonster::Initial()
{
	MAnimationSprite::Initial();

	SetMovedDistance(0);
	SetSinceLastAttack(0);
	SetExistence(true);

	RandomDirection();

	SetAttack(MONSTER_ATTACK);
	SetSpeed(MONSTER_SPEED);
	SetHP(MONSTER_HP);
}

void MMonster::Execute(MMusicPlayer&mMusicPlayer,MMap& mMap, MPlayer& mPlayer,double deltaTime)
{
	if (!GetExistence())
	{
		return;
	}
	Move(mMap);
	AttackPlayer(mMusicPlayer,mPlayer, deltaTime);
	BeenShot(mMusicPlayer,mPlayer.bullet);

	frozen.Execute(*this, deltaTime);
}
void MMonster::Move(MMap& mMap)
{
	if (GetChangeDirection())
	{
		RandomDirection();
		SetMovedDistance(0);
		SetChangeDirection(false);
	}
	CalculateNextHotPoint(GetAngle());
	if (!IsHotPointValid(mMap))
	{
		SetChangeDirection(false);
		SetAngle(GetAngle() + 180);
	}
	else
	{
		UpdateHotPoint();
		MovedDistancePlus(speed);
	}	
	if (GetMovedDistance() >= GetDistance())
	{
		SetMovedDistance(0);
		SetChangeDirection(true);
	}
	
}
void MMonster::BeenShot(MMusicPlayer&mMusicPlayer,vector < MBullet>& mBullet)
{
	for (int i = 0; i < mBullet.size(); i++)
	{
		if(IsCrashed(mBullet[i].GetHotPoint(), mBullet[i].GetRedius()))
		{
			mBullet[i].SetFly(false);
			HPMinuse(mMusicPlayer,mBullet[i].GetAttack());
			if (GetHP() <= 0)
			{
				SetHP(0);
				SetExistence(false);
				SetVisibility(false);
			}

			if (mBullet[i].GetBulletMode() == BULLET_FROZEN)
			{
				SetMonsterMode(mBullet[i].GetBulletMode());
				mBullet[i].SetBulletMode(BULLET_NORMAL);

				if (monsterMode == BULLET_FROZEN)
				{
					frozen.SetWorking(true);
					frozen.SetVisibility(true);
				}
			}
			break;
		}
	}
}
void MMonster::RandomDirection()
{
	SetAngle(rand() % 360);
}
bool MMonster::IsHotPointValid(MMap& mMap)
{
	if (mMap.IsCrashedWithCube(GetNextHotPoint(),GetRedius()))
	{
		return false;
	}
	if (GetNextHotPoint().x() <= mMap.GetLeft() + 0.5 * GetWidth()
		|| GetNextHotPoint().x() >= mMap.GetRight() - 0.5 * GetWidth()
		|| GetNextHotPoint().y() <= mMap.GetTop() + 0.5 * GetHeight()
		|| GetNextHotPoint().y() >= mMap.GetButtom() - 0.5 * GetHeight())
	{
		return false;
	}
	return true;
}
void MMonster::AttackPlayer(MMusicPlayer&mMusicPlayer,MPlayer&mPlayer,double deltaTime)
{
	sinceLastAttack += deltaTime;
	if (sinceLastAttack >= attackInterval)
	{
		if (IsCrashed(mPlayer.GetHotPoint(), mPlayer.GetRedius()))
		{
			SetSinceLastAttack(0);
			mPlayer.HPMinuse(mMusicPlayer,attack);
		}
	}
}


void MMonster::RenderHPLabel(QPainter& mPainter,QPaintDevice*mPaintDevice)
{
	mPainter.begin(mPaintDevice);

	QPen pen;
	pen.setWidth(7);
	pen.setColor(QColor(241, 67, 101));
	pen.setCapStyle(Qt::RoundCap);

	mPainter.setPen(pen);

	mPainter.drawLine(GetCurrentPoint().x()+15, GetCurrentPoint().y() -10,
		GetCurrentPoint().x()+HP+15, GetCurrentPoint().y()-10);

	mPainter.end();
}

void MMonster::SetHP(int mHP)
{
	HP = mHP;
}
int MMonster::GetHP()const
{
	return HP;
}
void MMonster::HPMinuse(MMusicPlayer&mMusicPlayer,int m)
{
	mMusicPlayer.monsterHurt->play();
	HP -= m;
}

void MMonster::SetDistance(int mDistance)
{
	distance = mDistance;
}
int MMonster::GetDistance()const
{
	return distance;
}

void MMonster::MovedDistancePlus(int mDistance)
{
	movedDistance += mDistance;
}
void MMonster::SetMovedDistance(int mMovedDistance)
{
	movedDistance = mMovedDistance;
}
int MMonster::GetMovedDistance()const
{
	return movedDistance;
}

void MMonster::SetChangeDirection(bool mChangeDirection)
{
	changeDirection = mChangeDirection;
}
bool MMonster::GetChangeDirection()const
{
	return changeDirection;
}

void MMonster::SetAttack(double mAttack)
{
	attack = mAttack;
}
double MMonster::GetAttack()const
{
	return attack;
}

void MMonster::SetAttackInterval(double mAttackInterval)
{
	attackInterval = mAttackInterval;
}
double MMonster::GetAttackInterval()const
{
	return attackInterval;
}

void MMonster::SetSinceLastAttack(double mSinceLastAttack)
{
	sinceLastAttack = mSinceLastAttack;
}
double MMonster::GetSinceLastAttack()const
{
	return sinceLastAttack;
}

void MMonster::SetMonsterMode(int mMonsterMode)
{
	monsterMode = mMonsterMode;
}
int MMonster::GetMonsterMode()const
{
	return monsterMode;
}

void MMonster::SetExistence(bool mExistence)
{
	existence = mExistence;
}
bool MMonster::GetExistence()const
{
	return existence;
}