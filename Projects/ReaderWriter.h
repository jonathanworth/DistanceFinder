//============================================================================
// Name        : ReaderWriter.H
// Authors     : Bourgein, Oliver, Worth
// Date        :
// Copyright   : copyright reserved
// Description : A Read/Write Class to handle file  i/o
//============================================================================/*

#ifndef READERWRITER_H_
#define READERWRITER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Location.h"
#include "Node.h"
#include "LocationTree.h"

using namespace std;

class ReaderWriter {
public:
ReaderWriter();
LocationTree * createTreeFromFile(string fileName);
void saveFile(string fileName, LocationTree* locTree);

private:

};

#endif




