
#ifndef album_hpp
#define album_hpp

#include <stdio.h>
#include "digital.hpp"
#include "song.hpp"
#include <vector>

class Album : public Digital {
	vector<Song*> songs;
public:
	Album(string prodID, string title, string artist, int releaseYear, double price, int numSold);
	
	Album(vector<Song*> songs, string prodID, string title, string artist, int releaseYear, double price, int numSold);
	
	string getTitle();
	string getArtist();
	int getYear();
	double getPrice();
};

#endif /* album_hpp */
