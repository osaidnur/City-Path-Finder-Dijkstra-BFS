# 🗺️ City Path Finder: Dijkstra & BFS Implementation

A comprehensive C implementation for finding the shortest paths between cities using two fundamental graph traversal algorithms: **Dijkstra's Algorithm** and **Breadth-First Search (BFS)**. This project demonstrates practical applications of graph theory in route planning and navigation systems.

## 📚 Table of Contents

- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [🚀 Quick Start](#-quick-start)
- [📊 Algorithms](#-algorithms)
- [🎮 Usage Guide](#-usage-guide)
- [📁 Project Structure](#-project-structure)
- [📝 Input Format](#-input-format)
- [📤 Output Examples](#-output-examples)
- [⚡ Performance Analysis](#-performance-analysis)
- [👨‍💻 Author](#-author)

## 🎯 Overview

The **City Path Finder** is an interactive console application that models cities as a weighted graph and provides optimal route planning capabilities. The program reads city connections from a file, constructs an adjacency matrix representation, and allows users to find paths using two different algorithmic approaches.

### 🌟 Key Highlights
- **Interactive Menu System**: User-friendly command-line interface
- **Dual Algorithm Support**: Compare BFS vs Dijkstra results
- **File I/O Operations**: Load data from files and save results
- **Real-time Path Visualization**: Display complete routes with distances
- **Memory Efficient**: Optimized data structures for performance

## ✨ Features

### 🔍 Core Functionality
- 📊 **Dynamic Graph Construction**: Automatically builds weighted graph from city data
- 🎯 **Interactive City Selection**: Choose source and destination cities from loaded data
- 🔄 **Algorithm Comparison**: Run both BFS and Dijkstra on the same dataset
- 💾 **Result Persistence**: Save shortest paths to output files
- 📈 **Performance Metrics**: Display path length, total distance, and edge count

### 🛠️ Technical Features
- **Adjacency Matrix Representation**: Efficient graph storage and traversal
- **Path Reconstruction**: Complete route tracking with predecessor arrays
- **Weighted Graph Support**: Handle real-world distance measurements
- **Input Validation**: Robust error handling for user inputs
- **Memory Management**: Proper allocation and deallocation

## 🚀 Quick Start

### Prerequisites
- GCC compiler or any C compiler
- Terminal/Command prompt access
- `cities.txt` file with city connections

### Installation & Run
```bash
# Clone the repository
git clone https://github.com/osaidnur/City-Path-Finder-Dijkstra-BFS.git
cd City-Path-Finder-Dijkstra-BFS

# Compile the program
gcc -o city_finder P4_1210733_OsaidNur_1.c

# Run the application
./city_finder
```

## 📊 Algorithms

### 🔵 Breadth-First Search (BFS)
- **Purpose**: Finds path with minimum number of edges
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)
- **Best For**: Unweighted graphs or when hop count matters

### 🟢 Dijkstra's Algorithm
- **Purpose**: Finds shortest weighted path
- **Time Complexity**: O(V²) with adjacency matrix
- **Space Complexity**: O(V)
- **Best For**: Weighted graphs with non-negative weights

### 📈 Comparison Table

| Aspect | BFS | Dijkstra |
|--------|-----|----------|
| **Optimal Path** | ❌ (by edges) | ✅ (by weight) |
| **Weighted Graphs** | ❌ | ✅ |
| **Implementation** | Simple | Moderate |
| **Memory Usage** | Low | Moderate |
| **Use Case** | Social networks | GPS navigation |

## 🎮 Usage Guide

The application provides an interactive menu with the following options:

```
***************** Welcome ***********************
Choose the operation(1-4) : 
1- Load Cities
2- Enter Starting City  
3- Enter Destination
4- Exit
```

### 📋 Step-by-Step Instructions

1. **Load Cities** (Option 1)
   - Reads `cities.txt` file
   - Constructs the adjacency matrix
   - Displays loading confirmation

2. **Enter Starting City** (Option 2)
   - Input your source city name
   - Validates city exists in loaded data
   - Prepares BFS path tracking

3. **Enter Destination** (Option 3)
   - Input your destination city
   - Executes both BFS and Dijkstra algorithms
   - Displays comparative results

4. **Exit** (Option 4)
   - Saves results to `shortest_distance.txt`
   - Cleanly terminates the program

## 📁 Project Structure

```
City-Path-Finder-Dijkstra-BFS/
├── 📄 P4_1210733_OsaidNur_1.c    # Main C source code
├── 📄 cities.txt                  # Input data file
├── 📄 README.md                   # Project documentation
├── 📄 project 4.pdf              # Assignment specifications
└── 📄 shortest_distance.txt      # Output results (generated)
```

## 📝 Input Format

The `cities.txt` file should follow this format:
```
City1    City2    Distance
Akka     Haifa    35km
Haifa    Nazareth 60km
Nazareth Jenin    45km
```

### 📋 Format Specifications
- **Delimiter**: Tab-separated or space-separated
- **Distance**: Number followed by "km"
- **Cities**: String names (no spaces within names)
- **Graph Type**: Undirected weighted graph

### 🌍 Sample Cities Dataset
The included dataset contains Palestinian cities with realistic distances:
- Akka, Haifa, Nazareth, Jenin
- Bethlehem, Jerusalem, Hebron, Jericho
- Tulkarem, Nablus, Ramallah, Jaffa

## 📤 Output Examples

### BFS Result
```
******** BFS path from Akka to Jerusalem ***************************************
Akka_____35km_____Haifa_____49km_____Jenin_____45km_____Nablus_____63km_____Ramallah_____15km_____Jerusalem
Total Distance  >>> 207 km
Number of edges >>> 5
```

### Dijkstra Result
```
******** Dijkstra path from Akka to Jerusalem ***************************************
Akka    Nazareth    Jenin    Nablus    Ramallah    Jerusalem
Total distance >>> 185 km
```


## ⚡ Performance Analysis

### 📊 Complexity Analysis

| Operation | BFS | Dijkstra |
|-----------|-----|----------|
| **Preprocessing** | O(E) | O(E) |
| **Path Finding** | O(V + E) | O(V²) |
| **Space Usage** | O(V) | O(V) |
| **Path Quality** | Suboptimal | Optimal |

### 🎓 Academic Context
This project was developed as part of a Data Structures and Algorithms course, demonstrating practical implementation of graph algorithms and their real-world applications in route planning systems.

---

## 👤 Author

- **Osaid Nur**
