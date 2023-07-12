#include <iostream>
#include <vector>
#include <cstdio>

#define MAX_NUM 1500000

using namespace std;

int D[MAX_NUM + 1];
vector<int> arr[MAX_NUM + 1];
pair<int, int> meeting[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// �Է¹ޱ�
	for (int i = 1; i <= N; i++) {
		int T, P;
		scanf("%d %d", &T, &P);
		meeting[i].first = T;
		meeting[i].second = P;

		if (i + T - 1 <= N) {
			arr[i + T - 1].push_back(i);
		}
	}

	// D[i] : i�ϱ��� ���� �� ���� �� �ִ� ���ð�
	// i�ϱ��� ����ϴ°� �ִ��� Ȯ���ϰ� �װ� j���� ����̸�
	// D[i-j] + "j�Ͽ� ����ؼ� �޴� ����"�� D[i-1]�� ���ؼ� �� ū ���� ����
	for (int i = 1; i <= N; i++) {
		int max = D[i - 1];
		for (auto t : arr[i]) {
			if (D[t - 1] + meeting[t].second > max) {
				max = D[t - 1] + meeting[t].second;
			}
		}
		D[i] = max;
	}

	cout << D[N];

	return 0;
}