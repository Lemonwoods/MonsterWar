#pragma once

#include<vector>

#include"MDefine.h"
#include"MCube.h"
#include"MBullet.h"
#include"MMusicPlayer.h"

using namespace std;

class MJelly :public MCube
{
public:
	MJelly();
	MJelly(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MJelly();

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMusicPlayer&mMusicPlayer,vector<MBullet>&mBullet);

	int CalculateDirection(MBullet&);//���ط���
private:

};