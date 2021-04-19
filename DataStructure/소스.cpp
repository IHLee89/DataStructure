#include "Allocator/QAllocator.h"
#include <list>
#include <vector>

using namespace std;

int main()
{
	std::vector<int, QAllocator<int>> a;
	a.reserve(50);
	a.push_back(1);

/*
	"warning STL4010: Various members of std::allocator are deprecated in C++17."
	"Use std::allocator_traits instead of accessing these members directly."
	"You can define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning."
*/

	a.push_back(3);
	auto size = a.max_size();

	return 0;
}