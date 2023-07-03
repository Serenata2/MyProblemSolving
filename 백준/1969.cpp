#include <iostream>
#include <cstdio>

using namespace std;

int dna[51][26]; // 각 자리별 나오는 문자의 수
int max_dna[51]; // 각 자리별 최대 문자

int main(void)
{
	int N, M;

	cin >> N >> M;

	getchar();

	for (int i = 1; i <= N; i++) {
		char ch;
		int j = 1;
		while ((ch = getchar()) != '\n') {

			dna[j][ch - 'A']++;
			if ((ch - 'A') != max_dna[j] && dna[j][max_dna[j]] == dna[j][ch - 'A'] && max_dna[j] > (ch - 'A')) {
				max_dna[j] = (ch - 'A');
			}
			else if (dna[j][ch - 'A'] > dna[j][max_dna[j]]) {
				max_dna[j] = (ch - 'A');
			}
			j++;
		}
	}

	for (int i = 1; i <= M; i++) {
		printf("%c", 'A' + max_dna[i]);
	}

	int count = 0;
	for (int i = 1; i <= M; i++) {
		count += dna[i][max_dna[i]];
	}

	cout << endl << N * M - count;


	return 0;
}

