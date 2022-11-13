#include <iostream>
#include <vector>

std::vector<long long> getBitstreamConfig(int n) {
    std::vector<long long> result;
    int i = 1;
    while(i <= n) {
        result.push_back(i);
        i *= 2;
    }
    return result;
}

int main() {
    std::vector<long long> p = getBitstreamConfig(4099);
    for(int i = 0; i < p.size(); i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}