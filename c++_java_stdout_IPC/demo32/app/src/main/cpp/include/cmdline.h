//
// Created by jc on 2023/5/7.
//

#ifndef _CMDLINE_H
#define _CMDLINE_H

#include "vector"
#include "string"
#include "iostream"


using namespace std;

std::vector<std::string>  getCommandLineArgsUTF8(int argc, const char* const* argv);

int test_main(int argc, string argv[]);


#endif //DEMO3_CMDLINE_H
