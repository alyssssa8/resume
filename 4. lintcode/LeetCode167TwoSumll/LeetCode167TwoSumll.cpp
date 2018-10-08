//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
//
//Note :
//
//	Your returned answers(both index1 and index2) are not zero - based.
//	You may assume that each input would have exactly one solution and you may not use the same element twice.
//	Example :
//
//	Input : numbers = [2, 7, 11, 15], target = 9
//	Output : [1, 2]
//	Explanation : The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.



#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include<unordered_map>
#include <vector>
using namespace std;
//beats 99.84%
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		map<int, int> myMap;
		vector<int>ans;
		for (int i = 0; i<numbers.size(); i++) {


			if (myMap.find(target - numbers[i]) != myMap.end()) {
				ans.push_back(myMap[target - numbers[i]]);
				ans.push_back(i + 1);
				return ans;
			}
			myMap[numbers[i]] = i + 1;
		}
	}
};

class Test2 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int low = 0;
		int high = numbers.size() - 1;
		vector<int>ans;
		while (low < high)
		{
			int start = low;
			int end = high;
			if (numbers[low] + numbers[high] > target)
			{
				while (start <= end)
				{
					int mid = start + (end - start) / 2;
					if (numbers[mid] + numbers[low] > target)
					{
						end = mid - 1;
					}
					else if (numbers[mid] + numbers[low] < target)
					{
						start = mid + 1;
					}
					else
					{
						ans.push_back(low + 1);
						ans.push_back(mid + 1);
						return ans;
					}
				}
				if (numbers[low] + numbers[end] > target)
				{
					end--;
				}
				high = end;
			}

			else if (numbers[low] + numbers[high] < target)
			{
				while (start <= end)
				{
					int mid = start + (end - start) / 2;
					if (numbers[mid] + numbers[high] > target)
					{
						end = mid - 1;
					}
					else if (numbers[mid] + numbers[high] < target)
					{
						start = mid + 1;
					}
					else
					{
						ans.push_back(mid + 1);
						ans.push_back(high + 1);
						return ans;
					}
				}
				if (numbers[start] + numbers[high] < target)
				{
					start++;
				}
				low = start;
			}
			else
			{
				ans.push_back(low + 1);
				ans.push_back(high + 1);
				return ans;
			}
		}

	}
};



class Test {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {


		//high：寻找比target小，但是其右边比target大的坐标
		//low：寻找比target大，但是左边比target小的坐标

		int low = 0;
		int high = numbers.size() - 1;
		vector<int> ans;
		while (low < high) 
		{
			cout << "1: low: " << low << "  high: " << high << endl;
			if ((numbers[low] + numbers[high]) > target) {
				int start = low;
				int end = high;
				cout << "start: " << start << "  end: " << end << endl;
				while (start <= end)
				{
					
					int mid = (start + end) / 2;
					cout<< " mid:" << mid << endl;

					if ((numbers[low] + numbers[mid]) > target)
					{
						end = mid - 1;
					}
					else if ((numbers[low] + numbers[mid]) < target)
					{
						start = mid + 1;
					}
					else
					{	
						ans.push_back(low + 1);
						ans.push_back(mid + 1);
						return ans;
					}
					
				}
				if ((numbers[low] + numbers[end]) > target) end--;
				high = end;
			}

			else if ((numbers[low] + numbers[high]) < target) {
				int start = low;
				int end = high;
				cout << "2: start: " << start << "  end: " << end << endl;
				while (start <= end) {
					cout << "3: start: " << start << "  end: " << end << endl;
					int mid = (start + end) / 2;//(0+8)/2=4 start = 0, end = 3
					 cout<< " mid:" << mid << endl;
					
					if ((numbers[high] + numbers[mid]) > target) {
						end = mid - 1;
					}
					else if ((numbers[high] + numbers[mid]) < target) 
					{
						start = mid + 1;
					}
					else 
					{
						ans.push_back(mid + 1);
						ans.push_back(high + 1);
						return ans;
					}
				}
				if ((numbers[end] + numbers[high]) < target) end++;
				low = end;
			}

			else {
				break;
			}
		}
		ans.push_back(low + 1);
		ans.push_back(high + 1);
		return ans;
	}
};

//beat 99.84
class Solution2 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int start = 0, end = numbers.size() - 1;
		vector<int> ans;
		while (start < end) {
			if (numbers[start] + numbers[end] > target)
				end--;
			else if (numbers[start] + numbers[end] < target)
				start++;
			else {
				ans.push_back(start + 1);
				ans.push_back(end + 1);
				return ans;
			}
		}
	}
};
//too slow.beat 6%
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		vector<int> myVector;
		for (int i = 1; i <numbers.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (numbers[i] + numbers[j] == target)
				{
					myVector.push_back(j + 1);
					myVector.push_back(i + 1);
					return myVector;
				}
			}
		}

	}
};


int main()
{
	//vector<int>numbers{ 0,1,2,3,4,5,6,7,8,9};
	//vector<int>numbers{ 2,7,11,14,15 };
	vector<int>numbers{ 2,3,6,10,11,12,13 };

	int target = 8;


	/*Solution question;
	question.twoSum(numbers, target);*/
	Test question2;
	vector<int> result;
	result = question2.twoSum(numbers, target);
	Test2 question3;
	 question3.twoSum(numbers, target);
	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++)
	{
		cout << *iter << "  ";
	}
	cout << endl;

	return 0;
}