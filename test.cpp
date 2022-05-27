#include <minivector.h>
#include <iostream>

int main() {
	mvec::vector<int> ree;
	std::cout << ree.write(4, 0) << '\n';
	std::cout << ree[0] << '\n';
	return 0;
}
