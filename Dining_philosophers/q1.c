#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int current[5];
int philosopher_array[5] = { 0, 1, 2, 3, 4 };
sem_t helper_mut;
sem_t sem_array[5];
void fork_pick(int idx)
{
    int l = (idx + 4) % 5;
    int r = (idx + 1) % 5;
	sem_wait(&helper_mut);
	current[idx] = 1;
	printf("Person %d is Hungry, wants to eat food\n", idx+1);
	if (current[idx] == 1 && current[l] != 0 && current[r] != 0) {
		current[idx] = 0;
		sleep(2);
		printf("Person %d is taking the fork %d and %d\n", idx + 1, idx+1 , idx);
		printf("Person %d is eating right now\n", idx + 1);
		sem_post(&sem_array[idx]);
	}
	sem_post(&helper_mut);
	sem_wait(&sem_array[idx]);
	sleep(1);
}
void fork_down(int idx)
{
    int l = (idx + 4) % 5;
    int r = (idx + 1) % 5;
	sem_wait(&helper_mut);
	current[idx] = 2;
	printf("Person %d is putting fork %d and %d on the table\n", idx + 1, idx + 1, idx);
	if (current[l] == 1 && current[l] != 0 && current[r] != 0) {
		current[l] = 0;
		sleep(2);
		printf("Person %d is taking the fork %d and %d\n", l + 1, l + 1, l);
		printf("Person %d is eating right now\n", l + 1);
		sem_post(&sem_array[l]);
	}
	if (current[r] == 1 && current[l] != 0 && current[r] != 0) {
		current[r] = 0;
		sleep(2);
		printf("Person %d is taking the fork %d and %d\n", r + 1, r + 1, r );
		printf("Person %d is eating right now\n", r + 1);
		sem_post(&sem_array[r]);
	}
	sem_post(&helper_mut);
}
void* philosopher(void* num)
{
	for (;;) {
		int* i = num;
		sleep(1);
		fork_pick(*i);
		fork_down(*i);
	}
}
int main()
{
	pthread_t th_identities[5];
	sem_init(&helper_mut, 0, 1);
      int a=0;
      while(a<5){
        sem_init(&sem_array[a], 0, 0);
        a++;
    }

    int b = 0;
    while (b<5) {
    pthread_create(&th_identities[b], NULL, philosopher, &philosopher_array[b]);
		printf("Person %d is thinking\n", b + 1);
        b++;
    }
    int c = 0;
    while (c<5) {
        pthread_join(th_identities[c], NULL);
        c++;
    }
}
