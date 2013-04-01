//============================================================================
// Name        : LocationTree.cpp
// Authors     : Bourgein, Oliver, Worth
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Binary Tree Class to store Nodes
//============================================================================/*


#include <string>
#include "LocationTree.h"
#include "Menu.h"

using namespace std;

// Constructor
LocationTree::LocationTree() {
	cout << "LocationTree object created" << endl;
	root = NULL;
}

// Destructor
LocationTree::~LocationTree() {
	freeNode(root);
}

// Function to find root
Node* LocationTree::getRoot() {
	return root;
	}

// Function to set root
Node* LocationTree::setRoot(Node* node) {
	root == node;
	}

//Function that adds new city locations to the tree (Nodes).
// Uses the 2 addNode methods below
bool LocationTree::addToTree(LocationTree* tree, Location* loc, Node* node, string city) {
	Node* duptest = getCity(node, city);
	if (duptest != NULL ) {
		Location* newDup = duptest->getLocation();
		while (newDup->getDups() != NULL) {
			newDup = newDup->getDups();
			loc->plusNum();
		}
		newDup->setDups(loc);
		loc->plusNum();
		duptest->plusDups();
		cout << "Adding new duplicate, locNum: " << loc->getNum() << " noDups: " << duptest->getDupsNo() <<
		endl;
	} else {
		tree->addNode(loc);
	}
}

// Function that adds nodes to the tree, used on the new tree to install root
void LocationTree::addNode (Location *loc) {
   if ( root != NULL ) {
		cout << "Tree established: adding a new node"<< endl;
		addNode(loc, root);
	} else {
		cout << "creating the root node" << endl;
		Node* n = new Node(loc);
		n->setIdent(loc->getCityName());
		root = n;
	}
}

// Function that adds nodes to the tree, finding the right position
void LocationTree::addNode(Location *loc, Node* leaf) {
	string ident = loc->getCityName();
	if ( ident <= leaf->getIdent() )
	{
		if ( leaf->getLeft() != NULL )
			addNode(loc, leaf->getLeft());
		else {
			Node* n = new Node(loc);
			n->setIdent(ident);
			n->setParent(leaf);
			leaf->setLeft(n);
		}
	}
	else
	{
		if ( leaf->getRight() != NULL )
			addNode(loc, leaf->getRight());
		else {
			Node* n = new Node(loc);
			n->setIdent(ident);
			n->setParent(leaf);
			leaf->setRight(n);
		}
	}
}

// Function that finds the furthest left entry
Node* LocationTree::getFirst(Node* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->getLeft()) {
		getFirst(node->getLeft());
	}
	else {
		return node;
	}
}

// Function that finds the furthest right entry
Node* LocationTree::getLast(Node* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->getRight()) {
		getLast(node->getRight());
	}
	else {
		return node;
	}
}

// Function that finds the furthest left entry (min) from a defined node
Node* LocationTree::getFarLeft(Node* node, string ident) {
	Node* current = getCity(node, ident);
	if (current->getLeft() != NULL) {
		return getFirst(current->getLeft());
	} else {
		return current;
	}
}


// Function that finds the furthest right entry (max) from the current node
Node* LocationTree::getFarRight(Node* node, string ident) {
	Node* current = getCity(node, ident);
	if (current->getRight() != NULL) {
		return getLast(current->getRight());
	} else {
		return current;
	}

}

/**
*	Function that finds the closest smaller node to the defined node
*/
Node* LocationTree::getPrevious(Node* node, string ident) {
	Node* current = getCity(node, ident);
	if (current != NULL) {
		return getLast(current->getLeft());
	} else {
		return current;
	}
}


// Function that finds the closest larger node the current node
Node* LocationTree::getNext(Node* node, string ident) {
	Node* current = getCity(node, ident);
	if (current != NULL) {
		return getFirst(current->getRight());
	} else {
		return current;
	}

}
/**
*   Function to delete a duplicate location
*	if location is last in list delete
*	if location is within list join before and after then delete
*/
bool LocationTree::deleteDupNode(Node* foundNode, int number) {
    Location* foundLoc = foundNode->getLocation();
	while (foundLoc->getNum() != number-1) { // find preceding loc
		foundLoc = foundLoc->getDups();
	}
	if (number == foundNode->getDupsNo()+1) {  // if last
		foundLoc->setDups(NULL);
	} else {
		foundLoc->setDups(foundLoc->getDups()->getDups()); // rejoin to following
    }
}



/**
*  Function to delete a node
*  Step 1: If node is a leaf delete
*  Step 2:If it has a single child, replace leaf with child
*  Step 3: If 2 children, find the closest replacement node
*  remove replacement node, remove target node and insert replacement
*/
bool LocationTree::deleteNode(string ident) {
	Node* current = getCity(root, ident);
	// Step 1
	if (current->getLeft() == NULL && current->getRight() == NULL) {
		// Check if root node
		if (current->getParent() == NULL) {
			cout << "This is the only entry in the tree" << endl;
			cout << "It cannot be deleted" << endl;
		}
		// Delete node
		else if (current->getIdent() > current->getParent()->getIdent()) {
			current->getParent()->setRight(NULL);
		} else {
			current->getParent()->setLeft(NULL);
		}
		delete current;
		return true;
	}
	// Step 2
	else if (current->getLeft() == NULL && current->getRight() != NULL) { //if leaf right
		// Check if root
		if (current->getParent() == NULL) {
			cout << "Creating new root" << endl;
			root = current->getRight();
			current->getRight()->setParent(NULL);
		}
		// Determine if node is on a right or left leaf
		else if (current->getIdent() > current->getParent()->getIdent()) { // if on right
			current->getParent()->setRight(current->getRight()); // Reset parents right
		} else {
			current->getParent()->setLeft(current->getRight()); // Reset parents left
		}
		delete current;
		return true;
	}
	else if (current->getLeft() != NULL && current->getRight() == NULL) { //if leaf left
		 // Check if root
		if (current->getParent() == NULL) {
			cout << "Creating new root" << endl;
			root = current->getLeft();
			current->getLeft()->setParent(NULL);
			}
		// Determine if parent is on a right or left leaf
		else if (current->getIdent() > current->getParent()->getIdent()) {
			current->getParent()->setRight(current->getLeft()); // Reset parents right
		} else {
			current->getParent()->setLeft(current->getLeft()); // Reset parents left
		}
		delete current;
		return true;
	}
	// Step 3
	else if (current->getLeft() != NULL && current->getRight() != NULL) { //if two leaves
		// Find nearest previous node
		Node* previous = getPrevious(current, ident);
		cout << "Previous: " << previous->getIdent() << endl;
		// Find nearest next node
		Node* next = getNext(current, ident);
		cout << "Next: " << next->getIdent() << endl;
		// create char arrays for comparison
		char * cstrCurr = new char[current->getIdent().length()+1];
		strcpy (cstrCurr, current->getIdent().c_str());
		char * cstrPrev = new char[previous->getIdent().length()+1];
		strcpy (cstrPrev, previous->getIdent().c_str());
		char * cstrNext = new char[next->getIdent().length()+1];
		strcpy (cstrNext, next->getIdent().c_str());
		// char[] copies of names made
		// find the nearest previous or next
		int prevDist, nextDist;
		int totPrev, totNext;
		int comLngth = ((current->getIdent().length() < previous->getIdent().length()) ? current->getIdent().length() : previous->getIdent().length());
		comLngth = ((comLngth < next->getIdent().length()) ? comLngth : next->getIdent().length());
		Node* selected = previous; // Pointer to the best replacement (default: previous)
		for (int i = 0; i < comLngth; i++) {
			totPrev = (cstrCurr[i]-cstrPrev[i]);
			totNext = (cstrNext[i]-cstrCurr[i]);
			if (totPrev < totNext || i == comLngth-1) {
				selected = previous;
				cout << "previous is closer: " << selected->getIdent() << endl;
				if (previous->getIdent() > previous->getParent()->getIdent()) { // If parent left
					if (previous->getLeft() == NULL) { // previous = leaf
						previous->getParent()->setRight(NULL); // Reset parents right
						cout << "Here we are 235" << endl;
					} else {
						previous->getParent()->setRight(previous->getLeft());
					}
				} else {  // Parent right
					if (previous->getLeft() == NULL) { // previous = leaf
						previous->getParent()->setLeft(NULL); // Reset parents right
						cout << "Here we are 242" << endl;
					} else {
						previous->getParent()->setLeft(previous->getLeft());
					}
				}
				break;
			} else {
				selected = next;
				cout << "next is closer: " << selected->getIdent() << endl;
				if (next->getIdent() > next->getParent()->getIdent()) { // If parent left
					if (next->getRight() == NULL) { // next = leaf
						next->getParent()->setRight(NULL); // Reset parent's right
					} else {
						next->getParent()->setRight(next->getRight());
					}
				} else {
					if (next->getRight() == NULL) {  // next = leaf
						next->getParent()->setRight(NULL);
					} else {
						next->getParent()->setRight(next->getRight());
					}
				}
				break;
			}
		}
		// Replacement node is now 'selected'
		// Link replacement to current's child nodes
		selected->setLeft(current->getLeft());
		cout << selected->getIdent() << " selected left now points to: " << endl;
		selected->setRight(current->getRight());
		cout << selected->getIdent() << " selected right now points to: " << endl;
		// Check if root
		if (current->getParent() == NULL) {
			cout << "Creating new root: " << endl;
			selected->setParent(NULL);
			//setRoot(selected);
			root = selected;
			cout << selected->getIdent() << " will be the root" << endl;
			cout << root->getIdent() << " is the new root node" << endl;
		}
		// Determine if parent is on a right or left leaf
		else if (current->getIdent() > current->getParent()->getIdent()) { // if on right
			current->getParent()->setRight(selected); // Reset parents right
		} else {
			current->getParent()->setLeft(selected); // Reset parents left
		}
		delete current;
		return true;
		}
	else {
		cout << "can't delete currently" << endl;
		return false;
	}
}

// Remove node
void LocationTree::freeNode(Node* leaf) {
	if (leaf != NULL) {
		freeNode(leaf->getLeft());
		freeNode(leaf->getRight());
		delete leaf;
	}
}

Node* LocationTree::getCity(Node* node, string ident)  {
	if (node != NULL) {
		if (ident == node->getIdent()) {
		return node;
		}
		if (ident < node->getIdent()) {
		return getCity(node->getLeft(), ident);
		}
		else {
		return getCity(node->getRight(), ident);
		}
	}
	else {
		return NULL;
	}
}




