#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <numeric>
#include <algorithm>
#include <exception>
#include <type_traits>
#include <new>
#include <map>
#include <iterator>
#include <deque>
#include <set>
#include <numeric>
using namespace std;
namespace tutorial
{
	template <class TContainer>
	class VecScopeGuard 
	{
	public:
		VecScopeGuard(TContainer* vecptr)
			: engaged_(true), vecptr_(vecptr) 
		{ 
			//Assign vecptr and set guard to true.
		}

		~VecScopeGuard() 
		{
			if (engaged_) 
			{
				//Remove last vector entry
				vecptr_->pop_back();
			}
		}
		void disengage()
		{
			engaged_ = false;
			//Vectors updated so release guard
		}
		
	private:
		bool engaged_;
		TContainer* vecptr_;
	};
#pragma region coursera
	class point 
	{
	public:
		point(double x = 0.0, double y = 0.0)
			: x(x), y(y) {}
		void setx(double v);
		void sety(double w);
		~point() {}
	private:
		double x, y; //the variables are used only in functions and operations!!!
	};
	//----------------REVISE LISTS IN C++/SPISKI
	class list
	{
	public:
		list(int n = 0, list *ptr = 0) :
			d(n), next(ptr) {}
		int d;
		list *next;
	};
#pragma endregion
	//-----------------------------------Microsoft
#pragma region Microsoft
	class rectangle
	{
	public:
		int sum();
		int square();
		int get_area();
		int length;
		int width;
		string color;
	private:
		int _width;
		int _length;
	};
	class triangle :public rectangle
	{
	public:
		int a = length;
		int b = width;
		int c = sum();
		int s = square();
	};
	/*
	class Vehicle
	{
	public:
		string Make;
		string Model;
		string Color;
		virtual void welcome(string hi);
	};

	class Car : public Vehicle
	{
		Car();
		Car(string x, string y, string z);
		~Car();
		void welcome(string hi);
	};
	*/
#pragma endregion

	class Squawker
	{
	public:
		Squawker();//default constructor
		Squawker(string n); //Constructor
		~Squawker();//Deconstructor
		void computer();
	private:
		string name;
	};
	class throwexception 
	{
	public:
		throwexception(); //Constructor

		~throwexception();  //Destructor
	};
	//--------------------------------Polymorphism
#pragma region Polymorphism
	class Enemy 
	{
	public:
		virtual void attack() {}
	};

	class Ninja : public Enemy 
	{
	public:
		void attack();
	};
	class Monster : public Enemy 
	{
	public:
		void attack();
	};
#pragma endregion
	static char *ErrorNames[] = {
		"Index Out Of Bounds",
		"Stack Overflow",
		"Stack Underflow",
		"Out of Memory"
	};

	enum Errors {
		INDEX_OUT_OF_BOUNDS = 1,
		STACK_OVERFLOW,
		STACK_UNDERFLOW,
		OUT_OF_MEMORY
	};

	struct errorinfo 
	{
		int id;
		int locationId;
		int level;
		string description;
		string reason;
	};

	class myexception : public exception 
	{
	public:
		myexception(const string& message) : msg(message)
		{
		}
		virtual char const* what() const;
		virtual ~myexception() throw ();
		void adderror(errorinfo info) throw(bad_alloc);
		vector<errorinfo>::iterator begin();
		vector<errorinfo>::iterator end();
	protected:
		string msg;
		vector<errorinfo> errorlist;
	};
	class MyBase {};

	class MyDerived : public MyBase {};

	class UnRelated {};

	class MyNewDeleteAllocator 
	{
	public:
		MyNewDeleteAllocator() {}
		~MyNewDeleteAllocator() {}
		static void* operator new (size_t size);
		static void operator delete (void *p);
	};
	
}

void file();
void pointer();
void mem();
void memory();
void objects();
bool is_connected(bool *graph[], int size);
void except();
void STL();
void ausnahme();
void exempt();
void STL2();
void STL3();
void fehlerwert();
void type_cast();
void allocfail();
void mem_alloc();
void cache();
void funktion();
void time_construction();
void current_time();
void preprocessor();