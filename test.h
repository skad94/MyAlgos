#include <string>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#pragma once
class LoggerFile : public ILogger
{
	static std::string fileName;
	std::string m_name;
public: 
	  LoggerFile(const std::string& name);
	  LoggerFile();
	  ~LoggerFile();
	  void logFile(const std::string& txt);
	  void log(const std::string& txt);
};
class LoggerScreen : public ILogger
{
public: 
void logScreen(const std::string& txt);
void log(const std::string& txt);
};

class ILogger
{
public:
	virtual void log(const std::string& txt) = 0;
};

// Composite class
class LoggerComposite //: public ILogger
{
private: std::vector<ILogger*> m_logger;
public:
	void log(const std::string& txt);
};

// string without repeating
std::pair<std::string, int> fun(const std::string& data);
std::pair<size_t, size_t> fun2(const std::vector<int>& data);
std::vector<int> mergeConcatenate(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> mergeSort(const std::vector<int>& data);
int maxSumSubArray(const std::vector<int>& data);
int exoNatixis(std::vector<int>data, const int& K);

