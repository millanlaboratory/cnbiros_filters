#include <ros/ros.h>
#include "cnbiros_filters/RangeToRangeFilterChain.hpp"

int main(int argc, char **argv) {
	ros::init(argc, argv, "range_to_range_filter_chain");
	
	cnbiros::range_filters::RangeToRangeFilterChain t;
	ros::spin();
	
	return 0;
}
