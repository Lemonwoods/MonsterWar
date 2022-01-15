#pragma once

#include<vector>

#include"MDefine.h"
#include"MMedicine.h"
#include"MAccelerator.h"
#include"MBomb.h"
#include"MPlayer.h"
#include"MMonsterArray.h"
#include"MPropArray.h"
#include"MMusicPlayer.h"

class MSpecial
{
public:
	MSpecial();

	void Construct();
	void Initial();
	
	void Execute(MMusicPlayer&mMusicPlayer,MMonsterArray&mMonsterArray,MPropArray&mPropArray,MPlayer&mPlayer,double deltaTime);
	void Render(QPainter& mPainter, QPaintDevice* mPaintDevice);

	void MedicineAdd();
	void MedicineExecute(MPlayer& mPlayer,double deltaTime);

	void AcceleratorAdd();
	void AcceleratorExecute(MPlayer& mPlayer, double deltaTime);

	void BombAdd(QPoint mHotPoint);
	void BombExecute(MMusicPlayer&mMusicPlayer,MMonsterArray& mMonsterArray, double deltaTime);

	vector<MMedicine> medicine;
	vector<MAccelerator>accelerator;
	vector<MBomb>bomb;

	vector<MMedicine>::iterator itMedicine;
	vector<MAccelerator>::iterator itAccelerator;
	vector<MBomb>::iterator itBomb;

	MMedicine medicineTemp;
	MAccelerator acceleratorTemp;
	MBomb bombTemp;
private:


};