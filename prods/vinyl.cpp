
#include "vinyl.hpp"

Vinyl::Vinyl(string prodID, string title, string artist, int releaseYear, double price, int inStock){
	this->prodID = prodID;
	this->title = title;
	this->artist = artist;
	this->releaseYear = releaseYear;
	this->price = price;
	this->inStock = inStock;
}

string Vinyl::getTitle(){ return this->title; }
string Vinyl::getArtist(){ return this->artist; }
int Vinyl::getYear(){ return this->releaseYear; }
double Vinyl::getPrice(){ return this->price; }
