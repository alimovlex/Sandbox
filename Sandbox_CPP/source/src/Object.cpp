/*
    Object.cpp
    The module represents my demo functions on object-oriented approach.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <exception>
#include <algorithm>
#include <iterator>
#include <array>
#include <functional>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <memory>
#include <cstdarg>
#include "Object.hpp"

using namespace std;
//---------------------------------------------------------------Object Oriented Programming
int polymorphismTest()
{
    //first approach
    auto_ptr<Base> bp (new Derived);
    bp->show();
    //second approach
    Base *basic=nullptr;
    Derived der;
    DerivedNext dre;
    basic=&der;
    basic->show();
    basic=&dre;
    basic->show();

    return 0;
}
//------------------------------Template classes programming

template<class T>
void TemplateItem<T>::SetData(T nValue)
{
    nValue = Data;
    cout <<"The template class object is: "<< Data<<endl;
}

template<class T>
void TemplateItem<T>::array(T arr[],int n)
{
    for (int i=0;i<n;i++)
        cout<<"\t"<<arr[i];
    cout<<endl;
}
template<class T>
void TemplateClass<T>::Print(T Data)
{
    cout<<"Hello from the template class! Your value is "<<Data<<endl;
}

int templateClassTest()
{
    srand((unsigned)time(NULL));
    TemplateItem<int> object;
    TemplateItem<char> obj;
    TemplateClass<int> car;
    car.Data =rand()%10;
    car.Print(car.Data);

    return 0;
}

//------------------------------Template functions programming

template <class T>
T summ(T &a, T &b)
{
    return a+b;
}

template <class T>
T summa(T *a, T *b)
{
    return *a+*b;
}

template <class T>
T sum(T a, T b)
{
    return a+b;
}

int templateFunctionTest()
{
    srand((unsigned)time(NULL));
    long a=rand() %10,b=rand() %20, c=sum<long>(rand() %10,rand() %10);
    double x=a,y=b;
    x++;
    y+=0.55;
    cout<<"The template function <int> summ = "<<c<<endl;   //initialization of a template function with int type and random parameters
    cout<<"The template function summ passed by reference = "<<summ(a,b)<<endl;
    cout<<"The template function summ passed by reference = "<<summ(x,y)<<endl;
    x++;
    y+=0.55;
    cout<<"The template function summ passed by address = "<<summa(&a,&b)<<endl;
    cout<<"The template function summ passed by address = "<<summa(&x,&y)<<endl;

    return 0;
}