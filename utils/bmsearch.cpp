#include "bmsearch.hpp"
//Implementation of Boyer Moore Search

//get the maximum of 2 integers, utility function
int BmSearch::max(int a, int b) { return (a > b) ? a : b; }

//preprocessing function
void BmSearch::badCharHeuristic(string pat, int patternLength, int badchar[NO_OF_CHARS]) {
	for (int i = 0; i < NO_OF_CHARS; i++) {
		badchar[i] = -1; //sets all possible char values to -1
	}
	for (int i = 0; i < patternLength; i++) {
		badchar[(int)pat[i]] = i; //converts letter to ascii value, stores i in badchar[] at that index
	}
}

int BmSearch::search_matches(string text, string pat) {

	int patternLength = pat.length() * 1.0;
	int textLength = text.length() * 1.0;

	int matches = 0;

	int badchar[NO_OF_CHARS];
	
	badCharHeuristic(pat, patternLength, badchar); //fill badchar[] for given pattern

	int shift = 0; //shift of the pattern with respect to text
	int j = patternLength - 1; //last index of pattern

	while (shift <= (textLength - patternLength)) {
		while (j >= 0 && pat[j] == text[shift + j]) { //start searching for matching chars from the right
			j--;
		}
		if (j < 0) {
			//shift pattern to align next charachter in text with its last occurence in pattern
			shift += (shift + patternLength < textLength) ? patternLength - badchar[text[shift + patternLength]] : 1;
			matches++;
		}
		else {
			//shift pattern to align bad charachter in text with its last occurence in pattern
			shift += max(1, j - badchar[text[shift + j]]);
		}
	}
	return matches;
}
