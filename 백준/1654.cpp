#include <iostream>

#define MAX_NUM 10000

using namespace std;

long long arr[MAX_NUM + 1];

int main() 
{
	long long N, K;
	cin >> K >> N;

	long long sum = 0;
	for (long long i = 1; i <= K; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	long long left = 1;
	long long right = (sum / N) + 1;
	long long ans = 0;

	// Parametric search 진행
	while (left <= right) {
		long long mid = (left + right) / 2;

		// mid값으로 랜선을 자르는 경우 총 몇 개의 랜선이 나오는지 카운트
		long long count = 0;
		for (long long i = 1; i <= K; i++) {
			count += arr[i] / mid;
		}

		if (count < N) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = max(ans, mid);
		}
	}

	cout << ans;

	return 0;
}
