#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include "Task.h"
#include "TaskData.h"
#include "Time.h"

Task::Task(const TaskData& data) : m_data{ data } {}

Task::~Task(){}


// Print Current Time
void Task::print_time_point(std::chrono::system_clock::time_point timePoint) 
{
	std::time_t timeStamp = std::chrono::system_clock::to_time_t(timePoint);
	std::cout << std::ctime(&timeStamp) << std::endl;
}


void Task::ThreadFunc()
{
	std::cout << "Current Time :: ";  // Print Current Time
	print_time_point(std::chrono::system_clock::now());

	Time taskTime(m_data); // time in a week to execute task
	int min_diff_currTime_to_task = Time::TimeDifference(taskTime);  // the different time in minutes between current time to task desire time

	// create a time point pointing to the desire time in future to execute the task from now
	std::chrono::system_clock::time_point timePointToExec =
		std::chrono::system_clock::now() + std::chrono::minutes(min_diff_currTime_to_task);

	std::cout << "Going to Sleep Until :: "; print_time_point(timePointToExec);
	std::this_thread::sleep_until(timePointToExec); // Sleep Till specified time point

	WeeklyThreadFunc();
}

void Task::WeeklyThreadFunc()
{
	// create a time point to 1 week from now
	std::chrono::system_clock::time_point timePointToExec =
		std::chrono::system_clock::now() + std::chrono::minutes(Time::min_in_week);

	std::cout << "Going to Sleep Until :: "; print_time_point(timePointToExec);

	std::this_thread::sleep_until(timePointToExec); // Sleep Till specified time point - in 1 week from now

	WeeklyThreadFunc();
}

std::thread* Task::Run()
{
	std::thread* m_thread = new std::thread(&Task::ThreadFunc, this);
	return m_thread;
}
