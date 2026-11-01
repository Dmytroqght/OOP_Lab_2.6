#pragma once
#include <iostream>
#include <string>

using namespace std;

// Клас Тріада (трійка чисел)
class Triad {
private:
    int first;  // Години
    int second; // Хвилини
    int third;  // Секунди

public:
    // Конструктори
    Triad();
    Triad(int f, int s, int t);
    Triad(const Triad& other);

    // Геттери та сеттери з перевіркою (інкапсуляція)
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }

    void setFirst(int f);
    void setSecond(int s);
    void setThird(int t);

    // Перевантаження операції присвоєння (метод класу)
    Triad& operator=(const Triad& other);

    // Приведення типу до string (метод класу)
    operator string() const;

    // Інкремент та декремент (методи класу)
    // Префіксні модифікують first (години)
    Triad& operator++();
    Triad& operator--();
    // Постфіксні модифікують second (хвилини)
    Triad operator++(int);
    Triad operator--(int);

    // Бінарні операції порівняння (зовнішні дружні функції)
    friend bool operator>(const Triad& t1, const Triad& t2);
    friend bool operator<(const Triad& t1, const Triad& t2);
    friend bool operator==(const Triad& t1, const Triad& t2);
    friend bool operator!=(const Triad& t1, const Triad& t2);
    friend bool operator>=(const Triad& t1, const Triad& t2);
    friend bool operator<=(const Triad& t1, const Triad& t2);

    // Операції вводу/виводу
    friend ostream& operator<<(ostream& out, const Triad& t);
    friend istream& operator>>(istream& in, Triad& t);
};