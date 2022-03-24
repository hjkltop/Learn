#include <mutex>
#include <thread>
#include <iostream>

//线程非安全版本
class NonThreadSafeSingleton
{
private:
	NonThreadSafeSingleton();

public:
	static NonThreadSafeSingleton *getInstance();
	static NonThreadSafeSingleton *m_instance;
};

NonThreadSafeSingleton *NonThreadSafeSingleton::m_instance = nullptr;
NonThreadSafeSingleton *NonThreadSafeSingleton::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new NonThreadSafeSingleton();
	}
	return m_instance;
}

//依靠锁的线程安全单例，但可能会引起 Double-Checked Locking Pattern。
class ThreadSafeSingleton
{
private:
	ThreadSafeSingleton();

public:
	static ThreadSafeSingleton *getInstance();
	static ThreadSafeSingleton *m_instance;
};

ThreadSafeSingleton *ThreadSafeSingleton::m_instance = nullptr;

ThreadSafeSingleton *ThreadSafeSingleton::getInstance()
{
	static std::mutex singleton_mutex; //互斥锁
	std::lock_guard<std::mutex> lock(singleton_mutex);
	if (m_instance == nullptr)
	{
		m_instance = new ThreadSafeSingleton();
	}
	return m_instance;
}

int main(int argc, char *argv[])
{
	std::cout << &*NonThreadSafeSingleton::getInstance() << &*NonThreadSafeSingleton::getInstance() << std::endl;
	std::cout << &*ThreadSafeSingleton::getInstance() << &*ThreadSafeSingleton::getInstance() << std::endl;
	return (0);
}