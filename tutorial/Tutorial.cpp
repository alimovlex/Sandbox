// Tutorial.cpp : Defines the entry point for the console application.
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <memory>
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
#include "Tutorial.h"
#include "Convert.h"

using namespace std;
using namespace tutorial;
using namespace convert;
using namespace templ;

#pragma region tutorial
//coursera---------------------
void point::setx(double v)
{
	x = v;
}
void point::sety(double w)
{
	y = w;
}
#pragma endregion
myClass::operator int() 
{

	return 99;
}
myClass::operator double() 
{

	return 22.56;
}

void transformer()
{
	explicitConversion mycc(100.01);
	Conversion myc(64.06);
	mycc.printValue(mycc);      //No conversion
	double myccdouble(53.53);
	mycc.printValue((explicitConversion)myccdouble);      //Explicit conversion of double to float.													  //Conversion would be illegal with explicit hence wont work with mycc object of type explicitConversion.
	double mycdouble(23.23);
	myc.printValue(mycdouble); //Implicit conversion double to float.

}
void conv()
{
	myClass mc;

	int myint = mc;  //implicit conversion

	double mydouble = (double)mc;  //explicit conversion

	cout << " myint is " << myint << " and mydouble is " << mydouble << endl;
}
void templt()
{
	Point<int> basePoint(5, 5);
	Point3D<double> derivedPoint(99.9, 99.9, 99.9);

	cout << "basePoint is ";
	basePoint.printPoint();

	cout << "derivedPoint is ";
	derivedPoint.printPoint();
}

int main()
{
		
	system("Pause");
    return 0;
}

//mem();
//allocate();
//int zz = 6, yy = 5;
//cout << sum(zz, yy);
//-----------------------------Microsoft
//point a;
//a.setx(2.5);
//a.sety(-1.8);
#pragma region Micros
/*
int i{ 0 };
rectangle R;
rectangle *B = &R;
B->square();
BankAccount const I;
I.sayHi();
R.length = 4;
R.width = 3;
R.color = "Blue";
int s = R.square();
*/
//objects();
//file();
//ausnahme();
//except();
//exempt();
//STL3();
//fehlerwert();
//type_cast();
//transformer();
//conv();
//allocfail();
//mem_alloc();
//cache();
#pragma endregion
#pragma region inherit
/*
Ninja n;
Monster m;
Enemy *e1 = &n;
Enemy *e2 = &m;
e1->attack();
e2->attack();
n.attack();
m.attack();
*/

#pragma endregion
//time_construction();
//templt();
//current_time();
//preprocessor();
