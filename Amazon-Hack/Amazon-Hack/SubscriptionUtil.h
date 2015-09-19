

// main includes here..

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <map>
using namespace std;


// Macros
#define			DATABASE_NAME				"Hackathon.db"
#define			DATABASEPATH				"../Database/Hackathon.db"
#define			SUBSCRIPTION_TABLE			"SUBSCRIPTION_TABLE"
#define			SUBSCRIPTION_INSERT_QUERY	""
#define			SUBSCRIPTION_READ_QUERY		""

// Struct 

struct CSVstruct{
	string Subription_attribuite;
	int Symbol;
	string SubscriptionValue;
};

// Class

class SubscriptionUtil
{
public: 
	SubscriptionUtil();
	~SubscriptionUtil();

	vector< vector<CSVstruct> > GetSubscription( int ID );
	void SetSubscription( int ID, vector< vector<CSVstruct> > );

private:
	void     SaveConfigurationInDB( vector< vector<CSVstruct> > );
	void	 GetDBConnection();
	string   ExecuiteQuery( string Query );
	string   CheckandCreateDatabase();
	void	 CreateDatabase();
	BOOL	 CheckDatabaseExists();
	void	 CreateSubscriptionTable();
	BOOL	 CheckSubscriptionTable();

};