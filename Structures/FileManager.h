#pragma once
#include<fstream>

class FileManager
{
public:
	//source:
	//https://en.cppreference.com/w/cpp/io/ios_base/openmode
	//https://en.cppreference.com/w/cpp/named_req/BitmaskType
	static void openFile(std::ofstream&, const char*, std::ios_base::openmode);
	static void openFile(std::ifstream&, const char*, std::ios_base::openmode);
	static void openFile(std::fstream&, const char*, std::ios_base::openmode);

	static void openFile(std::ofstream&, const char*);
	static void openFile(std::ifstream&, const char*);
	static size_t getFileSize(std::ifstream&);
	static size_t getFileSize(std::fstream&);
};
