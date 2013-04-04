//============================================================================
// Name        : Node.h
// Authors     : Bourgein, Oliver, Worth
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class to store locations in a tree
//============================================================================/*


#ifndef NODE_H_
#define NODE_H_

#include "Location.h"

using namespace std;

class Node {
private:
	int balance;
	int childLeft;
	int childRight;

public:

	string ident;
	int noDups;
	Node* left;
	Node* right;
	Node* parent;
	Location* location;

    //Constructor
	Node(Location *location);

	//Function Prototypes
	void setLeft(Node* left);
	void setRight(Node* right);
	void setParent(Node* parent);
	void setDuplicate(Node* dups);
	string getIdent();
	void setIdent(string id);
	Node* getLeft();
	Node* getRight();
	Node* getParent();
	Location* getLocation();
	void setLocation(Location* location);
	int getDupsNo();
	void plusDups();
	void minusDups();
	int getBalance();
	int getCL();
	int getCR();
	void plusCL();
	void minusCL();
	void plusCR();
	void minusCR();

};

#endif /* NODE_H_ */

