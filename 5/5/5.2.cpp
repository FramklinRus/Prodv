#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main()
{

	set<int> number;
	int enter_begin = 0;
	int enter_cont;
	int count = 0;
	cout << "In:" << endl;
	cin >> enter_begin;
	
	while (count != enter_begin)
	{
		cin >> enter_cont;

		number.insert(enter_cont);
		count++;
	
	
	}
	cout << endl;


	vector<int> vec(number.begin(), number.end());
	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = i + 1; j < vec.size(); ++j) {
			if (vec[i] < vec[j]) {
				std::swap(vec[i], vec[j]);
			}
		}
	}
	cout << "Out: " << endl;
	for (const auto& p : vec) {

		std::cout << p <<endl;
	}
	return 0;


}

