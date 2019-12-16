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

/* 2а) для обчислення суми довільної низки чисел */
int sumNumbers(int kolChisel, ...) { // на вхід: 1) кількість чисел; 2)числа у довільному порядку;
	int result = 0;
	for (int *current = &kolChisel; kolChisel > 0; kolChisel--) {
		result = result + *(++current);
	}
	return result;
}

/* 2б) для обчислення добутку; */
double multiplication(int n, ...) { // на вхід: 1) кількість невідомих; 2)числа X1, X2, X3, ..., Xn
	double result = 1.0;
	for (int *current = &n; n > 0; n--) {
		double x = *(++current);
		result = result * (double) (pow(x, 2)) / (1 - x);
	}
	return result;
}

/* 2в) для обчислення числа сполучень з m чисел по n.*/
int factorial(int n) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int combination(int n, int m) {
// обчислення за формулою числа комбінацій
	if (n > m) {
		throw std::invalid_argument(
				"неможливо порахувати сполучення по заданим параметрам");
	}
	return factorial(m) / (factorial(n) * factorial(m - n));
}

/*3. Скласти програму пошуку мінімального елемента з низки довільних чисел N, що вводяться з клавіатури.*/
int minElement(void) {
	vector<int> numbers;
	cout
			<< "Введите числа через пробел. Для окончания ввода введите точку и нажмите Enter: "
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

/*5. Скласти схему алгоритму і програму обчислень суми ряду/
     Варіант 8.
      */
void lineSum(double x, double eps) {
	if (x <= -1 || x > 1) {
		throw invalid_argument("Введено параметри за межами умов задачі");
	}

	double chetnist = 1.0;

	int n = 1;           // номер доданку
	double s = 0.0;      // сума
	double a;            // обчислений доданок

	do {
		a = chetnist * (pow(x, n) / n);
		s = s + a;
		n++;
		chetnist = -1.0 * chetnist;
	} while (abs(a) > eps);

	cout << "При eps = " << eps << " Сума ряду дорівнює " << s << endl;
	cout << "Число ітерацій дорівнює " << n << endl;
}

int main() {

	/* 2а) для обчислення суми довільної низки чисел */
	//cout << sumNumbers(4,   5, 7, 1, 3) << endl;
	/* 2б) для обчислення добутку; */
	//cout << multiplication(2,   2, 2) << endl;
	/* 2в) для обчислення числа сполучень з m чисел по n. */
	//	cout << combination(2, 4) << endl;
	/*3. Скласти програму пошуку мінімального елемента з низки довільних чисел N, що вводяться з клавіатури.*/
	// int minimum = minElement();
	// cout << minimum << endl;

	/*5. Скласти схему алгоритму і програму обчислень суми ряду */
	lineSum(1, 0.01);
	lineSum(1, 0.0001);
	return 0;
}

