cmake_minimum_required(VERSION 3.5)
project(DP_01_03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS_LIST sqlselectquerybuilder.h advancedsqlselectquerybuilder.h)
set(SRC_LIST sqlselectquerybuilder.cpp advancedsqlselectquerybuilder.cpp)

add_executable(${PROJECT_NAME} main.cpp ${HEADERS_LIST} ${SRC_LIST})
