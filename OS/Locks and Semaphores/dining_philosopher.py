from threading import *
import time
import random


fork = [Semaphore(1) for n in range(5)] #initialising array of semaphore i.e forks
mutex = [Semaphore(1) for n in range(5)] #initialising array of semaphore i.e forks


def pick_fork(name, i):
	mutex[i].acquire()
	fork[i].acquire();
	fork[(i+1) % 5].acquire();
	mutex[i].release()	


	print(name)
	print (f'Philosopher eating, by {name}')
	print(f'forks begin used {i + 1} and  {i + 2}')
	time.sleep(3)
	print(f"Done eating {name}")
	print()

	mutex[i].acquire()
	fork[i].release()
	fork[(i + 1) % 5].release()
	mutex[i].release()
	print(f'-----------------------{name} exited----------------------------------')



def main():
	print()
	print("[+] Start")
	print()

	t1 = Thread(target=pick_fork, args=('Thread-1',0))
	t2 = Thread(target=pick_fork, args=('Thread-2',1))
	t3 = Thread(target=pick_fork, args=('Thread-3',2))
	t4 = Thread(target=pick_fork, args=('Thread-4',3))
	t5 = Thread(target=pick_fork, args=('Thread-5',4))

		
	t1.start()
	t2.start()
	t3.start()
	t4.start()
	t5.start()

	
	t1.join()
	t2.join()
	t3.join()
	t4.join()
	t5.join()

	print()
	print("[+] Done")


if __name__ == '__main__':
	main()