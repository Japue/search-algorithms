#include "grid.h"
#include "state.h"

#include <vector>
#include <random>
#include <iostream>

int main(int argc, char* argv[]) {
  // check the input
  if (argc < 4 || argc > 4) {
    std::cout << "Input is not valid \n" << "Valid input: int dimension, int seed \n";
    return -1;
  }
  const int dim = std::stoi(argv[1]);
  const int seed = std::stoi(argv[2]);
  const int iterations = std::stoi(argv[3]);

  // uncomment one of the two modes to run it

  // run one magic square
  // std::mt19937 engine(seed);
  // State state(dim, engine);
  // std::cout << state;
  // state.simulate();

  // run the magic square an amount of iterations and print the average number of retries
  int retries = 0;
  for (int i = seed; i < seed + iterations; i++) {
    std::mt19937 engine(i);
    State state(dim, engine);
    retries += state.simulate(engine);
  }
  std::cout << "average retries = " << static_cast<double>(retries) / static_cast<double>(iterations) << '\n';
  return 0;
}
