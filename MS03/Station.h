// Name: Tanimul Islam
// Seneca Student ID: 129414223
// Seneca email: tislam38@myseneca.ca
// Date of completion: 13-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//Station.h

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include<string>

namespace seneca {
	class Station {
		int stationId{ 0 };
		std::string itemName{ "" };
		std::string m_description{ "" };
		size_t nSerialNumber{ 0u };
		size_t numOfItems{ 0u };

		//class var
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& src);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}


#endif // !SENECA_STATION_H
