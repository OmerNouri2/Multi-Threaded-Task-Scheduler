#include "TaskData.h"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>

class Task
{

public:
	Task() = default;
	Task(const TaskData& data);
	~Task();

public:
	std::thread* Run();

	void print_time_point(std::chrono::system_clock::time_point timePoint);
	void ThreadFunc();
	void WeeklyThreadFunc();
		

protected:
	TaskData m_data;

};

