#include "grid.h"

#include <vector>
#include <iostream>
#include <cmath>

int calculate_total(const int dim) {
  int total = 0;
  for (int i = 1; i <= dim * dim; i++) {
    total += i;
  }
  return total;
}

int calculate_goal(const int dim) {
  int total = calculate_total(dim);
  int goal = total / dim;
  return goal;
}

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
  for (int row_i = 0; row_i < grid.dim; row_i++) {
    for (int col_i = 0; col_i < grid.dim; col_i++) {
      int vec_i = grid.dim * row_i + col_i;
      os << std::to_string(grid.grid[vec_i]);
      os << " ";
    }
    os << '\n';
  }
  return os;
}

int Grid::calculate_cost() {
  int cost = 0;
  int result = 0;

  // rows
  for (int row_i = 0; row_i < dim; row_i++) {
    result = 0; 
    for (int col_i = 0; col_i < dim; col_i++) {
      int vec_i = dim * row_i + col_i;
      result += grid[vec_i];
    }
    cost += std::abs(goal - result);
  }

  // columns
  for (int col_i = 0; col_i < dim; col_i++) {
    result = 0;
    for (int row_i = 0; row_i < dim; row_i++) {
      int vec_i = dim * row_i + col_i;
      result += grid[vec_i];
    }
    cost += std::abs(goal - result);
  }
  
  // left diagonal
  result = 0;
  for (int i = 0; i < dim; i++) {
    int vec_i = dim * i + i;
    result += grid[vec_i]; 
  }
  cost += std::abs(goal - result);

  // right diagonal
  result = 0;
  for (int i = 0; i < dim; i++) {
    int vec_i = (dim * i + dim - i - 1);
    result += grid[vec_i];
  }
  cost += std::abs(goal -result);

  return cost;
}
