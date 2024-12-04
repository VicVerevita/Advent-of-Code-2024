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

	// get all mul(x, y) patterns
	std::regex expr(R"(mul\((\d{1,3}),(\d{1,3})\))");

	std::smatch m;

	for(std::sregex_iterator it{input.begin(), input.end(), expr}, end{}; it != end; ++it) {
		buffer << it->str() << std::endl;
		printf("%s", buffer.str().c_str());

		int num1 = std::stoi((*it)[1]);
		int num2 = std::stoi((*it)[2]);
		sum += (num1 * num2);
	}

	std::cout << sum;

	return 0;
}

