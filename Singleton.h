#pragma once

/// <summary>
/// �̱��� ����.
/// </summary>
/// <typeparam name="T">������ ���� �ν��Ͻ��� Ÿ��.</typeparam>
template <typename T>
class Singleton abstract {
protected:

	Singleton() {}
	Singleton(const Singleton& _other) = delete;
	void operator = (const Singleton& _other) = delete;

public:
	/// <summary>
	/// ������ ���� �ν��Ͻ��� �����ɴϴ�.
	/// </summary>
	/// <returns></returns>
	static T& GetInstance() {
		static T* instance = new T();
		return *instance;
	}

};
