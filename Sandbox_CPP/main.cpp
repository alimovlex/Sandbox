/*
    main.cpp
    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include "GRE.hpp"
#include "Tutorial.hpp"
#include "STLTest.hpp"
#include "Algorithms.hpp"
#include "Internet.hpp"

using namespace std;

int main(int argc, char **argv) {
    timerFunction(containersTest);
    timerFunction(algorithmsTest);
    timerFunction(jsonRequest);
    gre_vocabulary();
    return 0;
}