#pragma once
///
/// Author: Giovanni Rasera
/// Link: https://github.com/GiovanniRaseraF
///
/// Description: Simple test and debug header
#include <cassert>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include <chrono>

#define TEST(func, expected, error)\
{\
    if(func != expected){\
        std::cerr << std::setw(std::strlen(error) + 7) << std::setfill('-') << "";std::cerr << std::setfill(' ');\
        std::cerr << std::endl << "ERROR: "<< error << "" << std::endl;\
        std::cerr << std::boolalpha;\
        std::cerr << std::setw(15) << std::left << " -expected:" << expected << std::endl;\
        std::cerr << std::setw(15) << std::left << " -got:" << func << std::endl;\
        std::cerr << std::noboolalpha;\
       	std::cerr << std::setw(std::strlen(error) + 7) << std::setfill('-') << "" << std::endl;std::cerr << std::setfill(' ');\
    }\
    else{\
        std::cerr << std::setw(std::strlen(error) + 8) << std::setfill('-') << "" << std::endl;\
        std::cerr << "PASSED: "<< error << "" << std::endl;std::cerr << std::setfill(' ');\
        std::cerr << std::setw(std::strlen(error) + 8) << std::setfill('-') << "" << std::endl;\
    }\
}
#define CHRONO_TEST(func, message)\
{\
    std::cout << std::setw(std::strlen(message) + 9) << std::setfill('-') << "" << std::endl;std::cout << std::setfill(' ');\
    std::cout << "CHRONING: " << message << std::endl;\
    std::chrono::time_point<std::chrono::system_clock> start, end;\
    start = std::chrono::system_clock::now();\
    func;\
    end = std::chrono::system_clock::now();\
    std::cout << std::setw(15) << std::left << " -Duration: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "ms" << std::endl;\
    std::cout << std::setw(std::strlen(message) + 9) << std::setfill('-') << "" << std::endl;std::cout << std::setfill(' ');\
}

#ifdef DEB
#define PRINT(str) debugPrint(str);
#define PRINTLN(str) debugPrintln(str);

void debugPrint(const char *const str){
    std::cout << "DEB:" << str;
}
void debugPrint(std::string str){
    std::cout << "DEB:" << str;
}
void debugPrintln(const char *const str){
    std::cout << "DEB:" << str << std::endl;
}
void debugPrint(double str){
    std::cout << "DEB:" << str;
}
void debugPrintln(double str){
    std::cout << "DEB:" << str << std::endl;
}
void debugPrintln(std::string str){
    std::cout << "DEB:" << str << std::endl;
}

#else
#define PRINT(str) ;
#define PRINTLN(str) ;
#endif
