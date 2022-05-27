#include "minivector.h"

namespace mvec {
	template <typename T>
	vector<T>::vector() {
		this->length = 0;
		this->arr_size = 0; // sizeof(T);
		// this->array = new T[sizeof(T)]; // (T*)malloc(sizeof(T));
		this->freed = true;
	}

	template <typename T>
	vector<T>::~vector() {
		this->dealloc();
	}

	template <typename T>
	bool vector<T>::push(T data, int index) {
		if (this->freed) {
			return false;
		}

		// do we need more heap?
		if ((sizeof(T) * this->arr_size)+1 > (sizeof(T) * this->arr_size)) {
			return true;
		} else {
			return false;
		}
	}

	template <typename T>
	unsigned int vector<T>::size() {
		return this->arr_size;
	}

	template <typename T>
	bool vector<T>::dealloc() {
		if (this->freed) {
			return true;
		} else {
			delete[] this->array;
		}
	}
}
