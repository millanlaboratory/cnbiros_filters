#ifndef CNBIROS_FILTERS_RANGEINTERPOLATION_CPP
#define CNBIROS_FILTERS_RANGEINTERPOLATION_CPP

#include "cnbiros_filters/RangeInterpolationFilter.hpp"

namespace cnbiros {
	namespace filters {

RangeInterpolationFilter::RangeInterpolationFilter(void) {
}

template<typename T>
RangeInterpolationFilter::~RangeInterpolationFilter(void) {
}

bool RangeInterpolationFilter::configure(void) {
	return true;
}

bool RangeInterpolationFilter::update(const int& data_in, int& data_out) {

	data_out = data_in;
	return true;
}

PLUGINLIB_REGISTER_CLASS(RangeInterpolationFilterInt, cnbiros::filters::RangeInterpolationFilter<int>, filters::FilterBase<int>)

	}
}

#endif
