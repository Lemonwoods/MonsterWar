#pragma once

#include<vector>

#include"MCube.h"
#include"MBullet.h"
#include"MMusicPlayer.h"

using namespace std;

class MIce :public MCube
{
public:
	MIce();
	MIce(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MIce();

	void Construct(int mXStart, int mYStart, int mXFrames, int mYFrames, int mFps, int mFrames, short mMode, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Initial();

	void Execute(MMusicPlayer&mMusicPlayer,vector<MBullet>&mBullet);

	void Broke();
	void Invisible();

private:
	
};