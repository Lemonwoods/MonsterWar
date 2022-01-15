#include"MMap.h"

MMap::MMap()
{

}
MMap::MMap(int mLeft, int mTop, int mRight, int mButtom, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MAnimationSprite(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	SetLeft(mLeft);
	SetTop(mTop);
	SetRight(mRight);
	SetButtom(mButtom);
}
MMap::~MMap()
{

}

void MMap::Construct(int mLeft, int mTop, int mRight, int mButtom, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MAnimationSprite::Construct(mXStart, mYStart, mXFrames, mYFrames, mFps, mFrames, mMode, mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	SetLeft(mLeft);
	SetTop(mTop);
	SetRight(mRight);
	SetButtom(mButtom);
}
void MMap::Initial()
{
	brickTemp.Initial();
	iceTemp.Initial();
	jellyTemp.Initial();
	spikerockTemp.Initial();

	for (int i = 0; i < brick.size(); i++)
	{
		brick[i].Initial();
	}
	for (int i = 0; i < ice.size(); i++)
	{
		ice[i].Initial();
	}
	for (int i = 0; i < jelly.size(); i++)
	{
		jelly[i].Initial();
	}
	for (int i = 0; i < spikerock.size(); i++)
	{
		spikerock[i].Initial();
	}
}
void MMap::Clear()
{
	brick.clear();
	ice.clear();
	jelly.clear();
	spikerock.clear();
}

void MMap::DefaultMap()
{
	brickTemp.SetHotPoint(QPoint(520, 170));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(520, 230));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(520, 290));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(520, 350));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(520, 410));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(520, 470));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(760, 470));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(700, 470));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1180, 230));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1240, 230));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1300, 230));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1360, 230));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1360, 260));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1360, 320));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1360, 380));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1360, 440));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(1360, 500));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(580, 170));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(640, 170));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(700, 170));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(760, 170));
	brick.push_back(brickTemp);
	brickTemp.SetHotPoint(QPoint(820, 170));
	brick.push_back(brickTemp);

	iceTemp.SetHotPoint(QPoint(580, 470));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(580, 530));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(580, 590));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(580, 590));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(640, 590));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(700, 590));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(940, 290));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(880, 290));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(820, 290));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(760, 350));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1180, 710));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1180, 590));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1180, 650));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1120, 710));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1060, 710));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1000, 710));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(640, 470));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(700, 830));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(700, 890));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(760, 830));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(820, 830));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(880, 830));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(820, 890));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(940, 830));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(940, 890));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1000, 830));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1060, 890));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1360, 560));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1360, 620));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1360, 680));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1360, 740));
	ice.push_back(iceTemp);
	iceTemp.SetHotPoint(QPoint(1360, 800));
	ice.push_back(iceTemp);

	jellyTemp.SetHotPoint(QPoint(880, 650));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(940, 710));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1180, 410));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1180, 470));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1180, 530));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1000, 290));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1000, 350));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1300, 830));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1360, 830));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(1240, 890));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(580, 650));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(640, 650));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(580, 710));
	jelly.push_back(jellyTemp);
	jellyTemp.SetHotPoint(QPoint(640, 710));
	jelly.push_back(jellyTemp);

	spikerockTemp.SetHotPoint(QPoint(700, 650));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(700, 710));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(700, 770));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(1120, 530));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(1120, 590));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(1120, 650));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 530));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 590));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 650));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 710));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 770));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 830));
	spikerock.push_back(spikerockTemp);
	spikerockTemp.SetHotPoint(QPoint(520, 890));
	spikerock.push_back(spikerockTemp);
}

void MMap::RenderMap(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	MAnimationSprite::Render(mPainter, mPaintDevice);
}
void MMap::RenderCube(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	for (int i = 0; i < brick.size(); i++)
	{
		brick[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}
	for (int i = 0; i < ice.size(); i++)
	{
		ice[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}
	for (int i = 0; i < jelly.size(); i++)
	{
		jelly[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}
	for (int i = 0; i < spikerock.size(); i++)
	{
		spikerock[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}
}

void MMap::UpdateCube(double deltaTime)
{
	for (int i = 0; i < brick.size(); i++)
	{
		brick[i].Update(deltaTime);
	}
	for (int i = 0; i < ice.size(); i++)
	{
		ice[i].Update(deltaTime);
	}
	for (int i = 0; i < jelly.size(); i++)
	{
		jelly[i].Update(deltaTime);
	}
	for (int i = 0; i < spikerock.size(); i++)
	{
		spikerock[i].Update(deltaTime);
	}
}
void MMap::ExecuteCube(MMusicPlayer&mMusicPlayer,MPlayer&mPlayer, vector<MBullet>& mBullet,double deltaTime)
{
	for (int i = 0; i < brick.size(); i++)
	{
		brick[i].Execute(mMusicPlayer,mBullet);
	}
	for (int i = 0; i < ice.size(); i++)
	{
		ice[i].Execute(mMusicPlayer,mBullet);
	}
	for (int i = 0; i < jelly.size(); i++)
	{
		jelly[i].Execute(mMusicPlayer,mBullet);
	}
	for (int i = 0; i < spikerock.size(); i++)
	{
		spikerock[i].Execute(mMusicPlayer,mPlayer,deltaTime);
	}
}
bool MMap::IsCrashedWithCube(QPoint mHotPoint, int mWidth,int mHeight)
{
	for (int i = 0; i < brick.size(); i++)
	{
		if (brick[i].MCube::IsCrashed(mHotPoint, mWidth, mHeight))
			return true;
	}
	for (int i = 0; i < ice.size(); i++)
	{
		if (ice[i].MCube::IsCrashed(mHotPoint, mWidth, mHeight))
			return true;
	}
	for (int i = 0; i < jelly.size(); i++)
	{
		if (jelly[i].MCube::IsCrashed(mHotPoint, mWidth, mHeight))
			return true;
	}
	return false;
}
bool MMap::IsCrashedWithCube(QPoint mHotPoint, int mRedius)
{
	for (int i = 0; i < brick.size(); i++)
	{
		if (brick[i].MSprite::IsCrashed(mHotPoint,mRedius))
			return true;
	}
	for (int i = 0; i < ice.size(); i++)
	{
		if (ice[i].MSprite::IsCrashed(mHotPoint, mRedius))
			return true;
	}
	for (int i = 0; i < jelly.size(); i++)
	{
		if (jelly[i].MSprite::IsCrashed(mHotPoint, mRedius))
			return true;
	}
	return false;
}

void MMap::AddBrick(QPoint mHotPoint)
{
	brickTemp.SetHotPoint(mHotPoint);
	brick.push_back(brickTemp);
}
void MMap::AddIce(QPoint mHotPoint)
{
	iceTemp.SetHotPoint(mHotPoint);
	ice.push_back(iceTemp);
}
void MMap::AddJelly(QPoint mHotPoint)
{
	jellyTemp.SetHotPoint(mHotPoint);
	jelly.push_back(jellyTemp);
}
void MMap::AddSpikerock(QPoint mHotPoint)
{
	spikerockTemp.SetHotPoint(mHotPoint);
	spikerock.push_back(spikerockTemp);
}

void MMap::SetLeft(int mLeft)
{
	left = mLeft;
}
void MMap::SetTop(int mTop)
{
	top = mTop;
}
void MMap::SetRight(int mRight)
{
	right = mRight;
}
void MMap::SetButtom(int mButtom)
{
	buttom = mButtom;
}
int MMap::GetLeft()const
{
	return left;
}
int MMap::GetTop()const
{
	return top;
}
int MMap::GetRight()const
{
	return right;
}
int MMap::GetButtom()const
{
	return buttom;
}