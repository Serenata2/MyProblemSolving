#include <iostream>

#define MAX_NUM 10000

using namespace std;

int arr[101];
int D[MAX_NUM + 1];

int main()
{
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// 초기화
	// 첫번째 동전으로 k원을 만들 수 있는지 확인
	for (int i = 1; i <= K; i++) {
		if (arr[1] <= i && i % arr[1] == 0) {
			D[i] = 1;
		}
	}

	// 입력받은 모든 동전들을 사용할 수 있는 동전 구성에 하나씩 추가하는 방식으로
	// 동적 계획법 이용
	for (int i = 2; i <= N; i++) {
		// 동전의 가치가 k 원보다 클 수 있기에 예외 처리
		if (arr[i] <= MAX_NUM) {
			D[arr[i]] += 1;
		}
		// D[i] : 지금까지 사용할 수 있는 동전 구성으로 i 원을 만들 수 있는 경우의 수
		for (int j = arr[i] + 1; j <= K; j++) {
			D[j] += D[j - arr[i]];
		}
	}

	cout << D[K];

	return 0;
}