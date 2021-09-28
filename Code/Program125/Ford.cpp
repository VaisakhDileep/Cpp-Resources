#include "Ford.hpp"

Ford::Ford()
    : model_name {""}, year_of_release {0}
{
}

Ford::~Ford()
{
}

void Ford::set_model_name(string model_name)
{
    this->model_name = model_name;
}

void Ford::set_year_of_release(int year_of_release)
{
    this->year_of_release = year_of_release;
}

string Ford::get_model_name()
{
    return model_name;
}

int Ford::get_year_of_release()
{
    return year_of_release;
}