cmake_minimum_required(VERSION 3.16)

project(EnderStrap VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(JNI REQUIRED)

qt5_wrap_cpp(MOC_SRCS login.h)
qt5_wrap_ui(UI_HEADERS login.ui)

add_executable(strap strap.cpp login.cpp ${MOC_SRCS} ${UI_HEADERS})

target_link_libraries(strap Qt5::Widgets jsoncpp curl ${JNI_LIBRARIES})
target_include_directories(strap PRIVATE ${JNI_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
