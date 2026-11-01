#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time {
public:
    // Вкладений клас Triad
    class Triad {
    private:
        int first;  // години
        int second; // хвилини
        int third;  // секунди
        static int countTriad; // лічильник об'єктів вкладеного класу

    public:
        Triad();
        Triad(int f, int s, int t);
        Triad(const Triad& other);
        ~Triad();

        void setFirst(int f);
        void setSecond(int s);
        void setThird(int t);

        int getFirst() const { return first; }
        int getSecond() const { return second; }
        int getThird() const { return third; }

        Triad& operator=(const Triad& other);
        operator string() const;

        Triad& operator++();    // префіксний інкремент
        Triad& operator--();    // префіксний декремент
        Triad operator++(int);  // постфіксний інкремент
        Triad operator--(int);  // постфіксний декремент

        static int getCountTriad() { return countTriad; }

        // Дружні функції для бінарних операцій та вводу/виводу
        friend bool operator>(const Triad& t1, const Triad& t2);
        friend bool operator<(const Triad& t1, const Triad& t2);
        friend bool operator==(const Triad& t1, const Triad& t2);
        friend bool operator!=(const Triad& t1, const Triad& t2);
        friend bool operator>=(const Triad& t1, const Triad& t2);
        friend bool operator<=(const Triad& t1, const Triad& t2);

        friend ostream& operator<<(ostream& out, const Triad& t);
        friend istream& operator>>(istream& in, Triad& t);
    };

private:
    Triad t; // поле вкладеного класу
    static int countTime; // лічильник об'єктів зовнішнього класу

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& other);
    ~Time();

    Time& operator=(const Time& other);
    operator string() const;

    Time& operator++();    // префіксний інкремент (години)
    Time& operator--();    // префіксний декремент (години)
    Time operator++(int);  // постфіксний інкремент (хвилини)
    Time operator--(int);  // постфіксний декремент (хвилини)

    static int getCountTime() { return countTime; }

    // Дружні функції для бінарних операцій порівняння часу
    friend bool operator>(const Time& t1, const Time& t2);
    friend bool operator<(const Time& t1, const Time& t2);
    friend bool operator==(const Time& t1, const Time& t2);
    friend bool operator!=(const Time& t1, const Time& t2);
    friend bool operator>=(const Time& t1, const Time& t2);
    friend bool operator<=(const Time& t1, const Time& t2);

    friend ostream& operator<<(ostream& out, const Time& timeObj);
    friend istream& operator>>(istream& in, Time& timeObj);
};