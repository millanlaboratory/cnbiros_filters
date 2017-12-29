cmake_minimum_required(VERSION 2.8.3)
project(cnbiros_filters)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS roscpp roslib pluginlib rosconsole
	filters sensor_msgs message_filters)

catkin_package(
  INCLUDE_DIRS 
	include
  LIBRARIES 
	cnbiros_filters
  CATKIN_DEPENDS 
	roscpp
	roslib
	rosconsole
	pluginlib
	filters
	sensor_msgs
  DEPENDS
)

include_directories(
	include
 ${catkin_INCLUDE_DIRS}
)

add_library(cnbiros_filters
	src/cnbiros_filters.cpp
	src/RangeToRangeFilterChain.cpp
)
target_link_libraries(cnbiros_filters ${catkin_LIBRARIES})

add_executable(range_to_range_filter_chain src/range_to_range_filter_chain.cpp)
target_link_libraries(range_to_range_filter_chain cnbiros_filters ${catkin_LIBRARIES})

add_executable(multi_range_to_range_filter_chain src/multi_range_to_range_filter_chain.cpp)
target_link_libraries(multi_range_to_range_filter_chain cnbiros_filters ${catkin_LIBRARIES})
