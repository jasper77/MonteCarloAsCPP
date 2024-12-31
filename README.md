# MonteCarloAsCPP
Using modern C++ to generate monte carlo simulations from a data set.

This is a C++ exercise to use modern C++. I first wrote the Python version; see that
README for explanations of why you might want to use this.
https://github.com/jasper77/MonteCarloFromCSV


## Dependencies
### argparse
* Linux: sudo apt install libargparse-dev
* Mac: brew install argparse

### googletest
* Mac: brew install googletest

## Notes
This is built with cmake. The CMake file is made to run on either arm or x86, but only tested
on arm.

```
$ cd build
$ cmake ..
$ cmake --build .
$ ctest
./run_mc_simulations ./run_mc_simulations -h
```