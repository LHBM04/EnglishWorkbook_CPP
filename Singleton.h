#pragma once

/// <summary>
/// 싱글톤 패턴.
/// </summary>
/// <typeparam name="T">생성할 정적 인스턴스의 타입.</typeparam>
template <typename T>
class Singleton abstract {
protected:

	Singleton() {}
	Singleton(const Singleton& _other) = delete;
	void operator = (const Singleton& _other) = delete;

public:
	/// <summary>
	/// 생성한 정적 인스턴스를 가져옵니다.
	/// </summary>
	/// <returns></returns>
	static T& GetInstance() {
		static T* instance = new T();
		return *instance;
	}

};
