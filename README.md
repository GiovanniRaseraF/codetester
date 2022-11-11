# codetester
- Test your code like this
- Compile with "-std=c++20 -Wall -Werror" flags
```cpp
#include <string>
#include "test.hpp"

int main(){
    std::string s1 = "ciao mondo";
    TEST(s1.length(), 10, "s1 has 10 letters"); 
}
```

```cpp
#define VEC_PRINT
#include "test.hpp"
// To print std::vector<T> 
```
## TODO
- Implementing CHRONO_TEST, to get timings
- Implement AVG_CHRONO_TEST, multiple execution of the same function to calculate avg