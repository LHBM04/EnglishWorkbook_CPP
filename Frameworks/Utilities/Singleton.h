#pragma once

template <typename T>
class Singleton abstract {
protected:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	void operator = (const Singleton&) = delete;

public:
	/// <summary>
	/// ������ ���� �ν��Ͻ��� �����ɴϴ�.
	/// </summary>
	static const T& GetInstance() {
		static T* instance = new T();
		return *instance;
	}
};