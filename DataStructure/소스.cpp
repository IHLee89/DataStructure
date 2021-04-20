#include "Allocator/QAllocator.h"
#include "LinearStructure/QSinglyLinkedList.h"
#include "LinearStructure/QVector.h"
#include <list>
#include <vector>

using namespace std;

int main()
{
	std::list<int> cc;
	std::list<int>::iterator cIter;

	std::vector<int, QAllocator<int>> a;
	a.reserve(50);
	a.push_back(1);
	a.push_back(3);
	auto size = a.max_size();

	std::QSinglyLinkedList<int> qList;
	auto z1 = qList.push_front(1);
	auto z2 = qList.push_front(2);
	auto z3 = qList.push_front(3);
	auto z4 = z3++;
	auto z5 = ++z3;

	qList.pop_front();
	for (auto& data : qList)
	{
		std::cout << "qList : " << data << std::endl;
	}

	

	return 0;
}