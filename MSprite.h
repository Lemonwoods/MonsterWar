#pragma once
#include<qobject.h>
#include<qimage.h>
#include<qpainter.h>

class MSprite
{
public:
	MSprite();
	MSprite(QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MSprite();
	void Initial();

	void Render(QPainter&, QPaintDevice*);
	void RotateRender(QPainter&, QPaintDevice*);
	
	void SetHotPoint(QPoint);//设置热点坐标
	void SetNextHotPoint(QPoint);//设置精灵的下一热点坐标
	void SetCurrentPoint(QPoint);//设置精灵的当前位置

	void CalculateNextHotPoint(double);//朝着以某一个角度位移

	void UpdateXdYd();
	void UpdateHotPoint();//更新热点坐标
	void UpdateCurrentPoint();//更新当前点（对象的左上角）点的坐标
	QPoint GetHotPoint()const;//获得精灵的热点坐标
	QPoint GetNextHotPoint()const;
	QPoint GetCurrentPoint()const;
	
	void SetZ_Order(int);//设置精灵的Z轴坐标
	int GetZ_Order()const;

	void SetVisibility(bool);//设置精灵的可见性
	bool GetVisibility()const;

	void SetSpeed(int);
	int GetSpeed()const;

	void SetWidth(int);
	void SetHeight(int);
	int GetWidth();//获得精灵的宽度
	int GetHeight();//获得精灵的高度
	
	void CalculateAngle(double, double);
	void SetAngle(double);//设置精灵的旋转角度
	double GetAngle()const;

	void SetImage(QImage);//设置图像
	void SetImage(QString);
	QImage GetImage()const;

	void SetScaleFactor(double, double);//设置精灵的缩放系数
	double GetXScaleFactor()const;
	double GetYScaleFactor()const;

	bool IsCrashed(QPoint, int);
	void SetRedius(int);
	int GetRedius()const;

protected:

	double xd;//精确的x与y，用于计算时减小误差
	double yd;

	QPoint currentPoint;//精灵的当前位置
	QPoint hotPoint;//热点坐标
	QPoint nextHotPoint;//精灵的下一个热点位置 

	QImage image;//图片

	int Z_Order;//Z轴坐标，用于决定渲染时的叠加次序

	int width;
	int height;

	int speed=0;//精灵的速度

	double xScaleFactor=1;//精灵的x方向缩放系数
	double yScaleFactor=1;//精灵的y方向缩放系数
	double angle=0;//设置旋转的角度

	int redius;//设置精灵的碰撞半径
	bool visibility = true;//设置精灵的可见性
};

