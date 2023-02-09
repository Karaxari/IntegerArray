#pragma once
#include <iostream>
#include <cassert>
#include <exception>

using namespace std;

class BadRange : public exception
{
private:
    string _message{};
public:
    BadRange() = default;
    BadRange(string message) : _message{ message }
    {
    }
    virtual const char* what() const noexcept override
    {
        return "\nERROR: Выход за пределы массива!";
    }
    string ShowMessage()
    {
        return _message;
    }
};

class IntArray
{
private:
    int _length{};
    int* _array{};

public:
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);
    ~IntArray();

    void erase();

    int& operator[](int index);
    void reallocate(int newLength);

    void resize(int newLength);
    IntArray& operator=(const IntArray& a);
    void insertBefore(int value, int index);
    void remove(int index);
    void showArray();
    int findElement(int num);

    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, _length); }

    int getLength() const { return _length; }
};