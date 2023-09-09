#include <iostream>

using namespace std;

int main() 
{
    int current_p = 0;
    int in, out;

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        cin >> out >> in;

        current_p += (in - out);

        ans = max(ans, current_p);
    }

    cout << ans;

    return 0;
}