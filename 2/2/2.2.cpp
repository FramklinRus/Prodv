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

        if (count > (size - 1)) {
            std::cout << "Full arr\n";
        }
        else {
            a[count] = add;
            count++;
        }

    }
    int get_element(int take)
    {
        if (take > (size - 1) || take < 0) { throw std::out_of_range("Index out of range"); }
        else {
            return a[take];
        }

    }
    smart_array& operator=(const smart_array& smart_array)
    {
        if (&smart_array != this)
        {
            *a = *smart_array.a;
        }
        return *this;
    }
    ~smart_array()
    {
        delete[] a;
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
