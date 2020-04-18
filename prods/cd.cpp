
#include "cd.hpp"
using namespace std;

CD::CD(string prodID, string title, string artist, int releaseYear, double price, int inStock){
	this->prodID = prodID;
	this->title = title;
	this->artist = artist;
	this->releaseYear = releaseYear;
	this->price = price;
	this->inStock = inStock;
}

string CD::getTitle(){ return this->title; }
string CD::getArtist(){ return this->artist; }
int CD::getYear(){ return this->releaseYear; }
double CD::getPrice(){ return this->price; }
int CD::getInStock(){ return this->inStock; }
