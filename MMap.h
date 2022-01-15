#pragma once

#include<vector>

#include"MDefine.h"
#include"MBrick.h"
#include"MIce.h"
#include"MJelly.h"
#include"MSpikerock.h"
#include"MPlayer.h"
#include"MMusicPlayer.h"

using namespace std;

class MMap :public MAnimationSprite
{
public:
	MMap();
	MMap(int mLeft,int mTop,int mRight, int mButtom, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MMap();

	void Construct(int mLeft, int mTop, int mRight, int mButtom, int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();
	void Clear();

	void DefaultMap();

	void RenderMap(QPainter&, QPaintDevice*);
	void RenderCube(QPainter&, QPaintDevice*);

	void UpdateCube(double deltaTime);
	void ExecuteCube(MMusicPlayer&mMusicPlaeyr,MPlayer& mPlayer,vector<MBullet>&mBullet,double deltaTime);
	bool IsCrashedWithCube(QPoint,int,int);
	bool IsCrashedWithCube(QPoint mHotPoint, int mRedius);

	void AddBrick(QPoint mHotPoint);
	void AddIce(QPoint mHotPoint);
	void AddJelly(QPoint mHotPoint);
	void AddSpikerock(QPoint mHotPoint);

	void SetLeft(int mLeft);
	void SetTop(int mTop);
	void SetRight(int mRight);
	void SetButtom(int mButtom);
	int GetLeft()const;
	int GetTop()const;
	int GetRight()const;
	int GetButtom()const;

	MBrick brickTemp;
	MIce iceTemp;
	MJelly jellyTemp;
	MSpikerock spikerockTemp;

	vector<MBrick>brick;
	vector<MIce>ice;
	vector<MJelly>jelly;
	vector<MSpikerock>spikerock;
private:
	int left;
	int top;
	int right;
	int buttom;
};