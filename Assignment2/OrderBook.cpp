// OrderBook.cpp
#include "OrderBook.h"
#include <iostream>

// Add a new order by value
void OrderBook::addOrder(const Order& o){
    orders_.push_back(o);
}

// Find an order by ID. Return pointer or nullptr if not found.
Order* OrderBook::findOrderById(int id){
    for (int i = 0; i<orders_.size(); ++i){
        if(orders_[i].id() == id){
            return &orders_[i];
        }
    }
    return nullptr;
}

// Read-only access to all orders (for printing/debugging).
const std::vector<Order>& OrderBook::all() const{
        return orders_;
}