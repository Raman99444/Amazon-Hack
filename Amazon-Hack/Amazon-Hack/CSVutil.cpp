

// main includes here..



// Local includes 
#include "CSVutil.h"


CSVUtil::CSVUtil()
{

}

CSVUtil::~CSVUtil()
{

}
void CSVUtil::openFIle( string filename )
{
	this->CSVFileName = filename;
	fstream FileObj;
	FileObj.open(this->CSVFileName, fstream::in );
// 	{
// 		cout << "\n Error while opening file.\n";
// 	}

	//this->CSVContentsMap = this->SplitCSVLines(FileObj);
	

}


void CSVUtil::SplitCSVLines( fstream& str)
{
	map<LONG, vector<string>> result;
	string  line;
	
	if( str.good() )
	{
		while (getline(str, line))
		{
			vector<string> elems;
			split(line, ',', elems);
			vector<string> Second;
			if( elems.size() != 4 )
			{
				cout << "\n No of elements in csv file is not equal to 3 ::\n FIle name ::" << this->CSVFileName << "\n Line is :: "<< line << "\n";
				break;
			}
			LONG ID = atol( elems[ITEM_ID].c_str() );
			Second.push_back(elems[ITEM_ATTRIBUITE]);
			Second.push_back(elems[ITEM_VALUE]);
			result.insert ( make_pair<LONG, vector<string>>( ID ,Second ) );
		}
	}
	else
	{
		cout << "\n Unable to read the file.. \n";
		throw( "Unable to read the file.." );
		return;
	}
	this->CSVContentsMap = result;
	//return result;
}

vector<string> CSVUtil::split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}