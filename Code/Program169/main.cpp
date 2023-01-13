/*
Created by  : Vaisakh Dileep
Date        : 6, November, 2022
Description : This program helps to understand open-closed principle in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

// Open-closed principle states that classes should be open for extension, closed for modification.

enum class COLOUR {VIOLET, PURPLE, BLUE, WHITE};

enum class SIZE {SMALL, REGULAR, LARGE};

enum class TRANSPORT {AIR, WATER, LAND};

struct Product
{
    string product_name;

    COLOUR product_colour;

    SIZE product_size;


};

using Product_List = vector<Product *>;

class Product_Filter_V1
{
public:
    static Product_List filter_by_colour(Product_List items, const COLOUR filter_colour)
    {
        Product_List result {};

        for(int i {0}; i < items.size(); i++)
        {
            if(items[i]->product_colour == filter_colour)
            {
                result.push_back(items[i]);
            }
        }

        return result;
    }

    static Product_List filter_by_size(Product_List items, const SIZE filter_size)
    {
        Product_List result {};

        for(int i {0}; i < items.size(); i++)
        {
            if(items[i]->product_size == filter_size)
            {
                result.push_back(items[i]);
            }
        }

        return result;
    }

    static Product_List filter_by_size_and_colour(Product_List items, const SIZE filter_size, const COLOUR filter_colour)
    {
        Product_List result {};

        for(int i {0}; i < items.size(); i++)
        {
            if((items[i]->product_colour == filter_colour) and (items[i]->product_size == filter_size))
            {
                result.push_back(items[i]);
            }
        }

        return result;
    }
};

template<typename T>
class Specification
{
public:
    virtual bool is_satisfied(T *item) const = 0;

    virtual ~Specification() {};
};

class Colour_Specification_Product : public Specification<Product>
{
public:
    COLOUR spec_colour;

    Colour_Specification_Product(COLOUR spec_colour) : spec_colour {spec_colour} {}

    bool is_satisfied(Product *prod)  const
    {
        return prod->product_colour == spec_colour;
    }
};

class Size_Specification_Product : public Specification<Product>
{
public:
    SIZE spec_size;

    Size_Specification_Product(SIZE spec_size) : spec_size {spec_size} {}

    bool is_satisfied(Product *prod) const
    {
        return prod->product_size == spec_size;
    }
};

template<typename T>
class And_Two_Specification_Product : public Specification<T>
{
public:
    Specification<T> first, second;

    And_Two_Specification_Product(Specification<T> first, Specification<T> second) : first {first}, second {second} {}

    bool is_satisfied(T *item) const
    {
        return (first.is_satisfied() and second.is_satisfied());
    }
};

template<typename T>
And_Two_Specification_Product<T> operator&&(Specification<T> &first, Specification<T> &second)
{
    return And_Two_Specification_Product<T> {first, second};
}

template<typename T>
class Filter
{
public:
    virtual vector<T *> filter(vector<T *> items, const Specification<T> &spec) = 0;
};

class Product_Filter_V2 : Filter<Product>
{
public:
    Product_List filter(Product_List items, const Specification<Product> &spec)
    {
        Product_List result {};

        for(int i {0}; i < items.size(); i++)
        {
            if(spec.is_satisfied(items[i]))
            {
                result.push_back(items[i]);
            }
        }

        return result;
    }
};

int main()
{
    Product_List prod_list_1 {new Product {"prod_1", COLOUR::BLUE, SIZE::SMALL}, new Product {"prod_2", COLOUR::BLUE, SIZE::REGULAR}, new Product {"prod_3", COLOUR::PURPLE, SIZE::SMALL}};

    cout<<"Product_Filter::filter_by_colour(prod_list_1, COLOUR::BLUE)                      : ";
    for(auto &prod_iter : Product_Filter_V1::filter_by_colour(prod_list_1, COLOUR::BLUE))
    {
        cout<<(prod_iter->product_name)<<" ";
    }
    cout<<"\n";

    cout<<"Product_Filter::filter_by_size(prod_list_1, SIZE::SMALL)                         : ";
    for(auto &prod_iter : Product_Filter_V1::filter_by_size(prod_list_1, SIZE::SMALL))
    {
        cout<<(prod_iter->product_name)<<" ";
    }
    cout<<"\n";


    cout<<"Product_Filter::filter_by_size_and_colour(prod_list_1, SIZE::SMALL, COLOUR::BLUE): ";
    for(auto &prod_iter : Product_Filter_V1::filter_by_size_and_colour(prod_list_1, SIZE::SMALL, COLOUR::BLUE))
    {
        cout<<(prod_iter->product_name)<<" ";
    }
    cout<<"\n\n";

    Product_List prod_list_2 {new Product {"prod_4", COLOUR::BLUE, SIZE::LARGE}, new Product {"prod_5", COLOUR::BLUE, SIZE::REGULAR}, new Product {"prod_6", COLOUR::WHITE, SIZE::LARGE}};

    Product_Filter_V2 prod_filter_v2 {};

    cout<<"prod_filter_v2.filter(prod_list_2, Colour_Specification_Product {COLOUR::BLUE})  : ";
    for(auto &prod_iter : prod_filter_v2.filter(prod_list_2, Colour_Specification_Product {COLOUR::BLUE}))
    {
        cout<<(prod_iter->product_name)<<" ";
    }
    cout<<"\n";

    cout<<"prod_filter_v2.filter(prod_list_2, Size_Specification_Product {SIZE::LARGE})     : ";
    for(auto &prod_iter : prod_filter_v2.filter(prod_list_2, Size_Specification_Product {SIZE::LARGE}))
    {
        cout<<(prod_iter->product_name)<<" ";
    }

/*
    for(auto &prod_iter : prod_filter_v2.filter(prod_list_2, Size_Specification_Product {SIZE::LARGE} && Colour_Specification_Product {COLOUR::BLUE})) // This will given an error, since we are using temporary objects.
    {
        cout<<(prod_iter->product_name)<<" ";
    }
*/

    Colour_Specification_Product blue_colour_specifier {COLOUR::BLUE};

    Size_Specification_Product large_size_specifier {SIZE::LARGE};

    And_Two_Specification_Product<Product> blue_and_large_size_specifier {blue_colour_specifier && large_size_specifier};

    for(auto &prod_iter : prod_filter_v2.filter(prod_list_2, blue_colour_specifier && large_size_specifier))
    {
        
    }

    return 0;
}