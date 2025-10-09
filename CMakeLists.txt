# ----- CMake configuration ----- #
cmake_minimum_required(VERSION 3.15)
project(chess_engine LANGUAGES CXX)
enable_testing()

# ----- Set C++ standard ----- #
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ----- Find packages ----- #
find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)
find_package(OpenCL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

# ----- Include directories ----- #
include_directories(${SDL2_TTF_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_MIXER_INCLUDE_DIRS})

# ----- Link directories ----- #
link_directories(${SDL2_TTF_LIBRARY_DIRS})
link_directories(${SDL2_IMAGE_LIBRARY_DIRS})
link_directories(${SDL2_MIXER_LIBRARY_DIRS})

# ----- Source files ----- #
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    lib/*.cpp
)

# ----- Build target ----- #
add_executable(chess_engine ${SRC_FILES})

# ----- Target properties ----- #
target_include_directories(chess_engine
    PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/lib
)

target_link_libraries(chess_engine
    OpenMP::OpenMP_CXX
    MPI::MPI_CXX
    OpenCL::OpenCL
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)

# ----- Post-build commands ----- #
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            ${CMAKE_BINARY_DIR}/assets
)

# ----- Tests ----- #

# ----- Installation ----- #
