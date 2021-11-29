#pragma once

#include <istream>

class TaskData
{

public:
	TaskData(); // Constructor
	TaskData(const TaskData& data); // Copy Constructor
	~TaskData();
	friend class Task;
	friend class Time;

public:
	friend std::istream& operator>>(std::istream& is, TaskData& taskData);
	friend std::ostream& operator<<(std::ostream& os, TaskData& taskData);

protected:
	int m_minute;
	int m_hour;
	int m_day;
	std::string m_command;
};
