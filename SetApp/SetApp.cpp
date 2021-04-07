#include "../SetLib/SetLib.h"
#include <string>

int main()
{
	std::vector<int> numbers1 = { 1, 2, 3, 4 };
	Set<int> set1(numbers1);
	std::vector<int> numbers2 = { 1, 2, 3, 4, 6, 7, 8 };
	Set<int> set2(numbers2);

	std::cout << std::hash<Set<int>>{}(set1);


}

