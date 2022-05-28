#include <minivector.h>
#include <iostream>

int main() {
	mvec::vector<int> ree;
	ree.push_back(0);
	ree.push_back(1);
	ree.push_back(2);
	ree.push_back(3);
	ree.print();
	std::cout << *ree.pop_back() << '\n';
	ree.print();
	return 0;
}
