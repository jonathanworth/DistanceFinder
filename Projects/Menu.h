#ifndef Menu_H
#define Menu_H

using namespace std;

class Menu {
public:
	//Constructor
	Menu();

	//Function Prototypes
    void menuOptions(int &choice);
    void addRecord();
    void administerRecord();
    void findDistance();

};

#endif
