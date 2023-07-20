#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;
int arr[MAX_NUM + 1]; // 수열을 담는 배열
pair<int, int> D[MAX_NUM + 1];

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> b;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}

	int min = abs(N - 100);
	int size = log10((double)(N));
	int result_size = 0;

	for (int i = 0; i < 3; i++, size++) {
		if (size > 0) {
			for (int j = pow(10, size - 1) - 1; j < pow(10, size); j++) {
				int n = j;
				do {
					for (int k = 0; k < b.size(); k++) {
						if (n % 10 == b[k]) {
							n = -1;
							break;
						}
					}
					if (n == -1) {
						break;
					}
					n /= 10;
				} while (n > 0);

				if (i == 2 && n != -1) {
					if (abs(N - j) + size > min + result_size) {
						break;
					}
				}
				if (n != -1) {
					cout << "j : " << j << endl;
					if (min + result_size > abs(N - j) + size) {
						min = abs(N - j);
						result_size = size;
					}
				}
		
			}
		}
		else {
			for (int j = 0; j < 10; j++) {
				int n = j;

			}
		}
	}

	cout << min + result_size << endl;

	return 0;
}