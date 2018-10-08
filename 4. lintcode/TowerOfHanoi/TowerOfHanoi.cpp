
//http://www.jamalalsakran.me/DataStruct/Recursion.html
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


class Solution {
public:
	void MoveDisks(int count, int needle1, int needle3, int needle2)
	{
		if (count > 0)
		{
			MoveDisks(count - 1, needle1, needle2, needle3);

			cout << "Move disk " << count << " from " << needle1
				<< " to " << needle3 << "." << endl;

			MoveDisks(count - 1, needle2, needle3, needle1);
		}
	}

};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.MoveDisks(5, 3, 2, 4);


	return 0;
}
