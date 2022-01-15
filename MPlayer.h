#pragma once

#include<qevent.h>
#include<vector>

#include"MPlayerTop.h"
#include"MPlayerButtom.h"
#include"MDefine.h"
#include"MBullet.h"
#include"MMusicPlayer.h"


using namespace std;

class MPlayer :public MSprite
{
public:
	MPlayer();
	MPlayer(int mHP,int mArmor, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	void Construct(int mHP, int mArmor, QPoint mHotPoint, QString mPath, int mWidth, int mHeight, int mSpeed, int mRedius);
	~MPlayer();
	void Initial();

	void Execute(int);
	void Move();
	void ShootBullet(MMusicPlayer&mMusicPlayer,int mLeft, int mTop, int mRight, int mButtom);
	void RenderBullet(QPainter& mPainter, QPaintDevice* mPaintDevice);
	void UpdateBullet(double deltaTime);
	bool IsHotPointValid(int mLeft, int mTop, int mRight, int mButtom);

	void SetDirection(int);
	int GetDirection()const;
	void SetHotPoint(QPoint);
	void SetNextHotPoint(QPoint);
	void UpdateHotPoint();

	void HPAdd(int);
	void HPMinuse(MMusicPlayer&mMusicPlayer,int);
	void SetHP(int);
	int GetHP()const;

	void SetArmor(int);
	int GetArmor()const;

	bool GetMove()const;
	void Run();
	void Stand();

	void SetNextBulletMode(int mNextBulletMode);
	int GetNextBulletMode()const;

	void SetBombBulletWorking(bool mBombBulletWokring);
	bool GetBombBulletWorking()const;

	QPoint GetBombHotPoint()const;

	MPlayerTop playerTop;
	MPlayerButtom playerButtom;

	MBullet bulletTemp;	
	vector<MBullet>bullet;

private:
	vector<MBullet>::iterator itBullet;

	int HP;
	int armor;

	int direction;
	bool move;

	int nextBulletMode;

	bool bombBulletWorking;
	QPoint bombHotPoint;
};