#This is an example of the use of static and shared libraries#

The program uses umfpack to solve a simple linear system.

Look at the Makefile. If you compile with static libraries (make
static), you need to specify all dependencies af libumfpack.a and the
dependencies of the dependencies... a lot.

With the shared library versione (make shared) you just have to
specify -lumfpack!
