#include <ros/ros.h>
#include "cnbiros_filters/RangeToRangeFilterChain.hpp"

int main(int argc, char **argv) {
	ros::init(argc, argv, "multi_range_to_range_filter_chain");

	std::vector<std::string> topics;
	std::vector<cnbiros::range_filters::RangeToRangeFilterChain*> filters;
	ros::NodeHandle nh("~");
	
	if(nh.getParam("topic_list", topics) == false) {
		ROS_ERROR("Topic list is required for the multi range version");
		ros::shutdown();
	}
	 
	for(auto it = topics.begin(); it!=topics.end(); ++it) {
		filters.push_back(new cnbiros::range_filters::RangeToRangeFilterChain((*it).c_str()));
	}

	ros::spin();
	
	for(auto it = filters.begin(); it!=filters.end(); ++it)
		delete (*it);

	return 0;
}
