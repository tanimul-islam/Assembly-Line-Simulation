// Name: Tanimul Islam
// Seneca Student ID: 129414223
// Seneca email: tislam38@myseneca.ca
// Date of completion: 24-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//LineManager.h
#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include<iostream>
#include<vector>
#include<string>
#include"Workstation.h"

namespace seneca {

	class LineManager {

		std::vector<Workstation*> m_activeLine; // the collection of workstations for the current assembly line.
		size_t m_cntCustomerOrder; //the total number of CustomerOrder objects
		Workstation* m_firstStation; //points to the first active station on the current line

	public:
		//2- arg constructor
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		// reorders the workstations present in the instance variable
		void reorderStations();
		//performs one iteration of operations on all of the workstations 
		bool run(std::ostream& os);
		//displays all active stations
		void display(std::ostream& os) const;
	};
}

#endif // !SENECA_LINEMANAGER_H
