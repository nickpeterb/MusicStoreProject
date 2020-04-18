#ifndef product_hpp
#define product_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Product {
protected:
	string prodID;
	string title;
	string artist;
	int releaseYear;
	double price;
public:
	virtual string getTitle() = 0;
	virtual string getArtist() = 0;
	virtual int getYear() = 0;
	virtual double getPrice() = 0;
	
	void toString();
	
};

#endif /* product_hpp */
