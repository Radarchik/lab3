//============================================================================
// Name        : lab3.cpp
// Author      : Taras
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
using namespace std;

/* 2�) ��� ���������� ���� ������� ����� ����� */
int sumNumbers(int kolChisel, ...) { // �� ����: 1) ������� �����; 2)����� � ��������� �������;
	int result = 0;
	for (int *current = &kolChisel; kolChisel > 0; kolChisel--) {
		result = result + *(++current);
	}
	return result;
}

/* 2�) ��� ���������� �������; */
double multiplication(int n, ...) { // �� ����: 1) ������� ��������; 2)����� X1, X2, X3, ..., Xn
	double result = 1.0;
	for (int *current = &n; n > 0; n--) {
		double x = *(++current);
		result = result * (double) (pow(x, 2)) / (1 - x);
	}
	return result;
}

/* 2�) ��� ���������� ����� ��������� � m ����� �� n.*/
int factorial(int n) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int combination(int n, int m) {
// ���������� �� �������� ����� ���������
	if (n > m) {
		throw std::invalid_argument(
				"��������� ���������� ���������� �� ������� ����������");
	}
	return factorial(m) / (factorial(n) * factorial(m - n));
}

/*3. ������� �������� ������ ���������� �������� � ����� �������� ����� N, �� ��������� � ���������.*/
int minElement(void) {
	vector<int> numbers;
	cout
			<< "������� ����� ����� ������. ��� ��������� ����� ������� ����� � ������� Enter: "
			<< endl;

	int num;
	while (cin >> num) {
		numbers.push_back(num);
	}

	int minimum = numbers.at(0);
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] < minimum) {
			minimum = numbers[i];
		}
	}

	return minimum;
}

/*5. ������� ����� ��������� � �������� ��������� ���� ����/
     ������ 8.
      */
void lineSum(double x, double eps) {
	if (x <= -1 || x > 1) {
		throw invalid_argument("������� ��������� �� ������ ���� ������");
	}

	double chetnist = 1.0;

	int n = 1;           // ����� �������
	double s = 0.0;      // ����
	double a;            // ���������� �������

	do {
		a = chetnist * (pow(x, n) / n);
		s = s + a;
		n++;
		chetnist = -1.0 * chetnist;
	} while (abs(a) > eps);

	cout << "��� eps = " << eps << " ���� ���� ������� " << s << endl;
	cout << "����� �������� ������� " << n << endl;
}

int main() {

	/* 2�) ��� ���������� ���� ������� ����� ����� */
	//cout << sumNumbers(4,   5, 7, 1, 3) << endl;
	/* 2�) ��� ���������� �������; */
	//cout << multiplication(2,   2, 2) << endl;
	/* 2�) ��� ���������� ����� ��������� � m ����� �� n. */
	//	cout << combination(2, 4) << endl;
	/*3. ������� �������� ������ ���������� �������� � ����� �������� ����� N, �� ��������� � ���������.*/
	// int minimum = minElement();
	// cout << minimum << endl;

	/*5. ������� ����� ��������� � �������� ��������� ���� ���� */
	lineSum(1, 0.01);
	lineSum(1, 0.0001);
	return 0;
}

