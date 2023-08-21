cmake_minimum_required(VERSION 3.22.1)
project(Classful-C C CXX)

set(CMAKE_C_STANDARD 99)

if(MODEL)
	add_subdirectory(model)
endif()

add_subdirectory(src)


if(BUILD_TEST)
	add_subdirectory(googletest)
	add_subdirectory(test)
endif()
