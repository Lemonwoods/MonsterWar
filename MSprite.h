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
	
	void SetHotPoint(QPoint);//�����ȵ�����
	void SetNextHotPoint(QPoint);//���þ������һ�ȵ�����
	void SetCurrentPoint(QPoint);//���þ���ĵ�ǰλ��

	void CalculateNextHotPoint(double);//������ĳһ���Ƕ�λ��

	void UpdateXdYd();
	void UpdateHotPoint();//�����ȵ�����
	void UpdateCurrentPoint();//���µ�ǰ�㣨��������Ͻǣ��������
	QPoint GetHotPoint()const;//��þ�����ȵ�����
	QPoint GetNextHotPoint()const;
	QPoint GetCurrentPoint()const;
	
	void SetZ_Order(int);//���þ����Z������
	int GetZ_Order()const;

	void SetVisibility(bool);//���þ���Ŀɼ���
	bool GetVisibility()const;

	void SetSpeed(int);
	int GetSpeed()const;

	void SetWidth(int);
	void SetHeight(int);
	int GetWidth();//��þ���Ŀ��
	int GetHeight();//��þ���ĸ߶�
	
	void CalculateAngle(double, double);
	void SetAngle(double);//���þ������ת�Ƕ�
	double GetAngle()const;

	void SetImage(QImage);//����ͼ��
	void SetImage(QString);
	QImage GetImage()const;

	void SetScaleFactor(double, double);//���þ��������ϵ��
	double GetXScaleFactor()const;
	double GetYScaleFactor()const;

	bool IsCrashed(QPoint, int);
	void SetRedius(int);
	int GetRedius()const;

protected:

	double xd;//��ȷ��x��y�����ڼ���ʱ��С���
	double yd;

	QPoint currentPoint;//����ĵ�ǰλ��
	QPoint hotPoint;//�ȵ�����
	QPoint nextHotPoint;//�������һ���ȵ�λ�� 

	QImage image;//ͼƬ

	int Z_Order;//Z�����꣬���ھ�����Ⱦʱ�ĵ��Ӵ���

	int width;
	int height;

	int speed=0;//������ٶ�

	double xScaleFactor=1;//�����x��������ϵ��
	double yScaleFactor=1;//�����y��������ϵ��
	double angle=0;//������ת�ĽǶ�

	int redius;//���þ������ײ�뾶
	bool visibility = true;//���þ���Ŀɼ���
};

