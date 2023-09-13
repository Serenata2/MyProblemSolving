#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        string str;
        
        cin >> n >> str;

        str.erase(str.begin() + n - 1);

        cout << str << endl;
    }

    return 0;
}