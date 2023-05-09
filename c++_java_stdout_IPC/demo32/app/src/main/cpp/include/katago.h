//
// Created by jc on 2023/5/8.
//

#ifndef _KATAGO_H
#define _KATAGO_H



int StartEngine(std::string weightfilename);
int SendGTP(std::string cmd);
std::string getStdout();


std::string testOut();




#endif
