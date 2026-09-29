#include <iostream>
#include <fstream>
#include <chrono>
#include "KPM_matcher.h"



int main() {
	auto start = std::chrono::steady_clock::now();

	std::cout <<"Starting..." <<std::endl;
	std::string adapter = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";

	auto matcher = new KPM::KPM_matcher();
	matcher->construct_LPS(adapter);

	std::fstream myFile("dna_files/s_3_sequence_1M.txt");
	std::string dna;
	std::string buffer;
	int count = 0;

	while (getline (myFile, dna)) {
		int match_start = matcher->compare(dna);
		if (match_start != -1) {
			count++;
			buffer.append("Match at position " + std::to_string(match_start) + " for: " + dna + "\n");
			// std::cout <<"Match at position " << match_start <<" for: " <<dna <<"\n";
		}
	}
	std::cout <<buffer <<std::endl;
	std::cout <<"Found " <<count <<" matches" <<std::endl;

	delete matcher;
	myFile.close();

	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time: " << elapsed.count() << " s\n";

	return 0;
}
