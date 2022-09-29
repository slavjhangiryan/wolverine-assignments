#include <iostream>
#include <map>
#include <string>

enum class Colors {
	Red,
	Green,
	Blue,
	White,
	Black,
	Orange,
};

std::map<std::string, Colors> getColorsMap() {
	std::map<std::string, Colors> ret;

	ret["Red"] = Colors::Red;
	ret["Green"] = Colors::Green;
	ret["Blue"] = Colors::Blue;
	ret["White"] = Colors::White;
	ret["Black"] = Colors::Black;
	ret["Orange"] = Colors::Orange;

	return ret;
}

std::string toString(Colors colorToFind) {
	auto colorsMap = getColorsMap();
	for(auto [name, color] : colorsMap) {
		if(color == colorToFind) {
			return name;
		}
	}

	return "";
}

Colors toEnum(const std::string& color) {
	return getColorsMap()[color];
}

int main() {
	std::cout << toString(Colors::Green) << std::endl;
	std::cout << static_cast<int>(toEnum("Red")) << std::endl;

}

