#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Stack {
public:
	Stack();
	~Stack();

	void push(std::string date);
	std::string pop();
	std::string peek();
	bool isEmpty();
	std::string getStack();

private:
	int size;
	int maxSize;
	std::string top[25];
	//std::string* top;
};