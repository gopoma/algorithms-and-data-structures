#include <iostream>
#include <vector>

using namespace std;

void solve(int amount) {
    vector<int> money;
    money.push_back(1);
    money.push_back(2);
    money.push_back(5);
    money.push_back(10);
    money.push_back(20);
    money.push_back(50);
    money.push_back(100);
    money.push_back(200);

    int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int aux = money.size() - 1;

    while(aux >= 0) {
        if(amount - money[aux] >= 0) {
            amount -= money[aux];
            result[aux]++;
        } else {
            aux--;
        }
    }

    cout << "Billetes de 200: " << result[7] << endl;
    cout << "Billetes de 100: " << result[6] << endl;
    cout << "Billetes de 50: " << result[5] << endl;
    cout << "Billetes de 20: " << result[4] << endl;
    cout << "Billetes de 10: " << result[3] << endl;
    cout << "Billetes de 5: " << result[2] << endl;
    cout << "Billetes de 2: " << result[1] << endl;
    cout << "Billetes de 1: " << result[0] << endl;
}

int main() {
    solve(1373);

    return 0;
}