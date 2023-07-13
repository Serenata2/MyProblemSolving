#include <iostream>
#include <cstdio>

#define MAX_NUM 100000

using namespace std;

// D[i] : i번째에서 끝나는 부분수열 중 가장 합이 제일 큰 것
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
		//  +       -		-> 어쩔 수 없이 더해야겠다
		//  +		+		-> 더함
		//  -		+		-> num
		//  -		-		-> num

		if (D[i - 1] >= 0) {
			D[i] = D[i - 1] + num;
		}
		else {
			D[i] = num;
		}

		// 최댓값을 계속 갱신한다.
		if (D[i] > max) {
			max = D[i];
		}
	}

	cout << max;

	return 0;
}