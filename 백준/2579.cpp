#include <iostream>
#include <cstdio>

#define MAX_NUM 350

using namespace std;

// D[x][0] : x칸까리 오를 때, 이전에 한칸 올라간 경우
// D[x][1] : x칸까지 오를 때, 이전에 두칸 올라간 경우
int D[MAX_NUM][2];

int point[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &point[i]);
	}

	// 초기화
	D[1][0] = D[1][1] = point[1];
	D[1][1] = -1; // 이 경우는 없기에 -1값 대입
	D[2][0] = point[1] + point[2];
	D[2][1] = point[2];

	for (int i = 3; i <= N; i++) {
		// i-2 계단까지 올라갈 때 마지막에 한 계단, 두 계단 오른 경우 중 더 점수가 큰 것을 선택
		D[i][1] = ((D[i - 2][0] > D[i - 2][1]) ? D[i - 2][0] : D[i - 2][1]) + point[i];

		// 마지막에 한번에 두 계단을 올라서 i-1 계단에 오른 경우 선택
		D[i][0] = D[i - 1][1] + point[i];

	}

	// N 계산을 올라갈 때, 마지막에 한 계단, 두 계단 오른 경우 중 더 점수가 큰 것을 선택
	cout << ((D[N][0] > D[N][1]) ? D[N][0] : D[N][1]);

	return 0;
}