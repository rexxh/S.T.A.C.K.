#include <stdlib.h>
#include <iostream>
#include <string>

#define MULTIPLIER 2  

using namespace std;

template <typename T>
class stack;

template<typename T>
T* New_n_copy(size_t ar_size, size_t count_, T* ar_){
	T*temp = new T[ar_size];
	std::copy(ar_, ar_ + count_, temp);
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
	T pop(); /* strong */
	stack<T>& operator=(stack<T>); /* strong */
	auto operator==(const stack & obj) const -> bool; /* strong */
	friend T* New_n_copy <>(size_t ar_size, size_t count_, T* ar_);
	~stack(); /* noexcept */
};


template <typename T>
stack<T>::stack() : array_size_(0), count_(0) {}

template <typename T>
size_t stack<T>::count() const {
	return count_;
}

template <typename T>
stack<T>::~stack(){
	std::cout << "\ndestructor!"; delete[] array_;
}

template <typename T>
size_t stack<T>::array_size() const {
	return array_size_;
}

template <typename T>
void stack<T>::push(T const &obj) {
	if (count_ + 1 > array_size_)
	{
		if (array_size_ == 0) 
		{ 
			++array_size_; 
			array_ = new T[array_size_];
		}
		else {
			array_size_ *= MULTIPLIER;
			T * temp = New_n_copy(array_size_, count_, array_);
			delete[] array_;
			array_ = temp;
		}
	}
	array_[count_] = obj;
	count_++;
}

template <typename T>
T stack<T>::pop() {
	if ( count_ > 0) 
	{
		return array_[--count_];
	}
	throw ("The stack is empty");
}

template <typename T>
stack<T>::stack(const stack<T>& obj) : array_size_(obj.array_size_), count_(obj.count_){
	array_ = New_n_copy(array_size_, count_, obj.array_);
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> obj){
		swap(obj.array_size_, array_size_);
		swap(obj.count_, count_);
		swap(obj.array_, array_);
		return *this;
}

template <typename T>
auto stack<T>::operator==(const stack & object) const -> bool
{
	if (count_ != object.count_) {
		throw ("Wrong dimension");
	}
	for (unsigned int i = 0; i < count_; ++i) {
		if (array_[i] != object.array_[i]) 
		{
				return false;
		}
	}
	return true;
}
