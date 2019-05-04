# Cpp-game-of-life

C++ version of the Game of Life.
This is a basic implementation to test C++ classes and bash scripting


* To execute, type on a terminal:
  * ./run.sh $n1 $n2 $n3
  * @n1 is the x dimension of the seed
  * @n2 is the x dimension of the seed
  * @n3 is the number of iterations of the game of life

The output is a float type "".bin" file of size "n1*n2*n3"

I you have Seismic Unix installed on your computer you can uncomment the last
line inside "run.sh" to automatically plot the output with "xmovie" command.


The seed must be manually modified inside "main.cpp" file. Change the values of
"myCells.data" in the first for loop to a different initial state.
