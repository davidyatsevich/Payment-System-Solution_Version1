#ifndef CARDMETHOD_HPP
#define CARDMETHOD_HPP

#include "Payment.hpp" // Methods used => Payment<T>::Payment(), Payment<T>::getPaymentID(), Payment<T>::getAmount(), Payment<T>::getPaymentType() (overridden)
#include <string>      // Methods used => std::string, constructor, copy

class CardMethod : public Payment
{
private:
    long long cardNumber;       // Stores card number
    std::string cardHolderName; // Stores card holder name
    std::string expiryDate;     // Stores expiry date
    int cvv;                    // Stores CVV

public:
    //================================
    // Constructor
    CardMethod(int pID, double amt, long long crdNmb, std::string crdHldNme, std::string expDta, int cV)
        : Payment(pID, amt), cardNumber(crdNmb), cardHolderName(crdHldNme), expiryDate(expDta), cvv(cV) {}
    //================================
    // Override virtual method from Payment
    std::string getPaymentType() const override
    {
        return "Card";
    }
    //================================
    // Getters
    long long getCardNumber() const
    {
        return cardNumber;
    }
    std::string getCardHolderName() const
    {
        return cardHolderName;
    }
    std::string getExpiryDate() const
    {
        return expiryDate;
    }
    int getCvv() const
    {
        return cvv;
    }
};

#endif // CARDMETHOD_HPP
