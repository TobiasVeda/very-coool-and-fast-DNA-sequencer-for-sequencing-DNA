#include <string>

bool has_3_adapter(const std::string &dna, const std::string &adapter, int &match_start) {

	int global_i = 0;
	int i = 0;
	int j = 0;
	match_start = -1;


	while (global_i < dna.length()) {


		i = global_i;
		j = 0;

		while (dna[i] != '\0' && j < adapter.length()) {

			if (dna[i] == adapter[j]) {
				match_start = global_i;
				i++;
				j++;
			} else {
				match_start = -1;
				break;
			}

		}

		if (match_start != -1) {
			return true;
		}

		global_i++;
	}

	return false;
}
