#pragma once
#include<string>
#include<map>
#include "Binary_Tree.h"

class morse_code {
public:
	morse_code();
	//morse_code(std::string);
	std::string encode(std::string);
	std::string decode(std::string);
private:
	Binary_Tree<char> decodeTree;
	std::map<char, std::string> characterMap;
	void addnode(char, std::string);
};
