#pragma once
#ifndef NODE_H
#define NODE_H

template <class T>

class Node
{
private:
	T data;
	Node<T>* next;
public:
	explicit Node(T);
	T getData() const;
	void setData(T);
	Node<T>* getNext() const;
	void setNext(Node<T>*);
};
#endif
