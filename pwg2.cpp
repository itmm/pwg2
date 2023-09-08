#line 9 "README.md"
// includes
#line 75
	#include <exception>
	#include <random>
#line 36
	#include <fstream>
	#include <iostream>
	#include <string>
#line 10
// globals
#line 84
	using Uniform = std::uniform_int_distribution<int>;
#line 49
	const char* dictionary_path = "/usr/share/dict/ngerman";
#line 11

#line 51
	template<typename L> int foreach_word(const L& action) {
		std::ifstream in { dictionary_path };
		std::string line;
		int count { 0 };
		while (std::getline(in, line)) {
			action(line, count++);
		}
		return count;
	}
#line 12
int main() {
	// main
#line 26
	// count lines
#line 67
	int count = foreach_word([](const std::string&, int) { });
#line 27
	// generate
#line 93
	auto seed { (std::random_device {})() };
	std::mt19937 re { seed };
	int max = count - 1;
	if (max < 0) {
		throw std::invalid_argument("no chars");
	}
	Uniform d { 0, max };
	for (int i = 0; i < 3; ++i) {
		if (i) { std::cout << '-'; }
		int cur { d(re) };
		auto &out { std::cout };
		foreach_word([=, &out](const std::string &word, int i) {
			if (i == cur) { out << word; }
		});
	}
	std::cout << '\n';
#line 14
}
