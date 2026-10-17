#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
    T* data;
    int size;
    int capacity;

public:
    Array();
    ~Array();

    void insertAt(int index, T value);
    void removeAt(int index);
    void clear();

    bool empty() const;

    friend std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
    {
        if (arr.empty())
        {
            out << "{}";
            return out;
        }

        out << "{ ";

        for (int i = 0; i < arr.size; i++)
        {
            out << arr.data[i];

            if (i < arr.size - 1)
            {
                out << ", ";
            }
        }

        out << " }";

        return out;
    }
};

template <typename T>
Array<T>::Array()
{
    size = 0;
    capacity = 2;

    data = new T[capacity];
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
bool Array<T>::empty() const
{
    return size == 0;
}

template <typename T>
void Array<T>::insertAt(int index, T value)
{
    if (index < 0 || index > size)
    {
        std::cout << "Помилка: неправильний індекс!\n";
        return;
    }

    if (size == capacity)
    {
        capacity *= 2;

        T* newData = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
    }

    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;

    size++;
}

template <typename T>
void Array<T>::removeAt(int index)
{

    if (index < 0 || index >= size)
    {
        std::cout << "Помилка: неправильний індекс!\n";
        return;
    }

    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }

    size--;
}

template <typename T>
void Array<T>::clear()
{
    size = 0;
}