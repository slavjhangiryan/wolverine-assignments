#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>


std::vector<std::string> parseLine(const std::string& line) {
	std::vector<std::string> ret;

	for (auto tokenBegin = line.begin(); tokenBegin < line.end(); ++tokenBegin) {
		while (tokenBegin < line.end() && *(tokenBegin) == ' ') { ++tokenBegin; }

		auto tokenEnd = tokenBegin;
		while (tokenEnd < line.end() && isalnum(*(tokenEnd))) { ++tokenEnd; }

		std::string token = std::string(tokenBegin, tokenEnd);
		tokenBegin = tokenEnd;
		if (!token.empty()) {
			ret.push_back(token);
		}
	}

	return ret;
}

void transferData(std::ifstream& src, std::ofstream& dest) {
	std::string line;
	while (std::getline(src, line)) {
		if (line.empty()) {
			continue;
		}

		std::vector<std::string> parsedLine = parseLine(line);
		for (int i = 0; i < parsedLine.size(); ++i) {
			dest << parsedLine[i] << '\n';
		}
	}
}

int main() {
	std::ifstream src("source.txt");
	std::ofstream dest("destination.txt");
	
	transferData(src, dest);
}
