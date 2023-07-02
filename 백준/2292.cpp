#include <iostream>

using namespace std;

int main(void)
{
	int count = 1; // 지나가는 방의 개수
	int N = 0; // 입력 받는 숫자 N

	cin >> N;

	N -= 1;
	int i = 1;

	while (N > 0) {
		N -= 6 * i++; // 벌집은 한꺼풀씩 배낀다.
		count++;
	}

	cout << count;

	return 0;
}

