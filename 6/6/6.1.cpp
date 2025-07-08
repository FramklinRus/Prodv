#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main_1()

{
	
	vector<int> vec { 1, 1, 2, 5, 6, 1, 2, 4 };
	cout << "IN: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i]<< " ";

	}
	for (size_t i = 0; i < vec.size();i++)

	{
		for (size_t j = 0; j < vec.size(); j++)
		{
			if (vec[i] < vec[j])
			{
				
				swap(vec[i], vec[j]);
			
			
				
			}


		}

	}
	
	cout << endl;
	auto it=unique(vec.begin(), vec.end());

	vec.erase(it, vec.end());
	
	
	
	cout << "OUT: ";
	for (size_t i=0; i<vec.size(); i++)
	{
		cout << vec[i]<< " ";

	}
	cout << endl;
	
	return 0;
}

