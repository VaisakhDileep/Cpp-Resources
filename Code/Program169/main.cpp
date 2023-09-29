/*
Created by  : Vaisakh Dileep
Date        : 26, September, 2023
Description : This program helps to understand open-closed principle in C++.
*/

#include<iostream>

#include<vector>

enum class COLOUR    {RED, GREEN, BLUE};
enum class SIZE      {SMALL, REGULAR, LARGE};
enum class TRANSPORT {LAND, WATER, AIR};

#include "FilterV1.hpp"
#include "FilterV2.hpp"

using namespace std;

// open-closed principle states that classes should be open for extension, closed for modification.

struct Product {
    string product_name;
    COLOUR product_colour;
    SIZE product_size;
    TRANSPORT transport_size;
};

using Product_List = vector<Product *>;

int main() {
    Product_List prod_list_1 {new Product {"prod_1", COLOUR::RED, SIZE::SMALL, TRANSPORT::LAND},
                              new Product {"prod_2", COLOUR::GREEN, SIZE::REGULAR, TRANSPORT::WATER},
                              new Product {"prod_3", COLOUR::GREEN, SIZE::SMALL, TRANSPORT::LAND}};

    FilterV1<Product> filter_ver_1_inst {};

    cout << "Results for FilterV1:\n";

    cout << "filter_ver_1_inst.filter_by_colour(prod_list_1, COLOUR::GREEN): ";
    for(auto &prod_iter: filter_ver_1_inst.filter_by_colour(prod_list_1, COLOUR::GREEN)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "filter_ver_1_inst.filter_by_size(prod_list_1, SIZE::SMALL): ";
    for(auto &prod_iter: filter_ver_1_inst.filter_by_size(prod_list_1, SIZE::SMALL)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "filter_ver_1_inst.filter_by_colour_and_size(prod_list_1, COLOUR::GREEN, SIZE::SMALL): ";
    for(auto &prod_iter: filter_ver_1_inst.filter_by_colour_and_size(prod_list_1, COLOUR::GREEN, SIZE::SMALL)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "Results for FilterV2:\n";

    Colour_Specification<Product> green_spec                 {COLOUR::GREEN};
    Size_Specification<Product> small_spec                   {SIZE::SMALL};
    Transport_Specification<Product> land_spec               {TRANSPORT::LAND};
    // AND_Specification<Product> green_and_small_spec {green_spec && small_spec};
    AND_Specification<Product> green_and_small_spec {Colour_Specification<Product> {COLOUR::GREEN} && Size_Specification<Product> {SIZE::SMALL}}; // Also valid.

    FilterV2<Product> filter_ver_2_inst {};

    cout << "filter_ver_2_inst.filter(prod_list_1, green_spec)                                   : ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, green_spec)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, Colour_Specification<Product> {COLOUR::GREEN}): ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, Colour_Specification<Product> {COLOUR::GREEN})) { // Notice here we can pass an r-value of type Colour_Specification<Product> to the filter method.
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, small_spec)                               : ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, small_spec)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, Size_Specification<Product> {SIZE::SMALL}): ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, Size_Specification<Product> {SIZE::SMALL})) { // Notice here we can pass an r-value of type Size_Specification<Product> to the filter method.
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, land_spec)                                         : ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, land_spec)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, Transport_Specification<Product> {TRANSPORT::LAND}): ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, Transport_Specification<Product> {TRANSPORT::LAND})) { // Notice here we can pass an r-value of type Transport_Specification<Product> to the filter method.
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, green_and_small_spec)                                                                      : ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, green_and_small_spec)) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, Colour_Specification<Product> {COLOUR::GREEN} && Size_Specification<Product> {SIZE::SMALL}): ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, Colour_Specification<Product> {COLOUR::GREEN} && Size_Specification<Product> {SIZE::SMALL})) { // Notice here we can pass an r-value of type AND_Specification<Product> to the filter method.
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n\n";

    cout << "filter_ver_2_inst.filter(prod_list_1, Colour_Specification<Product> {COLOUR::RED} && Size_Specification<Product> {SIZE::SMALL} && Transport_Specification<Product> {TRANSPORT::LAND}): ";
    for(auto &prod_iter: filter_ver_2_inst.filter(prod_list_1, Colour_Specification<Product> {COLOUR::RED} && Size_Specification<Product> {SIZE::SMALL} && Transport_Specification<Product> {TRANSPORT::LAND})) {
        cout << (prod_iter->product_name) << " ";
    }
    cout << "\n";

    return 0;
}