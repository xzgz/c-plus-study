#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

struct args_struct {
  int thread_id;
};

void *thread_run_func(void *args) {
  args_struct *args_str = (args_struct *)args;
  int thread_id = args_str->thread_id;
  int delay = 1e9;
  for(int i = 0; i < 4; ++i) {
    while(delay > 0) { delay--; }
    cout << thread_id << endl;
    delay = 1e9;
  }
}

int main() {
  const int thread_num = 4;
  pthread_t thread_id[thread_num];
  args_struct *args_array = new args_struct[thread_num];
  for(int i = 0; i < thread_num; ++i) {
    args_array[i].thread_id = i;
    pthread_create(&thread_id[i], 0, thread_run_func, &args_array[i]);
  }
  for(int i = 0; i < thread_num; ++i) {
    pthread_join(thread_id[i], 0);
  }
  delete [] args_array;

  return 0;
}

