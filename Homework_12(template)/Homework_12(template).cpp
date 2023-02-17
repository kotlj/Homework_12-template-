
#include <iostream>

template <typename T>
class Array
{
private:
    T* _arr;
    int _size;
    int _curIndx;

public:
    Array()
    {
        _size = 1;
        _arr = new T[_size];
        _curIndx = -1;
    }
    Array(int size)
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
        return this->_curIndx;
    }

    bool IsEmpty()
    {
        return (_curIndx > -1 ? true : false);
    }

    bool IsFull()
    {
        return (_curIndx == _size - 1 ? true : false);
    }

    void FreeExtra()
    {
        this->_size = this->_curIndx + 1;
        T* temp = new T[this->_size];
        for (int i = 0; i < this->_size; i++)
        {
            temp[i] = this->_arr[i];
        }
        delete[] this->_arr;
        this->_arr = temp;
        temp = nullptr;
    }

    void RemoveAll()
    {
        delete[] this->_arr;
        this->_arr = new T[this->_size];
        this->_curIndx = -1;
    }

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
        T* temp = new T[_size + grow];
        for (int i = 0; i < _curIndx; i++)
        {
            temp[i] = this->_arr[i];
        }
        delete[] _arr;
        this->_arr = temp;
        temp = nullptr;
        this->_size += grow;
    }
    else if (size <= _size)
    {
        this->FreeExtra();
    }
}

template <typename T>
void Array<T>::Add(T obj)
{
    this->_curIndx++;
    this->_arr[_curIndx] = obj;
}

template <typename T>
void Array<T>::Append(Array& obj)
{
    this->_size = this->_curIndx + obj._curIndx + 1;
    T* temp = new T[this->_size];
    for (int i = 0; i < this->_curIndx = 1; i++)
    {
        temp[i] = this->_arr[i];
    }
    for (int i = 0; i < obj._curIndx + 1; i++)
    {
        temp[i] = obj._arr[i];
    }
    delete[] this->_arr;
    this->_arr = temp;
    temp = nullptr;
    this->_curIndx = this->_size - 1;
}

template <typename T>
void Array<T>::InsertAt(T &obj, int indx)
{
    if (this->IsFull())
    {
        this->SetSize(this->_size + 1);
    }
    T* temp = new T[this->_size];
    for (int i = 0; i < this->_size; i++)
    {
        if (i < indx)
        {
            temp[i] = this->_arr[i];
        }
        else if (i > indx)
        {
            temp[i] = this->_arr[i - 1];
        }
        else
        {
            temp[indx] = obj;
        }
    }
    delete[] this->_arr;
    this->_arr = temp;
    temp = nullptr;
    this->_curIndx++;
}

template <typename T>
void Array<T>::RemoveAt(int indx)
{
    if (indx <= this->_curIndx)
    {
        T* temp = new T[this->_size];
        for (int i = 0; i < this->_size - 1; i++)
        {
            if (i < indx)
            {
                temp[i] = this->_arr[i];
            }
            else
            {
                temp[i] = this->_arr[i + 1];
            }
        }
        delete[] this->_arr;
        this->_arr = temp;
        temp = nullptr;
        this->_curIndx--;
    }
}

int main()
{
    int size = 10;
    Array<int> test(size);
    for (int i = 0; i < size; i++)
    {
        test.InsertAt(i, i);
    }
    int help = test[5];
    std::cout << help;
}