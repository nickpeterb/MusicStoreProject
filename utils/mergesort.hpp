#ifndef mergesort_hpp
#define mergesort_hpp

#include <stdio.h>
#include <vector>
#include "product.hpp"
using namespace std;

class MergeSort{
public:
	enum sortBy {Price, Year};
	void merge(vector<Product*>& products, int l, int middle, int r, sortBy sortby);
	void sort(vector<Product*> &products, int left, int right, sortBy sortby);
};

#endif /* mergesort_hpp */
