cmake_minimum_required(VERSION 3.10)
project(AssociativeContainer)

set(CMAKE_CXX_STANDARD 20);
set(CMAKE_CXX_STANDARD_REQUIRED ON);

add_executable(associative_container
	main.cpp
	word.cpp
	functions.cpp
)