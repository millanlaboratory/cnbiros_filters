#ifndef CNBIROS_FILTERS_RANGETORANGEFILTERCHAIN_HPP
#define CNBIROS_FILTERS_RANGETORANGEFILTERCHAIN_HPP

#include <functional>
#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <message_filters/subscriber.h>
#include <filters/filter_chain.h>

namespace cnbiros {
	namespace range_filters {

class RangeToRangeFilterChain {

	public:
		RangeToRangeFilterChain(const std::string& topic = "/range");
		~RangeToRangeFilterChain(void);
	
		void callback(const sensor_msgs::Range::ConstPtr& msg_in);
			

	protected:
		ros::NodeHandle nh_;
  		ros::NodeHandle private_nh_;

  		filters::FilterChain<sensor_msgs::Range> filter_chain_;

  		sensor_msgs::Range msg_;
  		ros::Publisher	pub_;
  		message_filters::Subscriber<sensor_msgs::Range> sub_;
	
};


	}
}


#endif
