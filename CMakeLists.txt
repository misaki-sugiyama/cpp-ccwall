cmake_minimum_required(VERSION 3.14.5)
project (${CCWALL_PROJECT_PREFIX}ccwall LANGUAGES CXX)

file(GLOB_RECURSE hdrs LIST_DIRECTORIES true CONFIGURE_DEPENDS src/ccwall/*.h)
add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE ${hdrs})
target_include_directories(${PROJECT_NAME} INTERFACE src)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

