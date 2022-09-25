#include <string>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val) {
	//Variable Declaration
	TrieNode* myRoot = this->root;
	int index;
	
	//Go through each letter
	for(int i = 0; i < key.length(); i++) {
		index = key[i] - 'a';
		if(myRoot->children[index] == NULL) { //if node to letter doesn't exist
			myRoot->children[index] = new TrieNode(); //create new node
			(this->tree_size)++; 
		}	
		myRoot = myRoot->children[index]; //go down tree
	}
	myRoot->val = val; //change val
	(this->map_size)++;
}

int Trie::search(string key) {
	TrieNode* myRoot = this->root;
	int index;
	for(int i = 0; i < key.length(); i++) {
		index = key[i] - 'a';
		if(myRoot->children[index] == NULL) return 0; //if any pointer doesnt exist return 0
		myRoot = myRoot->children[index];
	}
    return myRoot->val;
}

void Trie::remove(string key) {
	TrieNode* myRoot = this->root;
	int index;
	bool hasChildren = false;
	
	for(int i = 0; i < key.length(); i++) {
		index = key[i] - 'a';
		if(i == key.length() - 1) {
			for(int i = 0; i < ALPHABET_SIZE; i++) { //check if leaf
				if(myRoot->children[index]->children[i] != NULL) 
				hasChildren = true;
			}
			if(hasChildren) { //if not leaf set val to 0
				myRoot->children[index]->val = 0;
				(this->map_size)--;
			} else { //if leaf set to NULL
				myRoot->children[index] = NULL;
				(this->map_size)--;
				(this->tree_size)--;
			}
		}
		myRoot = myRoot->children[index];
	}
	return;
}