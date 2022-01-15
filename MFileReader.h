#pragma once

#include<qfile.h>
#include<qdatastream.h>
#include<qmessagebox.h>

#include"MMap.h"
#include"MMonsterArray.h"
#include"MPlayer.h"
#include"MDefine.h"

class MFileReader
{
public:
	void Construct(QString& mFilePath);
	void Initial();

	int ReadFile(MMap& mMap, MMonsterArray& mMonsterArray,MPlayer&mPlayer);

	void SetFilePath(QString& mFilePath);
	QString GetFilePath()const;
private:
	QString filePath;

	qint32 mode;
	QPoint hotPoint;

	qint32 fileCode;
};
