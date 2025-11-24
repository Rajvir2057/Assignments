// Restaurant.h
#pragma once

#include <iostream>
#include "OrderBook.h"
#include "SimpleQueue.h"
#include "SimpleStack.h"
#include "PriorityQueue.h"

class Restaurant {
public:
    // -- adding orders --
    // Add to internal registry (not yet queued).
    void addOrder(const Order& o);

    // -- placing orders in queues --

    // Dine-in, regular (non-rush)
    bool placeDineInRegular(int orderId);

    // Dine-in, rush
    bool placeDineInRush(int orderId, int priority);

    // Uber order (always treated as rush)
    bool placeUberOrder(int orderId, int priority);

    // -- processing orders --
    bool completeNextOrder(); // kitchen prepares next order
    bool undoLastCompletion(); // move last completed order back to queue

    // -- utility --
    void printState() const;  // simple summary of state
    Order* findOrderById(int id); // delegate to OrderBook

private:
    OrderBook orderBook_;         // registry of all orders
    SimpleQueue regularQueue_;    // regular order IDs
    PriorityQueue rushQueue_;     // rush order IDs + priority
    SimpleStack completedStack_;  // completed order IDs
};