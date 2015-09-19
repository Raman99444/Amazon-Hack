

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#pragma comment(lib, "sqlite3.lib")
#include "sqlite3.h"


class SQLIteUitl{
public:
	SQLIteUitl();
	~SQLIteUitl();
	bool ConnectDB( string DB );
	void DisonnectDB();
	sqlite3 *dbfile;
	int ExecuiteQuery( string str );
	void GetTableData( string Query );
private:
	bool isOpenDB;
};