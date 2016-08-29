#include "LinkedList.h"

template <class T>
Node<T>* LinkedList<T>::getNewNode(T t)
{
	return new Node<T>(t);
}

template <class T>
LinkedList<T>::LinkedList<T>() : first(nullptr), last(nullptr), size(0)
{
}

template <class T>
LinkedList<T>::~LinkedList<T>()
{
	clear();
}

template <class T>
void LinkedList<T>::add(T t)
{
	Node<T>* newPtr = getNewNode(t);
	if (isEmpty())
	{
		size = 1;
		first = last = newPtr;
	}
	else
	{
		last->setNext(newPtr);
		last = newPtr;
		++size;
	}
}

template <class T>
void LinkedList<T>::add(unsigned int i, T t)
{
	int index = 0;
	if (i == 0)
		addFirst(t);
	else if (i == size - 1)
		addLast(t);
	else
	{
		Node<T>* newPtr = getNewNode(t);
		Node<T>* iterator = first;
		Node<T>* aux;
		while (index < i - 1)
		{
			iterator = iterator->getNext();
			++index;
		}
		aux = iterator->getNext();
		iterator->setNext(newPtr);
		newPtr->setNext(aux);
		++size;
	}
}

template <class T>
void LinkedList<T>::addFirst(T t)
{
	Node<T>* newPtr = getNewNode(t);
	if (isEmpty())
	{
		size = 1;
		first = last = newPtr;
	}
	else
	{
		newPtr->setNext(first);
		first = newPtr;
		++size;
	}
}


template <class T>
void LinkedList<T>::addLast(T t)
{
	add(t);
}

template <class T>
void LinkedList<T>::clear()
{
	if (isEmpty())
		return;
	Node<T>* iterator = first;
	Node<T>* tempPtr;
	while (iterator)
	{
		tempPtr = iterator;
		iterator = iterator->getNext();
		delete tempPtr;
	}
	first = last = nullptr;
	size = 0;
}

// Verify if item 't' is in the list.
template <class T>
bool LinkedList<T>::contains(const T& t)
{
	Node<T>* iterator = first;
	while (iterator)
	{
		if (iterator->getData() == t)
			return true;
		iterator = iterator->getNext();
	}
	return false;
}

// Returns the direction in memory of item 'i'.
template <class T>
T LinkedList<T>::get(unsigned int i)
{
	int index = 0;
	if (i == 0)
		return getFirst();
	if (i == size - 1)
		return getLast();
	Node<T>* iterator = first;
	while (index != i)
	{
		iterator = iterator->getNext();
		++index;
	}
	return iterator->getData();
}


template <class T>
T LinkedList<T>::getFirst() const
{
	return first->getData();
}


template <class T>
T LinkedList<T>::getLast() const
{
	return last->getData();
}

template <class T>
int LinkedList<T>::getSize() const
{
	return size;
}

// Returns index of item 't'
template <class T>
int LinkedList<T>::indexOf(const T& t) const
{
	Node<T>* iterator = first;
	int i = 0;
	while (iterator)
	{
		if (iterator->getData() == t)
			return i;
		iterator = iterator->getNext();
		++i;
	}
	return -1;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
	return first == nullptr;
}

// Returns an "iterator", pointer of the list in the position 'i'
template <class T>
Node<T>* LinkedList<T>::listIterator(unsigned int i)
{
	int index = 0;
	if (i == 0)
		return first;
	if (i == size - 1)
		return last;
	Node<T>* iterator = first;
	while (index != i)
	{
		iterator = iterator->getNext();
		++index;
	}
	return iterator;
}

// Removes and returns first item in the list.
template <class T>
T LinkedList<T>::pop()
{
	T aux = first->getData();
	removeItem(0);
	return aux;
}

// Push new item to the beginning of list.
template <class T>
void LinkedList<T>::push(T t)
{
	addFirst(t);
}

// Removes item number 'i'.
template <class T>
void LinkedList<T>::remove(unsigned int i)
{
	if (isEmpty() || i > size)
		return;
	int index = 0;
	if (i == 0)
	{
		Node<T>* aux = first;
		first = first->getNext();
		delete aux;
		--size;
	}
	if (i == size - 1)
	{
		Node<T>* aux = last;
		Node<T>* iterator = first;
		while (index < size - 1)
		{
			iterator = iterator->getNext();
			++index;
		}
		last = iterator;
		iterator->setNext(nullptr);
		delete aux;
		--size;
	}
	else
	{
		Node<T>* aux;
		Node<T>* iterator = first;
		while (index < i - 1)
		{
			iterator = iterator->getNext();
			++index;
		}
		aux = iterator->getNext();
		iterator->setNext(aux->getNext());
		delete aux;
		--size;
	}
}

// Removes 't' from list.
template <class T>
void LinkedList<T>::removeItem(const T& t)
{
	int index = indexOf(t);
	remove(index);
}


/* Reverse the list order
* http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
*/
template <class T>
void LinkedList<T>::reverse()
{
	Node<T> *iterator = first, *result = nullptr, *next;
	if (first != last && iterator)
	{
		last = first;
		while (iterator)
		{
			next = iterator->getNext();
			iterator->setNext(result);
			result = iterator;
			iterator = next;
		}
		first = result;
	}
}

// Replaces an item in 'i' position with 't'.
template <class T>
void LinkedList<T>::set(unsigned int i, T t)
{
	if (i > size - 1)
		add(t);
	else
		listIterator(i)->setData(t);
}

// Replaces first item of list.
template <class T>
void LinkedList<T>::setFirst(T t)
{
	first->setData(t);
}

// Replaces last item of list.
template <class T>
void LinkedList<T>::setLast(T t)
{
	last->setData(t);
}

// Returns items of std::string or a native variable in a std::string.
template <class T>
std::string LinkedList<T>::toString() const
{
	if (isEmpty())
		return "";
	Node<T>* actualPtr = first;
	std::stringstream out;
	while (actualPtr)
	{
		out << actualPtr->getData() << std::endl;
		actualPtr = actualPtr->getNext();
	}
	return out.str();
}

template class LinkedList<char>;
