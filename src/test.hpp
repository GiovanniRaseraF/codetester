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
        std::cerr << std::setw(std::strlen(error) + 7) << std::setfill('-') << "" << std::endl;\
    }\
    else{\
        std::cerr << std::setw(std::strlen(error) + 8) << std::setfill('-') << "" << std::endl;\
        std::cerr << "PASSED: "<< error << "" << std::endl;std::cerr << std::setfill(' ');\
        std::cerr << std::setw(std::strlen(error) + 8) << std::setfill('-') << "" << std::endl;\
    }\
}

#define CHRONO_TEST(func, message)\
{\
    std::chrono::time_point<std::chrono::system_clock> start, end;\
    start = std::chrono::system_clock::now();\
    func;\
    end = std::chrono::system_clock::now();\
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "ms" << std::endl;\
}