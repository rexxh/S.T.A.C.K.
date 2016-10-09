#pragma once
#ifndef Stack_hpp
#define Stack_hpp
#include <stdlib.h>
#include <iostream>
#include <string>
 
#define MULTIPLIER 2  

using namespace std;

template<typename T>
T* New_n_copy(size_t ar_size, size_t count_, T* ar_){ /* strong */
	T*temp = new T[ar_size];
	try {
	std::copy(ar_, ar_+count_, temp);
	}
	catch (...) {
		delete [] temp;
		throw;
	}
	return temp;
}


template <typename T>
class stack
{
	T*array_;
	size_t array_size_;
	size_t count_;
public:
	stack(); /* noexcept */
	stack(stack<T> const & obj); /* strong */
	size_t count() const; /* noexcept */
	size_t array_size() const; /* noexcept */
	void push(T const &); /* strong */
	void pop(); /* strong */
        const T& top(); /* strong */
	stack<T>& operator=(const stack<T> &); /* strong */
	auto operator==(const stack & obj) const -> bool; /* strong */
	~stack(); /* noexcept */
};


template <typename T>
stack<T>::stack() : array_size_(0), count_(0), array_(nullptr){}
	

template <typename T>
size_t stack<T>::count() const {
	return count_;
}

template <typename T>
stack<T>::~stack(){
	delete[] array_;
}

template <typename T>
size_t stack<T>::array_size() const {
	return array_size_;
}

template <typename T>
void stack<T>::push(T const &obj) {
	if (count_ +1 > array_size_)
	{
		if (array_size_ == 0) 
		{ 
			++array_size_; 
			array_ = new T[array_size_];
		}
		else {
			T * temp = New_n_copy(array_size_* MULTIPLIER, count_, array_);
			delete[] array_;
			array_ = temp;
			array_size_ *= MULTIPLIER;	
		}
	}
	array_[count_] = obj;
	count_++;
}

template <typename T>
void stack<T>::pop() {
	if (count_==0)
	{
		throw("the stack is empty");
	}
	--count_;
}

template <typename T>
const T& stack<T>::top() {
	if (count_==0)
	{
		throw("the stack is empty");
	}
	return array_[count_-1];
}

template <typename T>
stack<T>::stack(const stack<T>& obj) : array_size_(obj.array_size_), count_(obj.count_){
	array_ = New_n_copy(array_size_, count_, obj.array_);
}

template <typename T>
stack<T>& stack<T>::operator=(const stack<T> &obj) {
    if (this != &obj) {
	    T *tmp = array_;
		array_ = New_n_copy(obj.array_size_, obj.count_, obj.array_);
		delete[] tmp;
		count_ = obj.count_;
		array_size_ = obj.array_size_;
   
    }
    return *this;
}

template <typename T>
auto stack<T>::operator==(const stack & object) const -> bool
{
	if (count_ != object.count_) {
		throw ("Wrong Dimension");
	}
	for (unsigned int i = 0; i < count_; ++i) {
		if (array_[i] != object.array_[i]) 
		{
				return false;
		}
	}
	return true;
}

#endif
