#include"MPropArray.h"

void MPropArray::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	propTemp.Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	sinceLastProp = 0;
	interval = PROP_INTERVAL;
	workingMode = NORMAL;
}
void MPropArray::Initial()
{
	sinceLastProp = 0;
	interval = PROP_INTERVAL;
	workingMode = NORMAL;
	prop.clear();
}

void MPropArray::Execute(MMap&mMap,MPlayer&mPlayer,double deltaTime)
{
	if (Update(deltaTime))
	{
		AddNewProp(mMap, mPlayer);
	}

	IsCrashed(mPlayer);

	if (workingMode == FROZEN || workingMode == BOMB)
	{
		mPlayer.SetNextBulletMode(workingMode);
		workingMode = NORMAL;
	}
}
void MPropArray::Render(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	for (int i = 0; i < prop.size(); i++)
	{
		prop[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}
}
void MPropArray::UpdateProp(double deltaTime)
{
	for (int i = 0; i < prop.size(); i++)
	{
		prop[i].Update(deltaTime);
	}
}

void MPropArray::LoadImage(QString mMedicine, QString mAccelerator,
	QString mFrozen, QString mBomb)
{
	propImage[0].load(mMedicine);
	propImage[1].load(mAccelerator);
	propImage[2].load(mFrozen);
	propImage[3].load(mBomb);
}
bool MPropArray::Update(double deltaTime)
{
	sinceLastProp += deltaTime;
	if (sinceLastProp >= interval)
	{
		sinceLastProp = 0;
		return true;
	}
	return false;
}
void MPropArray::AddNewProp(MMap&mMap,MPlayer&mPlayer)
{
	propTemp.RandomHotPoint(mMap,mPlayer);
	int modeNum = (rand() % 4) + 1;
	propTemp.SetMode(modeNum);
	propTemp.SetImage(propImage[modeNum - 1]);
	prop.push_back(propTemp);
}
void MPropArray::IsCrashed(MPlayer& mPlayer)
{
	for (int i = 0; i < prop.size(); )
	{
		if (prop[i].IsCrashed(mPlayer.GetHotPoint(), mPlayer.GetRedius()))
		{
			SetWorkingMode(prop[i].GetMode());
			itProp = prop.begin();
			itProp += i;
			prop.erase(itProp);
			return;
		}
		i++;
	}
}

void MPropArray::SetWorkingMode(int mWorkingMode)
{
	workingMode = mWorkingMode;
}
int MPropArray::GetWorkingMode()const
{
	return workingMode;
}