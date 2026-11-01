#include "Time.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Ініціалізація статичних полів
int Time::Triad::countTriad = 0;
int Time::countTime = 0;

// ==========================================
// Реалізація методів вкладеного класу Triad
// ==========================================

Time::Triad::Triad() : first(0), second(0), third(0) {
    countTriad++;
}

Time::Triad::Triad(int f, int s, int t) {
    setFirst(f);
    setSecond(s);
    setThird(t);
    countTriad++;
}

Time::Triad::Triad(const Triad& other) : first(other.first), second(other.second), third(other.third) {
    countTriad++;
}

Time::Triad::~Triad() {
    countTriad--;
}

void Time::Triad::setFirst(int f) {
    first = (f >= 0 && f < 24) ? f : 0;
}

void Time::Triad::setSecond(int s) {
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::Triad::setThird(int t) {
    third = (t >= 0 && t < 60) ? t : 0;
}

Time::Triad& Time::Triad::operator=(const Triad& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
        third = other.third;
    }
    return *this;
}

Time::Triad::operator string() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << first << ":"
        << setfill('0') << setw(2) << second << ":"
        << setfill('0') << setw(2) << third;
    return ss.str();
}

// Префіксні операції змінюють перше поле (години)
Time::Triad& Time::Triad::operator++() {
    first = (first + 1) % 24;
    return *this;
}

Time::Triad& Time::Triad::operator--() {
    first = (first == 0) ? 23 : first - 1;
    return *this;
}

// Постфіксні операції змінюють друге поле (хвилини)
Time::Triad Time::Triad::operator++(int) {
    Triad temp(*this);
    second = (second + 1) % 60;
    return temp;
}

Time::Triad Time::Triad::operator--(int) {
    Triad temp(*this);
    second = (second == 0) ? 59 : second - 1;
    return temp;
}

// Порівняння тріад згідно варіанту 11
bool operator>(const Time::Triad& t1, const Time::Triad& t2) {
    if (t1.first > t2.first) return true;
    if (t1.first == t2.first && t1.second > t2.second) return true;
    if (t1.first == t2.first && t1.second == t2.second && t1.third > t2.third) return true;
    return false;
}

bool operator<(const Time::Triad& t1, const Time::Triad& t2) {
    return t2 > t1;
}

bool operator==(const Time::Triad& t1, const Time::Triad& t2) {
    return (t1.first == t2.first && t1.second == t2.second && t1.third == t2.third);
}

bool operator!=(const Time::Triad& t1, const Time::Triad& t2) {
    return !(t1 == t2);
}

bool operator>=(const Time::Triad& t1, const Time::Triad& t2) {
    return (t1 > t2) || (t1 == t2);
}

bool operator<=(const Time::Triad& t1, const Time::Triad& t2) {
    return (t1 < t2) || (t1 == t2);
}

ostream& operator<<(ostream& out, const Time::Triad& t) {
    out << string(t);
    return out;
}

istream& operator>>(istream& in, Time::Triad& t) {
    int f, s, th;
    cout << "Enter hours: "; in >> f;
    cout << "Enter minutes: "; in >> s;
    cout << "Enter seconds: "; in >> th;
    t.setFirst(f);
    t.setSecond(s);
    t.setThird(th);
    return in;
}

// ==========================================
// Реалізація методів зовнішнього класу Time
// ==========================================

Time::Time() : t() {
    countTime++;
}

Time::Time(int h, int m, int s) : t(h, m, s) {
    countTime++;
}

Time::Time(const Time& other) : t(other.t) {
    countTime++;
}

Time::~Time() {
    countTime--;
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        t = other.t;
    }
    return *this;
}

Time::operator string() const {
    return string(t);
}

Time& Time::operator++() {
    ++t;
    return *this;
}

Time& Time::operator--() {
    --t;
    return *this;
}

Time Time::operator++(int) {
    Time temp(*this);
    t++;
    return temp;
}

Time Time::operator--(int) {
    Time temp(*this);
    t--;
    return temp;
}

bool operator>(const Time& t1, const Time& t2) { return t1.t > t2.t; }
bool operator<(const Time& t1, const Time& t2) { return t1.t < t2.t; }
bool operator==(const Time& t1, const Time& t2) { return t1.t == t2.t; }
bool operator!=(const Time& t1, const Time& t2) { return t1.t != t2.t; }
bool operator>=(const Time& t1, const Time& t2) { return t1.t >= t2.t; }
bool operator<=(const Time& t1, const Time& t2) { return t1.t <= t2.t; }

ostream& operator<<(ostream& out, const Time& timeObj) {
    out << timeObj.t;
    return out;
}

istream& operator>>(istream& in, Time& timeObj) {
    in >> timeObj.t;
    return in;
}