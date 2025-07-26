// Name: Tanimul Islam
// Seneca Student ID: 129414223
// Seneca email: tislam38@myseneca.ca
// Date of completion: 21-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//CustomerOrder.h

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include"Station.h"

namespace seneca {
    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
        std::string m_name{ "" };       // he name of the customer
        std::string m_product{ "" };       // the name of the product being assembled
        size_t m_cntItem{ 0u };       // a count of the number of items in the customer's order
        Item** m_lstItem{ nullptr };  // a dynamically allocated array of pointers

        // Class Variables
        static size_t m_widthField;         // the maximum width of a field

    public:
        CustomerOrder() {};
        CustomerOrder(const std::string& src);
        CustomerOrder(const CustomerOrder& src); // the copy constructor should throw an exception
        CustomerOrder& operator=(const CustomerOrder& src) = delete;
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        ~CustomerOrder();

        // check if all the items in the order have been filled
        bool isOrderFilled() const;

        // check if all items specified by itemName have been filled
        bool isItemFilled(const std::string& itemName) const;

        // this modifier fills all items in the current order that the Station specified in the first parameter handles
        void fillItem(Station& station, std::ostream& os);

        // this query displays the state of the current object
        void display(std::ostream& os) const;
    };
}
#endif // !SENECA_CUSTOMERORDER_H
