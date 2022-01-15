#include"MJelly.h"

MJelly::MJelly()
{

}
MJelly::MJelly(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MCube(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	play = false;
}
MJelly::~MJelly()
{

}

void MJelly::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MCube::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	play = false;
}
void MJelly::Initial()
{
	MCube::Initial();
}

void MJelly::Execute(MMusicPlayer&mMusicPlayer,vector<MBullet>& mBullet)
{
	for (int i = 0; i<mBullet.size(); i++)
	{
		if (MSprite::IsCrashed(mBullet[i].GetHotPoint(), mBullet[i].GetRedius()))
		{
			mMusicPlayer.jelly->play();

			{
				mBullet[i].BouncePlus(1);
				if (mBullet[i].GetBounce() >= BULLET_BOUNCE)
				{
					mBullet[i].SetFly(false);
				}
			}

			play = true;
			switch (CalculateDirection(mBullet[i]))
			{
			case UP:
				if (mBullet[i].GetDirection() <= 180)
				{
					mBullet[i].SetDirection(180 - mBullet[i].GetDirection());
				}
				else
				{
					mBullet[i].SetDirection(540 - mBullet[i].GetDirection());
				}

				SetCurrentFrame(0);

				break;
			case DOWN:
				if (mBullet[i].GetDirection() <= 180)
				{
					mBullet[i].SetDirection(180 - mBullet[i].GetDirection());
				}
				else
				{
					mBullet[i].SetDirection(540 - mBullet[i].GetDirection());
				}

				SetCurrentFrame(50);

				break;
			case RIGHT:
				mBullet[i].SetDirection(360 - mBullet[i].GetDirection());

				SetCurrentFrame(100);

				break;
			case LEFT:
				mBullet[i].SetDirection(360 - mBullet[i].GetDirection());

				SetCurrentFrame(150);

				break;
			}
		}
	}
}

int MJelly::CalculateDirection(MBullet& mBullet)
{
	if ((mBullet.GetHotPoint().y()<hotPoint.y())&&(mBullet.GetDirection()>90&&mBullet.GetDirection()<270))
	{
		return UP;
	}
	else if ((mBullet.GetHotPoint().y() > hotPoint.y()) && (mBullet.GetDirection() < 90 || mBullet.GetDirection() > 270))
	{
		return DOWN;
	}
	else if ((mBullet.GetHotPoint().x() > hotPoint.x()) && (mBullet.GetDirection() > 180 && mBullet.GetDirection() < 360))
	{
		return RIGHT;
	}
	else if ((mBullet.GetHotPoint().x() < hotPoint.x()) && (mBullet.GetDirection() < 180 && mBullet.GetDirection() > 0))
	{
		return LEFT;
	}
}