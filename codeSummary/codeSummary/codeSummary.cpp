
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
#include <set>
#include<unordered_set>
#include <iomanip>      // std::setprecision
#include <fstream>      // std::ofstream
#define mySize 5
using namespace std;


//const int mySize = 5;
//beats 100%
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> seen;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            seen.insert(make_pair(nums1[i], false));
        }
        for (int j = 0; j < nums2.size(); j++) {
            auto itr = seen.find(nums2[j]);
            if (itr != seen.end()) {
                if (!itr->second) {  //false
                    res.push_back(nums2[j]);
                    itr->second = true;
                }
            }
        }
        return res;
    }
};

class Test {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>mySet1;
        set<int>mySet2;

        for (int i = 0; i < nums1.size(); i++)
        {
            mySet1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (mySet1.find(nums2[i]) != mySet1.end())
            {
                mySet2.insert(nums2[i]);
            }
        }
        vector<int>result(mySet2.begin(), mySet2.end()); //copy value
        return result;
    }
};
class Solution {
    unordered_set<int> V;
    vector<int> path;
    vector<vector<int>> ans;


    void go(const vector<int>& A) {
        int M = (int)path.size(), N = (int)A.size();
        if (M == N) {
            ans.push_back(path);
            cout << endl;
            cout << "---------------------" << endl;
            return;
        }
        // V = [0]
        for (int i = 0; i < N; ++i) {

            if (V.insert(i).second == true) { //if insert success, return true.


                cout << A[i] << " , ";
                path.push_back(A[i]);  // V = [ 0, 2 ]
                go(A); // 

                V.erase(i); // V = [ 0 ]

                //Removes from the set container either a single element or a range of elements([first, last)).
                //This effectively reduces the container size by the number of elements removed, which are destroyed.


                path.pop_back();
            }
            else {

            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& A) {
        ans.clear();
        go(A);
        return ans;
    }
};



/*//class

class Animal {
        Attributes: height weight variables
        capabilities: run eat functions/ methods
        };

        static: this varible of value is shared by every object of type animal
void demo()
    {
        // static variable
        static int count = 0;
        cout << count << " ";

        // value is updated and
        // will be carried to next
        // function calls
        count++;
    }


    Static functions in a class: Just like the static data members or static variables inside the class, 
    static member functions also does not depend on object of class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator.
    Static member functions are allowed to access only the static data members or other static member functions, 
    they can not access the non-static data members or member functions of the class.
int main()
    {
        for (int i=0; i<5; i++)
            demo();
        return 0;
    }



*/



/*

Static Variables : Variables in a function, Variables in a class
Static Members of Class : Class objects and Functions in a class
Static variables in a class: As the variables declared as static are initialized only once as they are allocated space in separate static storage so, 
the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. 
Also because of this reason static variables can not be initialized using constructors.

*/

//virtual
class p
{
     int a;   
     virtual int Out() = 0;  // *********the way to do the definition.
};

class son : public p
{
    virtual int out()
    {
        cout << "a" << endl;
    }
};



//__________________________
class Polygon2
{
protected:
    int width, height;
public:
    void set_values(int a, int b)
    {
        width = a; height = b;
    }
    virtual int area() = 0;
    void printarea()
    {
        cout << this->area() << '\n';
    }
};

class Rectangle2 : public Polygon2
{
public:
    int area(void)
    {
        return (width * height);
    }
};

class Triangle2 : public Polygon2
{
public:
    int area(void)
    {
        return (width * height / 2);
    }
};


//________________________
class Polygon
{
protected:
    int width, height;
public:
    Polygon(int a, int b) : width(a), height(b) {}
    virtual int area(void) = 0;
    void printarea()
    {
        cout << this->area() << '\n';
    }
};

class Rectangle : public Polygon
{
public:
    Rectangle(int a, int b) : Polygon(a, b) {}
    int area()
    {
        return width * height;
    }
};

class Triangle : public Polygon
{
public:
    Triangle(int a, int b) : Polygon(a, b) {}
    int area()
    {
        return width * height / 2;
    }
};




class A {
public:
    A() { std::cout << "called A" << std::endl; }
};

class B : public A {
public:
    B() { std::cout << "called B" << std::endl; }
};






//__________________________________________________________

int main()
{/*
    // vector
    //Vectors are sequence containers representing arrays that can change in size.
    // It is a dynamically allocated array of elements.

    Just like arrays, vectors use <contiguous storage locations > for their elements, 
    which means that their elements can also be accessed using <offsets> on regular pointers to its elements, 
    and just as efficiently as in arrays. But unlike arrays, their <size can change dynamically>, with their 
    storage being handled automatically by the container.


    */


 
    
        B l;  // what will happen?
    

    string dogString = "dog";
    string catString = "cat";


//    Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
//    Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.
    cout << dogString.compare(catString) << endl;//1 : catString> more than dogString
    cout << catString.compare(dogString) << endl;//-1: more than
    cout << dogString.compare(dogString) << endl;  // 0 : equal


    string a = "ddddd";  // can not use for int
    //cin >> a;
    //getline(cin,a);

    //cout << "dddd:"<<stoi(a) << endl;  
    
    cout << a.append("was your gusee") << endl;//123456was you guess
    int lastNameIndex = a.find("2", 0); // search at the 0 index.  return index. 
    cout << lastNameIndex << endl;
    cout << a.insert(5, "justin") << endl;
    //123456was your gusee
    //12345justin6was your gusee

    cout << a.erase(6, 7)<<endl;  // at index 6, for 7 members
    cout << a.replace(6, 5, "Maximus");



    
    
    //stod: Parses str interpreting its content as a floating-point number, which is returned as a value of type double.
   //stoi: Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.

    /*
        bool, char, unsigned char, signed char,             __int8	                             1 byte
        short, unsigned short,                              __int16,  wchar_t, __wchar_t	     2 bytes
        float, int, unsigned int, long, unsigned long       __int32, 	                         4 bytes
        double, long double, long long	                    __int64,                             8 bytes


        
down vote
accepted
Huge difference.

As the name implies, a double has 2x the precision of float[1].
In general a double has <15 decimal digits> of precision, while float <has 7>.
     */

    int b = 3.1415926516;  //3
    float c = 3.1415926516;  //3.14159
    double d = 3.1415926516;  //3.14159
    long e = 3.1415926516;//3
    short f = 3.1415926516;  //3
    //cout << fixed<<setprecision(4)<<c << endl;
    string wholeName = "dkjfkd dkfjdk";
    cout << wholeName.assign(wholeName, 0, 5);


    cout << endl;

    //int b = 1;
    //float c = 1;
    //double d = 1;
    //long e = 1;
    //short f = 1;
    cout << "int:" <<b<< endl;  
    cout << "float:" <<c<< endl; 
    cout << "double:" <<d<< endl;
    cout << "long:" << e<<endl; 
    cout << "short:" << f<<endl;  
    cout << endl;
    cout << (double)10 / 3 << endl; //3.33333
    cout << (float)10 / 3 << endl;//3.33333
    cout << endl;
    cout << "___________:" << endl;
    cout << "sizeof: " << sizeof(d)<<endl;
    cout << &d << endl;
    cout << endl;

    int myAge = 39;
    int* agePtr = &myAge;
    cout << "address of pointer" << agePtr << endl;
    cout << "Data at memory address" << *agePtr << endl;
    int badNums[5] = { 1,13,14,24,34 };

    int & ageRef = myAge;
    int ageRef2 = myAge;
    cout << &myAge << endl;
    cout << ++ageRef << endl;  //40   age changed to 40
    cout << ++ageRef2 << endl;  //41
    int *numArrayPtr = badNums;
    cout << "Address: " << numArrayPtr << " value: " << *numArrayPtr << endl;



    for (int i = 0; i < 5; i++) {

        cout << i << endl;

    }
    cout << endl;
    for (int i = 0; i < 5; ++i) {

        cout << i << endl;

    }
    cout << endl;
    int i = 5;
    cout << i++ << endl << endl;;
    int k = 0;
    cout << ++k << endl;

    //pointer reference
    //__________________________________________________________________________

/*
A pointer can be re-assigned while reference cannot, and must be assigned at initialization only.
Pointer can be assigned NULL directly, whereas reference cannot.
Pointers can iterate over an array, we can use ++ to go to the next item that a pointer is pointing to.
A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
A pointer to a class/struct uses ‘->'(arrow operator) to access it’s members whereas a reference uses a ‘.'(dot operator)
A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.
    References are usually preferred over pointers whenever we don’t need “reseating”.

        Overall, Use references when you can, and pointers when you have to.But if we want to write C code that compiles with both C 
        and a C++ compiler, you’ll have to restrict yourself to using pointers.
*/


//__________________________________________________________________________

    vector<int>nums1{ 1,2,2,1 };
    vector<int>nums2{ 2,2,1 };
    

    vector<int> candidates({ 1,2,3 });
    Solution test;
    test.permute(candidates);

 
   

  
    vector<int>myVector0; // default size = 0, no value.

    vector<int> myVector1(10, 1);  //{1,1,1,1,1,1,1,1,1,1}

    vector<int> myVector2(5);  // {0,0,0,0,0}

    vector<int> myVector3({ 1,2,3 });//{1,2,3}

    vector<vector<int>> myVector4({ {1,2,3}, {4,5,6} });


    //myVector4[0]: {1,2,3}
    //myVector4[1]:{4,5,6}

    myVector4.clear();  // size = 0 
    myVector3.push_back(4);
    myVector3.pop_back();
    myVector3.back();
    myVector3.end();
    myVector3.begin();
    myVector3.size();
    myVector3.insert(myVector3.begin() + 1, 6);
    vector<int>::iterator pos;
    pos = myVector3.begin() + 1;
    myVector3.erase(pos); //delete the value in pos

    vector<int> myVector5[10];
    //myVector5[0]
    //myVector5[1]
    //myVector5[2]
    //.....
    //myVector5[9]
    myVector5[0].push_back(5);

    vector<int> *myVector6 = new vector<int>[10];

    myVector6[0].push_back(0);
    myVector6[8].push_back(8);


    vector<int>result(myVector3.begin(), myVector3.end());  //copy value
    vector<int>lotteryNumVect(10);
    int  lotterNumArray[5] = { 4,13,14,24,34 };
    lotteryNumVect.insert(lotteryNumVect.begin(),lotterNumArray, lotterNumArray + 3);// 4 13 14 0 0 0 0 0 0 
    lotteryNumVect.insert(lotteryNumVect.begin() + 5, 44); //4 13 14 0 0 44 0 0 0 
    cout << lotteryNumVect.at(2);
    cout << lotteryNumVect.back() << endl;
    cout << lotteryNumVect.front() << endl;
    cout << lotteryNumVect.empty() << endl;
    cout << lotteryNumVect.size() << endl;
    lotteryNumVect.pop_back();

 //___________________________________________________

    string steveQuote = "dkjfkdsljf kdjfsld kdjfl sdf";
    ofstream writer("steveqeote.txt");
    if (!writer) {
        cout << "dkfjsl" << endl;
        return -1;
    }
    else {
        writer << steveQuote << endl;
        writer.close();
    }
    ofstream writer2("steveqeote.txt", ios::app);

    //open a stream to append to whats there with ios::app
    //ios::binary: treat the file as binary
    //ios::in: open a file to read input
    //ios::trunk: default
    //ios::out:Open a file to write output


    if (!writer2) {
        cout << "dkfj" << endl;
        return -1;
    }
    else {
        writer2 << "\n -Steve Martin" << endl;
        writer2.close();
    }
    
    char letter;
    ifstream reader("steveqeote.txt");

    if (!reader) {
            cout << "dkfj" << endl;
            return -1;
        }else{
        for (int i = 0; !reader.eof(); i++) {
            reader.get(letter);
            cout << letter;      
        }
        cout << endl;
        reader.close();
    }

//___________________________________________________
    int number = 0;
    try {
        if (number != 0) {
            cout << 2 / number << endl;
        }else throw(number); // look for a catch

    }
    catch (int number) {
        cout << number << " is not valid" << endl;
    }

//___________________________________________________
//___________________________________________________
//___________________________________________________
// iterator

    vector<int>::iterator iter;
    for (iter = myVector3.begin(); iter != myVector3.end(); iter++) {
        cout << *iter << endl;
    }



//___________________________________________________
// map

    unordered_map<int, int>myMap;
    myMap[3] = 6;
    myMap[2] = 8;
    //myMap[2]: 8
    //myMap[3]: 6

    //for (auto x : myMap)
    for (pair<int const, int> x : myMap)
        cout << x.first << x.second;

    for (auto p : myMap) {
        cout << "000" << p.first << endl;;
        cout << p.second << endl;;
    }
    
    map<char, int> first;

    first['a'] = 10;
    first['b'] = 30;
    first['c'] = 50;
    first['d'] = 70;
  
    map<char, int> second(first.begin(), first.end());
    map<char, int> third(second);



    std::map<char, int> mymap;
    std::map<char, int>::iterator it;

    // insert some values:
    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    mymap['d'] = 40;
    mymap['e'] = 50;
    mymap['f'] = 60;

    it = mymap.find('b');
    mymap.erase(it);                   // erasing by iterator

    mymap.erase('c');                  // erasing by key

    it = mymap.find('e');
    mymap.erase(it, mymap.end());    // erasing by range

    // show content:
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    

  


    //.at


    //.begin
    //.clear
    //.count
    //.empty
    //.end
    //.erase
    //.find
    //.insert
    //.size
    //.swap

/*
                     | map |          unordered_map
        -------------------------------------------------------- -
        Ordering       | increasing  order     | no ordering
                       | (by default)          |

        Implementation | Self balancing BST    | Hash Table
                       | <like Red - Black Tree> |

        search time    | log(n)                | O(1)->Average
                                               | O(n)->Worst Case

        Insertion time | log(n) + Rebalance    | Same as search

        Deletion time  | log(n) + Rebalance    | Same as search
        
        
   STL Map Internal Implementation :
    It’s implemented as a self - balancing red - black tree.Probably the two most common self balancing trees are 
    red - black tree and AVL trees.To balance the tree after an insertion / update both algorithms use the notion 
    of rotations where the nodes of the tree are rotated to perform the re - balancing. While in both algorithms 
    the insert / delete operations are O(log n), in the case of Red - Black tree re - balancing rotation is an O(1) 
    operation while with AVL this is a O(log n) operation, making the RB tree more efficient in this aspect of the re 
    - balancing sage and one of the possible reasons that is more commonly used.
    //___________________________________________________

   Differences between hash table and STL map
    Null Keys : STL Map allows one null key and multiple null values whereas hash table doesn’t allow any null key or value.
    Thread synchronization : Map is generally preferred over hash table if thread synchronization is not needed.Hash table is synchronized.
    Thread safe : STL Maps are not thread safe whereas Hashmaps are thread safe and can be shared with many threads.
    Value Order : In STL map, values are stored in sorted order whereas in hash table values are not stored in sorted order
    Searching Time : You can use STL Map or binary tree for smaller data(Although it takes O(log n) time, the number of inputs may be small enough 
    to make this time negligible) and for large amount of data, hash table is preferred.
    
  */


//___________________________________________________
// set
   /* Set
        Sets are containers that store <unique elements> following a <specific order>.

        In a set, the value of an element also identifies it(the value is itself the key, of type T), and each value must be unique.
        The value of the elements in a set cannot be modified once in the container(the elements are always const), 
        but they can be inserted or removed from the container.

        Internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by 
        its internal comparison object(of type Compare).

        set containers are generally <slower than unordered_set containers> to access <individual elements> by their key, 
        but they allow the direct iteration on subsets based on their order.

        Sets are typically implemented as <binary search trees>.*/

   std::set<int> myset2;
    std::set<int>::iterator it2;

    // insert some values:
    for (int i = 1; i < 10; i++) {
        myset2.insert(i * 10);  // 10 20 30 40 50 60 70 80 90
    }
    
    it2 = myset2.begin();
    ++it2;                                         // "it" points now to 20

    myset2.erase(it2);

    myset2.erase(40);

    it2 = myset2.find(60);
    myset2.erase(it2, myset2.end());

    std::cout << "myset contains:";
    for (it2 = myset2.begin(); it2 != myset2.end(); ++it2)
        std::cout << ' ' << *it2;
    std::cout << '\n';

    //.begin
    //.clear
    //.count
    //.empty
    //.end
    //.erase
    //.find
    //.insert
    //.size
    //.swap
   
   

//___________________________________________________
// deque
    //.back
    //.begin
    //.end
    //.front
    //.pop_back
    //.pop_front
    //.clear
    //.empty
    //.erase
    //.insert 
    //.size
    //.swap



//___________________________________________________
// queue
   /* FIFO queue
        queues are a type of container adaptor, specifically designed to operate in a FIFO context(first - in first - out), 
        where elements are inserted into one end of the container and extracted from the other.

        queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class
        as its underlying container, providing a specific set of member functions to access its elements.Elements are <pushed into the 
        "back" >of the specific container and <popped from its "front">.

        The underlying container may be one of the standard container class template or some other specifically 
        designed container class.This underlying container shall support at least the following operations :
   
   //.push_back
    //.front
    //.pop_front
    //.back
    
    //.empty
    //.size


    Double ended queue
deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are sequence containers 
with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

Specific libraries may implement deques in different ways, generally as some form of dynamic array. But in any case, they allow for the individual elements to be accessed directly through random access iterators, with storage handled automatically by expanding and contracting the container as needed.
    */
//___________________________________________________
// stack

    //LIFO stack
     //Stacks are a type of container adaptor, specifically designed to operate in a 
    //LIFO context(last - in first - out), where elements are inserted and extracted only 
    //from one end of the container.
    /*
    stacks are implemented as containers adaptors, which are classes that use an encapsulated 
    object of a specific container class as its underlying container, providing a specific set 
    of member functions to access its elements. Elements are pushed/popped from the "back" of 
    the specific container, which is known as the top of the stack.

    */
    //.pop
    //.top
    //.push

     //.empty
    //.size
    //.swap

    //back
    //push_back
    //pop_back
//___________________________________________________
// hash table
   /* Values are <not stored in sorted order>
    Additionally, since hash tables <use the key to find the index that will store the value>, 
    an insert or lookup can be done in amortised O(1) time(assuming few collisions in the hash table).
    In a hash table, one must also handle <potential collisions>.This is often done <by chaining>, 
    which means to create a linked list of all the values whose keys map to a particular index.

    //Implementation of Hash Table : A hash table is traditionally <implemented with an array of linked lists>.
    //When we want to insert a key / Value pair, we map the <key to an index> in the array using the hash function.
    //The <value> is then inserted into the <linked list at that position>.
    

    //___________________________________________________

                    
                         | map |                 unordered_map
        -------------------------------------------------------- -
              Ordering | increasing  order     |  no ordering
                       | (by default)          |

        Implementation | Self balancing BST    | Hash Table
                       | like Red - Black Tree |

           search time |  log(n)               | O(1)->Average
                                               | O(n)->Worst Case

        Insertion time | log(n) + Rebalance    | Same as search

         Deletion time | log(n) + Rebalance    | Same as search
         

   STL Map Internal Implementation :
    It’s implemented as a self - balancing red - black tree.Probably the two most common self balancing trees are 
    red - black tree and AVL trees.To balance the tree after an insertion / update both algorithms use the notion 
    of rotations where the nodes of the tree are rotated to perform the re - balancing. While in both algorithms 
    the insert / delete operations are O(log n), in the case of Red - Black tree re - balancing rotation is an O(1) 
    operation while with AVL this is a O(log n) operation, making the RB tree more efficient in this aspect of the re 
    - balancing sage and one of the possible reasons that is more commonly used.
    //___________________________________________________

   Differences between hash table and STL map
    Null Keys : STL Map allows one <null key> and <multiple null values >  whereas hash table <doesn’t allow any null key or value>.
    Thread synchronization : Map is generally <preferred >over hash table <if thread synchronization is not needed>.Hash table is <synchronized>.
    Thread safe : STL Maps are <not thread safe> whereas Hashmaps are <thread safe> and can be <shared with many threads>.
    Value Order : In STL map, values are stored in <sorted order> whereas in hash table values are <not stored in sorted order>
    Searching Time : You can use STL Map or binary tree for smaller data(Although it takes <O(log n) time>, the number of inputs may be small enough 
    to make this time negligible) and for <large amount of data, hash table is preferred.>
    

     
    //___________________________________________________
    //array
    An array is a series of elements of the <same type> placed in <contiguous memory locations> that can be individually referenced by adding an
    index to a <unique identifier>.That means that, for example, five values of type int can be declared as an array without having to declare 
    5 different variables(each with its own identifier). Instead, using an array, the five int values are stored in contiguous memory locations,
    and all five can be accessed using the <same identifier, with the proper index.>
    */
    //int mySize = 5;
    double* p1 = new double[mySize]{}; // initialise to all zeroes
    double* p2 = new double[5]{ 1.7, 0.4, 6.2, -9.3, 8.4 }; // initialise with braced-init-list
    unique_ptr< double[] > p3(new double[5]{ 1.7, 0.4, 6.2 });

   
    int myArray1[mySize];
    int myArray2[5];  // array[0]: -858993460
                   //array[1]: -858993460
                   //     
    // ...
    delete[] p1;
    delete[] p2; 

//___________________________________________________
//virtual
//Virtual members/virtual function/ virtual method
//A virtual member is a member function that can be redefined in a derived class,

//The member function area has been declared as virtual in the base class because it is later redefined 
//in each of the derived classes.Non - virtual members can also be redefined in derived classes, 
//non - virtual members of derived classes cannot be accessed through a reference of the base class 
//    : i.e., if virtual is removed from the declaration of area in the example above, 
//    all three calls to area would return zero, because in all cases, the version of the base class would 
//    have been called instead.


//if no virtual in the parent class, the A *b will use the A constructor. 
    class A
    {
    public:
        virtual void Print() {
            printf("Hello A\n");
        }
        // void Print()
         //{
            // printf( "Hello A\n" );
         //}
    };

    class B : public A
    {
    public:
        //virtual void Print()
        void Print()
        {
            printf("Hello B\n");
        }
    };

    class C : public A
    {

    };

    class D : public A
    {
    public:
        void Print()
        {
            printf("Hello D\n");
        }
    };

    int max(int &a, int &b);

   
        //A* a = new A();
        //A* b = new B();
        //A* c = new C();
        //A* d = new D();
        //B x;
        //x.Print(); //Hello B
        //D y;
        //y.Print();//Hello D
        //// two pointer to A, but print is different, if no virtual, print will be same

        //C* rb = static_cast<C*>(b);

        //int sa = 10;
        //// float sb = reinterpret_cast< float >( sa );

        //a->Print(); //without virtual: Hello A // if with Virtual, will be A
        //b->Print(); //without virtual: Hello A // if with Virtual, will be B
        //c->Print(); //without virtual: Hello A // if with Virtual, will be A
        //d->Print(); //without virtual: Hello A // if with Virtual, will be D

//Pure virtual: also called abstract class. Pure virtual cannot new object.
//Son must define a virtual function.
//Why use pure virtual ?
//<To be sure the subclass implements>
       


        Polygon * ppoly1 = new Rectangle(4, 5);
        Polygon * ppoly2 = new Triangle(4, 5);
        ppoly1->printarea();  //20
        ppoly2->printarea(); //10
        delete ppoly1;
        delete ppoly2;


//__________________________
        Rectangle2 rect2;
        Triangle2 trgl2;
        Polygon2 * ppoly3 = &rect2;  // pay attention of the point: son or parents. 
        Polygon2 * ppoly4 = &trgl2;
        ppoly3->set_values(4, 5);
        ppoly4->set_values(6, 7);
        ppoly3->printarea();  //20
        ppoly4->printarea(); //21

        //____________________________
        makeMeYoung(&myAge);
        cout << "i'am " << myAge << " years old now" << endl;
      \ 

    return 0;
}




void makeMeYoung(int *age) {
    cout << "I used to be " << *age << endl;
    *age = 21;
}
/*

1.	边刷题边找工作， 积累面试的经验
2.	Good connections are very important

面试的要求：
1.	看你聪明不聪明
2.	跟着面试官的提示走
3.	特别渴望这份工作
4.	对公司有一定的了解
5.	认真读题（读懂题意）
public:
privatt:
protected:

compiler怎么区分两个constructor

可以字节实例化interface吗？

Dynamic memory
In the programs seen in previous chapters, all memory needs were determined before program 
execution by defining the variables needed. But there may be cases where the memory needs of 
a program can only be determined during runtime. For example, when the memory needed depends 
on user input. On these cases, programs need to dynamically allocate memory, for which the C++ 
language integrates the operators new and delete.

int * foo;
foo = new int [5];

There is a substantial difference between declaring a normal array and allocating dynamic memory 
for a block of memory using new. The <most important difference> is that the size of a regular <array >
needs to be a <constant> expression, and thus its size has to be determined at the moment of designing 
the program, before it is run, whereas the <dynamic memory> allocation performed by new allows to assign 
memory during <runtime> using any variable value as size.



$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

*/
