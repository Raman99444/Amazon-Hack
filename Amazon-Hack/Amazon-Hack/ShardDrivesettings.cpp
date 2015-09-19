
#include "ShardDrivesettings.h"
#include <stddef.h>

CshardDrive* CshardDrive::sharddrive = NULL;

CshardDrive* CshardDrive::GetMappedDriveConfiguration()
{
	if (sharddrive == NULL) {		
		sharddrive = new CshardDrive;
		sharddrive->Initialize();
	}
	return sharddrive;
};

void CshardDrive::Initialize()
{
	this->shardDriveList = new map<string, string>;
};

void CshardDrive::GetMapDriveConnection()
{
	string driveName = "R";
	string drivePath="";
	string userName = "";
	string passWord = "";
	cout<<" Enter the Drive path (\\ Your Ip\Drive_Name) format :: ";
	cin>>drivePath;
	//string drivePath = "\\\\192.168.4.181\\e";
	cout<<"\n Enter the User Name :: ";
	cin>>userName;
	cout<<" \nEnter the Password :: ";
	cin>>passWord;
	cout<<"\n Going to connected the Map drive \n";
	cout<<" drivePath :: "<<drivePath<< " userName :: "<<userName<< " passWord :: "<<passWord<< "\n";
	this->shardDriveList->clear();

	string tempPath = drivePath;
	
	NETRESOURCE nr;
	DWORD res;
	TCHAR szUserName[32]="", szPassword[32]="", szLocalName[32]="", szRemoteName[MAX_PATH]="";

	memcpy(szUserName, userName.c_str(), userName.length());
	memcpy(szPassword, passWord.c_str(), passWord.length());
	memcpy(szRemoteName, tempPath.c_str(), tempPath.length());
	//
	// Assign values to the NETRESOURCE structure.
	//
	nr.dwType = RESOURCETYPE_ANY;
	nr.lpLocalName = NULL;
	nr.lpRemoteName = szRemoteName;
	nr.lpProvider = NULL;

	res = WNetAddConnection2(&nr, szPassword, szUserName, FALSE);
	if (res == NO_ERROR)
	{
		cout << "The Network Drive " << szRemoteName << " is successfully mapped \n";
		map<string, string>::iterator pos = this->shardDriveList->find(driveName);
		if(pos == this->shardDriveList->end())
		{					
			this->shardDriveList->insert(pair<string,string>(driveName,drivePath));	
		}
	}else {
		cout<<" WNetAddConnection2 gettng failed : Error ::"<<res<<"\n";
	}
};