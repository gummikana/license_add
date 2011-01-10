/***************************************************************************

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>

#include "utils/dirlist/cdirlist.h"
#include "utils/dirlist/string.h"


void ParseFile( const std::string& file, const std::string& license_header )
{
	std::fstream file_loader( file.c_str(), std::ios::in );
	
	std::string line;
	std::string result = license_header;
	while ( file_loader.good() ) 
	{
		std::getline( file_loader, line );	
		result += line + "\n";
	}
	file_loader.close();

	std::fstream file_out( file.c_str(), std::ios::out );
	file_out << result;
	file_out.close();
}


std::string ReadFile( const std::string& file )
{
	std::fstream file_loader( file.c_str(), std::ios::in );
	
	std::string line;
	std::string result;
	while ( file_loader.good() ) 
	{
		std::getline( file_loader, line );	
		result += line + "\n";
	}
	file_loader.close();

	result += "\n";

	return result;
}

void ReadDirectories( const std::string& path, std::vector< std::string >& files )
{
	// std::string directory = "logs/2006";

	{
		CDirList dir_list;
		dir_list.ReadDir( path + "/" );

		while( dir_list.End() == false )
		{
			std::string file = dir_list.Next();
			std::cout << "directory: " << path + "/" + file << std::endl;
			ReadDirectories( path + "/" + file, files );
			// std::cout << "analyzing: " << file << std::endl;
			// AnalyzeFile( directory + "/" + file, analyzer, "2006" );
		}
	}

	{
		CDirList dir_list;
		dir_list.ReadFiles( path + "/" );

		while( dir_list.End() == false )
		{
			std::string file = dir_list.Next();
			std::cout << "an: " << path + "/" + file << std::endl;
			files.push_back( path + "/" + file );
			// std::cout << "analyzing: " << file << std::endl;
			// AnalyzeFile( directory + "/" + file, analyzer, "2006" );
		}
	}
}

int main( int arg, char* args )
{
	

	std::vector< std::string > files;
	ReadDirectories( ".", files );

	std::string license_file = "license.txt";
	std::string folder = "";
	
	std::string license_header = ReadFile( license_file );

	for( std::size_t i = 0; i < files.size(); ++i ) {
		if( files[i] != "./license.txt" )
		{
			std::cout << files[i] << std::endl;
			ParseFile( files[ i ], license_header );
		}
	}

	/*
	for( int i = 0; i < 61; ++i ) 
	{
	std::stringstream ss;
	ss << "target" << i << ".html";
	ParseFile( ss.str() );

	}	*/
	return 0;
}