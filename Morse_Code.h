#pragma oncce
#include <iostream>
#include <string>
#include <map>

using namespace std;

class morse_code {
private:
	Binary_Tree Tree;
	map<char, string> Map_Key;
	morse_code();
	void add_node(char, string);
public:
	string decode(string);
	string encode(string);
};
