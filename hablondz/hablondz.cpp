#include <iostream>
#include "Array.h"

int main()
{
    Array<int> arr;

    std::cout << "Початковий масив: ";
    std::cout << arr << "\n\n";

    arr.insertAt(0, 10);
    arr.insertAt(1, 20);
    arr.insertAt(2, 30);

    std::cout << "Після додавання: ";
    std::cout << arr << "\n";

    arr.insertAt(1, 15);

    std::cout << "Після вставки 15 на індекс 1: ";
    std::cout << arr << "\n";
    arr.insertAt(0, 5);

    std::cout << "Після вставки 5 на початок: ";
    std::cout << arr << "\n";

    arr.insertAt(5, 40);

    std::cout << "Після вставки 40 в кінець: ";
    std::cout << arr << "\n";

    arr.removeAt(2);

    std::cout << "Після видалення елемента з індексом 2: ";
    std::cout << arr << "\n";

    arr.removeAt(20);
    arr.clear();

    std::cout << "Після clear(): ";
    std::cout << arr << "\n";

}