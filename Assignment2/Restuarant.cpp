#include "Restuarant.h"

void Restaurant :: addorder(const Order& o){

    orderBook_.addOrder(o):

}

bool Restaurant :: placeDineInRegular(int orderId){

    if(!orderBook_.hasOrder(orderId)){
        return false;
    } 
    // check case to see if we have orders in the restuarant.

    Order* order = orderBook._getOrder(orderId);

    order -> setStatus("Pending");

    regularQueue_push(orderId);

    return true;
}

bool Restuarant :: placeUberOrder(int orderId, int priority){

    return placeDineInRush(orderId, priority);

}

bool Restuarant :: completeNextOrder(){

    
}

bool Restuarant :: undoLastCompletion(){

    if(completedStack_.empty()){
        return false;

    }

    int lastId = completedStack_.top();
    completedStack_.pop();

    Order* order = orderBook_.getOrder(lastId);

    if(order -> isRush()){
        order -> setStatus("PendingRush");

        rushQueue_.push(lastid, order -> priority());
    }
    else{
        order -> setStatus("PendingRegular");
        regularQueue_.push(lastId);
    }

    return true;

    Order* Restuarant :: findOrderById(int id){
        if (orderBook_.hasOrder(id)){
            return orderBook_.getOrder(id)
        }
    }
}