
Question 1

In this dining philosophers problem, we had to implement the program such that no
deadlocks occur with forks and philosophers were able to eat at the same time.
So in the first part of the traditional dining philosophers problem, we had made 
a mutex and an array of 5 semophores indicating each of the philospher.In the second part I have used pthread without using semaphores.
So in this question we try to create a deadlock free solution by creating semaphore which provides to each philosopher.


There are 3 functions in the program: - 

fork_pick

In this program, each condition is checked whether the 2 forks are availbale for
the philosopher to eat the food. If they are available then the current philospher 
is put into the eating phase. If not, then the current philosopher is put into 
waiting phase.

fork_down

In this function, after the philosopher is done eating the food then the forks are
kept beside him so that it is available for the other philosophers. 

philosophers

In this function, an infinite loop is there , which gives chance to each of the philosopher
and the condition is checked for each philosopher that he is able to eat the food or not.


So if one philosopher eating with 2 fork it must wait for the forks to be put down be used by another philosopher in a cyclic sense.


Question 2

The logic of the program is similar to that of the first one. Instead of one mutex and an array 
of semaphores now there are 2, as now bowls are also included.
The conditions checked for this question is different than Q1 , both the fork are available and 
a bowl for a philosopher is available to begin eating.

In one part I have used semaphores and in other part I have used pthread create join repetively without using semaphores.
So basically in this question 2 common sauce bowls are being shared which will revolve around bowl 1 and bowl 0 with the common sharing of forks as well.

