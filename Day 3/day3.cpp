#include <cstdio>
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

int main() {
	std::ifstream f("input.in");
	int sum = 0;
	std::stringstream buffer;
	buffer << f.rdbuf();

	std::string input = buffer.str();
	printf("%s", input.c_str());
	buffer.str("");

	/*
		* Part 1
	*/

	// Get all mul(x, y) patterns
	std::regex expr(R"(mul\((\d{1,3}),(\d{1,3})\))");
	std::smatch m;

	std::stringstream output_buffer;

	for(std::sregex_iterator it{input.begin(), input.end(), expr}, end{}; it != end; ++it) {
		output_buffer << it->str() << std::endl;

		int num1 = std::stoi((*it)[1]);
		int num2 = std::stoi((*it)[2]);
		sum += (num1 * num2);
	}

	std::cout << sum << std::endl;
	printf("\n");
	printf("\n");
	printf("\n");

	output_buffer.str("");

	/*
		* Part 2
	*/

	sum = 0;
	std::regex expr2(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don\'t\(\))");
	std::smatch n;

	for(std::sregex_iterator it{input.begin(), input.end(), expr2}, end{}; it != end; ++it) {
		if (it->str().compare("don\'t()") == 0) {
			while(it->str().compare("do()") != 0 && it != end) {
				++it;
			}

		}

		if (it->str().compare("do()") == 0) {
			++it;
		}

		if(it == end) {
			break;
		}

		output_buffer << it->str() << std::endl;
		printf("%s", output_buffer.str().c_str());

		int num1 = std::stoi((*it)[1]);
		int num2 = std::stoi((*it)[2]);
		sum += (num1 * num2);
	}

	printf("%d", sum);

	return 0;
}

