cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

project(keno)

add_executable(
  keno
  src/main.cpp
  src/GetData.cpp
  src/KenoBet.cpp
)