#include <cstddef>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {
	std::ifstream file("input.in");
	std::string buffer;
	std::map<int, std::vector<int>> ordering_rules;
	long sum = 0;

	// Read ordering rules
	while(std::getline(file, buffer)) {
		if(buffer.empty()) {
			break;
		}
		size_t delimiter_position = buffer.find('|');

		int num1 = std::stoi(buffer.substr(0, delimiter_position));
		int num2 = std::stoi(buffer.substr(delimiter_position + 1));

		ordering_rules[num1].push_back(num2);
	}

	// Read pages
	while(!file.eof() && std::getline(file, buffer)) {
		std::stringstream integers(buffer);
		std::string integer;
		std::vector<int> page_order_input;
		bool ok = true;

		while(std::getline(integers, integer, ',')) {
			int page = std::stoi(integer);

			std::cout << page << std::endl;

			page_order_input.push_back(page);

			for (int page: page_order_input) {
				std::cout << page << " ";
			}
			std::set<int> earlier;

			for(int i = 0; i < ordering_rules[page].size(); i++) {
				if(earlier.count(ordering_rules[page][i])) {
					ok = false;
				}
				earlier.insert(ordering_rules[page][i]);
			}

		}
		if(ok) {
			sum += page_order_input[page_order_input.size()/2];
		}
	}

	printf("%ld", sum);
}
