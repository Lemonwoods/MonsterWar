#include"MProp.h"

void MProp::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
}
void MProp::Initial()
{

}

void MProp::RandomHotPoint(MMap& mMap, MPlayer& mPlayer)
{
	SetHotPoint(QPoint(rand() % 1920, rand() % 1080));
	while (!IsHotPointValid(mMap, mPlayer))
	{
		SetHotPoint(QPoint(rand() % 1920, rand() % 1080));
	}
}
bool MProp::IsHotPointValid(MMap& mMap, MPlayer& mPlayer)
{
	if (GetHotPoint().x() <= mMap.GetLeft() + 0.5 * GetWidth()
		|| GetHotPoint().x() >= mMap.GetRight() - 0.5 * GetWidth()
		|| GetHotPoint().y() <= mMap.GetTop() + 0.5 * GetHeight()
		|| GetHotPoint().y() >= mMap.GetButtom() - 0.5 * GetHeight())
	{
		return false;
	}

	if (mMap.IsCrashedWithCube(GetHotPoint(), GetWidth(), GetHeight()))
	{
		return false;
	}

	for (int i = 0; i < mMap.spikerock.size(); i++)
	{
		if (mMap.spikerock[i].IsCrashed(GetHotPoint(), GetWidth(), GetHeight()))
		{
			return false;
		}
	}

	if (IsCrashed(mPlayer.GetHotPoint(), 3 * mPlayer.GetRedius()))
	{
		return false;
	}
	
	return true;
}

void MProp::SetMode(int mMode)
{
	mode = mMode;
}
int MProp::GetMode()const
{
	return mode;
}