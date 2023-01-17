# Operating-System
The repository contains code for assignment done as part of Operating Systems course. We perform multiplication of two arbitrarily large matrices using parallelism
provided by the Linux process and threads libraries.

## Description of Master and Child Processes
* S is the master process which spawns two child processes P1 and P2.
* P1 which takes three filenames (in1.txt, in2.txt and out.txt) as
command line arguments. The first two files (in1.txt and in2.txt) contain two matrices of
arbitrary size but satisfying the criteria for matrix multiplication. The sizes will be passed
in the command line. P1 spawns n threads which each read row(s) and column(s) each
from in1.txt and in2.txt.
    * Different threads read different parts of the file.
    * We record the time that it takes to read the entire file into memory with different
      number of threads (1, 2, … n).
    * We also plot time against the number of threads for different input sizes.

* P2 uses IPC mechanisms to receive the rows and columns
  read by P1. P2 spawns multiple threads to compute the cells in the product matrix. The
  program stores the product matrix in the file out.txt.
* The scheduler program S spawns 2 children processes which exec to become the
processes P1 and P2. The scheduling algorithm used is Round Robin (RR), for which the time quantum
is given as user input.

A high level diagram indicating the creation of various processes is shown below.


<img width="294" alt="image" src="https://user-images.githubusercontent.com/59122752/212822023-63ee1e93-5a51-4de9-93b2-988c1fd2126c.png">


**Note**: All the actions are performed assuming a uniprocessor environment.
