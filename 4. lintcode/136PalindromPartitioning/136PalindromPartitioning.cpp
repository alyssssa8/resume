//https://leetcode.com/problems/palindrome-partitioning/description/
//https://www.jiuzhang.com/solution/palindrome-partitioning/
//https://www.lintcode.com/en/problem/palindrome-partitioning/
//
//
//136. Palindrome Partitioning
//
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//Have you met this question in a real interview ?
//Example
//Given s = "aab", return :
//
//    [
//        ["aa", "b"],
//        ["a", "a", "b"]
//    ]




#include <iostream>
#include <math.h>
#include <algorithm> 
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
using namespace std;


vector<vector<string>>v;
vector<string>v1;
vector<vector<string>> partition(string s);

bool ishui(string s);
void dfs(int depth, string s);


class Solution {
private:
	vector<vector<string>>ans;
	vector<string>tempString;
public:
	vector<vector<string>> partition(string s) {
		if (s.size() == 0)
		{
			return ans;
		}
		dfs(0, s);
		return ans;	

	}

	void dfs(int i, string s)
	{
		if (i == s.size())
		{
			ans.push_back(tempString);
		}

		if (i < s.size())
		{
			for (int j = i; j < s.size(); j++)
			{
				if (isHui(s.substr(i, j - i + 1)))
				{
					tempString.push_back(s.substr(i, j - i + 1));
					dfs(j + 1, s);
					tempString.pop_back();
				}
			}
		}
	}

	bool isHui(string s)
	{
		int i = 0;
		int j = s.size() - 1;
		while (i < j)
		{
			if (s[i] == s[j])
			{
				i++; j--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};


int main()
{

    string s = "aab";
    partition(s);
	Solution question;
	question.partition(s);

    return 0;
}


vector<vector<string>> partition(string s) {
    // write your code here
    v.clear();
    if (s.size() == 0)return v;
    v1.clear();
    //called dfs
    dfs(0, s);
    return v;
}


void dfs(int depth, string s) { // depth start at 0 and increase 1 each time.

    if (depth == s.size())
    {
		vector<string>::iterator iter;
		cout << endl;
		cout << "v1: " << endl;
		for (iter = v1.begin(); iter != v1.end(); iter++) {

			cout << *iter << ",  ";
		}
		cout << endl<<endl;


        v.push_back(v1);
		
    }
	cout << "depth:" << depth << endl;


    if (depth<s.size())
    {
        for (int i = depth; i<s.size(); i++)
        {
            //to check if the substring is a parlindrome
			cout << "i: " << i << "   depth: " << depth << "   i - depth + 1: "<< i - depth + 1 << endl;
			cout << "check if it is hui: " << s.substr(depth, i - depth + 1) << endl;
			//substr(1,2)  //1: from here, 2:count the number of letters
			vector<string>::iterator iter;
			cout << endl;
			cout << "v1: " << endl;
			for (iter = v1.begin(); iter != v1.end(); iter++) {

				cout << *iter << ",  ";
			}
			cout << endl << endl;



            if (ishui(s.substr(depth, i - depth + 1)))
            {

                v1.push_back(s.substr(depth, i - depth + 1));  //+1 is the first index char
                
                dfs(i + 1, s);
				string popValue = v1.back();
                cout<<"v1.pop_back():" <<popValue <<endl;
				v1.pop_back();
            }
        }
    }
}


bool ishui(string s) 
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++; j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}