/*
    STLTest.cpp
    The module represents my demo functions regarding STL data structures and its methods.

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
#include <array>
#include <functional>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <utility>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <valarray>
using namespace std;

void output(const int &s)
{
    cout<<s<<"\t";
}

void vectorTest(vector <int> &vectorObject)
{
	srand((unsigned)time(NULL));
	// Initializing vector with array values 
	vectorObject.emplace(vectorObject.begin(), 5);//insert numbers at the given position
	vectorObject.emplace(vectorObject.end(), 25);
	vectorObject.emplace_back(50);
	cout <<endl<< "Vector is: ";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	cout << endl;
	vectorObject.empty() == true ? cout << "Vector is empty" << endl : cout << "Vector isn't empty" << endl;
	// Sorting the Vector in Ascending order 
	cout << "Size : " << vectorObject.size()<<endl;
	cout << "Capacity : " << vectorObject.capacity()<<endl;
	cout << "Max_Size : " << vectorObject.max_size()<<endl;
	cout << "Distance between first to max element: ";
	cout << distance(vectorObject.begin(), max_element(vectorObject.begin(), vectorObject.end())) << endl;
	sort(vectorObject.begin(), vectorObject.end());
	cout << "Vector after sorting is: ";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	// Reversing the Vector 
	cout << endl;
	reverse(vectorObject.begin(), vectorObject.end());
	cout << "Vector after reversing is: ";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	cout << endl;
	cout << "The vector elements in reverse order are:";
	for (auto it = vectorObject.rbegin(); it != vectorObject.rend(); it++)
		cout << *it << " ";
	cout << "\nMaximum element of vector is: ";
	cout << *max_element(vectorObject.begin(), vectorObject.end())<<endl;
	cout << "Minimum element of vector is: ";
	cout << *min_element(vectorObject.begin(), vectorObject.end())<<endl;
	// Starting the summation from 0 
	cout << "The summation of vector elements is: ";
	cout << accumulate(vectorObject.begin(), vectorObject.end(), 0)<<endl;
	cout << "Occurrences of 5 in vector : ";
	// Counts the occurrences of 20 from 1st to 
	// last element 
	cout << count(vectorObject.begin(), vectorObject.end(), 5);
	// find() returns iterator to last address if 
	// element not present 
	find(vectorObject.begin(), vectorObject.end(), 5) != vectorObject.end() ? cout << "Element found\n" : cout << "\nElement not found"<<endl;
	// Delete second element of vector 
	vectorObject.erase(vectorObject.begin() + 1);
	vectorObject.pop_back();
	cout << "Vector after erasing last and second element: ";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	// sorting to enable use of unique() 
	sort(vectorObject.begin(), vectorObject.end());
	cout << "\nVector before removing duplicate occurrences: ";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	// Deletes the duplicate occurrences 
	vectorObject.erase(unique(vectorObject.begin(), vectorObject.end()), vectorObject.end());

	cout << "\nVector after deleting duplicates: ";
	for (int i = 0; i< vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	cout << endl;
	// modifies vector to its next permutation order 
	next_permutation(vectorObject.begin(), vectorObject.end());
	cout << "Vector after performing next permutation:";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	prev_permutation(vectorObject.begin(), vectorObject.end());
	cout << "\nVector after performing prev permutation:";
	for (int i = 0; i<vectorObject.size(); i++)
		cout << vectorObject[i] << " ";
	cout << endl;
	cout << "Last element - First element = ";
	if (vectorObject.front() > vectorObject.back())
	{
		cout << vectorObject.front() - vectorObject.back();
	}
	else if (vectorObject.front() < vectorObject.back())
	{
		cout << vectorObject.back() - vectorObject.front();
	}
	else
		cout << "0";
	cout << endl;
	cout << "Displaying even positioned numbers: ";
	for (int i = 0; i < vectorObject.size(); i += 2) 
	{
		cout << vectorObject.at(i);
		cout << " ";
	}
	cout << endl;
	vectorObject.assign(5, 100);// 5 elements of 100 in vector
	cout << "The last element is: " << *vectorObject.rbegin()<<endl;
	vectorObject.clear();
	vectorObject.empty() == true ? cout << "Vector is empty"<<endl : cout <<"Vector isn't empty"<< endl;
}

void listTest(list<int> &listObject)
{
	srand((unsigned)time(NULL));
	// Add elements to the List 
    listObject.empty()==true ? cout <<endl<< "Empty List"<<endl : cout <<endl<< "Not Empty"<<endl;
	listObject.emplace(listObject.begin(), 5);//insert numbers at the given position
	listObject.emplace(listObject.end(), 25);
	listObject.emplace_back(50);
	cout << "Initial list: ";
	for (int i : listObject)
		cout <<" "<< i;
	cout << endl;
	cout << "Size : " << listObject.size() << endl;
	cout << "Max_Size : " << listObject.max_size() << endl;
	cout << "Distance between first to max element: ";
	cout << distance(listObject.begin(), max_element(listObject.begin(), listObject.end())) << endl;
	// Deletes the duplicate occurrences 
	cout << "Sorted list" << endl;
	listObject.sort();
    for (int i : listObject)
        cout << " " << i;
    cout << endl;
	reverse(listObject.begin(), listObject.end());
	cout << "Reversed list: ";
	for (int i : listObject)
		cout << " " << i;
	cout << endl;
	cout << "Deleting duplicates" << endl;
	listObject.erase(unique(listObject.begin(), listObject.end()), listObject.end());
	for (int i : listObject)
		cout << " " << i;
	cout << endl;
	cout << "First element of the list is: " << listObject.front() << endl;
	cout << "Last element of the list is: " << listObject.back() << endl;
	cout << "List after removing an element from front and bottom: ";
	listObject.pop_front();
	listObject.pop_back();
	for (int i : listObject)
		cout << " " << i;
	cout << endl;
	listObject.clear();
	listObject.empty() == true ? cout << "Empty List" << endl : cout << "Not Empty" << endl;
}

void dequeTest(deque <int> &dequeObject)
{
	dequeObject.emplace(dequeObject.begin(), 5);//insert numbers at the given position
	dequeObject.emplace(dequeObject.end(), 25);
	cout <<endl<< "The deque dequeObject is : ";
	for (int i : dequeObject)
		cout << " " << i;
	cout << endl;
	// Deletes the duplicate occurrences 
	reverse(dequeObject.begin(), dequeObject.end());
	cout << "Reversed list: ";
	for (int i : dequeObject)
		cout << " " << i;
	cout << endl;
	cout << "First element of the dequeue is: " << dequeObject.front() << endl;
	cout << "Last element of the dequeue is: " << dequeObject.back() << endl;
	cout << "dequeObject.size() : " << dequeObject.size()<<endl;
	cout << "dequeObject.max_size() : " << dequeObject.max_size()<<endl;
	cout << "dequeObject.at(2) : " << dequeObject.at(2) << endl;
	cout << "dequeObject.front() : " << dequeObject.front()<<endl;
	cout << "dequeObject.back() : " << dequeObject.back()<<endl;
	cout << "dequeObject.pop_front() : ";
	dequeObject.pop_front();
	for (int i : dequeObject)
		cout << " " << i;
	cout << endl;
	cout << "dequeObject.pop_back() : ";
	dequeObject.pop_back();
	for (int i : dequeObject)
		cout << " " << i;
	cout << endl;
	// resize to 5
	dequeObject.resize(5);
	// // Prints the deque elements after resize() 
	cout << "Size after resize " << dequeObject.size() << endl;
	cout << "The contents of deque :";
	for (int i : dequeObject)
		cout << " " << i;
	cout << endl;
	dequeObject.clear();
	dequeObject.empty() == true ? cout << "Empty dequeue" << endl : cout << "Not Empty" << endl;
}

void queueTest(queue <int> &queueObject)
{
	queueObject.empty() == true ? cout << "Empty Queue" << endl : cout << "Not Empty" << endl;
	
	cout << "queueObject.size() : " << queueObject.size()<<endl;
	cout << "queueObject.front() : " << queueObject.front()<<endl;
	cout << "queueObject.back() : " << queueObject.back()<<endl;
}

void arrayTest(array<int, 6> &arrayObject)
{

	// Initializing the array elements 

	// Checking size of array if it is empty 
	arrayObject.empty()==true ? cout <<endl<< "Array empty" : cout <<endl<< "Array not empty";
	cout << endl;
	// Printing array elements using at() 
	cout << "The array elemets are (using at()) : ";
	for (int i = 0; i<6; i++)
		cout << arrayObject.at(i) << " ";
	cout << endl;

	// Printing array elements using get() 
	cout << "The array elemets are (using get()) : ";
	cout << get<0>(arrayObject) << " " << get<1>(arrayObject) << " ";
	cout << get<2>(arrayObject) << " " << get<3>(arrayObject) << " ";
	cout << get<4>(arrayObject) << " " << get<5>(arrayObject) << " ";
	cout << endl;

	// Printing array elements using operator[] 
	cout << "The array elements are (using operator[]) : ";
	for (int i = 0; i<6; i++)
		cout << arrayObject[i] << " ";
	cout << endl;
	// Printing number of array elements 
	cout << "The number of array elements is : ";
	cout << arrayObject.size() << endl;

	// Printing maximum elements array can hold 
	cout << "Maximum elements array can hold is : ";
	cout << arrayObject.max_size() << endl;
	// Printing first element of array 
	cout << "First element of array is : ";
	cout << arrayObject.front() << endl;

	// Printing last element of array 
	cout << "Last element of array is : ";
	cout << arrayObject.back() << endl;
}

void forwardListTest(forward_list<int> &forwardListObject)
{
	// Displaying the forward list 
	cout <<endl<< "The forward list after push_front operation : ";
	for (int i : forwardListObject)
		cout << " " << i;
	cout << endl;

	// Inserting value using emplace_front() 
	// Inserts 70 at front 
	forwardListObject.emplace_front(70);

	// Displaying the forward list 
	cout << "The forward list after emplace_front operation : ";
	for (int i : forwardListObject)
		cout << " " << i;
	cout << endl;

	// Deleting first value using pop_front() 
	// Pops 70 
	forwardListObject.pop_front();
	forwardListObject.sort();
	// Use of unique() to remove repeated occurrences 
	forwardListObject.unique();
	// Displaying the forward list 
	cout << "The forward list after pop_front operation : ";
	for (int i : forwardListObject)
		cout << " " << i;
	cout << endl;
	cout << "The contents of forward list after reversing are : ";
	forwardListObject.reverse();
	for (int i : forwardListObject)
		cout << " " << i;
	cout << endl;
	cout << "Maximum element of forward list is: ";
	cout << *max_element(forwardListObject.begin(), forwardListObject.end()) << endl;
	cout << "Minimum element of forward list is: ";
	cout << *min_element(forwardListObject.begin(), forwardListObject.end()) << endl;
	// Starting the summation from 0 
	cout << "The summation of forward list elements is: ";
	cout << accumulate(forwardListObject.begin(), forwardListObject.end(), 0) << endl;
	forwardListObject.clear();
	forwardListObject.empty() == true ? cout << "Empty forward list" << endl : cout << "Not Empty" << endl;
}

void stackTest(stack <int> &stackObject)
{
	cout << "The top element:" << stackObject.top() << endl;
	cout << "The size of the stack = " << stackObject.size() << endl;
	cout << "The stack is : ";
	while (!stackObject.empty())
	{
		cout << '\t' << stackObject.top();
		stackObject.pop();
	}
	cout << endl;
	stackObject.empty() == true ? cout << "Empty stack" << endl : cout << "Not Empty" << endl;
} 

void setTest(set <int, greater <int> > &setObject)
{
    // printing set setObject
    set <int, greater <int> > :: iterator itr;
    cout <<endl<< "The set setObject is : ";
    for (itr = setObject.begin(); itr != setObject.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;

    // assigning the elements from setObject to setObject2
    set <int> setObject2(setObject.begin(), setObject.end());

    // print all elements of the set setObject2
    cout << "\nThe set setObject after assignment from setObject is : ";
    for (itr = setObject2.begin(); itr != setObject2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;

    // remove all elements up to 30 in setObject2
    cout << "\nsetObject2 after removal of elements less than 30 : ";
    setObject2.erase(setObject2.begin(), setObject2.find(30));
    for (itr = setObject2.begin(); itr != setObject2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }

    // remove element with value 50 in setObject2
    int num;
    num = setObject2.erase (50);
    cout << "\nsetObject2.erase(50) : ";
    cout << num << " removed \t" ;
    for (itr = setObject2.begin(); itr != setObject2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }

    cout << endl;

    //lower bound and upper bound for set setObject
    cout << "setObject.lower_bound(40) : "
         << *setObject.lower_bound(40) << endl;
    cout << "setObject.upper_bound(40) : "
         << *setObject.upper_bound(40) << endl;

    //lower bound and upper bound for set setObject2
    cout << "setObject2.lower_bound(40) : "
         << *setObject2.lower_bound(40) << endl;
    cout << "setObject2.upper_bound(40) : "
         << *setObject2.upper_bound(40) << endl;
}

void multisetTest(multiset <int, greater <int> > &multisetObject)
{
    // printing multiset multisetObject
    multiset <int, greater <int> > :: iterator itr;
    cout << endl<<"The multiset multisetObject is : ";
    for (itr = multisetObject.begin(); itr != multisetObject.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;

    // assigning the elements from multisetObject to multisetObject2
    multiset <int> multisetObject2(multisetObject.begin(), multisetObject.end());

    // print all elements of the multiset multisetObject2
    cout << "\nThe multiset multisetObject2 after assign from multisetObject is : ";
    for (itr = multisetObject2.begin(); itr != multisetObject2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;

    // remove all elements up to element with value 30 in multisetObject2
    cout << "\nmultisetObject2 after removal of elements less than 30 : ";
    multisetObject2.erase(multisetObject2.begin(), multisetObject2.find(30));
    for (itr = multisetObject2.begin(); itr != multisetObject2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }

    // remove all elements with value 50 in multisetObject2
    int num;
    num = multisetObject2.erase(50);
    cout << "\nmultisetObject2.erase(50) : ";
    cout << num << " removed \t" ;
    for (itr = multisetObject2.begin(); itr != multisetObject2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }

    cout << endl;

    //lower bound and upper bound for multiset multisetObject
    cout << "multisetObject.lower_bound(40) : "
         << *multisetObject.lower_bound(40) << endl;
    cout << "multisetObject.upper_bound(40) : "
         << *multisetObject.upper_bound(40) << endl;

    //lower bound and upper bound for multiset multisetObject2
    cout << "multisetObject2.lower_bound(40) : "
         << *multisetObject2.lower_bound(40) << endl;
    cout << "multisetObject2.upper_bound(40) : "
         << *multisetObject2.upper_bound(40) << endl;
}

void mapTest(map<int, int> &mapObject)
{
    // printing map mapObject
    map<int, int>::iterator itr;
    cout << endl<<"The map mapObject is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = mapObject.begin(); itr != mapObject.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    // assigning the elements from mapObject to mapObject2
    map<int, int> mapObject2(mapObject.begin(), mapObject.end());

    // print all elements of the map mapObject2
    cout << "\nThe map mapObject2 after"
         << " assign from mapObject is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = mapObject2.begin(); itr != mapObject2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    // remove all elements up to
    // element with key=3 in mapObject2
    cout << "\nmapObject2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    mapObject2.erase(mapObject2.begin(), mapObject2.find(3));
    for (itr = mapObject2.begin(); itr != mapObject2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

    // remove all elements with key = 4
    int num;
    num = mapObject2.erase(4);
    cout << "\nmapObject2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = mapObject2.begin(); itr != mapObject2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

    cout << endl;

    // lower bound and upper bound for map mapObject key = 5
    cout << "mapObject.lower_bound(5) : "
         << "\tKEY = ";
    cout << mapObject.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << mapObject.lower_bound(5)->second << endl;
    cout << "mapObject.upper_bound(5) : "
         << "\tKEY = ";
    cout << mapObject.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << mapObject.upper_bound(5)->second << endl;
}

void multimapTest(multimap <int, int> &multimapObject)
{

    // printing multimap multimapObject
    multimap <int, int> :: iterator itr;
    cout << "\nThe multimap multimapObject is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = multimapObject.begin(); itr != multimapObject.end(); ++itr)
    {
        cout  <<  '\t' << itr->first
              <<  '\t' << itr->second << '\n';
    }
    cout << endl;

    // assigning the elements from multimapObject to multimapObject2
    multimap <int, int> multimapObject2(multimapObject.begin(),multimapObject.end());

    // print all elements of the multimap multimapObject2
    cout << "\nThe multimap multimapObject2 after assignment from multimapObject is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = multimapObject2.begin(); itr != multimapObject2.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    // remove all elements up to element with value 30 in multimapObject2
    cout << "\nmultimapObject2 after removal of elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    multimapObject2.erase(multimapObject2.begin(), multimapObject2.find(3));
    for (itr = multimapObject2.begin(); itr != multimapObject2.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

    // remove all elements with key = 4
    int num;
    num = multimapObject2.erase(4);
    cout << "\nmultimapObject2.erase(4) : ";
    cout << num << " removed \n" ;
    cout << "\tKEY\tELEMENT\n";
    for (itr = multimapObject2.begin(); itr != multimapObject2.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

    cout << endl;

    //lower bound and upper bound for multimap multimapObject key = 5
    cout << "multimapObject.lower_bound(5) : " << "\tKEY = ";
    cout << multimapObject.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = " << multimapObject.lower_bound(5)->second << endl;
    cout << "multimapObject.upper_bound(5) : " << "\tKEY = ";
    cout << multimapObject.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = " << multimapObject.upper_bound(5)->second << endl;
}

void pairTest(pair<char, int> &pairFirst, pair<char, int> &pairSecond) {
    cout << "Before swapping: " << endl;
    cout << "Contents of pairFirst = " << pairFirst.first << " " << pairFirst.second << endl;
    cout << "Contents of pairSecond = " << pairSecond.first << " " << pairSecond.second << endl;
    pairFirst.swap(pairSecond);
    cout << "After swapping: " << endl;
    cout << "Contents of pairFirst = " << pairFirst.first << " " << pairFirst.second << endl;
    cout << "Contents of pairSecond = " << pairSecond.first << " " << pairSecond.second << endl;
}

void matrixTest(int row ,int col)
{
    // row and column of matrix

    // matrix of size row*col in row major form.
    valarray<int> matrix(row * col);

    // initialising matrix
    for (int i = 0; i < row * col; ++i)
        matrix[i] = i + 1;

    // using slice from start 0 with size as col and stride col+1
    valarray<int> diagonal = matrix[slice(0, col, col + 1)];

    // finding trace using diagonal we got using slice
    int index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[index++] << " "; // same as matrix[i][j]
        cout << endl;
    }

    int sum = 0; // initialising sum as 0
    // calculating trace of matrix
    for (int i = 0; i < diagonal.size(); i++)
        sum += diagonal[i];
    cout << "Trace of matrix is : ";
    cout << sum << endl; // sum is trace of matrix
}

int containersTest()
{
	srand((unsigned)time(NULL));
	vector<int>vectorObject;
	vector <int>::iterator vectorIterator;
	list<int> listObject;
	deque <int> dequeObject;
	forward_list<int> forwardListObject;
	queue<int> queueObject;
	stack <int> stackObject;
    multiset <int, greater <int>> multisetObject;
    map<int, int> mapObject;
    set <int, greater <int> > setObject;
    multimap <int, int> multimapObject;
    pair<char, int>pairObjectFirst;
    pair<char, int>pairObjectSecond;
	vectorObject.push_back(rand() % 10);
	vectorObject.push_back(rand() % 10);
	vectorObject.push_back(rand() % 10);
	vectorObject.push_back(rand() % 10);
	vectorObject.push_back(rand() % 10);
	cout << "-------------------VECTOR----------------------" << endl;
    for_each(vectorObject.begin(),vectorObject.end(),output);
	vectorTest(vectorObject);
	listObject.push_back(rand() % 10);
	listObject.push_back(rand() % 10);
	listObject.push_front(rand() % 10);
	listObject.push_front(rand() % 10);
	listObject.push_front(rand() % 10);
	cout << "-------------------LIST----------------------" << endl;
    for_each(listObject.begin(),listObject.end(),output);
	listTest(listObject);
	cout <<endl<< "-------------------FORWARD LIST----------------------" << endl;
	forwardListObject.push_front(rand() % 10);
	forwardListObject.push_front(rand() % 10);
	forwardListObject.push_front(rand() % 10);
	forwardListObject.push_front(rand() % 10);
	forwardListObject.push_front(rand() % 10);
    for_each(forwardListObject.begin(),forwardListObject.end(),output);
	forwardListTest(forwardListObject);
	cout << "-------------------DEQUEUE----------------------" << endl;
	dequeObject.push_back(rand() % 10);
	dequeObject.push_front(rand() % 10);
	dequeObject.push_back(rand() % 10);
	dequeObject.push_front(rand() % 10);
	dequeObject.push_back(rand() % 10);
    for_each(dequeObject.begin(),dequeObject.end(),output);
	dequeTest(dequeObject);
	cout << "-------------------QUEUE----------------------" << endl;
	queueObject.push(rand() % 10);
	queueObject.push(rand() % 10);
	queueObject.push(rand() % 10);
	queueObject.emplace(rand() % 10);
	queueObject.emplace(rand() % 10);
	queueTest(queueObject);
	cout << "-------------------ARRAY----------------------" << endl;
    array<int, 6> arrayObject = { 1, 2, 3, 4, 5, 6 };
    for_each(arrayObject.begin(),arrayObject.end(),output);
	arrayTest(arrayObject);
	cout << "-------------------STACK----------------------" << endl;
	stackObject.push(rand() % 10);
	stackObject.push(rand() % 10);
	stackObject.push(rand() % 10);
	stackObject.push(rand() % 10);
	stackObject.push(rand() % 10);
	stackTest(stackObject);
    cout << "-------------------SET----------------------" << endl;
    setObject.insert(40);
    setObject.insert(30);
    setObject.insert(60);
    setObject.insert(20);
    setObject.insert(50);
    setObject.insert(50); // only one 50 will be added to the set
    setObject.insert(10);
    for_each(setObject.begin(),setObject.end(),output);
	setTest(setObject);
    cout << "-------------------MULTISET----------------------" << endl;
    // insert elements in random order
    multisetObject.insert(40);
    multisetObject.insert(30);
    multisetObject.insert(60);
    multisetObject.insert(20);
    multisetObject.insert(50);
    multisetObject.insert(50); // 50 will be added again to the multiset unlike set
    multisetObject.insert(10);
    for_each(multisetObject.begin(),multisetObject.end(),output);
	multisetTest(multisetObject);
    cout << "-------------------MAP----------------------" << endl;
    // insert elements in random order
    mapObject.insert(pair<int, int>(1, 40));
    mapObject.insert(pair<int, int>(2, 30));
    mapObject.insert(pair<int, int>(3, 60));
    mapObject.insert(pair<int, int>(4, 20));
    mapObject.insert(pair<int, int>(5, 50));
    mapObject.insert(pair<int, int>(6, 50));
    mapObject.insert(pair<int, int>(7, 10));
    mapTest(mapObject);
    cout << "-------------------MULTIMAP----------------------" << endl;
    // insert elements in random order
    multimapObject.insert(pair <int, int> (1, 40));
    multimapObject.insert(pair <int, int> (2, 30));
    multimapObject.insert(pair <int, int> (3, 60));
    multimapObject.insert(pair <int, int> (4, 20));
    multimapObject.insert(pair <int, int> (5, 50));
    multimapObject.insert(pair <int, int> (6, 50));
    multimapObject.insert(pair <int, int> (6, 10));
    multimapTest(multimapObject);
    cout << "-------------------MATRIX----------------------" << endl;
    matrixTest(rand()%10,rand()%10);
    cout << "-------------------PAIR----------------------" << endl;
    pairObjectFirst = make_pair('A', 1);
    pairObjectSecond =  make_pair('B', 2);
    pairTest(pairObjectFirst,pairObjectSecond);
    return 0;
}

