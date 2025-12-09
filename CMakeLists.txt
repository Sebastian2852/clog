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
target_include_directories(clog
	PUBLIC source
)
set_target_properties(clog PROPERTIES FOLDER "CLog")

include(FetchContent)
FetchContent_Declare(
	fmt
	GIT_REPOSITORY	https://github.com/fmtlib/fmt
	GIT_TAG			2a50a0d8081cdc2f591a96648d6fbf0275a6e7c6
)
FetchContent_MakeAvailable(fmt)
target_link_libraries(clog
	PUBLIC fmt
)
set_target_properties(fmt PROPERTIES FOLDER "CLog")

if(CLOG_BUILD_EXAMPLE)
	add_executable(example
		example/main.cpp
	)
	target_link_libraries(example
		PRIVATE clog
	)
	if (CMAKE_GENERATOR MATCHES "Visual Studio")
		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT example)
	endif()
endif()