#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int count = 0;
    int num;

    while (cin >> num && num != 0) {
        int tens = num / 10;
        int ones = num % 10;
        if ((tens + ones) % 2 == 0) {
            arr[count] = num;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        cout << (char)arr[i];
    }
    cout << endl;

    return 0;
}
