#include <iostream>

void memset(char* ptr, char val, std::size_t count) {
	for(std::size_t i = 0; i < count; ++i) {
		ptr[i] = val;
	}
}


void memcpy(char* src, char* dest, std::size_t count) {
	for(std::size_t i = 0; i < count; ++i) {
		*dest = *src;
		++dest;
		++src;
	}
}

int main() { }
