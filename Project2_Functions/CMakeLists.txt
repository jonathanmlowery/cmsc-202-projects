cmake_minimum_required(VERSION 3.10.0)
project(CMSC202_Project2_Lowery_Jonathan VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/prompt.cpp
	src/colors.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)