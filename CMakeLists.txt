cmake_minimum_required(VERSION 3.0.0)
project(algorithm VERSION 0.1.0)


option(LOCAL_TEST "LOCAL_TEST library" ON)

if (LOCAL_TEST)
    add_definitions(/DLOCAL_TEST)
endif()

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
    "src/**/*/*.h"
    "src/**/*/*.hpp"
    "src/**/*/*.c"
    "src/**/*/*.cpp"
    "src/**/*.h"
    "src/**/*.hpp"
    "src/**/*.c"
    "src/**/*.cpp"
    "src/main.cpp"
)

 include_directories(src)

add_executable(build.out ${SRC} ${SOURCES} ${HEADERS})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
