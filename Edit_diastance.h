#ifndef VERY_COOOL_AND_FAST_DNA_SEQUENCER_FOR_SEQUENCING_DNA_KPM_MATCHER_H
#define VERY_COOOL_AND_FAST_DNA_SEQUENCER_FOR_SEQUENCING_DNA_KPM_MATCHER_H
#include <string>

namespace DE {
	class Edit_diastance {

	public:
		Edit_diastance();

		int distance(const std::string &S, const std::string &R) const;
	};
} // DE

#endif //VERY_COOOL_AND_FAST_DNA_SEQUENCER_FOR_SEQUENCING_DNA_KPM_MATCHER_H
