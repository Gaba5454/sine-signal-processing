cmake_minimum_required(VERSION 3.10)
project(SineSignalProcessing VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

set(SOURCES
    src/main.cpp
    include/sine_generator.cpp
    include/quantization.cpp
    include/interpolation.cpp
    include/tests.cpp
)

set(HEADERS
    include/const.h
    include/sine_generator.h
    include/quantization.h
    include/interpolation.h
    include/tests.h
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/results)


file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/results)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")