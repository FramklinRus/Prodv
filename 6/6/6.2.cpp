#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <list>
using namespace std;

template<typename T>

void print_container(T& box)
{
	for (auto i : box)
	{
		cout << i<< " ";

	}
	cout << endl;
}


int main()

{
	set<string> test_set = { "one", "two", "three", "four" };
	print_container(test_set);
	vector<string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); 
	list<string> test_list = { "one", "two", "three", "four" };
	print_container(test_list);

	return 0;
}