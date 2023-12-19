#include "Header.h"

const std::chrono::milliseconds Console::DEFAULT_DISPLAY_DURATION = std::chrono::milliseconds(5);

void Console::Write(const std::string& text, long long duration) {
	if (text.empty()) {
		return;
	}

	for (const char& ch : text) {
		std::cout << ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(duration ? std::chrono::milliseconds(duration) : DEFAULT_DISPLAY_DURATION));
	}
}

void Console::Write(const char* text, long long duration) {
	if (strlen(text) <= 0) {
		return;
	}

	for (const char* ch = text; *ch != '\0'; ++ch) {
		std::cout << *ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(duration ? std::chrono::milliseconds(duration) : DEFAULT_DISPLAY_DURATION));
	}
}

void Console::WriteLine(const std::string& text, long long duration) {
	if (text.empty()) {
		return;
	}

	for (const char& ch : text) {
		std::cout << ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(duration ? std::chrono::milliseconds(duration) : DEFAULT_DISPLAY_DURATION));
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
		std::this_thread::sleep_for(std::chrono::milliseconds(duration ? std::chrono::milliseconds(duration) : DEFAULT_DISPLAY_DURATION));
	}

	if (*((text + strlen(text)) - sizeof(char)) != '\n') {
		std::cout << std::endl;
	}
}

void Console::Clear() {
	std::cout << "\x1B[2J\x1B[H";
}

const char Console::Read(const char min, const char max, std::function<void()> event) {
	return Console::Read<char>(min, max, event);
}

const short Console::Read(const short min, const short max, std::function<void()> event) {
	return Console::Read<short>(min, max, event);
}

const int Console::Read(const int min, const int max, std::function<void()> event) {
	return Console::Read<int>(min, max, event);
}

const long Console::Read(const long min, const long max, std::function<void()> event) {
	return Console::Read<long>(min, max, event);
}

const long long Console::Read(const long long min, const long long max, std::function<void()> event) {
	return Console::Read<long long>(min, max, event);
}

const unsigned char Console::Read(const unsigned char min, const unsigned char max, std::function<void()> event) {
	return Console::Read<unsigned char>(min, max, event);
}

const unsigned short Console::Read(const unsigned short min, const unsigned short max, std::function<void()> event) {
	return Console::Read<unsigned short>(min, max, event);
}

const unsigned int Console::Read(const unsigned int min, const unsigned int max, std::function<void()> event) {
	return Console::Read<unsigned int>(min, max, event);
}

const unsigned long Console::Read(const unsigned long min, const unsigned long max, std::function<void()> event) {
	return Console::Read<unsigned long>(min, max, event);
}

const unsigned long long Console::Read(const unsigned long long min, const unsigned long long max, std::function<void()> event) {
	return Console::Read<unsigned long long>(min, max, event);
}

const std::string Console::ReadLine(const size_t length, std::function<void()> message) {
	auto value = std::string("");
	while (true) {
		std::getline(std::cin, value);

		if (value.length() <= length && !std::cin.fail()) {
			return value;
		}

		if (message != nullptr) {
			message();
		}

		std::cin.clear();
		std::cin.ignore(length ? length : std::numeric_limits<std::streamsize>().max(), '\n');
	}
}
