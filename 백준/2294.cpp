#include <iostream>
#include <climits>
#include <set>

#define MAX_NUM 10000

using namespace std;

int arr[101];
set<int> s;
//D[i]: ���ݱ��� �˰��ִ� �������� ������ i���� ���� �� �ִ� �ּ����� ��������
int D[MAX_NUM + 1];

int main()
{
	int N, K;

	cin >> N >> K;

	// �ߺ����� �ʰ� �Է¹ޱ�
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		if (s.find(num) == s.end()) {
			arr[cnt++] = num;
			s.insert(num);
		}
	}
	N = cnt - 1;

	// ù ��° ������ ������ ���� �� �ִ� ��� ��� �ʱ�ȭ�ϱ�
	for (int i = 1; i <= K; i++) {
		D[i] = INT_MAX;
		if (arr[1] <= i && i % arr[1] == 0) {
			D[i] = i / arr[1];
		}
	}

	// ������ �������� ���ʴ�� �߰��ϸ鼭 D�迭 ä���
	for (int i = 2; i <= N; i++) {
		if (arr[i] <= MAX_NUM) {
			D[arr[i]] = 1;
		}
		for (int j = arr[i] + 1; j <= K; j++) {
			if (D[j - arr[i]] != INT_MAX) {
				D[j] = min(D[j], 1 + D[j - arr[i]]);
			}
		}
	}

	// K���� �� ����� ���
	if (D[K] == INT_MAX) {
		cout << -1;
	}
	// K���� ���� �� �ִ� ���
	else {
		cout << D[K];
	}

	return 0;
}