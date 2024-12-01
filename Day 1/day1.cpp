#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> a;
    std::vector<int> b;

    int x = 0;
    int y = 0;

    std::map<int, int> z;

    std::ifstream input_stream("input.in");

    std::string string;

    while (std::getline(input_stream, string)) {
        std::istringstream string_stream(string);

        int m;
        int n;

        string_stream >> m >> n;

        a.push_back(m);
        b.push_back(n);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (std::size_t i = 0; i < a.size(); i++) x = x + std::abs(a[i] - b[i]);

    for (auto const j: b) z[j]++;

    for (auto const k: a) y = y + (k * z[k]);

    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

