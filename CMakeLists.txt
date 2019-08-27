cmake_minimum_required(VERSION 2.8)

project(v4l)

include_directories("/home/tangzhihua/gitlab/zed/v4l/include")
add_executable(v4l src/main.cpp src/v4l.cpp)

target_link_libraries(v4l)





