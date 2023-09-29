/*
Created by  : Vaisakh Dileep
Date        : 26, September, 2023
Description : Class declaration for FilterV2 class.
*/

#ifndef _FILTERV2_HPP_
#define _FILTERV2_HPP_

#include<vector>

using namespace std;

template<typename T>
class AND_Specification; // Forward declaring AND_Specification template class.

template<typename T>
class Specification {
public:
    virtual bool is_satisfied(T *entity) const = 0;

    AND_Specification<T> operator&&(Specification&& other) {
        return AND_Specification<T> {*this, other};
    }
    AND_Specification<T> operator&&(Specification &other) {
        return AND_Specification<T> {*this, other};
    }
};

template<typename T>
class AND_Specification: public Specification<T> {
public:
    Specification<T> &first, &second;

    AND_Specification(Specification<T> &first, Specification<T> &second): first {first}, second {second} {
    }

    virtual bool is_satisfied(T *entity) const {
        return (first.is_satisfied(entity) and second.is_satisfied(entity));
    }
};

template<typename T>
class Colour_Specification: public Specification<T> {
public:
    COLOUR colour_spec;

    Colour_Specification(const COLOUR colour_spec): colour_spec {colour_spec} {
    }

    virtual bool is_satisfied(T *entity) const {
        return (entity->product_colour == colour_spec );
    }
};

template<typename T>
class Size_Specification: public Specification<T> {
public:
    SIZE size_spec;

    Size_Specification(const SIZE size_spec): size_spec {size_spec} {
    }

    virtual bool is_satisfied(T *entity) const {
        return (entity->product_size == size_spec );
    }
};

template<typename T>
class Transport_Specification: public Specification<T> {
public:
    TRANSPORT transport_spec;

    Transport_Specification(const TRANSPORT transport_spec): transport_spec {transport_spec} {
    }

    virtual bool is_satisfied(T *entity) const {
        return (entity->transport_size == transport_spec );
    }
}; // Notice here in order to add TRANSPORTATION filter, we only need to add a single class. Code did not expand here, but rather we extended the behaviour to incorporate this new filter spec.

template<typename T>
class FilterV2 {
public:
    virtual vector<T *> filter(vector<T *> collection, const Specification<T> &spec) {
        vector<T *> result {};

        for(auto &item: collection) {
            if(spec.is_satisfied(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};

#endif