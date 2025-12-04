#include "Restaurant.h"

void Restaurant :: addOrder(const Order& o){

    orderBook_.addOrder(o);

}

bool Restaurant :: placeDineInRegular(int orderId){

    if(!orderBook_.findOrderById(orderId)){
        return false;
    } 
    // check case to see if we have orders in the restuarant.

    Order* order = orderBook_.findOrderById(orderId);

    order -> setStatus("Pending");

    regularQueue_.enqueue(orderId);

    return true;
}

bool Restaurant :: placeDineInRush(int orderId, int priority){

    if(!orderBook_.findOrderById(orderId)){
        return false;
    } 
    // check case to see if we have orders in the restuarant.

    Order* order = orderBook_.findOrderById(orderId);

    order -> setStatus("Pending");

    rushQueue_.push(orderId, priority);

    return true;

}
bool Restaurant :: placeUberOrder(int orderId, int priority){

    orderBook_.findOrderById(orderId) -> setSource("Uber");
    return placeDineInRush(orderId, priority);

}

bool Restaurant :: completeNextOrder(){
    
    if(!rushQueue_.empty()){
        //do rushqueue
        Order * order = findOrderById(rushQueue_.top().id);
        if(order -> status() != "Pendingrush" ) {
             rushQueue_.pop();
        } 

    }else {
        //do rushqueue
        Order * order = findOrderById(regularQueue_.front());
        if(order -> status() != "Pendingregular" ) {
             regularQueue_.dequeue();
        } 
    }

    
}

bool Restaurant :: undoLastCompletion(){

    if(completedStack_.empty()){
        return false;

    }

    int lastId = completedStack_.top();
    completedStack_.pop();

    Order* order = orderBook_.findOrderById(lastId);

    if(order -> isRush()){
        order -> setStatus("PendingRush");

        rushQueue_.push(lastId, order -> priority());
    }
    else{
        order -> setStatus("PendingRegular");
        regularQueue_.enqueue(lastId);
    }

    return true;
}
void Restaurant :: printState() const {
    for(Order i : orderBook_.all()) {
        std :: cout << i.status();
    } 
}

Order* Restaurant :: findOrderById(int id){
    if (orderBook_.findOrderById(id)){
        return orderBook_.findOrderById(id);
    }
}