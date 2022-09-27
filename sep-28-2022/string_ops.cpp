#include <iostream>
#include <cctype>


std::string toLowerCase(const std::string& str) {
    std::string res = str;

    for(int i = 0; i < res.size(); ++i) {
        if(isupper(res[i])) {
            res[i] += 32;
        }
    }

    return res;
}

std::string toUpperCase(const std::string& str) {
    std::string res = str;

    for(int i = 0; i < res.size(); ++i) {
        if(islower(res[i])) {
            res[i] -= 32;
        }
    }

    return res;
}

bool startsWith(const std::string& str, const std::string& sub) {
    return(std::string(str.cbegin(), str.cbegin() + sub.size()) == sub);
}

bool endsWith(const std::string& str, const std::string& sub) {
    return(std::string(str.cend() - sub.size(), str.cend()) == sub);
}

std::string replaceWith(const std::string& str, const std::string& t, const std::string& r) {
    std::string res = str;

    auto it = res.begin();

    while(it < res.end()) {
        while(it < res.end() && std::string(it, it + t.size()) != t) { ++it; }
        if(it != res.end()) {
            res.erase(it, it + t.size());
            res.insert(it, r.begin(), r.end());
        }
        it += r.size();
    }

    return res;
}

int main() {
}