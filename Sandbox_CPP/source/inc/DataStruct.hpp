#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int STLCombinedArrayTest();
int matrixTest();
int summVectorTest();

class VectorSumm
{
public:
    VectorSumm(vector<int> &list1);
    ~VectorSumm(){};
private:
    int sum;
};
