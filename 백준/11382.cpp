#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;

	// 현재 시간, 분, 필요 시간 입력받기
	cin >> A >> B >> C;

	// 60 * 24의 나머지 구하기
	int time = (60 * A + B + C) % (60 * 24);

	cout << (int)(time / 60) << " " << time % 60;

	return 0;
}

