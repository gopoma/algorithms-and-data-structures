#include <iostream>
#include <cstddef>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using i64 = long long;

template <typename T>
void show(size_t n, T arr[]) {
    for(size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

template <typename T>
void show(vector<T> v) {
    for(T e: v) {
        cout << e << " ";
    }
    cout << "\n";
}

template <typename T>
void show(vector<vector<T>> mtx) {
    for(vector<T> v: mtx) {
        show<T>(v);
    }
}

template <typename T>
void show(set<vector<T>> mtx) {
    for(vector<T> v: mtx) {
        show<T>(v);
    }
}

void dfs(size_t cl, const size_t ml, vector<i64> &current, const size_t n, i64 base[], const i64 ll, i64 mm, vector<vector<i64>> &rpatterns) {
    if(cl <= ml) {
        for(size_t i = 0; i < n; i++) {
            current.push_back(base[i]);
            
            vector<i64> partial;
            for(i64 cc: current) {
                partial.push_back(cc);
            }
            i64 ss = 0;
            for(i64 pp: partial) {
                ss += pp;
            }
            if(ss <= ll && ll - ss < mm) {
                rpatterns.push_back(partial);
            }
            
            dfs(cl+1, ml, current, n, base, ll, mm, rpatterns);
            current.pop_back();            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const i64 ll = 12;
    const size_t n = 4;
    i64 d[n] = {5, 7, 8, 3};
    i64 q[n] = {150, 200, 85, 100};

    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < n - i - 1; j++) {
            if(d[j] > d[j + 1]) {
                i64 tmp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = tmp;

                i64 tmp2 = q[j];
                q[j] = q[j + 1];
                q[j + 1] = tmp2;
            }
        }
    }

    const size_t levels = ll/d[0];
    vector<vector<i64>> rpatterns;
    vector<i64> current;
    dfs(1, levels, current, n, d, ll, d[0], rpatterns);
    set<vector<i64>> ppatterns;
    for(size_t i = 0; i < rpatterns.size(); i++) {
        sort(rpatterns[i].begin(), rpatterns[i].end());
        ppatterns.insert(rpatterns[i]);
    }
    vector<vector<i64>> patterns;
    for(vector<i64> v: ppatterns) {
        patterns.push_back(v);
    }

    i64 dp[n+1][patterns.size()]{};
    for(size_t j = 0; j < patterns.size(); j++) {
        for(size_t i = 0, counter = 0; i < n; i++) {
            while(patterns[j][counter] == d[i]) {
                dp[i][j]++;
                counter++;
            }
        }
    }

    for(size_t j = 0; j < patterns.size(); j++) {
        i64 ss = 0;
        for(i64 e: patterns[j]) {
            ss += e;
        }
        dp[n][j] = ll - ss;
    }

    for(size_t i = 0; i < n+1; i++) {
        for(size_t j = 0; j < patterns.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}