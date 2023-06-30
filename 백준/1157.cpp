#include <iostream>

using namespace std;

int main(void)
{
	char c;

	// 알파벳이 나온 횟수를 저장하는 배열
	int arr[26] = { 0 };

	int max_index = 0;

	while ((c = getchar()) != '\n') {
		c = (char)(tolower(c));
		arr[c - 'a']++;

		if (arr[c - 'a'] > arr[max_index]) {
			max_index = c - 'a';
		}
	}

	int result = 'A' + max_index;
	
	for (int i = 0; i < 26; i++) {
		if (i != max_index && arr[i] == arr[max_index]) {
			result = '?';
			break;
		}
	}

	printf("%c", result);

	return 0;
}

