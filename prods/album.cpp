
#include "album.hpp"

Album::Album(string prodID, string title, string artist, int releaseYear, double price, int numSold){
	this->prodID = prodID;
	this->title = title;
	this->artist = artist;
	this->releaseYear = releaseYear;
	this->price = price;
	this->numSold = numSold;
}

Album::Album(vector<Song*> songs, string prodID, string title, string artist, int releaseYear, double price, int numSold){
	this->songs = songs;
	this->prodID = prodID;
	this->title = title;
	this->artist = artist;
	this->releaseYear = releaseYear;
	this->price = price;
	this->numSold = numSold;
}

string Album::getTitle(){ return this->title; }
string Album::getArtist(){ return this->artist; }
int Album::getYear(){ return this->releaseYear; }
double Album::getPrice(){ return this->price; }
