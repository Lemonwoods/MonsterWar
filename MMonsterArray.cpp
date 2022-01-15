#include"MMonsterArray.h"

void MMonsterArray::Initial()
{
	monsterTemp.Initial();
	monsterTemp.Play();
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i].Initial();
	}
}
void MMonsterArray::Clear()
{
	monster.clear();
}

void MMonsterArray::DefaultMonsterArray()
{
	monsterTemp.SetHotPoint(QPoint(1200, 300));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(700, 700));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(640, 290));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(640, 230));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(640, 260));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(1120, 790));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(1120, 820));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(1120, 850));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(1000, 200));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(QPoint(1250, 350));
	monster.push_back(monsterTemp);
	monsterTemp.RandomDirection();
}

void MMonsterArray::Execute(MMusicPlayer&mMusicPlayer,MMap& mMap, MPlayer& mPlayer, double deltaTime)
{
	for (int i = 0; i < monster.size();)
	{
		if (monster[i].GetExistence())
		{
			monster[i].Execute(mMusicPlayer,mMap, mPlayer, deltaTime);
			i++;
		}
		else
		{
			itMonster = monster.begin();
			itMonster += i;
			monster.erase(itMonster);
		}
	}
}
void MMonsterArray::RenderMonster(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i].RenderHPLabel(mPainter, mPaintDevice);
		monster[i].MAnimationSprite::Render(mPainter, mPaintDevice);
		monster[i].frozen.MAnimationSprite::Render(mPainter, mPaintDevice);
	}
}
void MMonsterArray::Update(double deltaTime)
{
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i].MAnimationSprite::Update(deltaTime);
		monster[i].frozen.MAnimationSprite::Update(deltaTime);
	}
}

void MMonsterArray::AddMonster(QPoint mHotPoint)
{
	monsterTemp.RandomDirection();
	monsterTemp.SetHotPoint(mHotPoint);
	monster.push_back(monsterTemp);
}