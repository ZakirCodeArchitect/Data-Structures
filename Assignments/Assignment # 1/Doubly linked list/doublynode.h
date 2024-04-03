#pragma once

template<typename T>
struct node
{
	node<T> *next;
	node<T> *prev;
	T data;
};