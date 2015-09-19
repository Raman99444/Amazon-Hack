


#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

// Macros

#define		ITEM_ID				0
#define		ITEM_ATTRIBUITE		1
#define		ITEM_VALUE			2

struct CSVFIleStruct{
	string attribuite;
	string value;
};
// Creating class to handle CSV files.

class CSVUtil {

public:
	CSVUtil();
	~CSVUtil();

	void openFIle( string filename );

private:
	string CSVFileName;

	//map< int , vector<string> >
	void SplitCSVLines( fstream& str);
	map<LONG, CSVFIleStruct > CSVContentsMap;
	vector<string> CSVUtil::split(const string &s, char delim, vector<string> &elems);
};

