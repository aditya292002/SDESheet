from threading import *
import time


"""
Let a the string type variable s_res be our shared resource and cirtical section
"""

s_res = ""
mutex = Semaphore(1)   # locks are binary semaphores, so you can also use locks
wrt = Semaphore(1)  # same as above

read_count = 0  # how many readers are reading critical section


def writer(name, content):
    wrt.acquire()
    s_res += content
    wrt.release()


def reader(name):
    mutex.acquire()
    read_count += 1
    if (read_count == 1):
        wrt.acquire()
    mutex.release()

    if (s_res == ""):
        print("-----------String Empty-------------")

    print(s_res)  # reading critical section

    mutex.acquire()
    read_count -= 1
    if (read_count == 1):
        wrt.release()
    mutex.release()


if __name__ == '__main__':

	print()
	print("[+] Start")
	print()

	t1 = Thread(target=reader, args=('Thread-1'))
	t2 = Thread(target=reader, args=('Thread-2'))
	t3 = Thread(target=writer, args=('Thread-3', "abcd"))
	t4 = Thread(target=writer, args=('Thread-4', "efgh"))
	t5 = Thread(target=writer, args=('Thread-5', "uvwx"))
	t6 = Thread(target=reader, args=('Thread-6'))
	t7 = Thread(target=writer, args=('Thread-7', "mnop"))
