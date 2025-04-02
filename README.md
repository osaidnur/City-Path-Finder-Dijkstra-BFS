# City Path Finder - Dijkstra & BFS

This project is a C-based simulator for finding the shortest path between cities using two classical graph traversal algorithms: **Dijkstra's Algorithm** and **Breadth-First Search (BFS)**.

## 📚 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [How It Works](#-how-it-works)
- [Usage](#-usage)
- [Files](#-files)
- [Author](#-author)

## 🧭 Overview

The simulator reads a list of cities and their connections from a text file, builds an adjacency matrix, and then allows the user to choose between BFS or Dijkstra to compute paths between selected cities.

## ✨ Features

- Load cities and distances from a file (`cities.txt`)
- Allows users to:
  - View the graph
  - Choose start and destination cities
  - Find shortest paths using Dijkstra's algorithm
  - Explore paths using BFS
  - Save results to output files

## ⚙ How It Works

- **BFS** finds the path with the least number of edges.
- **Dijkstra** computes the shortest weighted path using a priority-based greedy approach.
- User chooses interaction via a command-line menu.
- Outputs include path sequences and total distances.

## 🧪 Usage

1. Compile the program:
   ```bash
   gcc -o city_path_finder P4_1210733_OsaidNur_1.c
   ```

2. Make sure `cities.txt` is present in the same directory.

3. Run the program:
   ```bash
   ./city_path_finder
   ```

4. Follow on-screen menu to choose operations.

## 📁 Files

- `P4_1210733_OsaidNur_1.c`: Main source code.
- `cities.txt`: Input file containing cities and distances.
- `project 4.pdf`: Project documentation and description.

## 👤 Author

- **Osaid Nur**
