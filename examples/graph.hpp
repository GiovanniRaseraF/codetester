#pragma once
#include <vector>
#include <set>
#include <tuple>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <chrono>
#include <queue>
#include <iomanip>
// Graph 
class graph{
    public:
    virtual std::set<int> getAllNeigh(int v) const = 0;
    virtual std::set<int> getOutNeigh(int v) const  = 0;
    virtual std::set<int> getInNeigh(int v) const = 0;
    virtual void addSide(int from, int to) = 0;
    virtual bool isSide(int from, int to) const = 0;
    virtual bool isConnected() const = 0;

    ~graph() = default;
};

/// @brief Dense graphs are implemented using 
/// adiacence matrix
class densegraph : public graph {
    private:
    std::vector<std::vector<int>> admatrix;

    public:
    densegraph(int m);

    virtual std::set<int> getAllNeigh(int v) const override;
    virtual std::set<int> getOutNeigh(int v) const override;
    virtual std::set<int> getInNeigh(int v) const override;
    virtual void addSide(int from, int to) override;
    virtual bool isSide(int from, int to) const override;
    virtual bool isConnected() const override;
    friend std::ostream &operator<<(std::ostream &os, const densegraph &d);
    ~densegraph() = default;
};