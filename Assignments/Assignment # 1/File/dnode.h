#pragma once

template<typename T>
struct dnode 
{
    dnode<T> *prev;
    
    T data;
    dnode<T> *next;
};
