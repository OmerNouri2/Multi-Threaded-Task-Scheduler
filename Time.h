#include <iostream>
#include "TaskData.h"

class Time
{

public:
	Time();
	Time(const TaskData& data);
	Time(int min, int hour, int days);
	~Time();
	static int TimeDifference(Time taskTime);
	friend class Task;

protected:
	int m_t_minute;
	int m_t_hour;
	int m_t_day;
	static const int min_in_week = 10080;

};

