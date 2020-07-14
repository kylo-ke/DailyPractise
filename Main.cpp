//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//
//std::mutex mtx;
//std::condition_variable cv;
//bool ready = false;   // 全局标志位
//
//void printId(int id)
//{
//	std::unique_lock<std::mutex> lck(mtx);
//	// 如果标志位不为true，则等待
//	while (!ready)
//	{
//		std::cout << "TEST" << std::endl;
//		// 线程被阻塞，直到标志位变为true
//		cv.wait(lck);
//	}
//	std::cout << "thread: " << std::this_thread::get_id() << " id: " << id << "\n";
//}
//
//void go()
//{
//	std::unique_lock<std::mutex> lck(mtx);
//	// 改变全局标志位
//	ready = true;
//	// 唤醒所有线程
//	cv.notify_all();
//}
//
//int main()
//{
//	std::thread threads[20];
//
//	for (int i = 0; i < 20; ++i)
//	{
//		threads[i] = std::thread(printId, i);
//	}
//	std::cout << "create done.\n";
//
//	go();
//
//	for (auto &t : threads)
//	{
//		t.join();
//	}
//	std::cout << "process done.\n";
//	return 0;
//};


#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

int main()
{
	int counter = 0;
	std::mutex counter_mutex;
	std::vector<std::thread> threads;

	auto worker_task = [&](int id) {
		std::unique_lock<std::mutex> lock(counter_mutex);
		++counter;
		std::cout << id << ", initial counter: " << counter << '\n';
		lock.unlock();

		++counter;
		std::cout << id << ", final counter: " << counter << '\n';
		// don't hold the lock while we simulate an expensive operation
		std::this_thread::sleep_for(std::chrono::seconds(5));

		lock.lock();
		++counter;
		std::cout << id << ", final counter: " << counter << '\n';
	};

	for (int i = 0; i < 10; ++i) threads.emplace_back(worker_task, i);

	for (auto &thread : threads) thread.join();
}