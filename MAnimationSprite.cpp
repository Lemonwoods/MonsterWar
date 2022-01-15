#include"MAnimationSprite.h"


MAnimationSprite::MAnimationSprite()
{

}
MAnimationSprite::MAnimationSprite(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
	:MSprite(mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius)
{
	xStart = mXStart;
	yStart = mYStart;
	xFrames = mXFrames;
	yFrames = mYFrames;
	fps = mFps;
	CalculateInterval();
	frames = mFrames;
	playMode = mMode;
	currentFrame = 0;
	sinceLastFrame = 0;
	play = false;
}
void MAnimationSprite::Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{
	MSprite::Construct(mHotPoint, mPath, mWidth, mHeight, mSpeed, mRedius);
	xStart = mXStart;
	yStart = mYStart;
	xFrames = mXFrames;
	yFrames = mYFrames;
	fps = mFps;
	CalculateInterval();
	frames = mFrames;
	playMode = mMode;
	currentFrame = 0;
	sinceLastFrame = 0;
	play = false;
}
MAnimationSprite::~MAnimationSprite()
{

}
void MAnimationSprite::Initial()
{
	MSprite::Initial();

	currentFrame = 0;
	sinceLastFrame = 0;
	play = false;
}

void MAnimationSprite::Update(double deltaTime)
{
	if (!play)
	{
		return;
	}
	sinceLastFrame += deltaTime;
	if (sinceLastFrame >= interval)
	{
		sinceLastFrame = 0;
		SetCurrentFrame(currentFrame + 1);
	}
}
void MAnimationSprite::Render(QPainter& mpainter, QPaintDevice* mdevice)
{
	if (!visibility)
		return;
	mpainter.begin(mdevice);
	mpainter.drawImage(currentPoint.x(),currentPoint.y(), image,xStart,yStart,width,height);
	mpainter.end();
}
void MAnimationSprite::RotateRender(QPainter& mpainter, QPaintDevice* mdevice)
{
	if (!visibility)
		return;
	mpainter.begin(mdevice);
	mpainter.translate(hotPoint);
	mpainter.rotate(angle);
	mpainter.drawImage(currentPoint.x()-hotPoint.x(), currentPoint.y()-hotPoint.y(), image, xStart, yStart, width, height);
	mpainter.rotate(0);
	mpainter.translate(0, 0);
	mpainter.end();
}


void MAnimationSprite::SetXStart(int x)
{
	xStart = x;
}
void MAnimationSprite::SetYStart(int y)
{
	yStart = y;
}
int MAnimationSprite::GetXStart()const
{
	return xStart;
}
int MAnimationSprite::GetYStart()const
{
	return yStart;
}

void MAnimationSprite::SetXFrames(int xf)
{
	xFrames = xf;
}
void MAnimationSprite::SetYFrames(int yf)
{
	yFrames = yf;
}
int MAnimationSprite::GetXFrames()const
{
	return xFrames;
}
int MAnimationSprite::GetYFrames()const
{
	return yFrames;
}

void MAnimationSprite::CalculateInterval()
{
	interval = (double)1.0 / fps;
}
double MAnimationSprite::GetInterval()const
{
	return interval;
}
void MAnimationSprite::SetFps(int f)
{
	fps = f;
	CalculateInterval();
}
int MAnimationSprite::GetFps()const
{
	return fps;
}

void MAnimationSprite::SetFrames(int f)
{
	frames = f;
}
int MAnimationSprite::GetFrames()const
{
	return frames;
}

void MAnimationSprite::SetCurrentFrame(int c)
{
	switch (playMode)
	{
	case 1:
		if (c >= frames)
		{
			currentFrame = 0;
		}
		else
		{
			currentFrame = c;
		}
		break;
	case 2:
		if (c >= frames)
		{
			currentFrame = frames-1;
			Stop();
		}
		else
		{
			currentFrame = c;
		}
		break;
	case 3:
		if (currentFrame % xFrames == xFrames-1)
		{
			Stop();
		}
		else
		{
			currentFrame = c;
		}
		break;
	case 4:
		if (currentFrame % xFrames == xFrames-1)
		{
			currentFrame -= (xFrames - 1);
		}
		else
		{
			currentFrame = c;
		}
		break;
	case 5:
		if (c >= frames)
		{
			currentFrame = 0;
			Stop();
		}
		else
		{
			currentFrame = c;
		}
		break;
	case 6:
		if (currentFrame % xFrames == xFrames - 1)
		{
			currentFrame -= (xFrames - 1);
			Stop();
		}
		else
		{
			currentFrame = c;
		}
		break;
	default:
		currentFrame = c;
	}
	int xf = currentFrame % xFrames;
	int yf = currentFrame / xFrames;

	xStart = xf * width;
	yStart = yf * height;
}
int MAnimationSprite::GetCurrentFrame()const
{
	return currentFrame;
}

void MAnimationSprite::Play()
{
	play = true;
}
void MAnimationSprite::Stop()
{
	play = false;
}
bool MAnimationSprite::GetPlay()const
{
	return play;
}

void MAnimationSprite::SetPlayMode(int m)
{
	playMode = m;
}
int MAnimationSprite::GetPlayMode()const
{
	return playMode;
}