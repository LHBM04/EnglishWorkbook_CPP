#include "Console.h"

void Console::Write(const std::string& text, long long duration) {
	if (text.empty()) {
		return;
	}
	
	for (const char ch : text) {
		std::cout << ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(std::chrono::milliseconds(duration)));
	}
}

void Console::Write(const char* text, long long duration) {
	if (text == nullptr or 
		strlen(text) <= 0) {
		return;
	}
	
	for (const char* ch = text; *ch != '\0'; ++ch) {
		std::cout << *ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(std::chrono::milliseconds(duration)));
	}
}

void Console::WriteLine(const std::string& text, long long duration) {
	if (text.empty()) {
		return;
	}
	
	for (const char ch : text) {
		std::cout << ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(std::chrono::milliseconds(duration)));
	}

	if (text.back() != '\n') {
		std::cout << std::endl;
	}
}

void Console::WriteLine(const char* text, long long duration) {
	if (strlen(text) <= 0) {
		return;
	}
	
	for (const char* ch = text; *ch != '\0'; ++ch) {
		std::cout << *ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(std::chrono::milliseconds(duration)));
	}

	if (*((text + strlen(text)) - sizeof(char)) != '\n') {
		std::cout << std::endl;
	}
}

const char Console::Get(const char min, const char max) {
	return Console::Get<char>(min, max);
}

const short Console::Get(const short min, const short max) {
	return Console::Get<short>(min, max);
}

const int Console::Get(const int min, const int max) {
	return Console::Get<int>(min, max);
}

const long Console::Get(const long min, const long max) {
	return Console::Get<long>(min, max);
}

const long long Console::Get(const long long min, const long long max) {
	return Console::Get<long long>(min, max);
}

const unsigned char Console::Get(const unsigned char min, const unsigned char max) {
	return Console::Get<unsigned char>(min, max);
}

const unsigned short Console::Get(const unsigned short min, const unsigned short max) {
	return Console::Get<unsigned short>(min, max);
}

const unsigned int Console::Get(const unsigned int min, const unsigned int max) {
	return Console::Get<unsigned int>(min, max);
}

const unsigned long Console::Get(const unsigned long min, const unsigned long max) {
	return Console::Get<unsigned long>(min, max);
}

const unsigned long long Console::Get(const unsigned long long min, const unsigned long long max) {
	return Console::Get<unsigned long long>(min, max);
}

const std::string Console::GetLine(const size_t length) {
	std::string value{ "" };
	while (true) {
		std::getline(std::cin, value);

		if (value.length() <= length and !std::cin.fail()) {
			return value;
		}

		std::cin.clear();
		std::cin.ignore(length ? length : std::numeric_limits<std::streamsize>().max(), '\n');
	}
}
