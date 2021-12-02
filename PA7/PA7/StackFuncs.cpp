#include "Stack.hpp"

Stack::Stack() {
	size = 0;
	maxSize = 25;
	//top = new std::string[25];
}

Stack::~Stack() {/*wntdll.pdb not loaded
	if (isEmpty()) {
		delete top;
	} else {
		delete[] top;
	}*/
}

void Stack::push(std::string date) {
	top[size] = date;
	++size;
}

std::string Stack::pop() {
	--size;
	std::string returnString = top[size];
	top[size] = "";
	return returnString;
}

std::string Stack::peek() {
	if (!isEmpty()) {
		int tsize = size - 1;
		return top[tsize];
	} else {
		return top[size];
	}
}

bool Stack::isEmpty() {
	return (size == 0) ? true : false;
}


std::string Stack::getStack() {
	Stack temp;
	std::string returnStr;
	std::string str;
	while (!isEmpty()) {
		str = pop();
		temp.push(str);
		returnStr = returnStr + " " + str;
	}
	while (!temp.isEmpty()) {
		str = temp.pop();
		push(str);
	}
	return returnStr;
}