#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
const int MaxStackSize = 100;

template <class T>
class TStack
{
    T *pMem;
    int size;
    int top;
public:
    TStack(int size_ = 1): size(size_), top(-1)
    {
        if ((size < 1) || (size > MaxStackSize))
            throw std::out_of_range("Size of stack must be between 1 and 100");
        pMem = new T[size];
    }
    TStack(const TStack&) = delete;
    TStack(TStack&&) = delete;
    TStack& operator=(const TStack&) = delete;
    TStack& operator=(TStack&&) = delete;
    bool Empty() const noexcept
    {
        return top == -1;
    }
    bool Full() const noexcept
    {
        return top == (size - 1);
    }
    int Size() const noexcept
    {
        return top + 1;
    }

    void Push(const T& element)
    {
        if (Full())
            throw "Stack is full";
        pMem[++top] = element;
    }
    void Pop()
    {
        if (Empty())
            throw "Stack is empty";
        --top;
    }
    T Top()
    {
        if (Empty())
            throw "Stack is empty";
        return pMem[top];
    }
    void Clear() noexcept
    {
        top = -1;
    }
    ~TStack()
    {
        delete[] pMem;
    }
};

#endif
