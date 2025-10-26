#ifndef INVOICE_HPP
#define INVOICE_HPP

#include <string>      // Methods used => std::string
#include <vector>      // Methods used => std::vector, push_back(), size()
#include <memory>      // Methods used => std::shared_ptr
#include "Payment.hpp" // Methods used => Payment::getAmount()

class Invoice
{
private:
    int invoiceID;
    std::string customerName;
    std::vector<std::shared_ptr<Payment>> listOfPayments;
    double totalAmount;

public:
    //================================
    // Constructor
    Invoice(int invID, std::string cstNme)
        : invoiceID(invID), customerName(cstNme), totalAmount(0) {}

    void addPayment(std::shared_ptr<Payment> payment)
    {
        listOfPayments.push_back(payment);
        totalAmount += payment->getAmount();
    }
    //================================
    // Getters
    int getInvoiceID() const
    {
        return invoiceID;
    }
    std::string getCustomerName() const
    {
        return customerName;
    }
    std::vector<std::shared_ptr<Payment>> getListOfPayments() const
    {
        return listOfPayments;
    }
    double getTotalAmount() const
    {
        return totalAmount;
    }
};

#endif // INVOICE_HPP
