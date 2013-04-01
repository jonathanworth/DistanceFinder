//============================================================================
// Name        : Node.cpp
// Authors     : Bourgein, Oliver, Worth
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class for insertion into binary tree
//============================================================================/*

#include <string>
#include "Location.h"
#include "Node.h"

using namespace std;

	// Constructor creates an instance
	Node::Node(Location *location) {
		noDups = 0;
		ident=location->getCityName();
		this->location = location;
		left=NULL;
		right=NULL;
		parent=NULL;
		cout << "Node object created with name: " << ident << endl;
		};

	// Function to set left node
	void Node::setLeft(Node* left) {
		this->left = left;
	}

	// Function to set right node
	void Node::setRight(Node* right) {
		this->right = right;
	}

	// Function to set parent node
	void Node::setParent(Node* parent) {
		this->parent = parent;
	}

	// Function to return nodes name
	string Node::getIdent() {
		return this->ident;
	}

	// Function to return left node
	Node* Node::getLeft() {
		return this->left;
	}

	// Function to return right node
	Node* Node::getRight() {
		return this->right;
	}

	// Function to return parent node
	Node* Node::getParent() {
		return this->parent;
	}

	// Function to return location pointer
	Location* Node::getLocation() {
		return this->location;
    }

	void Node::setIdent(string id){
		this->ident = id;
	}

	int Node::getDupsNo() {
		return noDups;
	}

	void Node::plusDups() {
		noDups++;
    }

	void Node::minusDups() {
		noDups--;
	}






