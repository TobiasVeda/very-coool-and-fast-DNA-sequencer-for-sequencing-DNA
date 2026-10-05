//
// Created by Vetle on 05.10.2026.
//

#include "Edit_diastance.h"

#include <string>

namespace DE {

	Edit_diastance::Edit_diastance() = default;

	int Edit_diastance::distance(const std::string &S, const std::string &R) const {
		int s_len = S.length() + 1;
		int r_len = R.length() + 1;

		int *DP = (int*)malloc(r_len * s_len * sizeof(int));

		for (int i = 0; i < s_len; i++)
		{
			DP[i*r_len] = i;
		}

		for (int j = 0; j < r_len; j++)
		{
			DP[j] = j;
		}
		
		for (int j = 1; j < r_len; j++)
		{
			for (int i = 1; i < s_len; i++)
			{
				int top = DP[j + (i-1)*r_len];
				int left = DP[(j-1) + i*r_len];
				int corner = DP[(j-1) + (i-1)*r_len];

				int cross_min = left < top ? left : top;
				int result;
				
				if (cross_min >= corner)
				{
					if (S[i-1] == R[j-1])
					{
						result = corner;
					} else {
						result = corner + 1;
					}
					
				} else {
					 result = cross_min + 1;
				}

				DP[j + i*r_len] = result;
			}
		}

		return DP[(r_len) * (s_len) - 1];
	}
} // DE