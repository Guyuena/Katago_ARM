//
// Created by jc on 2023/5/9.
//
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <chrono>             // std::chrono::seconds
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable, std::cv_status
#include<time.h>
#include <sstream>
std::condition_variable cv;
void time_test ()
{


    // std::thread th (read_value);

    // std::cout << ss.str() <<std::endl;;

//    std::cout << "Please, enter an integer (I'll be printing dots): \n";


    std::mutex mtx;
    std::unique_lock<std::mutex> lck(mtx);
    while (cv.wait_for(lck,std::chrono::seconds(2))==std::cv_status::timeout)
    {
        // std::cout << '.' << std::endl;
        time_t now = time(NULL);
        tm* tm_t = localtime(&now);
        std::stringstream ss;
        ss << "year:" << tm_t->tm_year + 1900 << " month:" << tm_t->tm_mon + 1 << " day:" << tm_t->tm_mday
           << " hour:" << tm_t->tm_hour << " minute:" << tm_t->tm_min << " second:" << tm_t->tm_sec <<"--->" << "designed by xjc";
        std::cout << ss.str() <<std::endl;;

    }


//    th.join();
//    return 0;
}