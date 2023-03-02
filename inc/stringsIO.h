// Alexsandria Ryan
// Assignment #1
// PROG2100 - C++

#ifndef FILES_STRINGSIO_H
#define FILES_STRINGSIO_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <stdio.h>
#include <exception>

using namespace std;

string inputFile(const string& fileType, const string& action);
string validatePath(string filePath, const string& fileType);
bool checkFail(ifstream& inputFile, ofstream& outputFile, const string& cppFile, const string& htmlFile);
void readWriteFile(ifstream& inputFile, ofstream& outputFile);

#endif //FILES_STRINGSIO_H