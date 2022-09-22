#include <iostream>
#include <map>

enum class MathOperation {
	ADD,
	SUB,
	MUL,
	DIV,
};

template <typename T>
T add(T x, T y);

template <typename T>
T sub(T x, T y);

template <typename T>
T mul(T x, T y);

template <typename T>
T divide(T x, T y);

template <typename T>
std::map<MathOperation, T(*)(T, T)> getMapCalculator();

int main() {
	auto calc = getMapCalculator<float>();
	std::cout << calc[MathOperation::DIV](6, 0) << std::endl;
}

template <typename T>
T add(T x, T y) {
    return x + y;
}

template <typename T>
T sub(T x, T y) {
    return x - y;
}

template <typename T>
T mul(T x, T y) {
    return x * y;
}

template <typename T>
T divide(T x, T y) {
    if(!y) {
        std::cerr << "Can't divide by zero, aborting..." << std::endl;
        std::abort();
    }
    return x / y;
}

template <typename T>
std::map<MathOperation, T(*)(T, T)> getMapCalculator(){
	return std::map<MathOperation, T(*)(T, T)>() = {
		{MathOperation::ADD, &add<T>},
		{MathOperation::SUB, &sub<T>},
		{MathOperation::MUL, &mul<T>},
		{MathOperation::DIV, &divide<T>},
	};
}
