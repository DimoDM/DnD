#include "FileManager.h"
#pragma once

void FileManager::openFile(std::ofstream& file, const char* fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	if (!file.is_open()) {
		perror(fileName);
		exit(1);
	}
}

void FileManager::openFile(std::ifstream& file, const char* fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	if (!file.is_open()) {
		perror(fileName);
		exit(1);
	}
}

void FileManager::openFile(std::fstream& file, const char* fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	if (!file.is_open()) {
		perror(fileName);
		exit(1);
	}
}

void FileManager::openFile(std::ofstream& file, const char* fileName)
{
	openFile(file, fileName, std::ios::out | std::ios::trunc);
}

void FileManager::openFile(std::ifstream&file, const char* fileName)
{
	openFile(file, fileName, std::ios::in);
}

size_t FileManager::getFileSize(std::ifstream& file)
{
	if (!file.is_open()) return 0;
	size_t curPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t result = file.tellg();
	file.seekg(0, curPos);
	return result;
}

size_t FileManager::getFileSize(std::fstream& file)
{
	if (!file.is_open()) return 0;
	size_t curPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t result = file.tellg();
	file.seekg(0, curPos);
	return result;
}
