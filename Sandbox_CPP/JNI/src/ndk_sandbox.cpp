#include <iostream>
#include "jnipp.hpp"
using namespace std;

int test_jvm() {
    // An instance of the Java VM needs to be created.
    jni::Vm vm;

    // Create an instance of java.lang.Integer
    jni::Class Integer = jni::Class("java/lang/Integer");
    jni::Object i = Integer.newInstance("1000");
    //cout<< i.isNull() << endl;
    // Call the `toString` method on that integer
    string str = i.call<string>("toString");

    str.append("Hello ");

    cout << str << endl;
    // The Java VM is automatically destroyed when it goes out of scope.
    return 0;
}



