#include <iostream>

#define MAX_NUM 100000

using namespace std;

int arr[101];

int main() 
{
    int sum = 0;
    int max_index = 0;
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;

        // Æò±ÕÀ» À§ÇÑ sum
        sum += num;
        
        if (++arr[num / 10] > arr[max_index]) {
            max_index = num / 10;
        }
    }

    cout << sum / 10 << endl << 10 * max_index;

    return 0;
}