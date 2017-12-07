#ifndef CNBIROS_FILTERS_RANGETHRESHOLDFILTER_HPP
#define CNBIROS_FILTERS_RANGETHRESHOLDFILTER_HPP

#include <filters/filter_base.h>

namespace cnbiros {
	namespace rangefilters {

template<typename T>
class RangeThresholdFilter: public filters::FilterBase <T> {

	public: 
		RangeThresholdFilter(void) {};
		~RangeThresholdFilter(void) {};

		bool configure(void) { return true; }
		bool update( const T& data_in, T& data_out);
};

template<typename T>
inline bool RangeThresholdFilter<T>::update(const T& data_in, T& data_out) {
	data_out = data_in;
	return true;
}

	}
}

#endif

