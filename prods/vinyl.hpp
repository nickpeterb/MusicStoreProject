
#ifndef vinyl_hpp
#define vinyl_hpp

#include <stdio.h>
#include "physical.hpp"

class Vinyl : public Physical{
public:
	Vinyl(string prodID, string title, string artist, int releaseYear, double price, int inStock);
	
	string getTitle();
	string getArtist();
	int getYear();
	double getPrice();
};

#endif /* vinyl_hpp */
