#ifndef CNBIROS_FILTERS_CPP
#define CNBIROS_FILTERS_CPP

#include "cnbiros_filters/RangeThresholdFilter.hpp"
#include "cnbiros_filters/RangeConsistencyFilter.hpp"
#include <pluginlib/class_list_macros.h>


PLUGINLIB_EXPORT_CLASS(cnbiros::range_filters::RangeThresholdFilter, filters::FilterBase<sensor_msgs::Range>)
PLUGINLIB_EXPORT_CLASS(cnbiros::range_filters::RangeConsistencyFilter, filters::FilterBase<sensor_msgs::Range>)

#endif
