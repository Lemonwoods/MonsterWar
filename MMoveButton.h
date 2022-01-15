#pragma once

#include<qpushbutton.h>
#include<qevent.h>

#include"MDefine.h"
#include"MMusicPlayer.h"

class MMoveButton :public QPushButton
{
public:
	MMoveButton();
	MMoveButton(const MMoveButton& mMoveButton);

	void mouseMoveEvent(QMouseEvent* mEvent);

	void Initial();

	bool IsNextCubePointValid();

	void ChangeMoveState();
	void SetMoveState(bool mMoveState);
	bool GetMoveState()const;

private:
	QPoint nextCubePoint;

	bool moveState;

	static MMusicPlayer musicPlayer;
};