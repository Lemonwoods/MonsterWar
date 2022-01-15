#pragma once

#include<qpainter.h>

#include"MSprite.h"

class MAnimationSprite :public MSprite
{
public:
	MAnimationSprite();
	MAnimationSprite(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MAnimationSprite();
	void Initial();

	void Update(double);
	void Render(QPainter&, QPaintDevice*);
	void RotateRender(QPainter&, QPaintDevice* );

	void SetXStart(int);
	void SetYStart(int);
	int GetXStart()const;
	int GetYStart()const;

	void SetXFrames(int);
	void SetYFrames(int);
	int GetXFrames()const;
	int GetYFrames()const;

	void CalculateInterval();
	double GetInterval()const;
	void SetFps(int);
	int GetFps()const;

	void SetFrames(int);
	int GetFrames()const;

	void SetCurrentFrame(int);
	int GetCurrentFrame()const;

	void Play();
	void Stop();
	bool GetPlay()const;

	void SetPlayMode(int);
	int GetPlayMode()const;

protected:
	int xStart;//�ض�����ĺ�����
	int yStart;//�ض������������
	int xFrames=1;//��¼���᷽���м�֡
	int yFrames=1;//��¼���᷽���м�֡

	double interval;//ÿһ֮֡��ļ��
	int fps;//֡��
	double sinceLastFrame=0;//����һ֡���˶��
	int frames;//�ܵ�֡��
	int currentFrame;//��ǰ��֡��

	bool play;//�Ƿ񲥷�
	short playMode;//����ģʽ ������ģʽ��1.ѭ������ 2.�������ͣ�������һ֡��
	//3.��ͬһ����ѭ�� 4.ͬһ�в��ź�ͣ���ڸ��е����һ֡��5.���ź󷵻ص�һ֡Ȼ��ֹͣ
	//6.��ͬһ�в��ź󷵻ظ��е�һ֡Ȼ��ֹͣ
};