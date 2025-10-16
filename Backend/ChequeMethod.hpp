#ifndef CHEQUEMETHOD_HPP
#define CHEQUEMETHOD_HPP

#include "Payment.hpp" // Methods used => Payment::Payment(), Payment::getPaymentID(), Payment::getAmount(), Payment::getPaymentType() (overridden)
#include <string>      // Methods used => std::string, constructor, copy

class ChequeMethod : public Payment
{
private:
    int chequeNumber;              // Stores cheque number
    std::string bankName;          // Stores bank name
    std::string accountHolderName; // Stores account holder name

public:
    //================================
    // Constructor
    ChequeMethod(int pID, double amt, int chNum, std::string bnkNme, std::string accHldNme)
        : Payment(pID, amt), chequeNumber(chNum), bankName(bnkNme), accountHolderName(accHldNme) {}
    //================================
    // Override virtual method from Payment
    std::string getPaymentType() const override
    {
        return "Cheque";
    }
    //================================
    // Getters
    int getChequeNumber() const
    {
        return chequeNumber;
    }
    std::string getBankName() const
    {
        return bankName;
    }
    std::string getAccountHolderName() const
    {
        return accountHolderName;
    }
};

#endif // CHEQUEMETHOD_HPP
