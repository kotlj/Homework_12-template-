
#include <iostream>

template <typename T>
class Array
{
private:
    T* _arr;
    int _size;
    int _curIndx;

public:
    Array(T, int size)
    {
        _size = size;
        _arr = new T[_size];
        _curIndx = -1;
    }

    int GetSize()
    {
        return this->_size;
    }

    void SetSize(int size, int grow = 5);

    int GetUpperBound()
    {
        return this->_curIndx
    }

    bool IsEmpty()
    {
        return (_curIndx > -1 ? true : false);
    }

    bool IsFull()
    {
        return (_curIndx == size - 1 ? true : false)
    }

    void FreeExtra();

    void RemoveAll();

    T& GetAt(int indx)
    {
        return _arr[indx];
    }

    void SetAt(T& obj, int indx)
    {
        _arr[indx] = obj;
    }

    T& operator[](const int index)
    {
        return _arr[index];
    }

    void Add(T obj);

    void Append(Array& obj);

    Array& operator=(const Array& obj)
    {
        if (_arr != nullptr)
        {
            delete[] this->_arr;
        }
        this->_size = obj._size;
        this->_curIndx = obj.curIndx;
        this->_arr = new T[_size];
        for (int i = 0; i < _size; i++)
        {
            this->_arr[i] = obj._arr[i];
        }
        return *this;
    }

    Array GetData()
    {
        return this->_arr;
    }

    void InsertAt(T &obj, int indx);

    void RemoveAt(int indx);

    ~Array()
    {
        if (_arr != nullptr)
        {
            delete[] _arr;
        }
    }
};

template <typename T>
void Array<T>::SetSize(int size, int grow)
{
    if (size > _size)
    {

    }
    else if (size < _size)
    {

    }
}


int main()
{
    
}