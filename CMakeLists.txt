cmake_minimum_required(VERSION 3.15)
project(ChessEngineCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)
find_package(OpenCL REQUIRED)
find_package(SDL2 REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

include_directories(${SDL2_TTF_INCLUDE_DIRS})  # <-- AJOUT
link_directories(${SDL2_TTF_LIBRARY_DIRS})     # <-- AJOUT

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    lib/*.cpp
)

add_executable(chess_engine ${SRC_FILES})

target_include_directories(chess_engine
    PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}  # <-- AJOUT
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/lib
)

target_link_libraries(chess_engine
    OpenMP::OpenMP_CXX
    MPI::MPI_CXX
    OpenCL::OpenCL
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}      # <-- AJOUT
)
