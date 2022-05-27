#pragma once

namespace mvec {
	template <class T>
	class vector {
	public:
		 vector();
		~vector();

		// bool push_back(T);
		bool push(T, int);
		// T pop_back();
		// T pop(int);
		unsigned int size();
		bool dealloc();

		// T& operator[](int);
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
	bool vector<T>::push(T data, int index) {
		if (this->freed) {
			return false;
		}
		this->used_array = true;
		
		// if the index is outside the array boundary, we just push onto the end
		if (index > this->length+1) {
			index = this->length;
		}

		// add one more element to array

	}

	template <class T>
	unsigned int vector<T>::size() {
		return this->arr_size;
	}

	template <class T>
	bool vector<T>::dealloc() {
		if (this->freed || !this->used_array) {
			return true;
		} else {
			delete[] this->array;
			return true;
		}
	}
}
