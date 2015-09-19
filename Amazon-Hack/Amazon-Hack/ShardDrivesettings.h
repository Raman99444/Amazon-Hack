
#ifndef _SHARDDRIVESETTINGS_H_
#define _SHARDDRIVESETTINGS_H_

#include<iostream>
#include<vector>
#include<map>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <Winnetwk.h>
#include<string>

#include "SQLiteUtil.h"

using namespace std;

class CshardDrive
{
private:
	static CshardDrive* sharddrive;

	CshardDrive *mapDrive;
public:

	map <string, string>* shardDriveList;

	void Initialize();
	static CshardDrive* GetMappedDriveConfiguration();
	void GetMapDriveConnection();
	bool InsertMappedDriveConfiguration(string driveName, string drivePath, string userName, string password, bool* isExists);
	bool GetConnection(string driveName);
};

#endif