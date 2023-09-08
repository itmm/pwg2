# pwg – a password generator

* Generates random passwords
* takes three random words joined by '-'
* The repository for this project is at `https://github.com/itmm/pwg2`
* Sources are extracted into `pwg2.cpp`

```c++
// includes
// globals

int main() {
	// main
}
```
* First the included files are specified
* so the rest of the program can use them
* Then global elements are defined
* so the main function can use them
* At last the main function is defined
* This is the central entry point of the program

```c++
// ...
	// main
	// count lines
	// generate
// ...
```
* First the `main` function count all the lines in the dictionary
* Then we will generate the password by choosing three random words

```c++
// ...
// includes
	#include <fstream>
	#include <iostream>
	#include <string>
// ...
```
* The algorithm needs the `<string>` header for the `std::string`
  class
* and `<iostream>` to write them
* and `<fstream>` to read the dicitonry

```c++
// ...
// globals
	const char* dictionary_path = "/usr/share/dict/ngerman";

	template<typename L> int foreach_word(const L& action) {
		std::ifstream in { dictionary_path };
		std::string line;
		int count { 0 };
		while (std::getline(in, line)) {
			action(line, count++);
		}
		return count;
	}
// ...
```
* Helper function to iterate over all the words of a dictionary

```c++
// ...
	// count lines
	int count = foreach_word([](const std::string&, int) { });
// ...
```
* Counting lines is simply invoking `foreach_word` with an empty lambda

```c++
// ...
// includes
	#include <exception>
	#include <random>
// ...
```
* The `<random>` header from C++ is used to generate random numbers

```c++
// ...
// globals
	using Uniform = std::uniform_int_distribution<int>;
// ...
```
* Define type for uniform distribution
* This shortens the code parts that use random distributions

```c++
// ...
	// generate
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
// ...
```
