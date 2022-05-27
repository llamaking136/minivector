#pragma once

namespace mvec {
	template <typename T>
	class vector {
	public:
		 vector();
		~vector();

		bool push_back(T);
		bool push(T, int);
		T pop_back();
		T pop(int);
		unsigned int size();
		bool dealloc();
	private:
		unsigned int length;
		unsigned int arr_size;
		T* array;
	};
}
