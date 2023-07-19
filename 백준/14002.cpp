#include <iostream>
#include <cstdio>
#include <vector>

#define MAX_NUM 1000

using namespace std;
int arr[MAX_NUM + 1]; // ������ ��� �迭
// D[i].first : i ��° ���Ҹ� ���������� �ϴ� ���� �� �����ϴ� �κм����� ����
// D[i].second : i ��° ���Ҹ� ���������� �ϴ� ���� �� �����ϴ� �κм������� ������ �� ������ index
//               -> ���� ���ٸ� 0�� ������.
pair<int, int> D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// ���� �Է� �ޱ�
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	// �ʱ�ȭ
	D[1].first = 1;
	D[1].second = 0;

	// ���� ��ȹ��
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

	// ������ ���鼭 ���� ū ���� ������ D[i].first ���� ã�´�.
	int max = 1;

	for (int i = 2; i <= N; i++) {
		if (D[i].first > D[max].first) {
			max = i;
		}
	}

	// ���� �� �����ϴ� �κ� ������ ���� ���
	cout << D[max].first << endl;

	// vecotr<int> result : ���� �� �����ϴ� �κ� ������ ���Ҹ� ������ vector
	vector<int> result;
	result.push_back(arr[max]);

	// �ڿ������� ���鼭 ���ʷ� vector�� �ִ´�.
	for (int i = D[max].second; i > 0;) {
		result.push_back(arr[i]);
		i = D[i].second;
	}

	// ���� �ڿ������� ���!
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}

	return 0;
}