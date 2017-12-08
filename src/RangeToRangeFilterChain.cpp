#ifndef CNBIROS_FILTERS_RANGETORANGEFILTERCHAIN_CPP
#define CNBIROS_FILTERS_RANGETORANGEFILTERCHAIN_CPP

#include "cnbiros_filters/RangeToRangeFilterChain.hpp"

namespace cnbiros {
	namespace range_filters {

RangeToRangeFilterChain::RangeToRangeFilterChain(const std::string& topic) :
		private_nh_("~"), 
		filter_chain_("sensor_msgs::Range") {


		this->sub_.subscribe(this->nh_, topic, 50);
		this->filter_chain_.configure("range_filter_chain", this->private_nh_);

		this->sub_.registerCallback(boost::bind(&RangeToRangeFilterChain::callback, this, _1));
		this->pub_ = this->nh_.advertise<sensor_msgs::Range>(topic+"_filtered", 1000);
}	


RangeToRangeFilterChain::~RangeToRangeFilterChain(void) {
}

void RangeToRangeFilterChain::callback(const sensor_msgs::Range::ConstPtr& msg_in) {
	// Run the filter chain
    if (this->filter_chain_.update(*msg_in, this->msg_))
    {
      //only publish result if filter succeeded
      this->pub_.publish(this->msg_);
    }
}

	}
}

#endif
