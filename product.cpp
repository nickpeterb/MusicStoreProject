#include <iostream>
#include "product.hpp"
using namespace std;

void Product::toString(){
	cout << getArtist() << " - " << getTitle() << " (" << getYear() << ")" << " : $" << getPrice() << endl;
}
