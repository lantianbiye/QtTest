// QtTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <QtGui/QtGui>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Image
	int nWid = 512;
	unsigned char* data = new unsigned char[nWid * nWid * 4];
	QImage::Format format = QImage::Format_ARGB32;
	QImage image(data,nWid,nWid,format);
	
	//QWriter
	QBuffer buffer;
	QByteArray arrFmt("PNG");  // png:2246ms  Jpeg 577ms
	QImageWriter writer(&buffer,arrFmt);
	//writer.setQuality(20);
	bool bRet = false;
	DWORD t1 = GetTickCount();
	for (int i = 0; i < 50; i++)
	{
		bRet = writer.write(image);
	}
	DWORD t2 = GetTickCount();
	cout << "time:" << t2 - t1 << " ms" <<endl;

	return 0;
}

