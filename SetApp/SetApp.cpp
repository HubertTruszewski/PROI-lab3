#include "../SetLib/SetLib.h"
#include <string>

int main()
{
	Set<std::string> set1;
	Set<std::string> set2;
	set2 += "Hello";
	set2 += "world";
	set2 += "proi";

	std::cout << set2;

}

