/*
    Compilation instructions: g++ main.cpp sha1.cpp
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include "sha1.h"
#include <cstring>

const int MAX = 32000;

const char* str1 = "Alice owes Miles ";
const char* str2 = " dollars";

#define __uint32 unsigned long int

std::string sSha1(const std::string& );

int main()
{
    unsigned long count = 0;
    std::stringstream ss;
    ss.clear();
    unsigned long x,y;
    srand(time(NULL));
    std::string hash1, hash2, temp1, temp2;
    x=0;
    y=0;
    hash1="";
    hash2="";
    do{
        x = rand()%MAX;
        y = rand()%MAX;
        while(y == x)
            y = rand()%MAX;
        
        ss << str1 << x << str2;
        getline(ss, temp1);
        //        ss. >> hash1;
        ss.clear();
        ss << str1 << y << str2;
        getline(ss, temp2);
        //        ss >> hash2;
        ss.clear();
        // Hash hash1
        hash1 = sSha1(temp1);
        // Hash hash2
        hash2 = sSha1(temp2);
        count++;
    }while(hash1[0] != hash2[0] || hash1[1] != hash2[1]);
    std::cout << "************************************************" << std::endl;
    std::cout << "Stats:" << std::endl;
    std::cout << "Message 1: " << std::endl << temp1 << std::endl;
    std::cout << "Message 2: " << std::endl << temp2 << std::endl;
    std::cout << "Number of attempts: " << count << std::endl;
    std::cout << "************************************************" << std::endl;
    return 0;
}


std::string sSha1(const std::string& sInput)
{
    std::string sOutput;
    // Do Sha1 code
    sOutput =  sha1(sInput);
    return sOutput;
}
