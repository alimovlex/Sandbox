/*
    DataStruct.cpp
    The module represents my demo functions regarding existing data structures.

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
#include "DataStruct.hpp"
#include "STLTest.hpp"
using namespace std;

int STLCombinedArrayTest()
{
    srand((unsigned)time(NULL));
    vector <int> integers;
    array<int, 4> myarray;
    int t, i, num[3][3];
    // Initialize vector with strings using push_back
    // command
    integers.push_back(rand()%10);
    integers.push_back(rand() % 10);
    integers.push_back(rand() % 10);
    integers.push_back(rand() % 10);
    cout << "Array in STL Vector:" << endl;

    // Print Strings stored in Vector
    for (i = 0; i < integers.size(); i++)
    {
        sort(integers.begin(), integers.end());
        cout << integers[i] << "\t";
    }
    cout << endl;
    cout << "Filling myarray container" << endl;
    for (int i : myarray)
    {
        i = rand() % 10;
        cout << i << "\t";
    }
    cout << endl;
    cout<<"Static matrix:"<<endl;
    for (t = 0; t<3; t++)
    {
        cout << endl;
        for (i = 0; i < 3; i++)
        {
            num[t][i] = rand() % 10;
            cout << num[t][i] << "\t";
        }
    }
    cout << endl;

    return 0;
}

int matrixTest()
{
    cout << "Vector matrix" << endl;
    vector<vector<int> > a;
    //m * n is the size of the matrix
    int m = 3, n = 3,i;
    //Grow rows by m
    a.resize(m);
    for (i = 0; i < m; ++i)
    {
        //Grow Columns by n
        a[i].resize(n);
    }
    //Now you have matrix m*n with default values
    //OR
    for (i = 0; i < m; ++i)
    {
        cout << endl;
        for (int j = 0; j < n; ++j)
        {      //modify matrix
            a[i][j] = rand() % 10;
            cout << a[i][j] << "\t";
        }
    }
    cout <<endl<< "Dynamic matrix"<<endl;
    //---------------------------------------------------------- dynamic allocation
    int** ary = new int*[n];
    for (int i = 0; i < n; ++i)
        ary[i] = new int[m];

    // fill
    for (int i = 0; i < n; ++i)
    {
        cout << endl;
        for (int j = 0; j < m; ++j)
        {
            ary[i][j] = rand() % 10;
            cout << ary[i][j] << "\t";
        }
    }
    // free
    for (int i = 0; i < n; ++i)
        delete[] ary[i];
    delete[] ary;
    cout << endl;
    return 0;
}

VectorSumm::VectorSumm(vector<int> &list1) :sum(1)
{
    vector <int> :: iterator itr;
    for(auto i:list1)
    {
        sum*=i;
    }
    cout<<sum<<endl;
    sum=1;
    for(itr=list1.begin();itr<list1.end();++itr)
    {
        sum*=*itr;
    }
    cout<<sum<<endl;
    for_each(list1.begin(),list1.end(),output);
}

int summVectorTest()
{
    vector<int> list1{1,2,3,4,5};
    VectorSumm object(list1);
    return 0;
}