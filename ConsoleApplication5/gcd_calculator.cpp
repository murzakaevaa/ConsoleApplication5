#include "gcd_calculator.h"
#include <iostream>

using namespace std;

// Функция, проверяющая, является ли строка числом
bool isValidNumber(const string& str) {
    if (str.empty()) return false; // Проверка на пустую строку
    for (char c : str) {
        if (!isdigit(c)) { // Если есть хотя бы один нецифровой символ
            return false;
        }
    }
    return true;
}

// Функция для заполнения массива длинных целых чисел из строки
void fillArray(long long* array, const string& str, int parts) {
    int index = 0;
    // Цикл для извлечения подстрок из строки
    for (int i = str.length(); i > 0; i -= 9) {
        // Извлекаю подстроку длиной до 9 символов
        string substring = str.substr(max(0, i - 9), min(9, i));
        // Преобразую подстроку в long long и сохраняю в массив
        array[index++] = stoll(substring);
    }
}

// Функция для нахождения НОД двух чисел
long long gcd(long long a, long long b) {
    // Алгоритм Евклида для нахождения НОД
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Возвращаем НОД
}

// Функция для нахождения НОД трёх чисел
long long gcdOfThree(long long* a, long long* b, long long* c, int parts) {
    // Нахождение НОД между первым и вторым числами
    long long result = gcd(a[0], b[0]);
    // Нахождение НОД результата с третьим числом
    result = gcd(result, c[0]);
    return result; // Возвращаю НОД
}
