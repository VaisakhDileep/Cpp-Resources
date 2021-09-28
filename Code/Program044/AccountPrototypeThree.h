#ifndef _ACCOUNT_PROTOTYPE_THREE_H_ // This is an include guards, it will check if the header has been implemented before, if implemented then it will ignored.
#define _ACCOUNT_PROTOTYPE_THREE_H_

class AccountPrototypeThree
{
private:
    double balance;
public:
    void set_balance(double account_balance);
    double get_balance();
}; // This is the class declaration.

#endif