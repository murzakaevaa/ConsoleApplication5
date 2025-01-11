#include <string>
using namespace std;

// Функция, проверяющая, является ли строка числом
bool isValidNumber(const string& str);

// Функция для заполнения массива длинных целых чисел из строки
void fillArray(long long* array, const string& str, int parts);

// Функция для нахождения НОД двух чисел
long long gcd(long long a, long long b);

// Функция для нахождения НОД трёх чисел
long long gcdOfThree(long long* a, long long* b, long long* c, int parts);



