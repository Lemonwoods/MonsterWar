#include"MMoveButton.h"
#include"qdebug.h"

MMusicPlayer MMoveButton::musicPlayer;

MMoveButton::MMoveButton()
{
	connect(this, &MMoveButton::clicked, this, &MMoveButton::ChangeMoveState);
	moveState = false;
	setMouseTracking(true);
}
MMoveButton::MMoveButton(const MMoveButton& mMoveButton)
{
	connect(this, &MMoveButton::clicked, this, &MMoveButton::ChangeMoveState);
	moveState = false;
	setMouseTracking(true);
}

void MMoveButton::mouseMoveEvent(QMouseEvent* mEvent)
{
	if (moveState)
	{
		nextCubePoint = QPoint(mEvent->pos().x() - width() * 0.5 + pos().x(), mEvent->pos().y() - height() * 0.5 + pos().y());

		if (IsNextCubePointValid())
		{
			move(nextCubePoint);
		}
	}
}

void MMoveButton::Initial()
{
	moveState = false;
}

bool MMoveButton::IsNextCubePointValid()
{
	if (nextCubePoint.x() < MAP_LEFT  + 1
		|| nextCubePoint.x() > MAP_RIGHT - width() - 1
		|| nextCubePoint.y() < MAP_TOP+ 1
		|| nextCubePoint.y() > MAP_BUTTOM -height() - 1)
	{
		return false;
	}
	return true;
}

void MMoveButton::ChangeMoveState()
{
	moveState = !moveState;
}
void MMoveButton::SetMoveState(bool mMoveState)
{
	moveState = mMoveState;
}
bool MMoveButton::GetMoveState()const
{
	return moveState;
}