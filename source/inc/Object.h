#include "OOStd.h"

//
// Created by alimovlex
//

//
#ifdef __cplusplus
extern "C" {
#endif
int test_Animals_Class();
int exception_Test();

//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif
//--------------------------Animal Class initialization
CLASS(Animal) //Definition
{
    char *name;
STATIC(Animal);
    vFn talk; //virtual function
};
//----------------------------Cat Class initialization
CLASS_EX(Cat,Animal) //Definition and inheritance from Animal class
{
STATIC_EX(Cat, Animal);
};

//----------------------------Dog Class initialization
CLASS_EX(Dog,Animal) //Definition and inheritance from Animal class
{
STATIC_EX(Dog, Animal);
};


