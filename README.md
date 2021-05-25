<!-- SPDX-License-Identifier: Apache-2.0 -->
# name-to-motif
A C++ command line application designed to convert names into a musical motif, similar to Bach, Ravel, and Duruflé.

## Building
The recommended way to build the program is to execute `build.sh` (requires CMake >3.15 and uses Ninja generator by default, can be changed to use Makefile generator), which will create a `nametomotif` executable in the `build` directory. You can then install this by executing `sudo cmake --install build`.