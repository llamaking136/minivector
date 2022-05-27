// #include "minivector.h"

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
	};

	template <class T>
	vector<T>::vector() {
		this->length = 0;
		this->arr_size = 0; // sizeof(T);
		// this->array = new T[sizeof(T)]; // (T*)malloc(sizeof(T));
		this->freed = true;
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

		// do we need more heap?
		if ((sizeof(T) * this->arr_size)+1 > (sizeof(T) * this->arr_size)) {
			return true;
		} else {
			return false;
		}
	}

	template <class T>
	unsigned int vector<T>::size() {
		return this->arr_size;
	}

	template <class T>
	bool vector<T>::dealloc() {
		if (this->freed) {
			return true;
		} else {
			delete[] this->array;
			return true;
		}
	}
}
