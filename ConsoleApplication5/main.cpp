#include <iostream>
#include <string>
#include "gcd_calculator.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    string s1, s2, s3;
    cout << "Нахождение наибольшего общего делителя трёх чисел (m, n, p >= MaxInt)" << endl;

    // Ввод первого числа
    cout << "Введите первое число m: ";
    cin >> s1;
    while (!isValidNumber(s1)) {
        cerr << "Ошибка: Введите корректное число m (только цифры)! ";
        cin >> s1;
    }

    // Ввод второго числа
    cout << "Введите второе число n: ";
    cin >> s2;
    while (!isValidNumber(s2)) {
        cerr << "Ошибка: Введите корректное число n (только цифры)! ";
        cin >> s2;
    }

    // Ввод третьего числа
    cout << "Введите третье число p: ";
    cin >> s3;
    while (!isValidNumber(s3)) {
        cerr << "Ошибка: Введите корректное число p (только цифры)! ";
        cin >> s3;
    }

    // Определяем максимальную длину среди трёх введённых чисел
    int maxLength = s1.length();
    if (s2.length() > maxLength) maxLength = s2.length();
    if (s3.length() > maxLength) maxLength = s3.length();

    // Вычисляем количество частей

    int parts = (maxLength + 8) / 9;

    // Создаём динамические массивы для хранения чисел
    long long* a = new long long[parts]();
    long long* b = new long long[parts]();
    long long* c = new long long[parts]();

    // Заполняем массивы, разбивая строки на секции по 9 цифр
    fillArray(a, s1, parts);
    fillArray(b, s2, parts);
    fillArray(c, s3, parts);

    // Нахожу НОД трёх чисел
    long long result = gcdOfThree(a, b, c, parts);

    // Вывод результата на экран
    cout << "Наибольший общий делитель: " << result << endl;

    // Освобождение выделенной памяти
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
