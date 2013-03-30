//============================================================================
// Name        : LocationTree.h
// Author      : Ollie
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class for insertion into binary tree
//============================================================================/*


#ifndef LocationTree_H_
#define LocationTree_H_

#include "Location.h"
#include "Node.h"

using namespace std;

class LocationTree {
private:
	Node* root;

public:
	Node* getRoot();
	Node* setRoot(Node* node);
	Node* getCity(Node* node, string ident);
	void addNode (Location *loc); // To add first node
	void addNode(Location *loc, Node* leaf);
	bool deleteNode (string ident);
	void freeNode(Node* leaf);
	Node* getPrevious(Node* node, string ident);
	Node* getNext(Node* node, string ident);
	Node* getFirst(Node* node);
	Node* getLast(Node* node);
	Node* getFarLeft(Node* node, string ident);
	Node* getFarRight(Node* node, string ident);


	// Default Constructor
	LocationTree();

	// Destructor
	~LocationTree();
};

#endif /* NODE_H_ */

