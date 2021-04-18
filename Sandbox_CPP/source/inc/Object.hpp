#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int polymorphismTest();
int templateClassTest();
int templateFunctionTest();

class Base
{
public:
    virtual void show()
    {
        cout << " In Base \n";
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "In Derived \n";
    }
};

class DerivedNext : public Derived {
public:
    void show()
    {
        cout << "In DerivedNext \n";
    }
};

template<class T>
class TemplateItem  //template class
{
private:
    T Data;
public:
    TemplateItem() : Data(T())
    {}
    void SetData(T nValue);
    void array(T arr[],int n);
};
template <class T>
class TemplateClass
{
public:
    T Data;
    TemplateClass()= default;
    void Print(T Data);
};


