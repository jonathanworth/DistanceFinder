#include <iostream>
#include <fstream>
#include "LocationTree.h"
#include "Location.h"
#include "Menu.h"
#include "ReaderWriter.h"

using namespace std;

/*NOT SURE IF THIS IS WORKING**/
int main() {
	Menu men;
	ReaderWriter rw;
	string filename = "newloc.txt";
    LocationTree* locT = rw.createTreeFromFile(filename);
	int choice = -1;

	men.menuOptions(choice);


	return 0;
}
