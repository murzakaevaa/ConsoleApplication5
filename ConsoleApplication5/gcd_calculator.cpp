#include "gcd_calculator.h"
#include <iostream>

using namespace std;

// �������, �����������, �������� �� ������ ������
bool isValidNumber(const string& str) {
    if (str.empty()) return false; // �������� �� ������ ������
    for (char c : str) {
        if (!isdigit(c)) { // ���� ���� ���� �� ���� ���������� ������
            return false;
        }
    }
    return true;
}

// ������� ��� ���������� ������� ������� ����� ����� �� ������
void fillArray(long long* array, const string& str, int parts) {
    int index = 0;
    // ���� ��� ���������� �������� �� ������
    for (int i = str.length(); i > 0; i -= 9) {
        // �������� ��������� ������ �� 9 ��������
        string substring = str.substr(max(0, i - 9), min(9, i));
        // ���������� ��������� � long long � �������� � ������
        array[index++] = stoll(substring);
    }
}

// ������� ��� ���������� ��� ���� �����
long long gcd(long long a, long long b) {
    // �������� ������� ��� ���������� ���
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a; // ���������� ���
}

// ������� ��� ���������� ��� ��� �����
long long gcdOfThree(long long* a, long long* b, long long* c, int parts) {
    // ���������� ��� ����� ������ � ������ �������
    long long result = gcd(a[0], b[0]);
    // ���������� ��� ���������� � ������� ������
    result = gcd(result, c[0]);
    return result; // ��������� ���
}
