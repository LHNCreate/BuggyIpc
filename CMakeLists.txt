cmake_minimum_required(VERSION 3.29)
project(OneIpc)

find_package(cppzmq)
set(CMAKE_CXX_STANDARD 20)

include_directories(interface)

# target
add_library(OneIpc SHARED "")
set_target_properties(OneIpc PROPERTIES OUTPUT_NAME "OneIpcFoundation")

file(GLOB_RECURSE src "src/*.cpp")
file(GLOB_RECURSE header "interface/*.hpp")
target_sources(OneIpc PRIVATE
        ${src}
        ${header}
)

#test
add_executable(pub pub.cpp)
target_link_libraries(pub PRIVATE cppzmq OneIpc)

add_executable(sub sub.cpp)
target_link_libraries(sub PRIVATE cppzmq )

add_executable(inproc inproc.cpp)
target_link_libraries(inproc PRIVATE cppzmq )

