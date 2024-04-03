#pragma once

template<typename T>

struct node
{
	node<T> *next;
	T data;
};