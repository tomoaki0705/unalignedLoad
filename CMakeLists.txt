# minimum requirement
cmake_minimum_required(VERSION 3.6)

# solution
project(sampleSolution)

SET(NORMAL_TARGET programNormal)
SET(STRICT_TARGET programStrict)

# build NORMAL_TARGET from source code
add_executable(${NORMAL_TARGET} main.cpp load.cpp)
add_executable(${STRICT_TARGET} main.cpp load.cpp)


if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm.*|ARM.*)")
	set(ARM 1)
	target_compile_options(${NORMAL_TARGET} PUBLIC "-mfpu=neon")
	target_compile_options(${STRICT_TARGET} PUBLIC "-mfpu=neon -fstack-protector-strong")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64)")
	set(AARCH64 1)
	target_compile_options(${STRICT_TARGET} PUBLIC "-fstack-protector-strong")
else ()
	set(X86 1)
endif()

