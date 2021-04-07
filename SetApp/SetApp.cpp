#include "../SetLib/SetLib.h"

int main()
{
	Set set1;
	set1 += 5;
	set1 += 10;
	Set set2;
	set2 += 23;
	set2 += 10;
	Set set3 = set1 + set2;
	std::cout << set1 << std::endl;
	std::cout << set2 << std::endl;
	std::cout << set3 << std::endl;
}

