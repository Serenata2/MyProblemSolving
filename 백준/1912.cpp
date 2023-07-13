#include <iostream>
#include <cstdio>

#define MAX_NUM 100000

using namespace std;

// D[i] : i��°���� ������ �κм��� �� ���� ���� ���� ū ��
int D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	cin >> D[1];
	int max = D[1];

	for (int i = 2; i <= N; i++) {
		int num;
		scanf("%d", &num);

		// D[i-1]  num
		//  +       -		-> ��¿ �� ���� ���ؾ߰ڴ�
		//  +		+		-> ����
		//  -		+		-> num
		//  -		-		-> num

		if (D[i - 1] >= 0) {
			D[i] = D[i - 1] + num;
		}
		else {
			D[i] = num;
		}

		// �ִ��� ��� �����Ѵ�.
		if (D[i] > max) {
			max = D[i];
		}
	}

	cout << max;

	return 0;
}