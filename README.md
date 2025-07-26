
![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
# 🏭 Assembly Line Simulation (MS03)
A C++ simulation project that models a real-world **assembly line production system**, where customer orders move through a series of workstations, each responsible for filling specific items based on availability and sequence.
> 💼 **Built as part of an advanced C++ programming course, this project demonstrates mastery in object-oriented design, file-driven logic, memory management, and STL-based simulation control.**
> 
## 📂 Project Structure
main.cpp → Entry point, sets up and runs the simulation
Utilities.[h|cpp] → Token extraction and field formatting for file parsing
Station.[h|cpp] → Represents an inventory station with item info and stock
Workstation.[h|cpp] → Inherits Station, manages order queues and item processing
CustomerOrder.[h|cpp] → Models customer order with dynamic item lists
LineManager.[h|cpp] → Configures and orchestrates the assembly line process

## 🔧 How It Works

The simulation uses **four input files** provided via the command line:
```bash
./ms3 Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
```
1. Stations1.txt & Stations2.txt – Initialize stations with names, quantities, descriptions, etc.
2. CustomerOrders.txt – Defines multiple customer orders with lists of required items.
3. AssemblyLine.txt – Establishes the order and linkages of workstations in the line.

The application then:
 - Displays initial station info (summary and full)
 - Loads and displays customer orders
 - Validates station methods (e.g., serial number generation, quantity    updates)
 - Builds the assembly line
 - Iteratively processes orders through the line, filling items or marking them incomplete
 - Outputs completed and incomplete orders
 - Shows final inventory state

✨ Sample Output Snapshot
```bash
========================================
=           Filling Orders             =
========================================
Line Manager Iteration: 3
    Filled Chris S., Bedroom [Bed]
    Filled Cornel B., 1-Room Home Office [Desk]
...

========================================
=      Processed Orders (complete)     =
========================================
Cornel B. - 1-Room Home Office
[147852] Office Chair                   - FILLED
[459214] Desk                           - FILLED
[000987] Bookcase                       - FILLED
...

========================================
=     Processed Orders (incomplete)    =
========================================
Hong H. - 1-Room Office
[000000] Desk                           - TO BE FILLED
[147853] Office Chair                   - FILLED
...

========================================
=          Inventory (full)            =
========================================
001 | Armchair       | 654325 |    7 | Upholstered Wing Chair
...
```
## 🧠 Key Concepts Demonstrated
-   **Object-Oriented Design**
    -   Inheritance (`Workstation` extends `Station`)    
    -   Composition (`CustomerOrder` holds `Item` objects)
-   **Dynamic Memory Management**
    -   Manual `new/delete` handling in `CustomerOrder`
-   **STL Containers & Algorithms**
    -   `std::vector`, `std::deque`, `std::count`, `std::any_of`, `std::for_each`
-    **Move Semantics & Rule of 5**
    -   `CustomerOrder` explicitly deletes copy operations, defines move operations
-    **File I/O and Parsing**
    -   Custom `Utilities` class to tokenize input using flexible delimiters
-    **Simulation Loop Design**
    -   Iterative control via `LineManager::run()`
    

## 📁 Sample Input Files
You can use the provided:

-   `Stations1.txt`
-   `Stations2.txt`    
-   `CustomerOrders.txt`
-   `AssemblyLine.txt`

Ensure these are placed in the root directory and formatted properly (comma/pipe delimited).

## 💡 Highlights
-   This project simulates real-world **manufacturing workflows**
-   Strong understanding of **C++ memory models**
-   Proficient in **modular design**, **data processing**, and **simulation engineering**
-   Capable of building and managing **mid-sized systems** in C++ using OOP principles
## 🚀 Getting Started
```bash
g++ -std=c++17 -o ms3 *.cpp
# Run with sample files
./ms3 Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
```
## 📜 License
This project was created for academic purposes and is open for review, learning, and reuse with attribution.
