/**
 * Deadlock with Mutex Locks
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *do_work_one(void *param);
void *do_work_two(void *param);

/* create and initialize the mutex locks */
pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

int main(void)
{
  pthread_mutex_init(&first_mutex, NULL);
  pthread_mutex_init(&second_mutex, NULL);

  pthread_t tid1, tid2;
  pthread_attr_t attr1, attr2;

  pthread_attr_init(&attr1);
  pthread_attr_init(&attr2);
  pthread_create(&tid1, &attr1, do_work_one, NULL);
  pthread_create(&tid2, &attr2, do_work_two, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  return 0;
}

/* thread one runs in this function */
void *do_work_one(void *param)
{
  pthread_mutex_lock(&first_mutex);
  pthread_mutex_lock(&second_mutex);

  cout << "do_work_one: Hey!" << endl;

  pthread_mutex_unlock(&second_mutex);
  pthread_mutex_unlock(&first_mutex);

  pthread_exit(0);
}
/* thread two runs in this function */
void *do_work_two(void *param)
{
  pthread_mutex_lock(&second_mutex);
  pthread_mutex_lock(&first_mutex);

  cout << "do_work_two: Hey!" << endl;

  pthread_mutex_unlock(&first_mutex);
  pthread_mutex_unlock(&second_mutex);

  pthread_exit(0);
}
