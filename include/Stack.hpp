#include <stdlib.h>
#include <iostream>
#include <string>

#define INIT_SIZE 1 
#define MULTIPLIER 2  

using namespace std;

template <typename T>
class stack
{
	T*array_;
	size_t array_size_;
	size_t count_;
public:
	stack();
	stack(stack<T> const & obj);
	size_t count() const;
	size_t array_size() const;
	void push(T const &);
	stack<T>& operator=(stack<T>);
	T pop();
	~stack();
	friend T* New_n_copy(size_t ar_size, size_t count_, T* ar_);
	auto operator==(const stack & obj) const -> bool;
};


template <typename T>
stack<T>::stack() : array_size_(INIT_SIZE), count_(0) {
	std::cout << "constructor!"; array_ = new T[INIT_SIZE];
}

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
	if (count_ +1 > array_size_)
	{
		array_size_ *= MULTIPLIER;
		T * temp = New_n_copy(array_size_, count_, array_);
		delete[] array_;
		array_ = temp;
		std::cout << "\n ++++ Memory! ++++";
	}
	array_[count_] = obj;
	count_++;
}

template <typename T>
T stack<T>::pop() {
	if ( count_ > 0) 
	{
		T top = array_[count_ - 1];
		--count_;
		if ((array_size_ / count_) > MULTIPLIER)
		{
			array_size_ /= 1.5;
			T* temp = New_n_copy(array_size_, count_, array_);
			delete[] array_; std::cout << "---- Memory! ----";
			array_ = temp;
		}
		return top;
	}
	throw "nooooo!";
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
		throw "Dimension()";
	}
	for (unsigned int i = 0; i < count_; ++i) {
		if (array_[i] != object.array_[i]) 
		{
				return false;
		}
	}
	return true;
}


template<typename T>
T* New_n_copy(size_t ar_size, size_t count_, T* ar_){ 
	T*temp = new T[ar_size];
	std::copy(ar_, ar_+count_, temp);
	return temp;
}
