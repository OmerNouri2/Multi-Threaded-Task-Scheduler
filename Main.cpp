#include <iostream>

#include "CSVReader.h"
#include "TaskData.h"
#include "Task.h"

int main()
{
    // Creating an object of CSVWriter
    std::string csvFileName = "cpp_practical_test.csv";
    CSVReader reader(csvFileName);
  
    // Get the data from CSV File
    std::vector<TaskData*> dataVector = reader.Read();

    std::vector<Task*> tasksVector{};

    // Create tasks
    for (const TaskData* data : dataVector)
    {
        tasksVector.push_back(new Task(*data));
    }


    std::vector<std::thread*> threads_vector{};

    for (Task* task : tasksVector)
    {
        threads_vector.push_back(task->Run());
    }

    for (std::thread* th : threads_vector)
    {
        th->join();
    }

    for (std::thread* th : threads_vector)
    {
        delete th;
    }
    

    for (TaskData* data : dataVector)
    {
        delete data;
    }

    for (Task* task : tasksVector)
    {
        delete task;
    }

    return 0;
}