// Order.h
#pragma once
#include <string>

class Order {
public:
    // --- id ---
    int id() const;
    void setId(int v);

    // --- table (for DineIn) ---
    int table() const;
    void setTable(int t);

    // --- type (e.g., "Pizza" ---
    std::string type() const;
    void setType(const std::string& t);

    // --- rush / priority ---
    bool isRush() const;
    void setRush(bool r);

    int priority() const;
    void setPriority(int p);

    // --- status (must be one of: "New", "PendingRegular", "PendingRush", "Completed") ---
    std::string status() const;
    void setStatus(const std::string& s);

    // --- source (must be "DineIn" or "Uber") ---
    std::string source() const;
    void setSource(const std::string& src);

    // --- Uber-specific (optional for DineIn) ---
    std::string customerName() const;
    void setCustomerName(const std::string& n);

    std::string deliveryAddress() const;
    void setDeliveryAddress(const std::string& addr);

private:
    int id_ = -1;

    int table_ = -1;

    // Common:
    std::string type_;
    bool rush_ = false;
    int priority_ = 0;
    std::string status_ = "New";

    // Source string: "DineIn" or "Uber"
    std::string source_ = "DineIn";

    // Uber-specific:
    std::string customerName_;
    std::string deliveryAddress_;
};