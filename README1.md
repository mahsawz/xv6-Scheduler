## XV6 Process Scheduling
In phase 2, We try to create a basic system-call. The first step is to extend the current proc structure and add new fields ctime, etime and rtime for creation time, end-time and rabletime, runningtime and int flag,  respectively of a process. When a new process gets created the kernel code should update the process creation time. The run-time should get updated after every clock tick for the process. To extract this information from the kernel add a new system call which extends wait. The new call will be
int waitx(int *wtime, int *rtime)
The two arguments are pointers to integers to which waitx will assign the total number of clock ticks during which process was waiting and total number of clock ticks when the process was running. The return values for waitx should be same as that of wait system-call. Created a test program which utilises the waitx system-call by creating a ‘time’ like command for the same.

1. ADDING SYSTEM CALL (TIME CALCULATION)  :
   * waitx() system call was added modifying user.h , usys.S , syscall.h ,syscall.c , sysproc.c , defs.h .
   * proc.c contains the actual waitx() system call. Copied the code of wait() and modified it as follows - -Searched for a zombie child of parent in the proc table. -When the child was found , following pointers were updated :
     ''' 
       wtime= p->runningtime -  p->rabletime ;
       rtime=p->etime-p->ctime1;
     '''
   * sysproc.c is just used to call waitx() which is present in proc.c . The sys_waitx() function in sysproc.c although does one job - it passes the parameters (rtime,wtime) to the waitx() of proc.c , just like all other system calls do.
   * In scheduler() , unningtime and int flag keep track of the first response to proc
   * In allocproc(), rabletime keeps track of the RUNNABLE time

2. MODIFICATIONS DONE TO proc structure :
   * ctime1 (records CREATION TIME)
   * etime (records END TIME)
   * runningtime (calculates first time of RUN )
   * rabletime(calculates Runnable)
   * Flag checks whether runningtimeis being set or not
   * fields added to proc structure of proc.h file

In phase 3, We implemented Multi-Level Feedback Queue schedule algorithm to replace the Round Robin scheduler in xv6. This is done by adding three queues(or more - it is optional) associating with three different priority values, and reprogram scheduler to choose processes from the queues. Details of the changes are listed below.

### Modifications:
  * In proc.h, added a new filed int priority to struct proc, and added a 2-D array of pointers and an array of three integers to ptable. The array of pointers represent the three queues, while these tree integers represent how many processes are in each queue.
  * Changed pinit() in proc.c, added three instructions to initialize the newly added integers.
  * Modified functions:fork(), userinit(), yield(), wakeup1(), kill(). In fork() and userinit(), the new arrived process will be added to the end of queue 0. In wakeup1() and kill(), the corresponding process will be added to the queue associating with its priority. In yield(), the process will decrease its priority level(by increasing it priority value), and added to the end of corresponding queue.
  * Modified function scheduler(). Now this function will trying to get process from the queues instead of the original ptable.proc. It will look up the queue 0 first and move to other queues if no runnable processes found. Once it find a process to switch to, it will loop again from the beginning queue 0.
  * Implemented a new function resetPriority() in proc.c. It will be called in trap(), every xmsec. It will move all runnable process to queue 0, and delete them from its original queue. Besides that, it will also reset all processes priority value to 0.

### Per-CPU variables :
We've got an array of CPU data, cpus.
We can access specific CPU stuff via cpus[SOME_CPU_IDENTIFIER].
In order to get current CPU identifier, we call getcpu(), which is slow.
When we do this, we MUST stop interrupts from happening, to make sure we stay within the same CPU.