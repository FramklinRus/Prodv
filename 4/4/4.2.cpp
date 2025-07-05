#include <iostream>
#include <stdexcept>

template<typename T>
class Table {
public:

    Table(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
        data_ = new T * [rows_];
        for (size_t i = 0; i < rows_; ++i)
            data_[i] = new T[cols_];
    }

 
    ~Table() {
        for (size_t i = 0; i < rows_; ++i)
            delete[] data_[i];
        delete[] data_;
    }

  
    T* operator[](size_t row) {
        if (row >= rows_) throw std::out_of_range("Row index out of range");
        return data_[row];
    }

   
    const T* operator[](size_t row) const {
        if (row >= rows_) throw std::out_of_range("Row index out of range");
        return data_[row];
    }

    
    std::pair<size_t, size_t> Size() const {
        return { rows_, cols_ };
    }

private:
    T** data_;
    size_t rows_, cols_;
};
int main() {
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0]; 
}