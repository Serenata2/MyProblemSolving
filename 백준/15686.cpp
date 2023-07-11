#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<pair<int, int>> home;
	vector<pair<int, int>> shop;

	// ��, ġŲ�� ��ǥ �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (n == 2) {
				shop.push_back(make_pair(i, j));
			}
		}
	}

	vector<bool> temp(shop.size(), true);
	for (int i = 0; i < shop.size() - M; i++) {
		temp[i] = false;
	}

	// ���� �߿��� M���� �̰�,
	// ���� ��� �����κ��� ������ ġŲ �Ÿ��� ���ϰ�
	// �� �� �ּڰ��� ����ϱ�
	int result = INT_MAX;
	do {
		int sum = 0;
		for (auto h : home) {
			int min = INT_MAX;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i]) {
					int dis = abs(h.first - shop[i].first) + abs(h.second - shop[i].second);
					if (min > dis) {
						min = dis;
					}
				}
			}
			sum += min;
		}

		if (result > sum) {
			result = sum;
		}
	} while (next_permutation(temp.begin(), temp.end()));

	cout << result;

	return 0;
}