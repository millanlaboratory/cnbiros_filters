#ifndef CNBIROS_FILTERS_RANGECONSISTENCYFILTER_HPP
#define CNBIROS_FILTERS_RANGECONSISTENCYFILTER_HPP

#include <filters/filter_base.h>
#include <std_msgs/Empty.h>
#include <sensor_msgs/Range.h>

#define CNBIROS_FILTERS_RANGE_CONSISTENCY_TIME		1.0f

namespace cnbiros {
	namespace range_filters {

class RangeConsistencyFilter: public filters::FilterBase <sensor_msgs::Range> {

	public: 
		RangeConsistencyFilter(void) {};
		~RangeConsistencyFilter(void) {};

		virtual bool configure(void);
		virtual bool update(const sensor_msgs::Range& data_in, sensor_msgs::Range& data_out);

	public:
		ros::Time last_time_outrange_;
		ros::Time current_time_;
		double consistency_time_;
		double elapsed_time_;

};

bool RangeConsistencyFilter::configure(void) {

	// Initialization
	this->last_time_outrange_ = ros::Time::now();

	this->consistency_time_ = CNBIROS_FILTERS_RANGE_CONSISTENCY_TIME;
	this->getParam("consistency_time", this->consistency_time_);

	return true;
}

bool RangeConsistencyFilter::update(const sensor_msgs::Range& data_in, sensor_msgs::Range& data_out) {


	if( (data_in.max_range == 0.0f) ) {
		ROS_WARN("Consistency filter cannot be applied on Range messages without max_range fields");
		return true;
	}
	
	// Coping the input message
	data_out = data_in;

	// Getting current time
	this->current_time_ = ros::Time::now();

	// Consider max_range as no detection. Store the current time it occured
	if(data_out.range >= data_out.max_range) {
		this->last_time_outrange_ = this->current_time_;
	}

	// Computing elapsed time
	this->elapsed_time_ = (this->current_time_ - this->last_time_outrange_).toSec();

	// If the elapsed time is less than the consistency_time set,
	// then consider not valid the current range value and replace it with the
	// maximum value
	if(this->elapsed_time_ <= this->consistency_time_) {
		data_out.range = data_out.max_range;
	}


	return true;
}

	}
}

#endif

