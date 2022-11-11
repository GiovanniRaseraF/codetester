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

#ifdef VEC_PRINT
template <class T>
std::ostream &operator<<(std::ostream& os, std::vector<T> &vec){
    for(T val : vec){
        os << std::setw(4) << val;
    }

    return os;
}

template <class T>
std::ostream &operator<<(std::ostream& os, std::vector<T> &&vec){
    for(T val : vec){
        os << std::setw(4) << val;
    }

    return os;
}
#endif

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
    const auto start = std::chrono::high_resolution_clock::now();\
    func;\
    const auto end = std::chrono::high_resolution_clock::now();\
    const std::chrono::duration<double, std::milli> ms = end-start;\
    std::cout << std::setw(15) << std::left << " -Duration: " << ms.count() << "ms" << std::endl;\
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
