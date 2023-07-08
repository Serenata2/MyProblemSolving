#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[500001] = {};

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	sort(arr + 1, arr + 1 + n);

	long long sum = 0;
	// ���� �� �տ������� ���ʴ�� ����ִ´�.
	for (int i = 1; i <= n; i++)
		sum += abs(i - arr[i]);

	printf("%lld", sum);

	return 0;
}