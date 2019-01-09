cmake_minimum_required(VERSION 3.0.0)
project(algorithm VERSION 0.1.0)

include(CTest)
enable_testing()


set(HEADERS

)


set(SOURCES
    # src/**/*.cpp
    # src/matrix.cpp
    # src/problem.cpp
    # src/leetcode_224_calculator.cpp
   )

file(GLOB SRC
    "**/*.h"
    "**/*.hpp"
    "**/*.c"
    "**/*.cpp"
)

include_directories(src)

add_executable(build ${SRC} ${SOURCES} ${HEADERS})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
