

// Local includes 
#include "SubscriptionUtil.h"
#include "sqlite3.h"



SubscriptionUtil::SubscriptionUtil()
{

}
SubscriptionUtil::~SubscriptionUtil()
{

}

vector< vector<CSVstruct> > SubscriptionUtil::GetSubscription( int ID )
{
	vector< vector<CSVstruct> > result;
	result.clear();

	return result;
}
void SubscriptionUtil::SetSubscription( int ID, vector< vector<CSVstruct> > )
{

}

void SubscriptionUtil::SaveConfigurationInDB( vector< vector<CSVstruct> > )
{

}
void SubscriptionUtil::GetDBConnection()
{

}
string SubscriptionUtil::ExecuiteQuery( string Query )
{
	string result="";

	return result;
}
string SubscriptionUtil::CheckandCreateDatabase()
{
	string result="";

	return result;
}
void SubscriptionUtil::CreateDatabase()
{

}
BOOL SubscriptionUtil::CheckDatabaseExists()
{
	BOOL result=FALSE;

	return result;
}
void SubscriptionUtil::CreateSubscriptionTable()
{

}
BOOL SubscriptionUtil::CheckSubscriptionTable()
{
	return TRUE;
}
