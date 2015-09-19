
#include "ShardDrivesettings.h"
#include "CSVutil.h"

int main()
{
	cout<<"####### This much coding done for Amazon hach ####### \n";

	int l_option;
	cout<<" ########################## SELECTION MENU ######################## \n";
	cout<<" ######\t 1. Shard Drive configuration \t########################### \n";
	cout<<" ######\t 2. Parse CSV file \t\t########################### \n";
	cout<<" ######\t 3. Search attribute \t\t########################### \n";
	cout<<" ############################## END ############################### \n";
	cout<<" Enter the option to perform :: \t ";

	CSVUtil CSVObj;
	CSVObj.openFIle( "C:\\Users\\Administrator\\Desktop\\anji.csv" );
	cout << " \n\n Finished Parsing CSV file \n\n";
	cin>>l_option;
	switch(l_option)
	{
	case 1:
		cout<<" ######### Going to connect the Map Drive ############## \n";
		
		int l_mapopt;
		cout<<" ################## MAP DRIVE MENU ################### \n";
		cout<<" ############# 1. Add Configuration \t############ \n";
		cout<<" ############# 2. Get Map drive list \t############ \n";
		cout<<" ############# 3. Get conn Status \t############ \n";
		cout<<" ############# 4. List the files \t############ \n";
		cout<<" ############# 5. Delete Configuration \t############ \n";
		cout<<" \n Enter your option ::";
		cin>>l_mapopt;

		CshardDrive mapdrive;
		mapdrive.Initialize();

		switch(l_mapopt)
		{
		case 1:
			{
				string driveName = "";
				string drivePath="";
				string userName = "";
				string passWord = "";
				cout<<" Enter the Drive path (\\ Your Ip\Drive_Name) format :: ";
				cin>>drivePath;
				//string drivePath = "\\\\192.168.4.181\\e";
				cout<<" \n Enter the Drive Name :: ";
				cin>>driveName;
				cout<<"\n Enter the User Name :: ";
				cin>>userName;
				cout<<" \nEnter the Password :: ";
				cin>>passWord;
				cout<<"\n Going to connected the Map drive \n";
				mapdrive.InsertMappedDriveConfiguration(driveName,drivePath,userName,passWord,false);
			}
			break;
		case 2:
			{
				mapdrive.GetMapDriveConnection();
			}
			break;
		case 3:
			{
				string l_driveName;
				cout<<" \nEnter the Drive Name :: ";
				cin>>l_driveName;
				mapdrive.GetConnection(l_driveName);
			}
			break;
		case 4:
			{
				cout<<" Going to list the files from the Drive \n";
			}
			break;
		case 5:
			{
				cout<<" Going to delete the Mapped drive configuration \n";
			}
			break;
		default:
			cout<<" ####### Please select a valid option. Thanks!!!!!! \n";
			break;
		}		
		cout<<" ########## Map drive connection getting ended Here ########## \n";
		break;
	case 2:
		break;
	default:
		cout<<" Please enter the valid option to perform the task. Thanks!!!! \n";
	}
	cout<<" ########## The hack module ended up here ####### \n";
	system("pause");
	return 0;
}