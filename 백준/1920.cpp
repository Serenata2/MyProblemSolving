#include <iostream>
#include <cstdio>
#include <unordered_set>

#define MAX_NUM 20

using namespace std;

unordered_set<int> A;

int main() 
{
    int N, M;
    cin >> N;

    int n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        A.insert(n);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d", &n);
        if (A.find(n) != A.end()) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}