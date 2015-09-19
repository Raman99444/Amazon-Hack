

#include "SQLiteUtil.h"
#include "sqlite3.h"

SQLIteUitl::SQLIteUitl()
{
	this->isOpenDB = false;
}
SQLIteUitl::~SQLIteUitl()
{

}
//void SQLIteUitl::Initialize()
//{
//	this->isOpenDB = false;
//}

bool SQLIteUitl::ConnectDB( string DB )
{
	if ( sqlite3_open(DB.c_str(), &dbfile) == SQLITE_OK )
	{
		isOpenDB = true;
		return true;
	}		 

	return false;
}

void SQLIteUitl::DisonnectDB()
{
	if ( isOpenDB == true ) 
	{
		sqlite3_close(dbfile);
	}
}

int SQLIteUitl::ExecuiteQuery( string str )
{
								//"insert into table(,,,)values(,,,)";

	int result = 0;						//"update table set ?= where ?=";
	sqlite3_stmt *statement;
	const char *query = str.c_str();	//"delete from student where = ? ";
	{
		if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
		}
		//delete[] query;
		return result;
	}
	delete[] query;
	return 0;
}

void SQLIteUitl::GetTableData( string Query )
{
	sqlite3_stmt *statement;	

	const char *query = Query.c_str();	//"select * from table ";

	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		while ( 1 ) 		
		{
			res = sqlite3_step(statement);
			if ( res == SQLITE_ROW ) 
			{
				for ( int i = 0; i < ctotal; i++ ) 
				{
					string s = (char*)sqlite3_column_text(statement, i);
					cout << s << " " ;
				}
				cout << endl;
			}

			if ( res == SQLITE_DONE )	
			{
				cout << "done " << endl;
				break;
			}					

		}
	}
	delete[] query;
}