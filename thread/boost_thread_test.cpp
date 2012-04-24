#include <iostream>
#include <boost/thread.hpp>
#include <boost/smart_ptr/detail/atomic_count.hpp>

static boost::mutex simple_mutex;

void runnable(long i)
{
  std::cout << "thread " << i << std::endl;
}

int
main()
{
  std::cout << "Very simple thread example without synchronization:\n" << std::endl;
  boost::detail::atomic_count counter(-1);
  const unsigned int THREAD_COUNT = 5;
  boost::thread* threads[THREAD_COUNT];
  
  for (unsigned int i = 0; i < THREAD_COUNT; ++i)
  {
    threads[i] = new boost::thread(runnable, ++counter);
  }
  
  for (unsigned int i = 0; i < THREAD_COUNT; ++i)
  {
    threads[i]->join();
    delete threads[i];
    threads[i] = 0;
  }

  return 0;
}
