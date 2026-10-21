#include "grid.h"
#include "state.h"

#include <vector>
#include <random>
#include <iostream>

int main(int argc, char* argv[]) {
  // check the input
  if (argc < 3 || argc > 3) {
    std::cout << "Input is not valid \n" << "Valid input: int dimension, int seed \n";
    return -1;
  }
  const int dim = std::stoi(argv[1]);
  const int seed = std::stoi(argv[2]);

  // setup the random input
  std::mt19937 engine(seed);

  // initialize the state, output it, simulate until 0 is found
  State state(dim, engine);
  std::cout << state;
  state.simulate();
  return 0;
}
