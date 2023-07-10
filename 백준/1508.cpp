#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 50

using namespace std;

int pos[MAX_NUM + 1];

int main()
{
	// N : 레이스 길이, M : 심판의 수, K : 심판을 배치시킬 수 있는 위치의 수
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 1; i <= K; i++) {
		scanf("%d", &pos[i]);
	}

	// 이분 탐색 진행
	int low = 1;
	int high = (pos[K] - pos[1]) / (M - 1);
	string result;

	while (low <= high) {
		// 가장 가까운 두 심판의 거리를 mid로 가정
		int mid = (low + high) / 2;
		// 심판 사이의 거리
		int sum = 0;
		// 심판 배치 횟수
		// 문제 특성상 맨 처음 가능한 위치에 심판을 배치하는게 유리함으로 처음에 심판 배치
		int total_m = 1;
		string str = "1";

		for (int i = 2; i <= K; i++) {
			// 심판을 다 배치했으면 문자열에 0 추가
			if (total_m >= M) {
				str.append("0");
				continue;
			}

			sum += pos[i] - pos[i - 1];
			// 타이트하게 심판 사이의 거리가 mid보다 크면 심판 배치
			if (sum >= mid) {
				sum = 0;
				total_m++;
				str.append("1");
			}
			else {
				str.append("0");
			}
		}

		// 가장 가까운 두 심판 사이의 거리가 mid를 만족하는 경우
		if (total_m >= M) {
			result.assign(str);
			low = mid + 1;
		}
		// 만족하지 못하는 경우
		else {
			high = mid - 1;
		}
	}

	cout << result;


	return 0;
}