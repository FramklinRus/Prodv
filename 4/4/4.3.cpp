#include <iostream>

class functor
{
	int counter;
	int sum;
public:
	functor(): sum(0), counter(0){}
	
	void operator() (int* Array, int size)
	{
		int a = 0;
		
		for (int i = 0; i < size; i++)
		{
			
			a = Array[i] % 3;
			if (a == 0)
			{
				counter++;
				sum += Array[i];

			}

		}
		

	}
	int get_sum() { return sum; }
	int get_count() { return counter; }


};


int main()
{
	int* array = new int[6]{ 4, 1, 3, 6, 25, 54};

	functor f;
    f(array, 6);
	std::cout << "[IN]: ";
			for (int i = 0; i < 6; i++)
			{
				
				if (i == 5) { std::cout << array[i] << std::endl; }
				else {
					std::cout << array[i] << " ";
				}
				
			}
			
			
			std::cout << "[OUT]: Get_sum "<< f.get_sum()<<std::endl;
			std::cout << "[OUT]: Get_count " << f.get_count() << std::endl;
		
			
	
		
	
	}


