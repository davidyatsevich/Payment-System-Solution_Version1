#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <string> // Methods used => std::string

class Payment
{
private:
    int paymentID;
    double amount;

public:
    //================================
    // Constructor & Default Destructor
    Payment(int pID, double amt) : paymentID(pID), amount(amt) {}
    virtual ~Payment() = default;
    //================================
    // Getters
    int getPaymentID() const
    {
        return paymentID;
    }
    double getAmount() const
    {
        return amount;
    }

    virtual std::string getPaymentType() const = 0;
};

#endif // PAYMENT_HPP
