//Order.cpp
#include "Order.h"

int Order::id() const {return id_;}
void Order::setId(int v) {id_=v;}

// --- table (for DineIn) ---
int Order::table() const {return table_;}
void Order::setTable(int t) {table_ = t;}

// --- type (e.g., "Pizza" ---
std::string Order::type() const {return type_;}
void Order::setType(const std::string& t) {type_ = t;}

// --- rush / priority ---
bool Order::isRush() const {return rush_;}
void Order::setRush(bool r) {rush_ = r;}

int Order::priority() const {return priority_;}
void Order::setPriority(int p) {priority_ = p;}

// --- status (must be one of: "New", "PendingRegular", "PendingRush", "Completed") ---
std::string Order::status() const{return status_;}
void Order::setStatus(const std::string& s) {
    std::string a[4] = {"New", "PendingRegular", "PendingRush", "Completed"};
    for (std::string cur : a){
        if (cur==s){
            status_ = s;
            return;
        }
    }
}

// --- source (must be "DineIn" or "Uber") ---
std::string Order::source() const {return source_;}
void Order::setSource(const std::string& src){
    std::string a[4] = {"DineIn", "Uber"};
    for (std::string cur : a){
        if (cur==src){
            source_ = src;
            return;
        }
    }
}

// --- Uber-specific (optional for DineIn) ---
std::string Order::customerName() const{return customerName_;}
void Order::setCustomerName(const std::string& n) {customerName_ = n;}

std::string Order::deliveryAddress() const {return deliveryAddress_;}
void Order::setDeliveryAddress(const std::string& addr) {deliveryAddress_ = addr;}

//Initializes values for testing
void Order::initValues(int i, 
        int t, const std::string& ty, 
        const std::string& src){
            setId(i);
            setTable(t);
            setType(ty);
            setSource(src);
        }
