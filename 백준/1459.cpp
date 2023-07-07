#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main(void)
{
	// X, Y : 집 위치, W : 한 블록 가는데 걸리는 시간, S : 대각선으로 한 블록을 가로지르는 시간
	long long X, Y, W, S;			
	
	cin >> X >> Y >> W >> S;

	long long result = 0;

	// 대각선으로 가는 것보다 블록으로 두번 가는게 더 빠른 경우
	if (2 * W <= S) {
		result = (X + Y) * W;
	}
	// 블록으로 두번 가는 것보다 대각선으로 한번 가는게 더 빠른 경우
	else if (W <= S) {
		if (X < Y) {
			swap(X, Y);
		}
		// 최대한 대각선으로 간 이후에 블록을 이용
		result = Y * S + (X - Y) * W;
	}
	// 블록 한번 가는게 대각선 한번 가는 것보다 값이 큰 경우
	else {
		if (X < Y) {
			swap(X, Y);
		}
		// 최대한 대각선으로 간 이후, 직선 거리를 또한 대각선을 이용해서 이동
		result = Y * S + (long long)((X - Y) / 2) * 2 * S;
		// 만약 직선 거리가 홀수이면 블록 한번 이용
		if ((X - Y) % 2 == 1) {
			result += W;
		}
	}

	cout << result;

	return 0;
}