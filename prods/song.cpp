
#include "song.hpp"

Song::Song(string prodID, string title, string artist, int releaseYear, double price, int numSold){
	this->prodID = prodID;
	this->title = title;
	this->artist = artist;
	this->releaseYear = releaseYear;
	this->price = price;
	this->numSold = numSold;
}

string Song::getTitle(){ return this->title; }
string Song::getArtist(){ return this->artist; }
int Song::getYear(){ return this->releaseYear; }
double Song::getPrice(){ return this->price; }
