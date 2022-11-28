#include <iostream>
#include <vector>
#include <cmath>
#include <set>

const int amountRows = 5;
const int amountColumns = 4;
const int values[] = {5, 3, 2, 1};
const int reversed[] = {0, 3, 2, 1, 0, 5};

using namespace std;

void buildYupana(int num, vector<vector<int>> &y) {
    for(int i = amountRows - 1; i >= 0; i--) { // num.size()
        int d = num % 10;
        for(int j = 0; j < amountColumns; j++) {
            if(d - values[j] >= 0) {
                y[i][j] = 1;
                d -= values[j];
            } else {
                y[i][j] = 0;
            }
        }
        num /= 10;
    }
}

void showYupana(vector<vector<int>> &y) {
    for(vector<int> r: y) {
        for(int d: r) {
            cout << d;
        }
        cout << endl;
    }
}

void sumYupanas(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &R) {
    for(int i = 0; i < amountRows; i++) {
        for(int j = 0; j < amountColumns; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

void solve() {
    char t;
    cin >> t;

    if(t == 'N') {
        int a;
        cin >> a;

        vector<vector<int>> y(amountRows, vector<int>(amountColumns));
        buildYupana(a, y);
        showYupana(y);
    } else {
        int a, b;
        cin >> a >> b;

        vector<vector<int>> A(amountRows, vector<int>(amountColumns));
        vector<vector<int>> B(amountRows, vector<int>(amountColumns));
        vector<vector<int>> R(amountRows, vector<int>(amountColumns));
        buildYupana(a, A);
        buildYupana(b, B);
        sumYupanas(A, B, R);
        showYupana(R);

        set<string> pm;
        int counter = 0;
        do {
            for(int i = 0; i < amountRows; i++) {
                for(int j = 0; j < amountColumns; j++) {
                    if((R[i][j] >= 1 && R[i][j+1] >= 1) || (R[i][j] >= 1 && R[i][j+1] >= 1)) {
                        pm.insert("S "+to_string(values[j+1])+" "+to_string(pow(10, amountRows-i-1)));
                        counter++;
                    } else if(R[i][j] >= 2) {
                        pm.insert("D "+to_string(values[j])+" "+to_string(pow(10, amountRows-i-1)));
                        counter++;
                    }
                }
            }

            string instruction = *pm.end();
            vector<int> v;
            for(int i = 0; i < instruction.size(); i++) {
                if(instruction[i] == ' ') {
                    v.push_back(i);
                }
            }
            char type = instruction[0];
            int col = reversed[stoi(instruction.substr(v[0] + 1, 1))];
            int row = 5 - instruction.substr(v[1] + 1, instruction.size() - v[1] - 1).size();
            if(type == 'D') {
                if(col == 0) {
                    
                }
            } else {
                R[row][col - 1]--;    
                R[row][col]--;
                R[row][col - 2]++;

            }
            pm.erase(instruction);
        } while(!pm.empty());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int D;
    cin >> D;

    while(D--) {
        solve();
    }

    return 0;
}