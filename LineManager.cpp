// Name: Tanimul Islam
// Seneca Student ID: 129414223
// Seneca email: tislam38@myseneca.ca
// Date of completion: 24-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//LineManager.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include "LineManager.h"
#include "Utilities.h"

namespace seneca {

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities tempUtil;
		std::string eachLine = "", currentWStation = "", nextWStation = "";
		size_t pos = 0u;
		bool more = false;
		std::vector<std::string> v_currentWStation, v_nextWsSation;

		std::ifstream readFile(file);

		if (!readFile) {
			throw std::string("\n***Failed to open file ") + std::string(file) + std::string(" ***\n");
		}
		else {
			while (std::getline(readFile, eachLine)) {
				if (!eachLine.empty()) {
					currentWStation = tempUtil.extractToken(eachLine, pos, more);
					v_currentWStation.push_back(currentWStation);

					nextWStation = !more ? "" : tempUtil.extractToken(eachLine, pos, more);
					v_nextWsSation.push_back(nextWStation);

					auto errorCheck = std::any_of(stations.begin(), stations.end(), [=](Workstation* src) {
						if (src->getItemName() == currentWStation) {
							if (!nextWStation.empty()) {
								auto nextErrorCheck = std::any_of(stations.begin(), stations.end(), [=](Workstation* nextSrc) {
									if (nextSrc->getItemName() == nextWStation) {
										src->setNextStation(nextSrc);
										return true;
									}
									else
										return false;
									});

								if (!nextErrorCheck) throw std::string("\n\n***Next Workstation is not found***\n\n");
								else if (currentWStation == nextWStation) throw std::string("\n\n***Next Workstation is not found***\n\n");
							}
							m_activeLine.push_back(src);
							return true;
						}
						else
							return false;
						});
					if (!errorCheck) throw std::string("\n\n***Something Went Wrong***\n\n");
				}
			}
			readFile.close();

			std::for_each(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* src) {
				auto start = std::any_of(stations.begin(), stations.end(), [=](Workstation* nextSrc) {
					if (nextSrc->getNextStation() == src)
						return true;
					else
						return false;
					});

				if (!start) {
					m_firstStation = src;
				}
				});
			m_cntCustomerOrder = g_pending.size();
		}
	}

	void LineManager::reorderStations()
	{
		Workstation* nextWStation = m_firstStation;
		std::vector<Workstation*> v_WStation;

		while (nextWStation) {
			v_WStation.push_back(nextWStation);
			nextWStation = nextWStation->getNextStation();
		}
		m_activeLine = v_WStation;
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t iterationCount = 0u;

		os << "Line Manager Iteration: " << ++iterationCount << std::endl;
		if (!g_pending.empty()) {
			*m_activeLine.front() += std::move(g_pending.front());
			g_pending.pop_front();
		}

		for (auto src : m_activeLine)
			src->fill(os);

		for (auto src : m_activeLine)
			src->attemptToMoveOrder();

		return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
	}

	void LineManager::display(std::ostream& os) const {
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* src) {
			src->display(os);
			});
	}
}