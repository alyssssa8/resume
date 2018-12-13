#include <iostream>

#include <string>
#include <string.h>

#include <math.h>
#include <time.h>

#include <fstream>

#include <map>   //hash table
#include <queue>
#include <stack>
#include <list>
#include "windows.h"
#include <vector>
using namespace std;

//const int SIZE = 64;

class Student
{
private: 
    float mGpa;
public:
    Student(float gpa):mGpa(gpa)
    {
    }
    float getGpa()
    {
        return mGpa;
    }
   
  operator float() { return mGpa; }
};
class Teacher
{
private:
    float mGpa;

public:

    float getGpa()
    {
        return mGpa;
    }

};

int main()
{
    Student student(4.0f);
    cout << student.getGpa()<<endl;
    cout << (float)student <<endl;
    Teacher teacher;
    cout << teacher.getGpa() << endl;


    return 0;
}
