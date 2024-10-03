cmake_minimum_required(VERSION 3.22.1)
project(gtester)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

function(apply_gtester file)
    add_executable(test ${file} gtester/test.cpp)
    target_link_libraries(test gtest_main)
    target_compile_definitions(test PRIVATE TESTING)
endfunction()
