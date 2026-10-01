#include <iostream>
#include <iomanip>

using namespace std;

void calculateAndPrint(int speed, int energy, int precision) {
    float total;
    total = (3.0f * speed) + (4.0f * energy) - (2.0f * precision);
    cout << fixed << setprecision(1) << total << endl;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    for (int i = 1; i <= N; i++) {
        int speed, energy, precision;
        cin >> speed >> energy >> precision;
        cout << "Total efisiensi robot " << i << ": ";
        calculateAndPrint(speed, energy, precision);
    }

    return 0;
}
