#ifndef bmsearch_hpp
#define bmsearch_hpp

#include <stdio.h>
#include <string>
using namespace std;

class BmSearch {
	static const int NO_OF_CHARS = 256; //number of ascii values
public:
	int max(int a, int b);
	void badCharHeuristic(string pat, int patternLength, int badchar[NO_OF_CHARS]);
	int search_matches(string text, string pat);
};

#endif /* bmsearch_hpp */
