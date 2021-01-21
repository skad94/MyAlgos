#include "test.h"
#include <algorithm>

//Given a string, find the length of the longest substring without repeating characters.
int maxx(const int& a, const int& b)
{
	if (a <= b)
		return b;
	else
		return a;
}
std::pair<int, int> foo(int a, int b) {
	return std::make_pair(a + b, a - b);
}
std::pair<std::string, int> fun(const std::string& data)
{
	// case 0 and case 1 to take into account
	if (data.size() <= 1)
		return std::make_pair(data, data.size());
	//int intres = 0;
	std::string res_memor;
	int i = 0;
	while (i < data.size())
	{
		std::set<char> memor;
		int intcurr(0);
		while (i + intcurr < data.size() && memor.insert(data[i + intcurr]).second == true)
		{
			intcurr++;
			//intres = maxx(intres, intcurr);
		}
		if (res_memor.size() < intcurr)
		{
			std::string tmp(data.begin() + i, data.begin() + intcurr + i);
			res_memor = tmp;
		}
		i += intcurr;
	}
	return std::make_pair(res_memor, res_memor.size());
}

/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*/
int min(int a, int b)
{
	if (a < b)
		return a;
	else return b;
}
std::pair<size_t, size_t> fun2(const std::vector<int>& data)
{

	size_t down = 0;
	size_t up = data.size() - 1;
	size_t res_down = 0;
	size_t res_up = data.size() - 1;
	int area_max((up - down) * min(data[up], data[down]));
	while (up > down)
	{
		if ((up - down) * min(data[up], data[down]) > area_max) //gymnastic in order to get min
		{
			area_max = (up - down) * min(data[up], data[down]);
			res_up = up;
			res_down = down;
		}
		if (data[down] < data[up])
			down++;
		else
			up--;

	}
	return std::make_pair(res_down, res_up);
}
std::vector<int> mergeConcatenate(const std::vector<int>& a, const std::vector<int>& b)
{
	if (a.size() < 1)
		return b;
	if (b.size() < 1)
		return a;
	if (a[0] <= b[0])
	{
		int lowest(a[0]);
		std::vector<int> copyA(a.begin() + 1, a.end());
		std::vector<int> res = mergeConcatenate(copyA, b);
		res.insert(res.begin(), lowest);
		return res;
	}
	else
	{
		int lowest(b[0]);
		std::vector<int> copyb(b.begin() + 1, b.end());
		std::vector<int> res = mergeConcatenate(copyb, a);
		res.insert(res.begin(), lowest);
		return res;
	}
}
std::vector<int> mergeSort(const std::vector<int>& data)
{
	if (data.size() >= 2)
	{
		int nb = data.size();
		std::vector<int> tmpLow(data.begin(), data.begin() + nb / 2);
		std::vector<int> tmpUp(data.begin() + nb / 2, data.end());
		return mergeConcatenate(mergeSort(tmpLow), mergeSort(tmpUp));
	}
	return data;
}
// Given a integer (positive or negative) array find the value of the maximum sum of contiguous sub-array
int maxSumSubArray(const std::vector<int>& data)
{
	if (data.empty())
		throw("test::maxSumSubArray: the input is empty");
	if (data.size() == 1)
		return data[0];
	int currentMax(data[0]);
	int currentSum(currentMax);
	for (size_t i(1); i < data.size(); i++)
	{
		currentSum += data[i];
		currentSum = maxx(data[i], currentSum);
		currentMax = maxx(currentMax, currentSum);
	}
	return currentMax;
}
/*Écrire une fonction C++ qui à partir d’un tableau d’entier data et d’un entier K
sort le nombre de pair tel que la somme des deux nombres vaut K.

data = [0, 6, -1, 3, 2, 3, 4, 1]
k = 3.
(0, 3); (0, 3); (-1, 4); (2, 1) = > 4 paires.

On pourra utiliser la stl autant que l’on souhaite et on suppose que tous les includes nécessaires sont fait.
Soit N la taille du vecteur initiale que l'on peut modifier.
La fonction devra etre au plus en
O(NxLog(N)) opérations
O(N) en physique. */
int exoNatixis(std::vector<int> data, const int& K)
{
	std::map<size_t, int> storageData;

	for (size_t i = 0; i < data.size(); ++i)
	{
		storageData[K - data[i]] = i;
	}
	int res = 0;
	for (size_t j = 0; j < data.size(); ++j)
	{
		auto complementary = storageData.find(data[j]);
		if (complementary != storageData.end())
		{
			++res;
			data.erase(data.begin() + complementary->second);
		}
	}
	return res;
}
std::vector<int>
twoSum(std::vector<int>& data, const int& target)
{
	// ***** data must be sorted
	// the function returns the pair that sums up to target with the minimum value
	int up = data.size() - 1;
	int down = 0;
	while (up > down && data[down] + data[up] != target)
	{
		if (data[down] + data[up] > target)
			up--;
		if (data[down] + data[up] < target)
			down++;
	}
	if (up > down)
	{
		std::vector<int> res = { down, up };
		return res;
	}
	else
		return std::vector<int>();
}
////
std::vector<std::vector<int>>
threeSum(std::vector<int>& data)
{
	//Leetcode 15
	/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
	Find all unique triplets in the array which gives the sum of zero.
	Notice that the solution set must not contain duplicate triplets
	*/
	std::sort(data.begin(), data.end());
	std::vector<std::vector<int>> res;
	//auto it = data.begin();
	//for (; it != data.end(); ++it)
	for (int i = 0; i < data.size(); ++i)
	{
		//std::vector<int> tmpRes = twoSum(data, -(*it));
		std::vector<int> tmpRes = twoSum(data, -data[i]);
		if (tmpRes.size() != 0)
		{
			//std::vector<int> tmpTmpRes = { *it,data[tmpRes[0]], data[tmpRes[1]] };
			std::vector<int> tmpTmpRes = { data[i],data[tmpRes[0]], data[tmpRes[1]] };
			res.push_back(tmpTmpRes);
			//data.erase(it);
			data.erase(data.begin() + i);
			if (tmpRes[0] - 1 > 0)
				data.erase(data.begin() + tmpRes[0] - 1);
			if (tmpRes[1] - 2 > 0)
				data.erase(data.begin() + tmpRes[1] - 2);
		}
	}
	return res;
}

int 
divide(int dividend, int divisor)
{
	/*Given two integers dividend and divisor, divide two integers without using multiplication, division,
 and mod operator. Return the quotient after dividing dividend by divisor.
 The integer division should truncate toward zero, which means losing its fractional part. 
 For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.*/
	if dividend < divisor
		return 0;
	else
	{
		int remain = divisor + 1;
		int quotient = 0;
		while (remain > divisor)
		{
			remain -= divisor;
			quotient++;
		}
		return quotient;
		//while (remain >= divisor || remain < 0 )
		//{
		//	remain = dividend - quotient * divisor;
		//	if remain >= divisor
		//		quotient /= 2;
		//	if remain < 0

		//}

	}
}


/*Given an array of integers data sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
std::vector<int> searchRange(std::vector<int>& data, int target)
{
	std::vector<int> res(2, 2);
	int down = 0;
	int up = data.size();
	while (up > down)
	{
		int mid = (up - down) / 2;
		if (data[mid] > target)
			down = mid;
		else if (data[mid] )
	}
}*/

//// **** Design Pattern
// Composite
// Issue: I have 2 functions implemented Log (that enables the print of some messages on a file LogFile or the screen LogScreen)
// I would like to print both on screen and on the logFile

void LoggerFile::logFile(const std::string& txt)
{
	{
		std::ofstream myfile(m_name);
		// open/close in the constructor myfile.open("example.txt");
		myfile << txt;
	}
}

void LoggerFile::log(const std::string& txt)
{
	this->logFile(txt);
}

LoggerFile::LoggerFile(const std::string& name)
	:m_name(name)
{
	std::ofstream myfile;
	myfile.open(m_name);
}

LoggerFile::LoggerFile()
	:m_name("Log.txt")
{
	std::ofstream myfile;
	myfile.open(m_name);
}

LoggerFile::~LoggerFile()
{
	std::ofstream myfile(m_name);
	if (myfile.is_open())
		myfile.close();
}

/////////
void LoggerScreen::logScreen(const std::string& txt)
{
	std::cout << txt;
}

void LoggerScreen::log(const std::string& txt)
{
	this->logScreen(txt);
}

void LoggerComposite::log(const std::string& txt)
{
	for (ILogger* logo : m_logger)
	{
		logo->log(txt);
	}
}

bool
isSubset(const std::vector<int>& nums, const int& target)
{
	if (nums.size() == 1)
	{
		//targetAndOperation[std::to_string(nums.size()) + "-" + std::to_string(target)] = (nums[0] == target);
		return (nums[0] == target);
	}
	else
		if (*(nums.end() - 1) == target)
		{
			//targetAndOperation[std::to_string(nums.size()) + "-" + std::to_string(target)] = true;
			return true;
		}
		else
		{
			std::vector<int> newNums(nums.begin(), nums.end() - 1);
			auto b1 = isSubset(newNums, target - nums[nums.size() - 1]);
			auto b2 = isSubset(newNums, target);
			return (b1 || b2);
		}
}
bool
findSubsetAddsUp(const std::vector<int>& nums, const int& target)
{
	// find subset of number that adds up to target
	return isSubset(nums, target);
}

//bool
//isSubsetMem(const std::vector<int>& nums, const int& target, std::map<string, bool>& targetAndOperation)
//{
//	if (targetAndOperation.find(std::to_string(nums.size()) + "-" + std::to_string(target)) != targetAndOperation.end())
//		return targetAndOperation[std::to_string(nums.size()) + "-" + std::to_string(target)];
//
//	if (nums.size() == 1)
//	{
//		std::string sizePlusTarget = std::to_string(nums.size()) + "-" + std::to_string(target);
//		targetAndOperation[sizePlusTarget] = (nums[0] == target);
//		return (nums[0] == target);
//	}
//	else
//		if (*(nums.end() - 1) == target)
//		{
//			targetAndOperation[std::to_string(nums.size()) + "-" + std::to_string(target)] = true;
//			return true;
//		}
//		else
//		{
//			std::vector<int> newNums(nums.begin(), nums.end() - 1);
//			if (!(targetAndOperation.find(std::to_string(nums.size()) + "-" + std::to_string(target)) != targetAndOperation.end()))
//			{
//				bool b1 = isSubsetMem(newNums, target - nums[nums.size() - 1], targetAndOperation);
//				targetAndOperation[std::to_string(newNums.size()) + "-" + std::to_string(target - nums[nums.size() - 1])] = b1;
//			}
//			if (!(targetAndOperation.find(std::to_string(nums.size()) + "-" + std::to_string(target)) != targetAndOperation.end()))
//			{
//				bool b2 = isSubsetMem(newNums, target, targetAndOperation);
//				targetAndOperation[std::to_string(newNums.size()) + "-" + std::to_string(target)] = b2;
//			}
//			return (targetAndOperation[std::to_string(newNums.size()) + "-" + std::to_string(target - nums[nums.size() - 1])]
//				|| targetAndOperation[std::to_string(newNums.size()) + "-" + std::to_string(target)]);
//		}
//}
bool
isSubsetMem(const std::vector<int>& nums, const int& target, std::map<string, bool>& targetAndOperation)//, std::string& Operation)
{
	if (targetAndOperation.find(std::to_string(target)) != targetAndOperation.end())
		return targetAndOperation[std::to_string(target)];

	if (nums.size() == 1)
	{
		std::string sizePlusTarget = std::to_string(target);
		targetAndOperation[sizePlusTarget] = (nums[0] == target);
		return (nums[0] == target);
	}
	else
		if (*(nums.end() - 1) == target)
		{
			targetAndOperation[std::to_string(target)] = true;
			return true;
		}
		else
		{
			std::vector<int> newNums(nums.begin(), nums.end() - 1);
			if (!(targetAndOperation.find(std::to_string(target)) != targetAndOperation.end()))
			{
				bool b1 = isSubsetMem(newNums, target - nums[nums.size() - 1], targetAndOperation);
				targetAndOperation[std::to_string(target - nums[nums.size() - 1])] = b1;
			}
			if (!(targetAndOperation.find(std::to_string(target)) != targetAndOperation.end()))
			{
				bool b2 = isSubsetMem(newNums, target, targetAndOperation);
				targetAndOperation[std::to_string(target)] = b2;
			}
			return (targetAndOperation[std::to_string(target - nums[nums.size() - 1])]
				|| targetAndOperation[std::to_string(target)]);
		}
}



bool
findSubsetAddsUpMem(const std::vector<int>& nums, const int& target)
{
	// find subset of number that adds up to target
	std::map<string, bool> resultMem;
	return isSubsetMem(nums, target, resultMem);
}
