# minimum requirement
cmake_minimum_required(VERSION 3.5)

# solution
project(sampleSolution)

SET(NORMAL_TARGET loadExperiment)

# build NORMAL_TARGET from source code
add_executable(${NORMAL_TARGET} main.cpp load.cpp)


if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm.*|ARM.*)")
	target_compile_options(${NORMAL_TARGET} PUBLIC "-mfpu=neon")
endif()

