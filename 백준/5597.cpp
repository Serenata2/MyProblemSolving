#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int sum = 30 * 31 / 2; // 1 + 2 + ... + 30
	int square_sum = (30 * 31 * 61) / 6; // 1^2 + 2^2 + 3^3 + .. + 30^2

	int total_sum = 0;
	int total_square = 0;

	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		total_sum += num;
		total_square += num * num;
	}

	// 빠진 출석 번호가 a, b라고 한다면..

	total_sum = sum - total_sum; // a + b
	total_square = square_sum - total_square; // a^2 + b^2

	int mul = (total_sum * total_sum - total_square) / 2; // a*b

	int a = (int(sqrt(total_square - 2 * mul)) + total_sum) / 2;
	int b = total_sum - a;

	cout << b << endl << a;

	return 0;
}

