#include <sstream>

#include "CSVReader.h"

CSVReader::CSVReader(std::string fileName) : m_fileName{ fileName } {}

CSVReader::~CSVReader() {}

std::vector<TaskData*> CSVReader::Read()
{
    std::vector<TaskData*> output{};

    std::ifstream inputFile(m_fileName);

    // Make sure the file is open
    if (!inputFile.is_open()) 
    {
        std::cout << "Could not open file" << std::endl;
        return output;
    }
    
    std::string line;
  
    // Discard first line
    std::getline(inputFile, line);

    // Iterate through each line and split the content
    while (std::getline(inputFile, line))
    {
        std::istringstream stringStream(line);

        TaskData taskData;
        stringStream >> taskData;
        
        output.push_back(new TaskData(taskData));
    }

    // Close the File
    inputFile.close();

    return output;
}


//
//std::vector<std::string> CSVReader::split(string s, string delimiter)
//{
//    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
//    string token;
//    vector<string> res;
//
//    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
//        token = s.substr(pos_start, pos_end - pos_start);
//        pos_start = pos_end + delim_len;
//        res.push_back(token);
//    }
//
//    res.push_back(s.substr(pos_start));
//    return res;
//}
//
//
///*
//* Parses through csv file line by line and returns the data
//* in vector of vector of strings.
//*/
//std::vector<vector<string>> CSVReader::getData() {
//    ifstream file(this->fileName);
//    vector<vector<string> > dataList;
//    string line = "";
//
//    // Make sure the file is open
//    if (!file.is_open()) throw std::runtime_error("Could not open file");
//
//    // Iterate through each line and split the content using delimeter
//    while (getline(file, line))
//    {
//        // string delimiter = ",";
//        vector<string> vec = split(line, this->delimeter);
//        //   boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
//        dataList.push_back(vec);
//        for (auto i : vec) cout << i << endl;
//    }
//    // Close the File
//    file.close();
//
//    return dataList;
//
//};
