#include <iostream>
#include <cstdio>
#include <vector>

#define MAX_NUM 1000

using namespace std;
int arr[MAX_NUM + 1]; // 수열을 담는 배열
// D[i].first : i 번째 원소를 마지막으로 하는 가장 긴 증가하는 부분수열의 길이
// D[i].second : i 번째 원소를 마지막으로 하는 가장 긴 증가하는 부분수열에서 마지막 전 원소의 index
//               -> 만약 없다면 0을 가진다.
pair<int, int> D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// 수열 입력 받기
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	// 초기화
	D[1].first = 1;
	D[1].second = 0;

	// 동적 계획법
	for (int i = 2; i <= N; i++) {
		int max = 0;
		for (int j = i - 1; j > 0; j--) {
			if (arr[i] > arr[j] && D[j].first > D[max].first) {
				max = j;
			}
		}

		D[i].first = D[max].first + 1;
		D[i].second = max;
	}

	// 수열을 돌면서 가장 큰 값을 가지는 D[i].first 값을 찾는다.
	int max = 1;

	for (int i = 2; i <= N; i++) {
		if (D[i].first > D[max].first) {
			max = i;
		}
	}

	// 가장 긴 증가하는 부분 수열의 길이 출력
	cout << D[max].first << endl;

	// vecotr<int> result : 가장 긴 증가하는 부분 수열의 원소를 저장할 vector
	vector<int> result;
	result.push_back(arr[max]);

	// 뒤에서부터 보면서 차례로 vector에 넣는다.
	for (int i = D[max].second; i > 0;) {
		result.push_back(arr[i]);
		i = D[i].second;
	}

	// 이후 뒤에서부터 출력!
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}

	return 0;
}