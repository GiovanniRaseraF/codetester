#include "graph.hpp"
#include <cassert>
#include "../src/test.hpp"

int main(){
    densegraph gdense{5};
    gdense.addSide(1, 4);
    gdense.addSide(1, 3);
    gdense.addSide(3, 1);
    gdense.addSide(2, 1);
    gdense.addSide(5, 1);

    TEST(gdense.isConnected(), true, "gdense is connected");

    densegraph gdense1{5};
    gdense1.addSide(1, 4);
    gdense1.addSide(1, 3);
    gdense1.addSide(3, 1);
    gdense1.addSide(2, 1);
    
    // This is giving the wrong answare just to who the error output but the function in good
    TEST(gdense1.isConnected(), true, "gdense1 is NOT connected");
}