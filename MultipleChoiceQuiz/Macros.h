#pragma once

#include <iostream>

#define DEL_STD_VEC(vec) for (int i = 0; i < vec.size(); i++) { \
    if (vec[i] != nullptr) { \
        delete vec[i]; \
    } \
} \
vec.clear()

#define DEL_PTR_S(ptr) if (ptr != nullptr) { delete ptr; }

#define PRINT(s) std::cout << s << std::endl
#define PRINT_NO_NL(s) std::cout << s
#define PRINT_NL() std::cout << std::endl
#define PRINT_CONT(s) << s
#define PRINT_CONT_NL() << std::endl;
