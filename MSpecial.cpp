#include"MSpecial.h"
#include<qdebug.h>

MSpecial::MSpecial()
{

}

void MSpecial::Construct()
{
	
}

void MSpecial::Initial()
{
	medicine.clear();
	accelerator.clear();
	bomb.clear();
}

void MSpecial::Execute(MMusicPlayer&mMusicPlayer,MMonsterArray&mMonsterArray,MPropArray&mPropArray,MPlayer& mPlayer, double deltaTime)
{
	switch (mPropArray.GetWorkingMode())
	{
	case MEDICINE:
		MedicineAdd();
		mMusicPlayer.medicine->play();
		mPropArray.SetWorkingMode(NORMAL);
		break;
	case ACCELERATOR:
		AcceleratorAdd();
		mMusicPlayer.accelerator->play();
		mPropArray.SetWorkingMode(NORMAL);
		break;
	}

	if (mPlayer.GetBombBulletWorking())
	{
		BombAdd(mPlayer.GetBombHotPoint());
		mPlayer.SetBombBulletWorking(false);
	}

	MedicineExecute(mPlayer, deltaTime);
	AcceleratorExecute(mPlayer, deltaTime);
	BombExecute(mMusicPlayer,mMonsterArray, deltaTime);
}
void MSpecial::Render(QPainter& mPainter, QPaintDevice* mPaintDevice)
{
	for (int i = 0; i < medicine.size(); i++)
	{
		medicine[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}

	for (int i = 0; i < accelerator.size(); i++)
	{
		accelerator[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}

	for (int i = 0; i < bomb.size(); i++)
	{
		bomb[i].MAnimationSprite::Render(mPainter, mPaintDevice);
	}
}

void MSpecial::MedicineAdd()
{
	medicine.push_back(medicineTemp);
}
void MSpecial::MedicineExecute(MPlayer& mPlayer, double deltaTime)
{
	for (int i = 0; i < medicine.size(); i++)
	{
		medicine[i].Execute(mPlayer, deltaTime);
		if (!medicine[i].GetWorking())
		{
			itMedicine = medicine.begin();
			itMedicine += i;
			medicine.erase(itMedicine);
			i--;
		}
	}
}

void MSpecial::AcceleratorAdd()
{
	accelerator.push_back(acceleratorTemp);
}
void MSpecial::AcceleratorExecute(MPlayer& mPlayer, double deltaTime)
{
	for (int i = 0; i < accelerator.size(); i++)
	{
		accelerator[i].Execute(mPlayer, deltaTime);
		if (!accelerator[i].GetWorking())
		{
			itAccelerator = accelerator.begin();
			itAccelerator += i;
			accelerator.erase(itAccelerator);
			i--;
		}
	}
}

void MSpecial::BombAdd(QPoint mHotPoint)
{
	bombTemp.SetHotPoint(mHotPoint);
	bomb.push_back(bombTemp);
}
void MSpecial::BombExecute(MMusicPlayer&mMusicPlayer,MMonsterArray& mMonsterArray, double deltaTime)
{
	for (int i = 0; i < bomb.size(); i++)
	{
		bomb[i].Execute(mMusicPlayer,mMonsterArray, deltaTime);
		
		if (!bomb[i].GetWorking())
		{
			itBomb = bomb.begin();
			itBomb += i;
			bomb.erase(itBomb);
			i--;
		}
	}
}