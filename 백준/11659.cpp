#include <iostream>
#include <cstdio>

#define MAX_NUM 1000000

using namespace std;

int D[MAX_NUM + 1];

int main()
{
	int N, M;
	cin >> N >> M;

	// D[i] = 1 ~ i번째까지의 합
	for (int i = 1; i <= N; i++) {
		scanf("%d", &D[i]);
		D[i] += D[i - 1];
	}

	for (int i = 1; i <= M; i++) {
		int I, J;
		scanf("%d %d", &I, &J);

		printf("%d\n", D[J] - D[I - 1]);
	}

	return 0;
}