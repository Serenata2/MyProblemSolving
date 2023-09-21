#include <iostream>
#include <cstdio>

using namespace std;

int main() 
{
    int max_point = 0;
    int winner = 0;

    for (int i = 1; i <= 5; i++) {
        int point_sum = 0;

        for (int j = 0; j < 4; j++) {
            int point;
            cin >> point;

            point_sum += point;
        }

        if (point_sum > max_point) {
            max_point = point_sum;
            winner = i;
        }
    }

    cout << winner << " " << max_point;

    return 0;
}