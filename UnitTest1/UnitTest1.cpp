#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../OOP_Lab_2.6/Time.cpp "

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TimeTests
{
	TEST_CLASS(TimeTests)
	{
	public:

		TEST_METHOD(TestConstructorsAndStringConversion)
		{
			Time t1(14, 5, 9);
			string expected = "14:05:09";
			string actual = string(t1);

			Assert::AreEqual(expected, actual, L"Конструктор ініціалізації або перетворення в рядок працює некоректно");
		}

		TEST_METHOD(TestPrefixIncrement_Hours)
		{
			Time t(23, 30, 0);
			++t; // Префіксний інкремент має збільшувати години (first)

			string expected = "00:30:00"; // 23 + 1 = 24 -> 00
			Assert::AreEqual(expected, string(t));
		}

		TEST_METHOD(TestPostfixIncrement_Minutes)
		{
			Time t(14, 59, 0);
			Time temp = t++; // Постфіксний інкремент має збільшувати хвилини (second)

			string expectedOld = "14:59:00";
			string expectedNew = "14:00:00"; // 59 + 1 = 60 -> 00

			Assert::AreEqual(expectedOld, string(temp), L"Постфіксний інкремент повернув неправильне старе значення");
			Assert::AreEqual(expectedNew, string(t), L"Постфіксний інкремент неправильно змінив хвилини");
		}

		TEST_METHOD(TestComparisonOperators)
		{
			Time t1(14, 30, 0);
			Time t2(14, 29, 59);
			Time t3(14, 30, 0);

			Assert::IsTrue(t1 > t2, L"t1 має бути більшим за t2");
			Assert::IsFalse(t1 < t2, L"t1 не має бути меншим за t2");
			Assert::IsTrue(t1 == t3, L"t1 має дорівнювати t3");
			Assert::IsTrue(t1 >= t3, L"t1 має бути >= t3");
			Assert::IsTrue(t2 != t1, L"t2 не має дорівнювати t1");
		}

		TEST_METHOD(TestObjectCounting)
		{
			// Зберігаємо початкову кількість, щоб тест не залежав від порядку виконання
			int initialTimeCount = Time::getCountTime();
			int initialTriadCount = Time::Triad::getCountTriad();

			{
				Time t1;
				Time t2(10, 0, 0);

				Assert::AreEqual(initialTimeCount + 2, Time::getCountTime(), L"Лічильник Time не збільшився");
				Assert::AreEqual(initialTriadCount + 2, Time::Triad::getCountTriad(), L"Лічильник Triad не збільшився");

				Time t3 = t1; // Конструктор копіювання
				Assert::AreEqual(initialTimeCount + 3, Time::getCountTime());
			} // Тут викликаються деструктори t1, t2, t3

			Assert::AreEqual(initialTimeCount, Time::getCountTime(), L"Лічильник Time не зменшився після деструктора");
			Assert::AreEqual(initialTriadCount, Time::Triad::getCountTriad(), L"Лічильник Triad не зменшився");
		}
	};
}