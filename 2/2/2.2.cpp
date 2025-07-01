#include <iostream>
#include <exception>
class smart_array
{
    int size;
    int* array;
    int count;
public:
    smart_array(int c)
    {
        size = c;
        array = new int[size];

        count = 0;
    }

    void add_element(int add)
    {

        if (count > (size - 1)) {
            throw std::out_of_range("Index out of range");
        }
        else {
            array[count] = add;
            count++;
        }

    }
    int get_element(int take)
    {
        if (take > (size - 1) || take < 0) { throw std::out_of_range("Index out of range");  }
        else {
            return array[take];
        }

    }
    void creat_new_array(const smart_array& smart_array)
    {
        delete[] array;
        size = smart_array.size;
        count = smart_array.count;
        array = new int[size];
        for (int i = 0; i < size;i++)
        {
            array[i] = smart_array.array[i];
        }
    }
    smart_array& operator=(const smart_array& smart_array)
    {
        if (&smart_array != this)
        {
                     creat_new_array(smart_array);
        }
       
                return *this;
    }
    ~smart_array()
    {
        delete[] array;
    }
};


int main()
{

    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
   
    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);
    
   arr = new_array;
 
}
