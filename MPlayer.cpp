#include"MPlayer.h"

#include<qdebug.h>

MPlayer::MPlayer()
{
	
}
MPlayer::MPlayer(int mHP, int mArmor, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MSprite(mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	SetHP(mHP);
	SetArmor(mArmor);
	playerButtom.Stop();
	playerTop.Stop();
	Run();
	SetDirection(STOP);
	nextBulletMode = BULLET_NORMAL;
}
void MPlayer::Construct(int mHP, int mArmor, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MSprite::Construct(mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	SetHP(mHP);
	SetArmor(mArmor);
	playerButtom.Stop();
	playerTop.Stop();
	Run();
	SetDirection(STOP);
	nextBulletMode = BULLET_NORMAL;
}
MPlayer::~MPlayer()
{

}
void MPlayer::Initial()
{
	MSprite::Initial();

	playerTop.Initial();
	playerButtom.Initial();
	bulletTemp.Initial();

	SetDirection(STOP);
	SetHP(PLAYER_HP);
	SetArmor(PLAYER_ARMOR);
	SetSpeed(PLAYER_SPEED);
	nextBulletMode = BULLET_NORMAL;

	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].Initial();
	}
}

void MPlayer::Execute(int mkey)
{
	switch (mkey)
	{
		////玩家的四个移动方向
	case Qt::Key_W:
		playerButtom.Play();
		SetDirection(UP);
		break;
	case Qt::Key_S:
		playerButtom.Play();
		SetDirection(DOWN);
		break;
	case Qt::Key_A:
		playerButtom.Play();
		SetDirection(LEFT);
		break;
	case Qt::Key_D:
		playerButtom.Play();
		SetDirection(RIGHT);
		break;
	case Qt::Key_R://发射子弹
		if (!playerTop.GetPlay())
			playerTop.Play();
		break;
	}
	Move();
}
void MPlayer::Move()
{
	if (!move)
		return;
	switch (direction)
	{
	case UP:
		SetNextHotPoint(QPoint(GetHotPoint().x(), GetHotPoint().y() - speed));
		playerButtom.SetAngle(0);
		break;
	case DOWN:
		SetNextHotPoint(QPoint(GetHotPoint().x(), GetHotPoint().y() + speed));
		playerButtom.SetAngle(180);
		break;
	case LEFT:
		SetNextHotPoint(QPoint(GetHotPoint().x() - speed, GetHotPoint().y()));
		playerButtom.SetAngle(270);
		break;
	case RIGHT:
		SetNextHotPoint(QPoint(GetHotPoint().x() + speed, GetHotPoint().y()));
		playerButtom.SetAngle(90);
		break;
	}

}
void MPlayer::ShootBullet(MMusicPlayer& mMusicPlayer, int mLeft, int mTop, int mRight, int mButtom)
{
	if (playerTop.GetShoot())
	{
		if (GetNextBulletMode() != BULLET_NORMAL)
		{
			bulletTemp.SetBulletMode(GetNextBulletMode());
		}

		bulletTemp.SetFly(true);
		bulletTemp.SetDirection(playerTop.GetAngle());
		bulletTemp.SetAngle(playerTop.GetAngle());
		bulletTemp.SetHotPoint(GetHotPoint());
		bullet.push_back(bulletTemp);

		mMusicPlayer.shootBullet->play();

		if (GetNextBulletMode() != BULLET_NORMAL)
		{
			bulletTemp.SetBulletMode(BULLET_NORMAL);
			SetNextBulletMode(BULLET_NORMAL);
		}

		playerTop.NotShoot();
	}
	for (int i = 0; i < bullet.size();)
	{
		if (bullet[i].GetFly())
		{
			bullet[i].CalculateNextHotPoint();
			bullet[i].UpdateHotPoint();
			bullet[i].IsInWindow(mLeft,mTop,mRight,mButtom);
			i++;
		}
		else
		{
			if (bullet[i].GetBulletMode() == BULLET_BOMB)
			{
				bombBulletWorking = true;
				bombHotPoint = bullet[i].GetHotPoint();
			}

			itBullet = bullet.begin();
			itBullet += i;
			bullet.erase(itBullet);
		}
	}
}
void MPlayer::RenderBullet(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].MAnimationSprite::RotateRender(mPainter, mPaintDevice);
	}
}
void MPlayer::UpdateBullet(double deltaTime)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].Update(deltaTime);
	}
}
bool MPlayer::IsHotPointValid(int mLeft, int mTop, int mRight, int mButtom)
{
	if (GetNextHotPoint().x() <= mLeft + 0.5 * GetWidth()
		|| GetNextHotPoint().x() >= mRight - 0.5 * GetWidth()
		|| GetNextHotPoint().y() <= mTop + 0.5 * GetHeight()
		|| GetNextHotPoint().y() >= mButtom - 0.5 * GetHeight())
	{
		return false;
	}
	return true;
}

void MPlayer::SetDirection(int d)
{
	direction = d;
}
int MPlayer::GetDirection()const
{
	return direction;
}
void MPlayer::SetHotPoint(QPoint hot)
{
	MSprite::SetHotPoint(hot);
	playerTop.SetHotPoint(hot);
	playerButtom.SetHotPoint(hot);
}
void MPlayer::SetNextHotPoint(QPoint point)
{
	MSprite::SetNextHotPoint(point);
	playerTop.SetNextHotPoint(point);
	playerButtom.SetNextHotPoint(point);
}
void MPlayer::UpdateHotPoint()
{
	MSprite::UpdateHotPoint();
	playerTop.UpdateHotPoint();
	playerButtom.UpdateHotPoint();
}

void MPlayer::HPAdd(int mHP)
{
	HP += mHP;
	if (HP > PLAYER_HP)
	{
		HP = PLAYER_HP;
	}
}
void MPlayer::HPMinuse(MMusicPlayer&mMusicPlayer,int mHP)
{
	mMusicPlayer.playerHurt->play();
	int temp = mHP - armor;
	if (temp <= 0)
	{
		temp = 1;
	}
	HP -= temp;
}
void MPlayer::SetHP(int hp)
{
	HP = hp;
}
int MPlayer::GetHP()const
{
	return HP;
}

void MPlayer::SetArmor(int a)
{
	armor = a;
}
int MPlayer::GetArmor()const
{
	return armor;
}

bool MPlayer::GetMove()const
{
	return move;
}
void MPlayer::Run()
{
	move = true;
}
void MPlayer::Stand()
{
	move = false;
}

void MPlayer::SetNextBulletMode(int mNextBulletMode)
{
	nextBulletMode = mNextBulletMode;
}
int MPlayer::GetNextBulletMode()const
{
	return nextBulletMode;
}

void MPlayer::SetBombBulletWorking(bool mBombBulletWorking)
{
	bombBulletWorking = mBombBulletWorking;
}
bool MPlayer::GetBombBulletWorking()const
{
	return bombBulletWorking;
}

QPoint MPlayer::GetBombHotPoint()const
{
	return bombHotPoint;
}