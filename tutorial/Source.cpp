#include "Tutorial.h"
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <exception>
#include <type_traits>
#include <new>
#include <list>
#include <map>
#include <iterator>
#include <deque>
#include <set>
#include <numeric>
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MKSTR( x ) #x
using namespace std;
using namespace tutorial;

template <class T>
T sum(T a, T b) 
{
	return a+b;
}

throwexception::throwexception(void) 
{
	cout << "throw exception object constructed" << endl;
	//Constructor
}
throwexception::~throwexception(void) 
{
	//Destructor
	cout << "throw exception destructor called." << endl;
	throw 9;
}

#pragma region Microsoft
int rectangle::square()
{
	return length*width;
}
int rectangle::sum()
{
	return length + width;
}
int rectangle::get_area()
{
	return _width*_length;
}
//Constructors
Squawker::Squawker()
{
	cout << "Default Constructing " << endl;
}

Squawker::Squawker(string n) : name(n)
{
	cout << "Constructing " << name << endl;
}
Squawker::~Squawker()
{
	cout << "Destructing " << name << endl;
}
void Squawker::computer()
{
	cout << "Welcome!" << endl;
}
/*
Car::Car()
{
	Make = "Honda";
	Model = "Accord";
	Color = "Black";
}
Car::Car(string x, string y, string z)
{
	x = Make;
	y = Model;
	z = Color;
	string car = x + y + z;
	cout << "The entered car is" << endl;
}
Car::~Car()
{
	cout << "Destruction" << endl;
}
void Vehicle::welcome(string hi)
{
	cout << hi << endl;
}
void Car::welcome(string hi)
{
	cout << hi << endl;
}
*/
#pragma endregion
#pragma region polymorphism
void Ninja::attack()
{
	cout << "Ninja!" << endl;
}
void Monster::attack()
{
	cout << "Monster!" << endl;
}
#pragma endregion
void file()
{
	fstream MyFile;
	MyFile.open("bin.txt"); 
	MyFile << "Hello"<< endl;
	if (MyFile.is_open()) {
		MyFile << "This is awesome! \n";
	}
	else 
	{
		cout << "Something went wrong";
	}
	MyFile.close();
	MyFile.open("bin.txt");
	if (MyFile.is_open())
	{
		string line;
		while (!MyFile.eof())
		{
			getline(MyFile, line);
			cout << line << endl;
		}
	}
	MyFile.close();
}
void pointer()
{
	
	int x = 1;
	int *pointer_to_x = &x;
	cout << x << endl;
	int y = *pointer_to_x;
	y = 3;
	*pointer_to_x = 4;
	cout << *pointer_to_x << endl;
	int *p = &x;
	p = &y;
	*p = 0;
	int j = *p;
	p = nullptr;
	//Another program
	int  var;
	int  *ptr;
	int  **pptr;

	var = 3000;

	// take the address of var
	ptr = &var;

	// take the address of ptr using address of operator &
	pptr = &ptr;

	// take the value using pptr
	cout << "Value of var :" << var << endl;
	cout << "Value available at *ptr :" << *ptr << endl;
	cout << "Value available at **pptr :" << **pptr << endl;

	//j = *p; ERROR
	//now x==xref==3
	
}

void current_time()
{
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	cout << "The local date and time is: " << dt << endl;

	// convert now to tm struct for UTC
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "The UTC date and time is:" << dt << endl;
}
void preprocessor()
{
	cout <<"Minimum of 20 and 30 = "<< MIN(20, 30) << endl<< "Maximum of 20 and 30 = " << MAX(20, 30) << endl;
	cout << MKSTR(HELLO C++) << endl;
	cout << "Value of __LINE__ : " << __LINE__ << endl;
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	cout << "Value of __TIME__ : " << __TIME__ << endl;
}
void mem()
{
	try
	{
		int *p = new int{ 1 };
		*p = 2;
		throw exception{ "Trouble" };
		delete p;
	}
	catch (const exception& e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}
}
bool is_connected(bool *graph[], int size)
{
	int old_size, c_size = 0;
	bool *close = new bool[size];
	bool *open = new bool[size];
	for (int i = 0; i < size; i++)
	{
		open[i] = close[i] = false;
		open[0] = true;
	}
	while (c_size < size)
	{
		for (int i = 0; i < size; i++)
		{
			old_size = c_size;
			if (open[i] && (close[i] = false))
			{
				close[i] = true;
				c_size++;
				for (int j = 0; j < size; j++)
					open[j] = open[j] || graph[i][j];
			}

		}
		if (c_size == size)
			return true;
		if (old_size == c_size)
			return false;
	}
	return 0;
}
void memory()
{
	long long *pInt = new long long;
	double * pDouble = new double;
	*pInt = 3;
	*pDouble = 5.0;
	cout << "size of int = " << sizeof(pInt)<<endl;
	cout << "size of double = " << sizeof(pDouble)<<endl;
	delete pInt;
	delete pDouble;
}
void objects()
{
	Squawker x;
	Squawker b("Hello");
	b.computer();
	Squawker *squawker = new Squawker("hello");
	delete squawker;
	Squawker *squawkers = new Squawker();
	squawkers->computer();
	delete squawker;
}

void except()
{
	try
	{
		Squawker inner = "Inner";
		unique_ptr<Squawker> pS{ new Squawker{ "Heap" } };
		throw (exception{ "Trouble" });
	}
	catch (const exception& e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}
}
void exempt()
{
	try 
	{
		throwexception texc;
		cout << "Throwing exception will cause termination of program." << endl;
		throw 7;
	}
	catch (...) 
	{
		//Catch exception
		cout << "Main Exception caught" << endl;
	}
}
void ausnahme()
{
	try 
	{
		throw 20;
	}
	catch (int exc) 
	{ 
		cout << "int exception." << endl; 
	}
	catch (double exc) 
	{ 
		cout << "double exception." << endl; 
	}
	catch (...) 
	{ 
		cout << "All other exception types." << endl; 
	}
	try 
	{
		throw 20.0;
	}
	catch (int exc) 
	{ 
		cout << "int exception." << endl; 
	}
	catch (double exc) 
	{ 
		cout << "double exception." << endl; 
	}
	catch (...) 
	{ 
		cout << "All other exception types." << endl; 
	}
	try 
	{
		throw true;
	}
	catch (int exc) 
	{ 
		cout << "int exception." << endl; 
	}
	catch (double exc) 
	{ 
		cout << "double exception." << endl; 
	}
	catch (...) 
	{ 
		cout << "All other exception types." << endl; 
	}
	try 
	{
		try 
		{
			//Do something here that causes an exception
			throw 10;
		}
		catch (int numb) 
		{
			cout << "Caught int exception." << endl;
			throw;
		}
	}
	catch (...) 
	{
		cout << "An error occurred." << endl;
	}
}

//STL---------------------
void updateVector(std::vector<string>& firstvector_,vector<string>& secondvector_, string newString) 
{
	firstvector_.push_back(newString);
	try 
	{
		secondvector_.push_back(newString);
	}
	catch (...) 
	{
		firstvector_.pop_back();
		cout << "second vector update failed." << endl;
	}
}
void updateVector2(vector<string>& firstvector_, vector<string>& secondvector_,string newString) 
{
	firstvector_.push_back(newString);
	try 
	{
		bad_alloc excep;
		throw excep;
		secondvector_.push_back(newString);
	}
	catch (...) {
		firstvector_.pop_back();
		cout << "second vector update failed.\n" << endl;
	}
}

char const * tutorial::myexception::what() const
{
	return msg.c_str();
}

myexception::~myexception() throw()
{
	errorlist.clear();
}
void myexception::adderror(errorinfo info) throw(bad_alloc)
{
	try
	{
		errorlist.push_back(info);
	}
	catch (...)
	{
		//push_back has thrown an error. 
		cout << "Bad alloc in adderror function." << endl;
	}
}


vector<errorinfo>::iterator myexception::begin()
{
	return errorlist.begin();
}
vector<errorinfo>::iterator myexception::end()
{
	return errorlist.end();
}

void STL2()
{
	vector<string> firstvector;
	vector<string> secondvector;
	string mystring("Hello world!");

	cout << "Calling updateVector \n" << endl;

	updateVector(firstvector, secondvector, mystring);

	cout << "first vector size is " << firstvector.size() << endl;
	cout << "second vector size is " << secondvector.size() << endl;
	cout << "Calling updateVector2 \n" << endl;
	updateVector2(firstvector, secondvector, mystring);
	cout << "first vector size is " << firstvector.size() << endl;
	cout << "second vector size is " << secondvector.size() << endl;
}
void STL()
{
	int i = sum(1, 2);
	double d = sum(1.1, 2.2);
	string s = sum(string{ "Hello" }, string{ "world" });
	vector<int> integers = { 3, 7, 11, 23 };
	vector<double> doubles = { 1.1,5.4,77.2,-1.2 };
	int ilength = integers.size();
	int dlength = doubles.size();
	integers.push_back(-3);
	integers.push_back(22);
	ilength = integers.size();
	integers[0]++;
	auto third = integers[2];
	int total = 0;
	for (unsigned int i = 0; i < integers.size(); i++)
	{
		total += integers[i];
	}
	int total2 = 0;
	for (int elem : integers)
	{
		total2 += elem;
	}
	int total3 = accumulate(begin(integers), end(integers), 0);
	vector<int> consecutive{ 0,1,2,3,4,5,6,7,8,9 };
	vector<int> consecutive2(100);
	iota(begin(consecutive2), end(consecutive2), 0);
	consecutive.erase(begin(consecutive));
	consecutive.erase(begin(consecutive) + 2);
	consecutive.erase(begin(consecutive) + 4, end(consecutive));
	consecutive.insert(begin(consecutive) + 1, 7);
	sort(begin(doubles), end(doubles));
	auto seventyseven = find(begin(doubles), end(doubles), 77.2);
	*seventyseven = 7.2;
	string sentence = "Hello world new!";
	int spaces = count(begin(sentence), end(sentence), ' ');
}

void STL3()
{
	vector<string> firstvector;
	vector<string> secondvector;
	string mystring("Hello world!");
	try 
	{
		firstvector.push_back(mystring);
		VecScopeGuard<vector<string>> guard1(&firstvector);
		secondvector.push_back(mystring);
		VecScopeGuard<vector<string>> guard2(&secondvector);

		guard1.disengage();
		guard2.disengage();
	}
	catch (...) 
	{
		cout << "Caught error." << endl;
	}

	cout << "First use of scope guards ok, first vector size is  " << firstvector.size() << " second vector size is " << secondvector.size() << endl;

	//Clear vectors.
	firstvector.clear();
	secondvector.clear();

	try 
	{
		firstvector.push_back(mystring);
		VecScopeGuard<vector<string>> guard1(&firstvector);
		bad_alloc excp;
		throw excp; //Replicate error updating second vector.
		secondvector.push_back(mystring);
		VecScopeGuard<vector<string>> guard2(&secondvector);
		guard1.disengage();
		guard2.disengage();
	}
	catch (bad_alloc e) 
	{
		cout << "Caught exception " << endl;
		cout << "Second use of scope guards error, first vector size is  " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
	}
}
void fehlerwert()
{
	try 
	{
		try 
		{
			try 
			{
				myexception myex("myexception object thrown.");  //Create myexception object
				throw myex;   //Throw myexception object
			}
			catch (myexception e) 
			{    //Catch myexception object
				errorinfo firstinfo;    //Create errorinfo struct
				firstinfo.reason = "level 1 error";
				firstinfo.id = 1;
				firstinfo.locationId = 0;
				firstinfo.level = 0;
				firstinfo.description = "First level exception thrown.";
				try 
				{
					e.adderror(firstinfo);  //Add errorinfo struct to myexception object
				}
				catch (bad_alloc) 
				{
					cout << "Out of memory myexception.adderror bad_alloc." << endl;
				}
				throw e;   //Throw myexceptionobject up call stack.
			}
		}
		catch (myexception e) 
		{
			errorinfo secondinfo;
			secondinfo.reason = "level 2 error";
			secondinfo.id = 2;
			secondinfo.locationId = 1;
			secondinfo.level = 2;
			secondinfo.description = "Second level exception thrown.";
			try 
			{
				e.adderror(secondinfo);
			}
			catch (bad_alloc) 
			{
				cout << "Out of memory myexception.adderror bad_alloc." << endl;
			}
			throw e;
		}
	}
	catch (myexception e) 
	{
		//Print out errorinfo structs in myexception object
		for (vector<errorinfo>::iterator iter = e.begin(); iter != e.end(); ++iter) 
		{
			errorinfo next = *iter;
			cout << next.reason << " " << next.id << " " << next.locationId << " " << next.level << " " << next.description << endl;
		}
	}
}
void type_cast()
{
	MyBase* mb = new MyBase();

	MyDerived* md = new MyDerived();

	cout << "The type of mb is " << typeid(mb).name() << endl;
	cout << "The type of md is " << typeid(md).name() << endl;

	//Cast MyBase to MyDerived, Not safe as MyDerived can contain members not in MyBase.

	MyDerived* md2 = static_cast<MyDerived*>(mb);

	//Cast MyDerived to MyBase, Safe as MyDerived Contains MyBase public members from inheritance.

	MyBase* mb2 = static_cast<MyBase*>(md);

	cout << "The type of mb2 is " << typeid(mb2).name() << endl;
	cout << "The type of md2 is " << typeid(md2).name() << endl;

	//Cleanup
	delete mb;
	delete md;

	int myint = 5;

	cout << "The type of myint is " << typeid(myint).name() << " with value " << myint << endl;

	//Cast int to double, safe as precision of double is greater.

	double mydouble = static_cast<double>(myint);

	printf("The type of mydouble is %s with value %f \n", typeid(mydouble).name(), mydouble);


	//Dynamic cast
	MyDerived* md3 = new MyDerived();
	MyBase* mb3 = dynamic_cast<MyBase*>(md3);

	cout << "The type of md3 is " << typeid(mb3).name() << endl;

	//clean up
	delete md3;

	//Const cast
	const int myconst = 5;
	volatile int myvolatile = 9;

	int* nonconst = const_cast<int*>(&myconst);
	int* nonvolatile = const_cast<int*>(&myvolatile);

	//Can't print typeid's of const and volatile.

	//Reinterpret cast.

	MyBase* mb4 = new MyBase();
	UnRelated* urc = new UnRelated();

	//Possibly unsafe cast.
	MyBase* rcast = reinterpret_cast<MyBase*>(urc);

	cout << "The type of rcast is " << typeid(rcast).name() << endl;

	//cleanup
	delete mb4;
	delete urc;
}
//-----------------------------------------Memory Allocation
void allocfail()
{
	try 
	{
		while (true) 
		{
			int* intarray = new int[99999ul];
		}
	}
	catch (const bad_alloc& e) 
	{
		cout << "bad_alloc caught: " << e.what() << endl;
	}
}
void* MyNewDeleteAllocator::operator new (size_t size) 
{
	void *p;
	p = malloc(size);
	if (p == NULL) 
	{
		//Throw bad_alloc.
		bad_alloc exception;
		throw exception;
	}
	cout << "MyNewDeleteAllocator::operator new called with size_t " << size << endl;
	return p;
}
void MyNewDeleteAllocator::operator delete (void *p) 
{
	cout << "MyNewDeleteAllocator::operator delete called. " << endl;
	delete[] p;
}
void mem_alloc()
{
	MyNewDeleteAllocator *p = new MyNewDeleteAllocator; //Create MyNewDeleteAllocator object.
	delete p; //Delete MyNewDeleteAllocator object.
}
/*void cache()
{
	vector<int> myvec;
	vector<int> myvec2;
	clock_t clock_time;

	clock_time = clock();
	for (int i = 0; i < 9999999; i++) 
	{
		myvec.push_back(999);
	}
	clock_time = clock() - clock_time;

	printf("Loop without index in register took %f seconds \n", ((float)clock_time / CLOCKS_PER_SEC));
	//clear vector.
	myvec.clear();

	//start timer
	clock_time = clock();
	for (register int t = 0; t < 9999999; t++) 
	{
		myvec2.push_back(999);
	}
	clock_time = clock() - clock_time;
	//end timer.

	//clear vector.
	myvec2.clear();

	printf("Loop with index in register took %f seconds \n", ((float)clock_time / CLOCKS_PER_SEC));

	//c++11 alignment keywords
	alignas(16) int a[4];
	alignas(1024) int b[4];

	//Output padded results
	printf("%p\n", a);
	printf("%p\n", b);

	if (_alignof(a) == 16) 
	{
		cout << "int b aligned to 16 bytes" << endl;
	}

	if (_alignof(b) == 1024) 
	{
		cout << "int b aligned to 1024 bytes" << endl;
	}
}
*/
void funktion()
{
	register int z = 0;
	int x = 0;
	z++;
	x++;
	cout << z++ + ++x << endl;
}
void time_construction()
{
	Squawker* mcptr;

	cout << "Squawker constructor for object mcptr not yet called." << endl;

	mcptr = new Squawker();

	cout << "Squawker deconstructor for object mcptr not yet called." << endl;

	delete mcptr;

	cout << "Invoke constructor using placement new" << endl;

	new(mcptr) Squawker();

	cout << "Invoke deconstructor by calling it explicitly" << endl;

	mcptr->~Squawker();
}
namespace container
{
	template<typename Container>

	void printContainer(Container begin, Container end) 
	{
		//Generic container printer.
		for (Container it = begin; it != end; it++) 
		{
			cout << *it << " ";
		}
	}

	//Specialize print map function as need to access maps pairs using index operator.
	template<typename Container>
	void printMap(Container begin, Container end) 
	{
		//Generic container printer.
		for (Container it = begin; it != end; it++) 
		{
			cout << it->first << " " << it->second << " ";
		}
	}

	//Helper function to accumulate map pairs.
	int mymapacc(int lhs, const pair<char, int> & rhs) 
	{
		return lhs + rhs.second;
	}

}
