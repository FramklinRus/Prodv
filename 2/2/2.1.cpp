#include <iostream>
#include <exception>
class smart_array
{
    int size;
    int* a;
    int count;
public:
    smart_array(int c)
    {
        size = c;
        a = new int[size];
       
        count = 0;
    }

    void add_element(int add)
    {
       
        if (count > (size-1)) {
            std::cout << "Full arr\n";
        }
        else {
            a[count] = add;
            count++;
        }
       
    }
    int get_element(int take) 
    {
        if (take > (size - 1)|| take<0) { throw std::out_of_range("Index out of range"); }
        else {
            return a[take];
        }
        
    }
    ~ smart_array()
    {
        delete[] a;
    }
};


int main()
{
   
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        
        std::cout << arr.get_element(1) << std::endl;
        
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
