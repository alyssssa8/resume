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
#include<unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<std::string> ans;
       
        for (int i = 0;i < emails.size(); i++ ){
            string temp;
            for (int j = 0; j <emails[i].size(); j++){
                if (emails[i][j] == '+'){        
                    while(emails[i][j] !='@'){
                        j++;
                    }  
                    while(j <emails[i].size()){
                        temp+=emails[i][j];
                        j++;
                    }
                }
                
                else if(emails[i][j] == '@')
                    while(j <emails[i].size()){
                        temp+=emails[i][j];
                        j++;
                    }
                else if (emails[i][j] != '.'){
                    temp+=emails[i][j];
                }
            }
            cout<<temp<<endl;
            ans.insert(temp);
        }
        return ans.size();
        
    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<std::string> trimmed_emails;
        for (auto& email : emails) {
            std::string tmp;
            // Copy everything that is not a '.' until a '+' or a '@' is encountered			
            auto it = email.begin();

            for (; '@' != *it && '+' != *it; ++it) {
                if ('.' != *it) {
                    tmp += *it;
                }
            }


            //vector's function: find and back_inserter 
            // Copy the domain into our tempary email

            it = find(it, email.end(), '@');
            copy(it, email.end(), back_inserter(tmp));

            // Add the trimmed email to our set of emails
            trimmed_emails.insert(tmp);
        }
        return trimmed_emails.size();
    }

};



int main()
{

    vector<string>nums({ "lll","hhh" });
    Solution question;
    question.numUniqueEmails(nums);
    //Solution2 question2;
    //question2.numUniqueEmails(nums);

    return 0;
}
