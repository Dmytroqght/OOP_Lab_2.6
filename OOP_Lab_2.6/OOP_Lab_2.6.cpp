#include "Time.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Initial Object Count ---" << endl;
    cout << "Time objects: " << Time::getCountTime() << endl;
    cout << "Triad objects: " << Time::Triad::getCountTriad() << endl << endl;

    // Демонстрація вводу/виводу та створення об'єктів
    Time t1;
    cout << "--- Input Time 1 ---" << endl;
    cin >> t1;

    Time t2(14, 30, 0); // Конструктор ініціалізації
    cout << "\nTime 2 (Initialized): " << t2 << endl;

    Time t3 = t1; // Конструктор копіювання
    cout << "Time 3 (Copy of Time 1): " << t3 << endl;

    cout << "\n--- Object Count After Creation ---" << endl;
    cout << "Time objects: " << Time::getCountTime() << endl;
    cout << "Triad objects: " << Time::Triad::getCountTriad() << endl << endl;

    // Демонстрація інкременту та декременту
    cout << "--- Operators Demonstration ---" << endl;
    cout << "Original t1: " << t1 << endl;

    ++t1; // Префіксний інкремент (Змінює години)
    cout << "After ++t1 (Prefix changes hours): " << t1 << endl;

    t1++; // Постфіксний інкремент (Змінює хвилини)
    cout << "After t1++ (Postfix changes minutes): " << t1 << endl;

    --t1; // Префіксний декремент
    cout << "After --t1: " << t1 << endl;

    t1--; // Постфіксний декремент
    cout << "After t1--: " << t1 << endl;

    // Демонстрація порівняння (завдання 11)
    cout << "\n--- Comparison Demonstration ---" << endl;
    cout << "t1: " << t1 << ", t2: " << t2 << endl;

    if (t1 > t2) {
        cout << "t1 is strictly greater than t2." << endl;
    }
    else if (t1 < t2) {
        cout << "t1 is strictly less than t2." << endl;
    }
    else {
        cout << "t1 is equal to t2." << endl;
    }

    // Демонстрація масиву об'єктів (також змінить кількість)
    cout << "\n--- Array Generation ---" << endl;
    Time* timeArray = new Time[3];
    cout << "Created array of 3 Time objects." << endl;
    cout << "Current Time objects count: " << Time::getCountTime() << endl;

    delete[] timeArray;
    cout << "Deleted array. Current Time objects count: " << Time::getCountTime() << endl;

    // Перевірка розміру класу
#pragma pack(push, 1)
    class TimePacked {
        Time::Triad t;
    };
#pragma pack(pop)

    cout << "\n--- Size of Class ---" << endl;
    cout << "Size of Time (standard): " << sizeof(Time) << " bytes" << endl;
    cout << "Size of Time (pack(1)): " << sizeof(TimePacked) << " bytes" << endl;

    return 0;
}