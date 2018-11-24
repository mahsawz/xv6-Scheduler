
#include "types.h"
#include "user.h"
#include "countTable.h"

int main(int argc, char **argv) {
    struct countTable ct;
    int res = counts(&ct);
    if (res < 0) {
        return -1;
    }

    printf(1,"------------\n");
    printf(1, "| Fork |: %d \n", ct.counts[0]);
    printf(1, "| Exit |: %d \n", ct.counts[1]);
    printf(1, "| Wait |: %d \n", ct.counts[2]);
    printf(1, "| Pipe |: %d \n", ct.counts[3]);
    printf(1, "| Read |: %d \n", ct.counts[4]);
    printf(1, "| Kill |: %d \n", ct.counts[5]);
    printf(1, "| Exec |: %d \n", ct.counts[6]);
    printf(1, "| Fstat |: %d \n", ct.counts[7]);
    printf(1, "| Chdir |: %d \n", ct.counts[8]);
    printf(1, "| Dup | : %d \n", ct.counts[9]);
    printf(1, "| Getpid |: %d \n", ct.counts[10]);
    printf(1, "| Sbrk |: %d \n", ct.counts[11]);
    printf(1, "| Sleep |: %d \n", ct.counts[12]);
    printf(1, "| Uptime |: %d \n", ct.counts[13]);
    printf(1, "| Open |: %d \n", ct.counts[14]);
    printf(1, "| Write |: %d \n", ct.counts[15]);
    printf(1, "| Mknood |: %d \n", ct.counts[16]);
    printf(1, "| Unlink |: %d \n", ct.counts[17]);
    printf(1, "| Link |: %d \n", ct.counts[18]);
    printf(1, "| Mkdir |: %d \n", ct.counts[19]);
    printf(1, "| Close |: %d \n", ct.counts[20]);
    printf(1, "| counts |: %d \n", ct.counts[21]);
    printf(1,"------------\n");
    exit();
}
