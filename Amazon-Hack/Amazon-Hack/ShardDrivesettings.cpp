
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
	//string drivePath="";
	string userName = "Administrator";
	string passWord = "Vembu123$";
	//cout<<" Enter the Drive path (\\ Your Ip\Drive_Name) format :: ";
	//cin>>drivePath;
	string drivePath = "\\\\192.168.4.181\\e";
	//cout<<"\n Enter the User Name :: ";
	//cin>>userName;
	//cout<<" \nEnter the Password :: ";
	//cin>>passWord;
	//cout<<"\n Going to connected the Map drive \n";

	string driveListQuery = "select drivename, drivepath, username, password from MAPPED_DRIVE_CONFIGURATION";

	SQLIteUitl conn;
	bool isconn = conn.ConnectDB("AMAZEHACK.db3");

	if(isconn)
	{
		conn.GetTableData(driveListQuery);
	}else
	{
		cout<<" ######### Unable to connect the DataBase ######## \n";
	}

	cout<<" drivePath :: "<<drivePath<< " userName :: "<<userName<< " passWord :: "<<passWord<< "\n";
	this->shardDriveList->clear();

	string tempPath = drivePath;
	
	NETRESOURCE nr;
	DWORD res;
	TCHAR szUserName[32]=L"", szPassword[32]=L"", szLocalName[32]=L"", szRemoteName[MAX_PATH]=L"";

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

bool CshardDrive::InsertMappedDriveConfiguration(string driveName, string drivePath, string userName, string password, bool* isExists)
{
	string driveCheckQuery = "select * from MAPPED_DRIVE_CONFIGURATION where drivename = '";
	driveCheckQuery.append(driveName);
	driveCheckQuery.append("' OR drivepath = '");
	driveCheckQuery.append(drivePath);
	driveCheckQuery.append("' OR lower(drivepath) LIKE '");
	driveCheckQuery.append(drivePath); // Drive path need to convert in to lower case
	driveCheckQuery.append("%'");

	SQLIteUitl conn;// = new SQLIteUitl;
	int resultSet = 0;

	//conn->Initialize();
	bool isconn = conn.ConnectDB("AMAZEHACK.db3");
    try {
		resultSet = conn.ExecuiteQuery(driveCheckQuery);
    }catch(const char *err)
    {
		char* error = (char*)err;
		cout << error << endl;
        delete error;
		return false;
    }

	if(resultSet == NULL)
	{
		cout << "The Drive Path or Drive Name already available \n";
		*isExists = true;
		conn.DisonnectDB();
		return false;
	}

	string addDriveQuery = "insert into MAPPED_DRIVE_CONFIGURATION values ('";
	addDriveQuery.append(driveName);
	addDriveQuery.append("','");
	addDriveQuery.append(drivePath);
	addDriveQuery.append("','");
	addDriveQuery.append(userName);
	addDriveQuery.append("','");
	addDriveQuery.append(password);
	addDriveQuery.append("','Success')");
		
	int mappedDriveID = 0;
	int status = 1;
	cout<<" ######## Query Going to Execute :: "<<addDriveQuery<< "\n";
	int isInserted = conn.ExecuiteQuery(addDriveQuery);
	if(isInserted == NULL)
	{
	   cout<<"@@@@ Error in inserting mapped drive configuration.\n";
	}
	else
	{
		cout<<" Mapped Drive Added successfully !!!!! \n";
		map<string, string>::iterator pos = this->shardDriveList->find(driveName);
		if(pos == this->shardDriveList->end())
		{	
			this->shardDriveList->insert(pair<string,string>(driveName, drivePath));	
		}
	}
	conn.DisonnectDB();
	return isInserted;
};

bool CshardDrive::GetConnection(string driveName)
{
	bool connected = false;
	string tempDriveName = "";

	//if (!driveName.empty() )//;
	//{
	//	if(driveName.length() > 2)
	//	{
	//		int colIndex = driveName.find(":");
	//		int strLength = colIndex;
	//		tempDriveName = driveName.substr(0,strLength);
	//	}
	//	else
	//	{
	//		tempDriveName = driveName.substr(0,1);
	//	}
	//	//tempDriveName = strUtil.ToUpperCase(tempDriveName);
	//	tempDriveName.append(":/");
	//	string driveListQuery = "select DRIVE_PATH, USER_NAME, PASSWORD from MAPPED_DRIVE_CONFIGURATION where DRIVE_NAME = '";
	//	driveListQuery.append(tempDriveName);
	//	driveListQuery.append("'");

	//	try
	//	{
	//		SGResultset* resultSet = connection->Execute(driveListQuery);
	//		if (!resultSet->Eof())
	//		{
	//			string drivePath = resultSet->GetStringData(0);
	//			tempDriveName = strUtil.ReplaceAll(tempDriveName, "/", "\\");
	//			if (fileUtil.IsReadable(drivePath))
	//			{
	//				connected = true;
	//				map<string, string>::iterator pos = this->mappedDriveList->find(tempDriveName);
	//				if(pos == this->mappedDriveList->end())
	//				{	
	//					drivePath = strUtil.ReplaceAll(drivePath, "/", "\\");
	//					this->mappedDriveList->insert(pair<string,string>(tempDriveName,drivePath));	
	//				}			
	//			}
	//			else
	//			{
	//				string userName = resultSet->GetStringData(1);
	//				string passWord = resultSet->GetStringData(2);
	//				if (!userName.empty() && !passWord.empty())
	//				{
	//					passWord = encryptionObj.DecryptGivenText(passWord);
	//					drivePath = strUtil.ReplaceAll(drivePath, "/", "\\");
	//					string tempPath = drivePath;
	//					if (strUtil.EndsWith(drivePath, "\\"))//;
	//					{
	//						tempPath = tempPath.substr(0,(tempPath.length()-1));
	//					}
	//					NETRESOURCE nr;
	//					DWORD res;
	//					TCHAR szUserName[32]="", szPassword[32]="", szLocalName[32]="", szRemoteName[MAX_PATH]="";
	//
	//					memcpy(szUserName, userName.c_str(), userName.length());
	//					memcpy(szPassword, passWord.c_str(), passWord.length());
	//					//memcpy(szLocalName, driveName.c_str(), driveName.length());
	//					memcpy(szRemoteName, tempPath.c_str(), tempPath.length());
	//					//
	//					// Assign values to the NETRESOURCE structure.
	//					//
	//					nr.dwType = RESOURCETYPE_ANY;
	//					nr.lpLocalName = NULL;
	//					nr.lpRemoteName = szRemoteName;
	//					nr.lpProvider = NULL;
	//					//
	//					// Call the WNetAddConnection2 function to assign
	//					//   a drive letter to the share.
	//					
	//					res = WNetAddConnection2(&nr, szPassword, szUserName, FALSE);
	//					if (res == NO_ERROR)
	//					{
	//						connected = true;
	//						cout << "The Network Drive " << szRemoteName << " is successfully mapped during backup.\n";					
	//						map<string, string>::iterator pos = this->mappedDriveList->find(tempDriveName);
	//						if(pos == this->mappedDriveList->end())
	//						{					
	//							this->mappedDriveList->insert(pair<string,string>(tempDriveName,drivePath));	
	//
	//						}
	//					}
	//					else
	//					{
	//						string mesg = ExceptionUtil::GetErrorMessage((int)res);
	//						string print = "During backup Error Occured while map the drive ";
	//						print.append(driveName);
	//						print.append(" with a error: ");
	//						print.append(mesg);
	//						cout << print << endl;
	//						if (EVENT_NOTIFICATIONS)
	//						{
	//							/* * /
	//							eventNotification->LogEvent(LOG, CRITICAL_EVENT, time(NULL), BACKUP_MODULE,
	//									print, true, false);
	//							/* */
	//							eventNotification->LogEvent(LOG, "SG5120113",  CRITICAL_EVENT, print, time(NULL),  
	//															__FILE__, __FUNCTION__, __LINE__);
	//						}
	//					}
	//				}
	//				else
	//				{
	//					string err = "During backup Error occured while reconnect the drive path ";
	//					err.append(drivePath);
	//					cout << err << endl;
	//					if (EVENT_NOTIFICATIONS)
	//					{
	//						/* * /
	//						eventNotification->LogEvent(LOG, CRITICAL_EVENT, time(NULL), BACKUP_MODULE,
	//								err, true, false);
	//						/* */
	//						eventNotification->LogEvent(LOG, "SG5120114",  CRITICAL_EVENT, err, time(NULL),  
	//															__FILE__, __FUNCTION__, __LINE__);
	//					}
	//				}			
	//			}
	//
	//
	//
	//
	//
	//
	//		}
	//		else
	//		{
	//			cout << "The Drive Name is not available in dB to connect during the backup. \n";
	//
	//		}
	//		resultSet->Finalize();
	//		delete resultSet;
	//}
	//catch(const char* err)
	//{
	//		cout << "Error while getting mapped drive connection : "<<err <<endl;
	//		delete[] (char*) err;
	//}
	//
	//}
	return connected;
};