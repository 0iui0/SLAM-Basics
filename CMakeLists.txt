cmake_minimum_required(VERSION 3.23)
project(SLAM-Basics)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(OpenCV REQUIRED QUIET)
include_directories(
        include
        ${OpenCV_INCLUDE_DIRS}
        ${CERES_INCLUDE_DIRS}
)
include_directories("/opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3")

link_directories(
        include
        ${OpenCV_LIBRARIES}
)

add_executable(Eigen-Base src/Eigen-Base.cpp)

add_executable(PointDist
        include/header.h
        src/PointDist.cpp)
add_executable(PoseInterpolation
        include/header.h
        src/PoseInterpolation.cpp)
add_executable(PlaneFitting
        include/header.h
        src/PlaneFitting.cpp)
add_executable(GridMap
        include/header.h
        src/GridMap.cpp)
add_executable(CeresDemo
        include/header.h
        src/CeresDemo.cpp)
target_link_libraries(CeresDemo ${CERES_LIBRARIES})
