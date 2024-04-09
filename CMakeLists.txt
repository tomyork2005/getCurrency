cmake_minimum_required(VERSION 3.26)
project(verylasssy)

set(CMAKE_CXX_STANDARD 17)

add_executable(verylasssy main.cpp
        httpGETandParsingJson.cpp
        httpGETandParsingJson.h)

include(FetchContent)

# fix bug with lib
if(WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# cpr lib
FetchContent_Declare(cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1ad1cd2daf138aefdcdb1c35d99608387d230ec1)
FetchContent_MakeAvailable(cpr)
target_link_libraries(verylasssy PRIVATE cpr::cpr)

# json lib
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(verylasssy PRIVATE nlohmann_json::nlohmann_json)