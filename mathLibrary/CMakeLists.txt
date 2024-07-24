cmake_minimum_required(VERSION 3.23)
project(mathLibrary C)

set(CMAKE_C_STANDARD 99)

# Enable testing
enable_testing()

include_directories(include)

# Define the library
add_library(mathLib SHARED
        src/basicOperations.c
        src/linearAlgebra.c
        src/trigonometricFunctions.c
        )

# Define the test executable
add_executable(run_tests
        tests/testLibrary.c
        )

# Link the library to the test executable
target_link_libraries(run_tests mathLib)

# Add the test
add_test(NAME MathLibraryTest COMMAND run_tests)