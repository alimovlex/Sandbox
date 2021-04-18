#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void STLCombinedArrayTest();
void matrixTest();
void summVectorTest();

class VectorSumm
{
public:
    VectorSumm(vector<int> &list1);
    ~VectorSumm(){};
private:
    int sum;
};
