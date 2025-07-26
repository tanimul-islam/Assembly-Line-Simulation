// Name: Tanimul Islam
// Seneca Student ID: 129414223
// Seneca email: tislam38@myseneca.ca
// Date of completion: 21-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//CustomerOrder.cpp
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include"CustomerOrder.h"
#include"Utilities.h"

namespace seneca {
	size_t CustomerOrder::m_widthField = 0u;

	CustomerOrder::CustomerOrder(const std::string& src)
	{
		Utilities Utili;
		bool more = true;
		size_t pos = 0u;
		size_t index = 0u;

		try {
			m_name = Utili.extractToken(src, pos, more);
			m_product = Utili.extractToken(src, pos, more);
			m_cntItem = std::count(src.begin(), src.end(), Utili.getDelimiter()) - 1;

			if (m_cntItem > 0) {
				m_lstItem = new Item * [m_cntItem]; // Allocate memory for the array of pointers

				while (more && index < m_cntItem) { // Ensure index is within bounds
					m_lstItem[index] = new Item(Utili.extractToken(src, pos, more));
					++index;
				}
			}
			else {
				m_lstItem = nullptr; // If no items, set m_lstItem to nullptr
			}

			CustomerOrder::m_widthField = std::max(Utili.getFieldWidth(), CustomerOrder::m_widthField);
		}
		catch (std::string err) {
			std::cout << err;
		}
	}


	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw false;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& seneca::CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src) {
			if (m_lstItem) {
				for (size_t i = 0u; i < m_cntItem; ++i)
					delete m_lstItem[i];

				delete[] m_lstItem;
			}

			m_name = std::move(src.m_name);
			m_product = std::move(src.m_product);
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;


			src.m_name.clear();
			src.m_product.clear();
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		if (m_lstItem) {
			for (auto i = 0u; i < m_cntItem; ++i)
				delete m_lstItem[i];

			delete[] m_lstItem;
			m_lstItem = nullptr;
		}
	}

	// Check if all items in the order have been filled
	bool CustomerOrder::isOrderFilled() const {
		for (auto i = 0u; i < m_cntItem; ++i)
			if (!m_lstItem[i]->m_isFilled)
				return false;
		return true;
	}

	// Check if all items with the specified name have been filled
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (auto i = 0u; i < m_cntItem; ++i)
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
				return false;
		return true;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool itemFilled = false; // Flag to track if an item has been filled

		for (size_t i = 0; i < m_cntItem && !itemFilled; ++i) {
			if (!m_lstItem[i]->m_isFilled && m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity()) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					itemFilled = true; // Set the flag to true after filling an item
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}



	void CustomerOrder::display(std::ostream& os) const
	{
		/*CUSTOMER_NAME - PRODUCT
			[SERIAL] ITEM_NAME - STATUS
			[SERIAL] ITEM_NAME - STATUS*/

		os << m_name << " - " << m_product << std::endl;
		
		for (size_t i = 0u; i < m_cntItem; ++i) {
			os << "[" <<std::setw(6)<<std::setfill('0')<<std::right<< m_lstItem[i]->m_serialNumber << "] ";
			os <<std::setw(CustomerOrder::m_widthField) <<std::setfill(' ')<< std::left << m_lstItem[i]->m_itemName;
			os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}


}