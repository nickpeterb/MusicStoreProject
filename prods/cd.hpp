
#ifndef cd_hpp
#define cd_hpp

#include <stdio.h>
#include "physical.hpp"
using namespace std;

class CD : public Physical {
public:
	CD(string prodID, string title, string artist, int releaseYear, double price, int inStock);
	
	string getTitle();
	string getArtist();
	int getYear();
	double getPrice();
	int getInStock();
};

#endif /* cd_hpp */
