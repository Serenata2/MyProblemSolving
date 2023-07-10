#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 2000000

using namespace std;

int home[MAX_NUM + 1];

int main()
{
	int N, C;
	cin >> N >> C;

	// 집의 좌표를 받고, 오름차순으로 정렬
	for (int i = 1; i <= N; i++) {
		scanf("%d", &home[i]);
	}
	sort(home + 1, home + N + 1);

	// 최대 거리를 이분 탐색으로 찾기
	int low = 1;
	int high = (home[N] - home[1]) / (C - 1);
	int result = 0;

	while (low <= high) {
		// 가장 인접한 두 공유기 사이의 거리를 mid로 가정
		int mid = (low + high) / 2;

		int sum = 0; // 공유기 사이 거리
		int total_c = 1; // 공유기 설치 횟수, 맨 처음 집에 이미 공유기를 설치했으므로 1로 초기화

		for (int i = 2; i <= N; i++) {
			sum += home[i] - home[i - 1];
			// 타이트하게 공유기 사이의 거리가 mid보다 크면 공유기 설치
			if (sum >= mid) {
				sum = 0;
				total_c++;
			}
			// 최대한으로 공유기를 설치한 경우 반복문 나오기
			if (total_c >= C) {
				break;
			}
		}

		// 가장 인접한 두 공유기 사이의 거리가 mid를 만족하는 경우
		if (total_c >= C) {
			result = mid;
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