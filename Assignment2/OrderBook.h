// OrderBook.h
#pragma once
#include <vector>
#include "Order.h"

class OrderBook {
public:
    // Add a new order by value
    void addOrder(const Order& o);

    // Find an order by ID. Return pointer or nullptr if not found.
    Order* findOrderById(int id);

    // Read-only access to all orders (for printing/debugging).
    const std::vector<Order>& all() const;

private:
    std::vector<Order> orders_;
};