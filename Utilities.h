// Name: Tanimul Islam
// Seneca Student ID: 129414223
// Seneca email: tislam38@myseneca.ca
// Date of completion: 13-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include<string>

namespace seneca
{
	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter;

	public:
		Utilities() {};
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}


#endif // !SENECA_UTILITIES_H
