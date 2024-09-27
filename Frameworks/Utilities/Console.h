#pragma once

#include <chrono>
#include <iostream>
#include <limits>
#include <thread>
#include <type_traits>

/// <summary>
/// 입/출력 담당 유틸리티.
/// </summary>
class Console {
public:	// Output
	/// <summary>
	/// 문장을 작성합니다.
	/// </summary>
	/// <param name="text">작성할 문장.</param>
	/// <param name="duration">글자 타이핑 시간.</param>
	static void Write(const std::string& text, long long duration = 0);
	static void Write(const char* text, long long duration = 0);

	/// <summary>
	/// 문장을 작성한 후, 개행합니다.
	/// </summary>
	/// <param name="text">작성할 문장.</param>
	/// <param name="duration">글자 타이핑 시간.</param>
	static void WriteLine(const std::string& text, long long duration = 0);
	static void WriteLine(const char* text, long long duration = 0);

public: // Input
	/// <summary>
	/// 값을 입력받습니다.
	/// </summary>
	/// <typeparam name="T">입력받을 값의 타입.</typeparam>
	/// <param name="min">입력받을 값의 최솟값.</param>
	/// <param name="max">압력받을 값의 최댓값.</param>
	/// <returns>입력값</returns>
	template<typename T> requires std::is_fundamental_v<T>
	static const T Get(const T min = std::numeric_limits<T>().min(), const T max = std::numeric_limits<T>().max()) {
		auto value = min;
		while (std::cin >> value, std::cin.ignore() && (value < min || value > max));

		return value;
	}
	
	static const char Get(const char min = std::numeric_limits<char>().min(), const char max = std::numeric_limits<char>().max());
	static const short Get(const short min = std::numeric_limits<short>().min(), const short max = std::numeric_limits<short>().max());
	static const int Get(const int min = std::numeric_limits<int>().min(), const int max = std::numeric_limits<int>().max());
	static const long Get(const long min = std::numeric_limits<long>().min(), const long max = std::numeric_limits<long>().max());
	static const long long Get(const long long min = std::numeric_limits<long long>().min(), const long long max = std::numeric_limits<long long>().max());

	static const unsigned char Get(const unsigned char min = std::numeric_limits<unsigned char>().min(), const unsigned char max = std::numeric_limits<unsigned char>().max());
	static const unsigned short Get(const unsigned short min = std::numeric_limits<unsigned short>().min(), const unsigned short max = std::numeric_limits<unsigned short>().max());
	static const unsigned int Get(const unsigned int min = std::numeric_limits<unsigned int>().min(), const unsigned int max = std::numeric_limits<unsigned int>().max());
	static const unsigned long Get(const unsigned long min = std::numeric_limits<unsigned long>().min(), const unsigned long max = std::numeric_limits<unsigned long>().max());
	static const unsigned long long Get(const unsigned long long min = std::numeric_limits<unsigned long long>().min(), const unsigned long long max = std::numeric_limits<unsigned long long>().max());
	
	static const std::string GetLine(const size_t length = std::numeric_limits<std::streamsize>().max());
	
};
