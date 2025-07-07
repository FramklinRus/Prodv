#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main2()
{
	
	multiset<char> word{'H','e','l','l','o',' ','w','o','r','l','d','!','!',};
	auto begin = word.begin();
	int count = 0;
	
	map<char, int> word2;
			for (char c : word) {
		
		if (count == (word.size() - 1))
		{
			if (*begin == *prev(begin))
			{
				begin = word.begin();
			}
			else
			{
				begin = prev(begin);
			}
			
		}
		
		if (*begin != *next(begin))
		{
			
			
			
			
			word2.insert({ c,word.count(c) });
		}
		
        
		 begin = next(begin);
	
		
		count++;
			
	}
	
	cout << endl;
	std::vector<std::pair<char, int>> vec(word2.begin(), word2.end());

	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = i + 1; j < vec.size(); ++j) {
			if (vec[i].second < vec[j].second) {
				std::swap(vec[i], vec[j]);
			}
		}
	}
	cout << "IN: Hello world!!" << endl;
	cout << "Out: " << endl;
	for (const auto& p : vec) {
		
		std::cout << p.first << ": " << p.second << "\n";
	}
	return 0;
	
	
}

