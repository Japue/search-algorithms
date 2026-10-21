#include "grid.h"

#include <iostream>
#include <random>
#include <vector>

int calculate_goal(const std::vector<int>& grid, const int dim);

struct State {
  Grid grid;
  int cost;

  // constructors
  State() {
    grid = Grid();
    cost = grid.calculate_cost();
  }

  State(Grid grid_) {
    grid = grid_;
    cost = grid_.calculate_cost();
  }

  State(Grid grid_, const int cost_) {
    grid = grid_;
    cost = cost_;
  }

  State(const int dim_, std::mt19937& engine) {
    grid = Grid(dim_, engine);
    cost = grid.calculate_cost();
  }

  // define the << operator to output a state
  friend std::ostream& operator<<(std::ostream &os, const State& state);
  
  // define the action in the 4 different directions
  State swap_right(int vec_pos);
  State swap_left(int vec_pos);
  State swap_up(int vec_pos);
  State swap_down(int vec_pos);
  std::vector<State> do_swaps(int vec_pos);

  // functions for the algorithm
  void iterate();
  void simulate();
};
