#include <iostream>
#include <thread>
#include <semaphore.h>
#include <chrono>

#define N 5

#define LEFT  ((i + N - 1) % N)
#define RIGHT ((i + 1) % N)

#define THINKING 0
#define HUNGRY   1
#define EATING   2

using namespace std;

typedef sem_t semaphore;
/* shared data */
int state[N];

/* mutex acting as binary semaphore */
semaphore mutex_sem;

/* condition variables act as semaphores s[i] */
semaphore s[N];

/* helper functions */
void think(int i) {
    cout << "Philosopher " << i << " is THINKING\n";
    this_thread::sleep_for(chrono::milliseconds(500));
}

void eat(int i) {
    cout << "Philosopher " << i << " is EATING\n";
    this_thread::sleep_for(chrono::milliseconds(500));
}

/* test if philosopher can eat */
void test(int i) {
    if (state[i] == HUNGRY &&
        state[LEFT] != EATING &&
        state[RIGHT] != EATING) {

        state[i] = EATING;
        sem_post(&s[i]);  // up(&s[i])
    }
}

/* take forks */
void take_forks(int i) {
    sem_wait(&mutex_sem);  // down(&mutex)
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING) {
        sem_post(&mutex_sem);  // unlock before waiting
        sem_wait(&s[i]);       // down(&s[i])
    } else {
        sem_post(&mutex_sem);  // unlock if already eating
    }
}

/* put forks */
void put_forks(int i) {
    sem_wait(&mutex_sem);  // down(&mutex)
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex_sem);  // up(&mutex)
}

/* philosopher thread */
void philosopher(int i) {
    while (true) {
        think(i);
        take_forks(i);
        eat(i);
        put_forks(i);
    }
}

int main() {
    thread philosophers[N];

    // Initialize semaphores
    sem_init(&mutex_sem, 0, 1);  // binary semaphore
    for (int i = 0; i < N; i++) {
        state[i] = THINKING;
        sem_init(&s[i], 0, 0);   // semaphore initialized to 0
        philosophers[i] = thread(philosopher, i);
    }

    for (int i = 0; i < N; i++) {
        philosophers[i].join();
    }

    return 0;
}
