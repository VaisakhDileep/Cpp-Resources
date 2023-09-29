#include<string>

using namespace std;

class Ford {
public:
    string model_name;
    int year_of_release {};

    Ford(); // Constructor

    ~Ford(); // Destructor

    void set_model_name(string model_name); // Setters
    void set_year_of_release(int year_of_release);

    string get_model_name(); // Getters
    int get_year_of_release();
};