/*
Created by  : Vaisakh Dileep
Date        : 26, September, 2023
Description : Class declaration for FilterV1 class.
*/

#ifndef _FILTERV1_HPP_
#define _FILTERV1_HPP_

#include<vector>

using namespace std;

template<typename T>
class FilterV1 {
public:
    vector<T *> filter_by_colour(vector<T *> collection, COLOUR colour_spec) {
        vector<T *> result {};
        for(auto &item: collection) {
            if(item->product_colour == colour_spec) {
                result.push_back(item);
            }
        }
        return result;
    }

    vector<T *> filter_by_size(vector<T *> collection, SIZE size_spec) {
        vector<T *> result {};
        for(auto &item: collection) {
            if(item->product_size == size_spec) {
                result.push_back(item);
            }
        }
        return result;
    }

    vector<T *> filter_by_colour_and_size(vector<T *> collection, COLOUR colour_spec, SIZE size_spec) {
        vector<T *> result {};
        for(auto &item: collection) {
            if((item->product_colour == colour_spec) and (item->product_size == size_spec)) {
                result.push_back(item);
            }
        }
        return result;
    }
/*
Suppose if we want to add a filter for TRANSPORTATION. We need to add 4 new functions which are:
1. filter_by_transportation()
2. filter_by_colour_and_transportation()
3. filter_by_size_and_transportation()
4. filter_by_colour_size_and_transportation()
*/
};

#endif