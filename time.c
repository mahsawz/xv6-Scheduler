#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{

 int pid;
 int status=0;
 int a=3,b=4;	
 pid = fork ();
 if (pid < 0)
   {	
    exec(argv[1],argv);
    printf(1, "exec %s failed\n", argv[1]);
   }
  else if(pid > 0)
 {
    status = waitx(&a,&b); 
    //printf(1,"with status %d ",status);
 }  
 printf(1, "Wait Time = %d\n Run Time = %d with status %d \n",a,b,status);

 exit();
}
