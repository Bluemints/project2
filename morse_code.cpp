#pragma once
#include"morse_code.h"
#include<fstream>
#include<sstream>

morse_code::morse_code() {
	decodeTree = Binary_Tree<char>(' ');
	std::ifstream fin("morse.txt");
	char c;
	std::string code;
	while (fin >> c) {
		fin >> code;
		addnode(c, code);
		characterMap[c] = code;
	}
}

void morse_code::addnode(char c, std::string code) {
	std::stringstream stream(code);
	BTNode<char>* localroot = decodeTree.getRoot();
	char next;
	while (stream >> next) {
		if (next == '.') {
			// If there is no left node, create one
			if (localroot->left == NULL)
				localroot->left = new BTNode<char>(NULL);
			localroot = localroot->left;
		}
		else if (next == '_') {
			// If there is no right node, create one
			if (localroot->right == NULL)
				localroot->right = new BTNode<char>(NULL);
			localroot = localroot->right;
		}
		else {
			// unexpected character encountered, throw error here
		}
	}
	localroot->data = c;
}

std::string morse_code::decode(std::string code) {
	std::stringstream stream(code);
	std::string return_string = "";
	BTNode<char>* localroot = decodeTree.getRoot();
	char next;
	while (stream.good()) {
		next = stream.get();
		if (next == '.')
			localroot = localroot->left;
		else if (next == '_')
			localroot = localroot->right;
		else if (next == ' ') 
		{
			return_string += localroot->data;
			localroot = decodeTree.getRoot();
		}
		else 
		{
			//throw error, unexpected character encountered
		}
	}
	return return_string;
}

std::string morse_code::encode(std::string word) {
	std::string return_string = "";
	std::stringstream stream(word);
	char next;
	while (stream >> next)
		return_string += characterMap[tolower(next)] + " ";
	return return_string;
}
