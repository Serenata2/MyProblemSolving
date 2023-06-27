#include <iostream>

using namespace std;

int main(void)
{
	int H, M;

	// 시간, 분 입력받기
	cin >> H >> M;

	// 입력한 24시간의 표현을 분 단위로 표현하고 45분을 뺀다.
	int time = (60 * H + M) - 45;

	time = (time < 0) ? (60 * 24 + time) : time;

	cout << (int)(time / 60) << " " << time % 60;

	return 0;
}

