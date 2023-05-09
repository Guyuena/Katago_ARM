//
// Created by jc on 2023/5/7.
//


#include "vector"
#include "string"
#include "iostream"
#include "include/cmdline.h"

using namespace std;

std::vector<std::string>  getCommandLineArgsUTF8(int argc, const char* const* argv) {

    // For non-Windows, for now assume we have UTF8. If we need to add a case for another OS here, we can do that later.
    std::vector<std::string> args;
//    args.reserve(argc);

    args.reserve(argc+1);
for(int i = 0; i<argc; i++)
        args.emplace_back(argv[i]);
    return args;

}


int test_main(int argc, string argv[])
{
    int i;
//    printf("Argument len(argc) is %d  \n", argc);
//    for (i = 0; i < argc; i++)
//        printf("Argument %d is %s\n", i, argv[i]);

//    vector<string> args = getCommandLineArgsUTF8(argc, reinterpret_cast<const char *const *>(argv));
    std::vector<std::string> args;
    args.reserve(argc);
    for(int i = 0; i<argc; i++)
        args.emplace_back(argv[i]);

    for (int i = 0; i < args.size(); ++i)
    {
        std::cout << args[i]<<std::endl;

    }
    return 0;
}

