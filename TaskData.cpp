#include "TaskData.h"

TaskData::TaskData()
{
	m_minute = 0;
	m_hour = 0;
	m_day = 0;
	m_command = "";
}

TaskData::TaskData(const TaskData& data)
{
	m_minute = data.m_minute;
	m_hour = data.m_hour;
	m_day = data.m_day;
	m_command = data.m_command;
}

TaskData::~TaskData() {}

// operator overloading - '>>' - for input stream
std::istream& operator>>(std::istream& inputStream, TaskData& taskData)
{
	inputStream >> taskData.m_minute;
	inputStream.ignore();
	inputStream >> taskData.m_hour;
	inputStream.ignore();
	inputStream >> taskData.m_day;
	inputStream.ignore();
	inputStream >> taskData.m_command;

	return inputStream;
}

// operator overloading - '<<' - for output stream
std::ostream& operator<<(std::ostream& os, TaskData& taskData)
{
	os << taskData.m_minute << " " << taskData.m_hour << " " << taskData.m_day << " " << taskData.m_command << std::endl;
	return os;
}
