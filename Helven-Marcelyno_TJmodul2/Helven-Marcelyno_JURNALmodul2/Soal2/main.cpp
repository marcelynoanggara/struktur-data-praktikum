#include <iostream>
#include <iomanip>

using namespace std;

float calculatePower(int physical, int magic, int defense) {
    float total;
    total = (2.0f * physical) + (3.0f * magic) - (0.5f * defense);
    return total;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    cout << fixed << setprecision(1);
    for (int i = 1; i <= N; i++) {
        int physical, magic, defense;
        cin >> physical >> magic >> defense;
        float power = calculatePower(physical, magic, defense);
        cout << "Total kekuatan petualang " << i << ": " << power << endl;
    }

    return 0;
}
