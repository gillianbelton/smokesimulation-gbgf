Build Instructions (Athena with Makefile)
==================
(cd into starter3, aka main file)
$ mkdir build
$ cd build
$ cmake ..
$ make
then run:
 ./a3 t 0.0009

(the cloth is diagonally fixed, and should drape down)

The sample solution binaries are in sample_solution/

Submission
==========

Collaboration:
I did not collaborate with anyone.

References:
-piazza

Known Issues:
-the reset button does reset the scene, but over time, hitting the reset button over and over again reduces the stability of the scene and often makes it explode or freeze. My hypothesis is that some data structure isn’t being resent properly, because the computation seems to build off of the previous one somehow. Debugging has shown that the data structure doesn’t seem to be increasing in size with each “R”, but computation certainly slows. I would imagine that the acceleration/velocity values aren’t being set back to 0 somewhere. 