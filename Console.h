#pragma once

/// <summary>
/// ��/��� ��� ��ƿ��Ƽ.
/// </summary>
class Console {
private:
	/// <summary>
	/// �⺻ ���� ��� �ð�.
	/// </summary>
	static const std::chrono::milliseconds DEFAULT_DISPLAY_DURATION;

public:	// Output
	/// <summary>
	/// ������ �ۼ��մϴ�.
	/// </summary>
	/// <param name="text">�ۼ��� ����.</param>
	/// <param name="duration">���� Ÿ���� �ð�.</param>
	static void Write(const std::string& text, long long duration = 0);
	static void Write(const char* text, long long duration = 0);

	/// <summary>
	/// ������ �ۼ��� ��, �����մϴ�.
	/// </summary>
	/// <param name="text">�ۼ��� ����.</param>
	/// <param name="duration">���� Ÿ���� �ð�.</param>
	static void WriteLine(const std::string& text, long long duration = 0);
	static void WriteLine(const char* text, long long duration = 0);

	/// <summary>
	/// �͹̳��� �����մϴ�.
	/// </summary>
	static void Clear();

private: // Input(Template)
	/// <summary>
	/// ���� �Է¹޽��ϴ�.
	/// </summary>
	/// <typeparam name="T">�Է¹��� ���� Ÿ��.</typeparam>
	/// <param name="min">�Է¹��� ���� �ּڰ�.</param>
	/// <param name="max">�з¹��� ���� �ִ�.</param>
	/// <returns>�Է°�</returns>
	template<typename T> requires std::is_fundamental_v<T>
	static const T Read(const T min, const T max, std::function<void()> message = nullptr) {
		auto value = min;
		while (true) {
			std::cin >> value;
			std::cin.ignore();

			if (value >= min || value <= max) {
				return value;
			}

			if (message != nullptr) {
				message();
			}
		}
	}
	
public: // Input(Default Type)
	/// <summary>
	/// ���� �Է� �޽��ϴ�.
	/// </summary>
	/// <param name="min">�Է¹��� ���� �ּڰ�</param>
	/// <param name="max">�Է¹��� ���� �ִ�</param>
	/// <returns>�Է°�.</returns>
	static const char Read(const char min = std::numeric_limits<char>().min(), const char max = std::numeric_limits<char>().max(), std::function<void()> message = nullptr);
	static const short Read(const short min = std::numeric_limits<short>().min(), const short max = std::numeric_limits<short>().max(), std::function<void()> message = nullptr);
	static const int Read(const int min = std::numeric_limits<int>().min(), const int max = std::numeric_limits<int>().max(), std::function<void()> message = nullptr);
	static const long Read(const long min = std::numeric_limits<long>().min(), const long max = std::numeric_limits<long>().max(), std::function<void()> message = nullptr);
	static const long long Read(const long long min = std::numeric_limits<long long>().min(), const long long max = std::numeric_limits<long long>().max(), std::function<void()> message = nullptr);

public: // Input(Unsigned Type)
	static const unsigned char Read(const unsigned char min = std::numeric_limits<unsigned char>().min(), const unsigned char max = std::numeric_limits<unsigned char>().max(), std::function<void()> message = nullptr);
	static const unsigned short Read(const unsigned short min = std::numeric_limits<unsigned short>().min(), const unsigned short max = std::numeric_limits<unsigned short>().max(), std::function<void()> message = nullptr);
	static const unsigned int Read(const unsigned int min = std::numeric_limits<unsigned int>().min(), const unsigned int max = std::numeric_limits<unsigned int>().max(), std::function<void()> message = nullptr);
	static const unsigned long Read(const unsigned long min = std::numeric_limits<unsigned long>().min(), const unsigned long max = std::numeric_limits<unsigned long>().max(), std::function<void()> message = nullptr);
	static const unsigned long long Read(const unsigned long long min = std::numeric_limits<unsigned long long>().min(), const unsigned long long max = std::numeric_limits<unsigned long long>().max(), std::function<void()> message = nullptr);
	
public: // Input(string Type)
	/// <summary>
	/// ������ �Է¹޽��ϴ�.
	/// </summary>
	/// <param name="length">�Է¹��� ������ �ִ� ����.</param>
	/// <returns>�Է¹��� ����.</returns>
	static const std::string ReadLine(const size_t length = std::numeric_limits<std::streamsize>().max(), std::function<void()> message = nullptr);
	
};

