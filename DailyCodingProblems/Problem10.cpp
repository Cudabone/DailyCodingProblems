//Suppose we represent our file system by a string in the following manner :
//
//The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents :
//
//	dir
//		subdir1
//		subdir2
//			file.ext
//	The directory dir contains an empty sub - directory subdir1 and a sub - directory subdir2 containing a file file.ext.
//
//	The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
//
//dir
	//subdir1
		//file1.ext
		//subsubdir1
	//subdir2
		//subsubdir2
			//file2.ext
//The directory dir contains two sub - directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second
//- level sub - directory subsubdir1.subdir2 contains a second - level sub - directory subsubdir2 containing a file file2.ext.
//
//We are interested in finding the longest( number of characters ) absolute path to a file within our file system. For example,
//in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including
//the double quotes).
//
//Given a string representing the file system in the above format, return the length of the longest absolute path to a file in
//the abstracted file system.If there is no file in the system, return 0.
//
//Note:
//
//The name of a file contains at least a period and an extension.
//
//The name of a directory or sub - directory will not contain a period.

// dir
//		path1
			//path2
			//	path3
			//		path4
			//			file
			//	file



#include "Problems.h"
#include <string>
#include <vector>
// The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

void insertPath( std::vector<std::string>& paths, size_t index, std::string dir )
{
	while ( index >= paths.size() )
	{
		paths.push_back( "" );
	}
	paths[index] = dir;
}

size_t LongestPathName(const std::string RawFiles)
{
	//delimiters \n \t
	//find the longest path name
	size_t longest = 0;
	std::string currentPath;
	std::vector<std::string> fullPaths; // paths[0] => directory youre under if you have one tab. paths[tabs - 1] == parent dir
	size_t currentTabs = 0;

	//put in the base path
	size_t i = RawFiles.find( '\n' );
	insertPath( fullPaths, 0, RawFiles.substr( 0, i ) );

	++i;
	while ( i < RawFiles.size() )
	{
		//first count tabs
		//then count all characters until \n
		while ( RawFiles[i] == '\t' && i < RawFiles.size() )
		{
			++currentTabs;
			++i;
		}
		while ( RawFiles[i] != '\n' && i < RawFiles.size())
		{
			currentPath += RawFiles[i];
			++i;
		}
		//RawPath[i] == '\n' or i is at the end of the string
		//if not a file
		std::string fullPath = fullPaths[currentTabs - 1] + "\\" + currentPath;
		if ( currentPath.find( '.' ) == currentPath.npos )
		{
			insertPath( fullPaths, currentTabs, fullPath);
		}
		else
		{
			if ( fullPath.size() > longest )
			{
				longest = fullPath.size();
			}
		}

		++i;
		if( i >= RawFiles.size() )
		{
			break;
		}

		currentTabs = 0;
		currentPath = "";
	}

	return longest;
}

void Problem10::RunTest()
{
	std::string s( "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" );
	std::printf( "\nProblem10:\n" );
	std::printf( "Longest Path to file is: %zu\n", LongestPathName( s ) );
}
