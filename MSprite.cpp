#include"MSprite.h"
#include<math.h>

MSprite::MSprite()
{

}
MSprite::MSprite(QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{	
	SetImage(mPath);
	width = mWidth;
	height = mHeight;
	speed = mSpeed;
	redius = mRedius;
	SetHotPoint(mHotPoint);
	SetNextHotPoint(mHotPoint);
	visibility = true;
}
void MSprite::Construct(QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius)
{	
	SetImage(mPath);
	width = mWidth;
	height = mHeight;
	speed = mSpeed;
	redius = mRedius;
	SetHotPoint(mHotPoint);
	SetNextHotPoint(mHotPoint);
	visibility = true;
}
MSprite::~MSprite()
{

}
void MSprite::Initial()
{
	visibility = true;
}

void MSprite::Render(QPainter& mpainter, QPaintDevice* mdevice)
{
	if (!visibility)
		return;
	mpainter.begin(mdevice);
	mpainter.drawImage(currentPoint, image);
	mpainter.end();
}
void MSprite::RotateRender(QPainter& mpainter, QPaintDevice* mdevice)
{
	if (!visibility)
		return;
	mpainter.begin(mdevice);
	mpainter.translate(currentPoint);
	mpainter.rotate(angle);
	mpainter.drawImage(currentPoint.x() - hotPoint.x(), currentPoint.y() - hotPoint.y(), image);
}

void MSprite::SetHotPoint(QPoint point)
{
	hotPoint = point;
	UpdateCurrentPoint();
	UpdateXdYd();
}
void MSprite::SetNextHotPoint(QPoint point)
{
	nextHotPoint = point;
}
void MSprite::SetCurrentPoint(QPoint point)
{
	currentPoint = point;
}

void MSprite::CalculateNextHotPoint(double angle)
{
	angle = ((double)angle / 180) * 3.1415926;

	xd = xd + speed * sin(angle);
	yd = yd - speed * cos(angle);

	nextHotPoint.setX(xd);
	nextHotPoint.setY(yd);
}

void MSprite::UpdateXdYd()
{
	xd = (double)hotPoint.x();
	yd = (double)hotPoint.y();
}
void MSprite::UpdateHotPoint()
{
	hotPoint = nextHotPoint;
	UpdateCurrentPoint();
}
void MSprite::UpdateCurrentPoint()
{
	currentPoint.setX(hotPoint.x() - 0.5 * width);
	currentPoint.setY(hotPoint.y() - 0.5 * height);
}

QPoint MSprite::GetHotPoint()const
{
	return hotPoint;
}
QPoint MSprite::GetNextHotPoint()const
{
	return nextHotPoint;
}
QPoint MSprite::GetCurrentPoint()const
{
	return currentPoint;
}

void MSprite::SetZ_Order(int Z)
{
	Z_Order = Z;
}
int MSprite::GetZ_Order()const
{
	return Z_Order;
}

void MSprite::SetVisibility(bool v)
{
	visibility = v;
}
bool MSprite::GetVisibility()const
{
	return visibility;
}

void MSprite::SetSpeed(int s)
{
	speed = s;
}
int MSprite::GetSpeed()const
{
	return speed;
}

void MSprite::SetWidth(int w)
{
	width = w;
}
void MSprite::SetHeight(int h)
{
	height = h;
}
int MSprite::GetWidth()
{
	return width;
}
int MSprite::GetHeight()
{
	return height;
}

void MSprite::CalculateAngle(double x, double y)
{
	double sinValue, cosValue;
	double anglePi;
	double lens_2 = pow((x - hotPoint.x()), 2) + pow((y - hotPoint.y()), 2);
	double lens = sqrt(lens_2);
	if (lens_2 == 0)
		return;
	if (lens <= speed)
		return;
	sinValue = (x - hotPoint.x()) / lens;
	cosValue = -(y - hotPoint.y()) / lens;

	anglePi = acos(cosValue);
	if (sinValue < 0)
	{
		anglePi = 2 * 3.1415926 - anglePi;
	}
	angle = anglePi * 180 / 3.1415926;
}
void MSprite::SetAngle(double a)
{
	angle = a;
}
double MSprite::GetAngle()const
{
	return angle;
}

void MSprite::SetImage(QImage ima)
{
	image = ima;
}
void MSprite::SetImage(QString str)
{
	image.load(str);
}
QImage MSprite::GetImage()const
{
	return image;
}

void MSprite::SetScaleFactor(double x, double y)
{
	xScaleFactor = x;
	yScaleFactor = y;
}
double MSprite::GetXScaleFactor()const
{
	return xScaleFactor;
}
double MSprite::GetYScaleFactor()const
{
	return yScaleFactor;
}

bool MSprite::IsCrashed(QPoint h, int r)
{
	double distance = pow(hotPoint.x() - h.x(), 2) + pow(hotPoint.y() - h.y(), 2);
	distance = sqrt(distance);
	if (distance <= r + redius)
		return true;
	else
		return false;
}
void MSprite::SetRedius(int r)
{
	redius = r;
}
int MSprite::GetRedius()const
{
	return redius;
}