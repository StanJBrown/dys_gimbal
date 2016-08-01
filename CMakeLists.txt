CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
PROJECT(dys_gimbal)

FIND_PACKAGE(catkin REQUIRED COMPONENTS
  roscpp
  serial
  std_msgs
  keyboard
  sensor_msgs
)

INCLUDE_DIRECTORIES(
  ${catkin_INCLUDE_DIRS}
)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/SBGC_lib
)

LINK_DIRECTORIES(
    /usr/local/lib
    /usr/lib
)

ADD_LIBRARY(SBGC src/SBGC_cmd_helpers.cpp)

ADD_EXECUTABLE(serial_test src/serial_test.cpp)
TARGET_LINK_LIBRARIES(
    serial_test
    ${catkin_LIBRARIES}
    SBGC
)
