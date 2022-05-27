#pragma once

#if !defined(NULL)
#define NULL (void*)0
#endif

namespace mvec {
	template <class T>
	class vector {
	public:
		 vector();
		~vector();

		bool push_back(T);
		bool write(T, int);
		// T pop_back();
		// T remove(int);
		unsigned int size();
		unsigned int mem_used();
		bool dealloc();

		T& operator[](int);
	private:
		unsigned int length; // amount of data
		unsigned int arr_size; // size of array in bytes
		T* array;
		bool freed;
		bool used_array;
	};

	template <class T>
	vector<T>::vector() {
		this->length = 0;
		this->arr_size = 0; // sizeof(T);
		// this->array = new T[sizeof(T)]; // (T*)malloc(sizeof(T));
		this->freed = false;
		this->used_array = false;
	}

	template <class T>
	vector<T>::~vector() {
		this->dealloc();
	}

	template <class T>
	bool vector<T>::push_back(T data) {
		if (this->freed) {
			return false;
		}

		T* temp = new T[this->arr_size + sizeof(T)];
		if (!temp) {
			return false;
		}

		for (unsigned int i = 0; i < this->length; i++) {
			temp[i] = this->array[i];
		}
		
		this->arr_size += sizeof(T);
		this->length++;
		if (this->used_array) {
			delete[] this->array;
		}
		this->array = temp;
		this->array[this->length-1] = data;

		this->used_array = true;

		return true;
	}

	template <class T>
	bool vector<T>::write(T data, int index) {
		if (this->freed) {
			return false;
		}
		
		if (index > this->length || index < 0 || (index == 0 && !this->freed)) {
			return false;
		}

		this->array[index] = data;

		this->used_array = true;

		return true;
	}

	template <class T>
	unsigned int vector<T>::size() {
		return this->length;
	}

	template <class T>
	unsigned int vector<T>::mem_used() {
		return this->arr_size;
	}

	template <class T>
	bool vector<T>::dealloc() {
		if (this->freed || !this->used_array) {
			return true;
		} else {
			delete[] this->array;
			this->arr_size = 0;
			return true;
		}
	}

	template <class T>
	T& vector<T>::operator[](int index) {
		/*
		if (this->freed) {
			return &nullptr;
		}

		if (index > this->length || index < 0) {
			return &nullptr;
		}
		*/

		return this->array[index];
	}
}
