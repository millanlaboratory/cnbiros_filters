#ifndef CNBIROS_FILTERS_RANGEINTERPOLATION_HPP
#define CNBIROS_FILTERS_RANGEINTERPOLATION_HPP

#include <stdio.h>
#include <filters/filter_base.h>
#include <pluginlib/class_list_macros.h>

namespace cnbiros {
	namespace filters {

class RangeInterpolationFilter: public filters::FilterBase <int> {

	public: 
		RangeInterpolationFilter(void);
		~RangeInterpolationFilter(void);

		virtual bool configure(void);
		virtual bool update( const T& data_in, T& data_out);
};

	}
}

#endif
