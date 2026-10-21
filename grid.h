#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>

int calculate_total(const int dim);

int calculate_goal(const int dim);

struct Grid {
  int dim;
  int goal;
  std::vector<int> grid;

  // constructors
  Grid() : 
    dim (3), 
    goal (15),
    grid (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})
  {}

  Grid(const int dim_, const int goal_, std::vector<int> grid_) : 
    dim (dim_), 
    goal (goal_), 
    grid (grid_) 
  {}

  Grid(const int dim_, std::mt19937& engine) {
    dim = dim_;
    goal = calculate_goal(dim_);
    std::vector<int> grid_;
    grid_.reserve(dim_ * dim_);
    for (int i = 1; i <= dim_ * dim_; i++) {
      grid_.push_back(i);
    }
    std::shuffle(std::begin(grid_), std::end(grid_), engine);
    grid = grid_;
  }

  //redefine the << operator to output the grid
  friend std::ostream& operator<<(std::ostream& os, const Grid& grid);

  // function to calculate the cost of the grid
  int calculate_cost();
};
