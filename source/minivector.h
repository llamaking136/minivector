#pragma once

namespace mvec {
	template <typename T>
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
}
