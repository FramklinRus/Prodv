#include <iostream>

#include <vector>

	template <typename T1>
T1 square(T1 number)
{
	return number * number;
}
template <typename T2>

std::vector<T2> square(std::vector <T2>& Array)
{
	
		
		for (int i = 0; i < Array.size(); i++)
		{
			Array[i] = Array[i] * Array[i];
			
		}
		return Array;
	
}	
int main()
{
	
	int a = 5;
		std::vector<int> v = { -1, 4, 8 };
	
		std::cout << "[IN]: "<< a<< std::endl;
		std::cout<< "[OUT] " << square(a) << std::endl;
		
		std::cout << "[IN]: ";
		for (int i = 0; i < v.size(); i++)
		{
			
			if (i == v.size()-1) { std::cout << v[i] << std::endl; }
			else {
				std::cout << v[i] << " ";
			}
			
		}
		
		square(v);
		std::cout << "[OUT]: ";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";

	}

}