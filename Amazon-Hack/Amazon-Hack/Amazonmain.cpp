
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
		CshardDrive mapdrive;
		mapdrive.Initialize();
		mapdrive.GetMapDriveConnection();
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