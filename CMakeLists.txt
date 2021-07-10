cmake_minimum_required(VERSION 3.19)
project(competitive_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -O2 -Wall -Wextra -fsanitize=undefined -D=LOCAL")

#include_directories(lib/data_structure)
#include_directories(lib/graph)
#include_directories(lib/math)
#include_directories(lib/modulus)
#include_directories(lib/utility)

add_executable(competitive_library
        lib/test/aoj/0560.test.cpp
        lib/test/aoj/DPL_5_A.test.cpp
        lib/test/aoj/DPL_5_B.test.cpp
        lib/test/aoj/DPL_5_D.test.cpp
        lib/test/aoj/DPL_5_E.test.cpp
        lib/test/atcoder/abc110d.test.cpp
        lib/test/library-checker/static_range_sum.test.cpp
        lib/test/my_stress_test/convert_base.test.cpp
        lib/test/yukicoder/1140.test.cpp
        )

add_executable(GRL_1_A.test lib/test/aoj/GRL_1_A.test.cpp)