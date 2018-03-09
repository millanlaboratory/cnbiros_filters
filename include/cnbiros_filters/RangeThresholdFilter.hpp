#ifndef CNBIROS_FILTERS_RANGETHRESHOLDFILTER_HPP
#define CNBIROS_FILTERS_RANGETHRESHOLDFILTER_HPP

#include <filters/filter_base.h>
#include <std_msgs/Empty.h>
#include <sensor_msgs/Range.h>

#define CNBIROS_FILTERS_RANGE_LOWER_THRESHOLD		0.0f
#define CNBIROS_FILTERS_RANGE_LOWER_REPLACE_VALUE	0.0f
#define CNBIROS_FILTERS_RANGE_UPPER_REPLACE_VALUE	10.0f

namespace cnbiros {
	namespace range_filters {

class RangeThresholdFilter: public filters::FilterBase <sensor_msgs::Range> {

	public: 
		RangeThresholdFilter(void) {};
		~RangeThresholdFilter(void) {};

		virtual bool configure(void);
		virtual bool update(const sensor_msgs::Range& data_in, sensor_msgs::Range& data_out);

	public:
		double	upper_threshold_;
		double	lower_threshold_;
};

bool RangeThresholdFilter::configure(void) {


	if(this->getParam("upper_threshold", this->upper_threshold_) == false) {
		ROS_ERROR("upper_threshold parameter is required");
		return false;
	}

	this->lower_threshold_ = CNBIROS_FILTERS_RANGE_LOWER_THRESHOLD;
	this->getParam("lower_threshold", this->lower_threshold_);

	return true;
}

bool RangeThresholdFilter::update(const sensor_msgs::Range& data_in, sensor_msgs::Range& data_out) {

	data_out = data_in;
	if( (data_in.min_range == 0.0f) && (data_in.max_range == 0.0f) ) {
		ROS_WARN("Threshold filter cannot be applied on Range messages without min_range and max_range fields");
		return true;
	  }


	if(data_in.range >= this->upper_threshold_) {
		data_out.range = data_in.max_range;
	} else if(data_in.range <= this->lower_threshold_) {
		//data_out.range = data_in.min_range;
		data_out.range = data_in.max_range;
	} else {
		data_out.range = data_in.range;
	}

	return true;
}

	}
}

#endif

