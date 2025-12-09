cmake_minimum_required(VERSION 4.2)

option(CLOG_BUILD_EXAMPLE "Build an example executable" OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(clog)
add_library(clog
	source/CLog.hpp
	source/Logger.hpp
	source/Logger.cpp
	source/LogLevel.hpp
	source/Utils.hpp
	source/Utils.cpp
	source/Sinks.hpp
	source/Sinks.cpp
)

include(FetchContent)
FetchContent_Declare(
	FMT
	GIT_REPOSITORY	https://github.com/fmtlib/fmt
	GIT_TAG			2a50a0d8081cdc2f591a96648d6fbf0275a6e7c6
)
FetchContent_MakeAvailable(FMT)
target_link_libraries(clog
	PUBLIC fmt
)
target_include_directories(clog
	PUBLIC source
)

if(CLOG_BUILD_EXAMPLE)
	project(example)
	add_executable(example
		example/main.cpp
	)
	target_link_libraries(example
		PRIVATE clog
	)
endif()