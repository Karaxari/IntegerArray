#include "IntArray.h"

IntArray::IntArray(int length) : _length{ length }
{
    if (length <= 0) {
        throw BadRange("������ ������� �� ����� ���� ������ ��� ������ 0!");
    }
    if (length > 0)
        _array = new int[length] {};
}

IntArray::IntArray(const IntArray& a)
{
    reallocate(a.getLength());

    for (int index{ 0 }; index < _length; ++index)
        _array[index] = a._array[index];
}

IntArray::~IntArray()
{
    cout << "\n������ ������!\n";
    delete[] _array;
}

void IntArray::erase()
{
    delete[] _array;

    _array = nullptr;
    _length = 0;
}

int& IntArray::operator[](int index)
{
    if (index < 0 || index >= _length)
        throw BadRange("����� �� ������� �������!, �� ������� ������������ ������");

    return _array[index];
}

// reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
void IntArray::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
        return;

    _array = new int[newLength];
    _length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == _length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };

    if (_length > 0)
    {
        int elementsToCopy{ (newLength > _length) ? _length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = _array[index];
    }

    delete[] _array;

    _array = data;
    _length = newLength;
}

IntArray& IntArray::operator=(const IntArray& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());

    for (int index{ 0 }; index < _length; ++index)
        _array[index] = a._array[index];

    return *this;
}

void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > _length)
        throw BadRange("����� �� ������� �������!, � ������� ��� ������� � ����� �������");

    int* data{ new int[_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _array[before];

    data[index] = value;

    for (int after{ index }; after < _length; ++after)
        data[after + 1] = _array[after];

    delete[] _array;
    _array = data;
    ++_length;
}

void IntArray::remove(int index)
{
    if (index < 0 || index >= _length)
        throw BadRange("����� �� ������� �������!, � ������� ����������� ������� � ����� ��������");

    if (_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _array[before];

    for (int after{ index + 1 }; after < _length; ++after)
        data[after - 1] = _array[after];

    delete[] _array;
    _array = data;
    --_length;
}

void IntArray::showArray()
{
    cout << "\n";
    for (int i = 0; i < _length; i++) {
        if (i < _length - 1)
            cout << _array[i] << ",";
        else
            cout << _array[i] << ";\n";
    }
}

int IntArray::findElement(int num)
{
    for (int i = 0; i < _length; i++) {
        if (_array[i] == num)
        {
            cout << "������� �� ���������: " << num << ", ������������� �� �������: " << i << endl;
            return i;
        }
    }
    cout << "� ������� ����������� ������� �� ���������: " << num << endl;
    return -1;
}