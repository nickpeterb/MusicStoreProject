
#include "digital.hpp"

Digital::Digital(){
	this->numSold = 0;
}

Digital::Digital(int numSold){
	this->numSold = numSold;
}

long Digital::getNumSold(){
	return this->numSold;
}
