#ifndef UPI_PAYMENT_STRATERGY_H
#define UPI_PAYMENT_STRATERGY_H

#include"PaymentStrategy.h"

class UpiPaymentStrategy : public PaymentStrategy{
    private:
        string mobile_number;
    public:
        UpiPaymentStrategy(const string& mob) : mobile_number(mob){}

        void pay(double amount) override{
            cout << "Paid ₹" << amount << " using UPI (" << mobile_number << ")" << endl;
        }
};
#endif