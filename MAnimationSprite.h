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
	int xStart;//截断坐标的横坐标
	int yStart;//截断坐标的纵坐标
	int xFrames=1;//记录横轴方向有几帧
	int yFrames=1;//记录纵轴方向有几帧

	double interval;//每一帧之间的间隔
	int fps;//帧率
	double sinceLastFrame=0;//自上一帧过了多久
	int frames;//总的帧数
	int currentFrame;//当前的帧数

	bool play;//是否播放
	short playMode;//播放模式 共四种模式：1.循环播放 2.播放完后停留在最后一帧，
	//3.在同一行中循环 4.同一行播放后停留在改行的最后一帧，5.播放后返回第一帧然后停止
	//6.在同一行播放后返回改行第一帧然后停止
};