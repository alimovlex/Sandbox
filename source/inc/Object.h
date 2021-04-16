#include "OOStd.h"
void Test_Animals_Class();
void Exception_Test();
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


