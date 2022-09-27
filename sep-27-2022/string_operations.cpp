#include <iostream>

#include <vector>

#include <string>
#include <cctype>


std::string rtrim(const std::string& str) {
    auto it = str.cend();
    while(it > str.cbegin() && *(--it) == ' ') {}

    return std::string(str.begin(), ++it);
}

std::string ltrim(const std::string& str) {
    auto it = str.cbegin();
    while(it < str.cend() && *(++it) == ' ') {}

    return std::string(it, str.end());
}

std::string trim(const std::string& str) {
    auto beginIt = str.cbegin();
    while(beginIt < str.cend() && *(++beginIt) == ' ') {}

    auto endIt = str.cend();
    while(endIt > str.cbegin() && *(--endIt) == ' ') {}

    return std::string(beginIt, ++endIt);
}

std::vector<std::string> split(const std::string& str, const std::string& del) {
    std::vector<std::string> ret;

    auto tokenBegin = str.begin();
    auto tokenEnd = str.begin();

    while(tokenBegin < str.end()) {
        while(tokenEnd < str.end() && std::string(tokenEnd, tokenEnd + del.size()) != del) { ++tokenEnd; }

        ret.push_back(std::string(tokenBegin, tokenEnd));
        tokenBegin = ++tokenEnd;
    }

	return ret;
}

int main() {
    
}
