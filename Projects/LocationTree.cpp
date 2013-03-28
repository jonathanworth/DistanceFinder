/*
 * A binary search tree for storing location nodes
 *
 *  Created on: 26 Feb 2013
 *      Author: Ollie
 */

#include <string>
#include "LocationTree.h"

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

// Function that adds nodes to the tree, used on the new tree to install root
void LocationTree::addNode (Location *loc) {
   if ( root != NULL ) {
		cout << "adding a new node"<< endl;
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
*  Function to delete a node
*  Step 1: If node is a leaf delete
*  Step 2:If it has a single child, replace leaf with child
*  Step 3: If 2 children, find the closest replacement node
*  remove replacement node, remove target node and insert replacement
*
*/
void LocationTree::deleteNode(string ident) {
	Node* current = getCity(root, ident);
	// Step 1
	if (current->getLeft() == NULL && current->getRight() == NULL) {
		if (current->getIdent() > current->getParent()->getIdent()) {
			current->getParent()->setRight(NULL);
		} else {
			current->getParent()->setLeft(NULL);
		}
		delete current;
	}
	// Step 2
	else if (current->getLeft() == NULL && current->getRight() != NULL) { //if leaf right
		if (current->getIdent() > current->getParent()->getIdent()) {
			current->getParent()->setRight(current->getRight());
		} else {
			current->getParent()->setLeft(current->getRight());
		}
		delete current;
	}
	else if (current->getLeft() != NULL && current->getRight() == NULL) { //if leaf left
		if (current->getIdent() > current->getParent()->getIdent()) {
			current->getParent()->setRight(current->getLeft());
		} else {
			current->getParent()->setLeft(current->getLeft());
		}
		delete current;
	}
	// Step 3
	else {
        cout << "can't delete currently" << endl;
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




