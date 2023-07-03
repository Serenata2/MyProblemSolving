#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int count = 0;
	int num = 665;

	while (count < N) {
		num++;
		int n = num;
		int i = 0;
		while (n > 0) {
			if (n % 10 == 6) {
				i++;
			}
			else {
				i = 0;
			}
			if (i == 3) { // 3번 연속 6이 나오면 count를 증가하고 반복문 나오기
				count++;
				break;
			}
			n /= 10;
		}
	}

	cout << num;

	return 0;
}