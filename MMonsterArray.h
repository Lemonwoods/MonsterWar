#pragma once

#include<vector>

#include"MDefine.h"
#include"MMonster.h"
#include"MMusicPlayer.h"

using namespace std;

class MMonsterArray
{
public:
	void Initial();
	void Clear();

	void DefaultMonsterArray();

	void Execute(MMusicPlayer&mMusicPlayer,MMap& mMap, MPlayer& mPlayer, double deltaTime);
	void RenderMonster(QPainter& mPainter, QPaintDevice* mPaintDevice);
	void Update(double deltaTime);

	void AddMonster(QPoint mHotPoint);

	MMonster monsterTemp;
	vector<MMonster>monster;
	vector<MMonster>::iterator itMonster;
private:
	

};