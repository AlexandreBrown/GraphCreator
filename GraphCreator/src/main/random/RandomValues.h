#ifndef GRAPHCREATOR_SRC_MAIN_RANDOM_RANDOMVALUES_H_
#define GRAPHCREATOR_SRC_MAIN_RANDOM_RANDOMVALUES_H_

#include <cstdlib>

class RandomValues {

	public:
		static size_t random(size_t fromInclusive, size_t toInclusive) {
			return static_cast<size_t>(rand()%(toInclusive - fromInclusive + 1) + fromInclusive);
		}
};

#endif
