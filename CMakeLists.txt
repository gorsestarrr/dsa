cmake_minimum_required(VERSION 4.1)
project(dsa)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/problems/**/*.cpp"
        "${CMAKE_SOURCE_DIR}/templates/**/*.cpp"
)

foreach(src ${SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()
