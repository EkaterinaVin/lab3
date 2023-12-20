#pragma once

#include <iostream>

using namespace std;
const int MaxStackSize = 255;

template <class T>
class TStack {
protected:
	int size;
	int top=-1;
	T* pMem;
public:
	TStack(int n = 10)
	{
		if ((n < 1) || (n > MaxStackSize))
			throw "wrong size";
		size = n;
		top = -1;
		pMem = new T[size]();
	}
	TStack(TStack<T>& stack)
	{
		size = stack.size;
		top = stack.top;
		pMem = new T[size];
		for (int i = 0; i < size; i++) {
			pMem[i] = stack.pMem[i];
		}
	}
	~TStack()
	{
		delete[] pMem;
	}

	void Push(T a) {
		
		if (top == size - 1) {
			T* tmpMem = new T[size * 2];
			std::copy(pMem, pMem + size, tmpMem);
			delete[] pMem;
			pMem = tmpMem;
			size *= 2;
		}
		pMem[++top] = a;
		
	}
	
	T TopView()
	{
		return pMem[top];
	}

	int GetSize()
	{
		return size;
	}
	int GetTop()
	{
		return top;
	}



	bool IsFull()
	{
		if (top == size - 1)
			return true;
		else
			return false;
	}
	bool IsEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	TStack& operator=(const TStack<T>& stack)
	{
		swap(*this, stack);
		return *this;
	}
	friend void swap(TStack& a, TStack& b)
	{
		swap(a.top, b.top);
		swap(a.memSize, b.memSize);
		swap(a.pMem, b.pMem);
	}
	//операторы вводы и выводы
	friend ostream& operator << (ostream& ostr, const TStack<T>& a) {
		for (int i = 0; i < a.top; i++) {
			ostr << a.pMem[i] << " ";
		}
		ostr << endl;
		return ostr;
	}
	friend istream& operator >> (istream& istr, TStack<T>& a) {
		for (int i = 0; i < a.GetSize(); i++) {
			istr >> a.pMem[i];
		}
		a.top = a.size;
		return istr;
	}
	T Pop() {
		if (IsEmpty()) 
			throw  "stack is empty";
		return pMem[top--];
	}
};


