#define _CRT_SECURE_NO_WARNINGS

#include "Time.h"

Time::Time()
{
	m_t_minute = 0; // minute - 00:00
	m_t_hour = 0; // hour - 00:00
	m_t_day = 0; // day - Sunday
}

Time::Time(const TaskData& data)
{
	m_t_minute = data.m_minute;
	m_t_hour = data.m_hour;
	m_t_day = data.m_day;
}

Time::Time(int min, int hour, int days) : m_t_minute{ min }, m_t_hour{ hour }, m_t_day{ days } {}

Time::~Time() {}

// calculate ms between current time to desire time of the task
int Time::TimeDifference(Time taskTime)
{
	time_t now = time(0); // current date/time based on current system
	tm* ltm = localtime(&now);

	Time zeroTime(); // Initial Time 

	int task_day = (taskTime.m_t_day + 1) % 7; // Make Day of week to be: 0-6, where 0 = Sunday, 6 = Sutarday

	int total_min_to_task = (((task_day * 24) + taskTime.m_t_hour) * 60) + taskTime.m_t_minute;

	int total_min_till_curr_time = (((ltm->tm_wday * 24) + ltm->tm_hour) * 60) + ltm->tm_min;

	int total_min_diff = total_min_to_task - total_min_till_curr_time;

	if (total_min_diff <= 0) // task can be executed this week
	{
		return (min_in_week + total_min_diff);
	}
	return total_min_diff;
}
