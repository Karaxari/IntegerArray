#include <iostream>
#include "IntArray.h"

int main()
{
    setlocale(LC_ALL, "rus");
    IntArray array;

    // Ошибка создания массива с некорректной размерностью
    try
    {
        IntArray temp_array(-1);
    }
    catch (BadRange& e)
    {
        cout << e.what() << endl;
        cout << e.ShowMessage() << endl;
    }

    try
    {
        IntArray temp_array(10);
        array = temp_array;
    }
    catch (BadRange& e)
    {
        cout << e.what() << endl;
        cout << e.ShowMessage() << endl;
    }

    // Инициализация массив числами от 1 до 10
    for (int i{ 0 }; i < array.getLength(); ++i)
        array[i] = i + 1;
    array.showArray();

    // Ошибка инициализации по некорректному индексу массива
    try
    {
        array[array.getLength()] = 99;
    }
    catch (BadRange& e)
    {
        cout << e.what() << endl;
        cout << e.ShowMessage() << endl;
    }

    // Изменение размера
    array.resize(8);
    array.showArray();

    // Добавление числа 20 на 6 позицию массива
    array.insertBefore(20, 5);
    array.showArray();

    // Ощибка вставки элемента в массив на позицию больше за рамками его размерности
    try
    {
        array.insertBefore(23, 14);
    }
    catch (BadRange& e)
    {
        cout << e.what() << endl;
        cout << e.ShowMessage() << endl;
    }

    // Удаление третьего элемента массива
    array.remove(3);
    array.showArray();

    // Ошибка удаления элемента по несуществующему индексу
    try
    {
        array.remove(14);
    }
    catch (BadRange& e)
    {
        cout << e.what() << endl;
        cout << e.ShowMessage() << endl;
    }

    // Добавление чисел 30 и 40 в конец и начало массива соответствуенно
    array.insertAtEnd(30);
    array.insertAtBeginning(40);
    array.showArray();

    // Поиск элемента в массиве по значению
    int index = array.findElement(20);
    array.findElement(77);

    // Проверка корректности выполениня копирования
    {
        IntArray a;
        IntArray b{ array };
        a.insertAtEnd(34);
        a.insertAtBeginning(232);
        b.insertAtBeginning(54);

        cout << "-----------------------------------------------\n";
        a.showArray();
        b.showArray();
        array.showArray();

        b = a;
        a = array;
        array = array;

        cout << "-----------------------------------------------\n";
        a.showArray();
        b.showArray();
        array.showArray();
    }

    return 0;
}