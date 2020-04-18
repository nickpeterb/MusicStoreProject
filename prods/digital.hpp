

#ifndef digital_hpp
#define digital_hpp

#include <stdio.h>
#include "../product.hpp"

class Digital : public Product {
protected:
	long numSold; //total digital copies sold
public:
	Digital();
	
	Digital(int numSold);
	
	virtual long getNumSold();
};

#endif /* digital_hpp */
