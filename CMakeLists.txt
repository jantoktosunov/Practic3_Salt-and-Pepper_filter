cmake_minimum_required(VERSION 2.8)
project(Practic3_Salt_and_Pepper_filter)

find_package( OpenCV REQUIRED )
add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} )