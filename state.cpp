#include "state.h"
#include "grid.h"

#include <iostream>
#include <vector>
#include <cmath>

std::ostream& operator<<(std::ostream &os, const State& state) { 
  os << state.grid << '\n' << "cost = " << std::to_string(state.cost) << "\n\n";
  return os;
}

State State::swap_right(int vec_pos) {
  if ((vec_pos + 1) % grid.dim == 0) {
    return State(grid, cost); 
  }

  std::vector<int> old_grid = grid.grid;
  std::vector<int> new_grid = grid.grid;

  new_grid[vec_pos] = old_grid[vec_pos + 1];
  new_grid[vec_pos + 1] = old_grid[vec_pos];

  Grid swapped_grid(grid.dim, grid.goal, new_grid);
  return State(swapped_grid, swapped_grid.calculate_cost());
}

State State::swap_left(int vec_pos) {
  if ((vec_pos - 1) % grid.dim == 0) {
    return State(grid, cost); 
  }

  std::vector<int> old_grid = grid.grid;
  std::vector<int> new_grid = grid.grid;

  new_grid[vec_pos] = old_grid[vec_pos - 1];
  new_grid[vec_pos - 1] = old_grid[vec_pos];

  Grid swapped_grid(grid.dim, grid.goal, new_grid);
  return State(swapped_grid, swapped_grid.calculate_cost());
}

State State::swap_up(int vec_pos) {
  if (vec_pos - grid.dim < 0) {
    return State(grid, cost); 
  }

  std::vector<int> old_grid = grid.grid;
  std::vector<int> new_grid = grid.grid;

  new_grid[vec_pos] = old_grid[vec_pos + grid.dim];
  new_grid[vec_pos - grid.dim] = old_grid[vec_pos];

  Grid swapped_grid(grid.dim, grid.goal, new_grid);
  return State(swapped_grid, swapped_grid.calculate_cost());
}

State State::swap_down(int vec_pos) {
  if (vec_pos + grid.dim > grid.dim * grid.dim - 1) {
    return State(grid, cost); 
  }

  std::vector<int> old_grid = grid.grid;
  std::vector<int> new_grid = grid.grid;

  new_grid[vec_pos] = old_grid[vec_pos + grid.dim];
  new_grid[vec_pos + grid.dim] = old_grid[vec_pos];

  Grid swapped_grid(grid.dim, grid.goal, new_grid);
  return State(swapped_grid, swapped_grid.calculate_cost());
}
