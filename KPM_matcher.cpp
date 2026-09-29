//
// Created by Tobias on 29.09.2026.
//

#include "KPM_matcher.h"

#include <string>

namespace KPM {

	KPM_matcher::KPM_matcher() = default;

	void KPM_matcher::construct_LPS(const std::string& pattern) {
		_pattern = pattern;
		_LPS.resize(pattern.length());
		_LPS[0] = 0;
		int len = 0;

		for (int i = 1; i < pattern.length(); ++i) {

			// Case 1: increment len and store it at lps[i]
			if (pattern[i] == pattern[len]) {
				_LPS[i] = ++len;
				continue;
			}
			// Case 2: No previous matches, and no new matches. Set lps[i] = 0
			if (pattern[i] != pattern[len] && len == 0) {
				_LPS[i] = 0;
				continue;
			}
			// Case 3: Current i doesnt match/cant extend lps. Might be a smaller prefix that matches current suffix.
			// Walk backwards to find a smaller prefix that matches current suffix.
			if (pattern[i] != pattern[len] && len > 0) {
				while (true) {
					if (pattern[i] == pattern[len]) {
						_LPS[i] = ++len;
						break;
					}
					if (len == 0) {
						break; // check for zero before it might be assigned
					}
					_LPS[i] = 0;
					len = _LPS[len - 1];

				}
			}
		}
	}


	int KPM_matcher::compare(const std::string& text) const {

		int i = 0;
		int j = 0;
		int match_start = -1;

		while (i < text.length()) {
			match_start = i - j; // match_start + j is the number of currently matched chars
			if (text[i] == _pattern[j]) {
				++i;
				++j;

				if (j == _pattern.length()) {
					return match_start;
				}

				if (i == text.length()) {
					return match_start;
				}

			} else if (j != 0) {
				j = _LPS[j - 1];
			} else {
				++i;
			}
		}
		match_start = -1;
		return match_start;
	}


} // KPM