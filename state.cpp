#include "state.h"
#include "grid.h"

#include <iostream>
#include <vector>
#include <cmath>

std::ostream& operator<<(std::ostream &os, const State& state) { 
  os << state.grid << '\n' << "cost = " << std::to_string(state.cost) << "\n\n";
  return os;
}

State State::swap(int vec_i1, int vec_i2) {
  if (vec_i1 < 0 || vec_i2 < 0 || vec_i1 >= grid.dim * grid.dim || vec_i2 >= grid.dim * grid.dim) {
    return *this;
  }

  std::vector<int> old_grid = grid.grid;
  std::vector<int> new_grid = grid.grid;

  new_grid[vec_i1] = old_grid[vec_i2];
  new_grid[vec_i2] = old_grid[vec_i1];

  Grid swapped_grid(grid.dim, grid.goal, new_grid);
  return State(swapped_grid, swapped_grid.calculate_cost());
}

std::vector<State> State::do_swaps(int vec_i) {
  std::vector<State> states;
  states.reserve(grid.dim * grid.dim - 1 - vec_i);
  for (int i = vec_i; i < grid.dim * grid.dim - 1; i++) {
    states.push_back(swap(vec_i, i));
  }
  return states;
}

void State::iterate() {
  Grid best_grid = grid;
  int best_cost = cost;

  for (int vec_i = 0; vec_i < grid.dim * grid.dim; vec_i++) {
    std::vector<State> new_states = do_swaps(vec_i);
    for (State state : new_states) {
      if (state.cost < best_cost) {
        best_grid = state.grid;
        best_cost = state.cost;
      }
    }
  }
  grid = best_grid;
  cost = best_cost;
}

int State::simulate(std::mt19937& engine) {
  int retries = 0;
  while (cost != 0) {
    *this = State(grid.dim, engine);
    int last_cost = -1;
    while (last_cost != cost) {
      last_cost = cost;
      iterate();
    }
    retries++;
  }
  std::cout << *this;
  std::cout << "retries = " << retries << "\n \n";
  return retries;
}
