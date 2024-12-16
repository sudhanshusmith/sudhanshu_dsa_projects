# Search Nearby Feature

This project implements a **2D Range Tree** in C++ to efficiently store, manage, and search for points in a 2D space based on given coordinate ranges.

## Features
- **O(nlogn)** construction time for the 2D Range Tree.
- **O(m + log²n)** query time to retrieve points in a specified rectangular range.
- Optimized for performance and scalability.

## Project Structure
- `point_database.cpp`: Core implementation of the 2D Range Tree and example usage.

## Requirements
- A C++ compiler (e.g., g++) supporting C++11 or later.

## Setup and Run
1. Clone the repository or download the `point_database.cpp` file.
2. Compile the code using a C++ compiler:
   ```bash
   g++ -std=c++11 point_database.cpp -o point_database
   ```
3. Run the executable:
   ```bash
   ./point_database
   ```

## Example Output
Given points:  
`[(1, 2), (3, 6), (5, 8), (4, 7), (7, 2), (6, 5), (2, 4)]`

Range:  
`x: (2, 6), y: (3, 7)`

Output:  
`Points in range: (3, 6) (5, 8) (4, 7) (6, 5) (2, 4)`

## How It Works
1. The `PointDatabase` class builds a **2D Range Tree** from input points.
2. `searchNearby(x_min, x_max, y_min, y_max)` efficiently retrieves all points within the specified rectangular range.

## Use Cases
- Spatial querying in maps.
- Search optimization in 2D grids.
- Real-time querying of geographical data.
