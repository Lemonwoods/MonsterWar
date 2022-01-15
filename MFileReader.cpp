#include"MFileReader.h"

void MFileReader::Construct(QString& mFilePath)
{
	filePath = mFilePath;
}
void MFileReader::Initial()
{
	
}

int MFileReader::ReadFile(MMap& mMap, MMonsterArray& mMonsterArray,MPlayer&mPlayer)
{
	//打开文件
	QFile file(filePath);
	if (file.open(QIODevice::ReadOnly))
	{
		QDataStream in(&file);

		in >> fileCode;
		if (fileCode != FILE_CODE)
		{
			return -1;
		}

		in >> mode;

		while (mode != END)
		{
			in >> hotPoint;

			switch (mode)
			{
			case BRICK:
				mMap.AddBrick(hotPoint);
				break;
			case ICE:
				mMap.AddIce(hotPoint);
				break;
			case JELLY:
				mMap.AddJelly(hotPoint);
				break;
			case SPIKEROCK:
				mMap.AddSpikerock(hotPoint);
				break;
			case MONSTER:
				mMonsterArray.AddMonster(hotPoint);
				break;
			case PLAYER:
				mPlayer.SetHotPoint(hotPoint);
				mPlayer.SetNextHotPoint(hotPoint);
				break;
			}

			in >> mode;
		}
		return 0;
	}
	else
	{
		/*QMessageBox::about(NULL, QString("错误"),
			QString("地图文件打开错误，请检查输入文件地址是否正确"));*/
		return -1;
	}
}

void MFileReader::SetFilePath(QString& mFilePath)
{
	filePath = mFilePath;
}
QString MFileReader::GetFilePath()const
{
	return filePath;
}
