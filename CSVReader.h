#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include "TaskData.h"

/*
 * A class to read data from a csv file.
 */
class CSVReader
{

public:
    CSVReader() = default;
    CSVReader(std::string fileName); // Constructor
    ~CSVReader();

public:
    std::vector<TaskData*> Read();

protected:
    std::string m_fileName;
};

