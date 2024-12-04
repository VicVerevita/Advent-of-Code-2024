#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include<map>
#include <vector>
#include <string>

int main() {
    std::vector<int> a, b;
    std::ifstream file("input.in");
    std::string input;
    long sum = 0;
    long similarity_score = 0;

    std::map<int, int> map;

    while(std::getline(file, input)) {
        std::istringstream string_stream(input);

        int m, n;
        string_stream >> m >> n;

        a.push_back(m);
        b.push_back(n);
        map[n]++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        sum += abs(a[i]-b[i]);

        if (map[a[i]]) {
            similarity_score += a[i] * map[a[i]];
        }
    }

    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The similarity_score is: " << similarity_score << std::endl;
}
