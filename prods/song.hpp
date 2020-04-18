
#ifndef song_hpp
#define song_hpp

#include <stdio.h>
#include "digital.hpp"

class Song : public Digital{
public:
	Song(string prodID, string title, string artist, int releaseYear, double price, int numSold);
	
	string getTitle();
	string getArtist();
	int getYear();
	double getPrice();
};

#endif /* song_hpp */
