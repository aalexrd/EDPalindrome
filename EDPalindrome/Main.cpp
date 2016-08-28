#include "LinkedList.h"
#include <iostream>

bool isPalindrome(std::string);
std::string getString();

int main()
{
	std::cout << "Ingrese una palabra para ver si es palindrome: ";
	if (isPalindrome(getString()))
		std::cout << "Es palindrome!" << std::endl;
	else
		std::cout << "No es palindrome!" << std::endl;
	std::cin.get();
	return 0;
}

bool isPalindrome(std::string s)
{
	LinkedList<char> characters, reversedChars;
	for (char x : s)
		if (x != 32)
		{
			characters.add(tolower(x));
			reversedChars.addFirst(tolower(x));
		}
	Node<char> *iterator = characters.listIterator(0), *iteratorReversed = reversedChars.listIterator(0);
	while (iterator)
	{
		if (iterator->getData() != iteratorReversed->getData())
			return false;
		iterator = iterator->getNext();
		iteratorReversed = iteratorReversed->getNext();
	}
	return true;
}

std::string getString()
{
	std::string line;
	while (true)
	{
		getline(std::cin, line);
		if (line.empty())
			continue;
		return line;
	}
}
