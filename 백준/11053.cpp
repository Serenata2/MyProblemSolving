#include <iostream>
#include <cstdio>

#define MAX_NUM 1000

using namespace std;
int arr[MAX_NUM + 1];
// D[i] : i 번째 끝나는 원소로 끝나는 부분 수열 중에서 가장 긴 증가하는 부분 수열의 길이
int D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// 수열 입력 받기
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	// 초기화
	D[1] = 1;

	// 동적 계획법
	for (int i = 2; i <= N; i++) {
		int max = i;
		for (int j = i - 1; j > 0; j--) {
			if (arr[i] > arr[j] && D[j] > D[max]) {
				max = j;
			}
		}

		D[i] = D[max] + 1;
	}

	// 모든 D 배열 원소를 보면서 최댓값 찾기
	int result = D[1];

	for (int i = 2; i <= N; i++) {
		if (D[i] > result) {
			result = D[i];
		}
	}

	cout << result;

	return 0;
}