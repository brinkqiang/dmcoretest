
#include <time.h>
#include <stdexcept>


static void CrashFunction_INNER()
{
    int *i = reinterpret_cast<int*>(0x45);
    *i = 5;  // crash!
}

static void CrashFunction()
{   
    srand(time(0));
    int x = rand() % 2;
    int y = 10;
    int z = y / x;// crash!

    printf("%d", z);
    CrashFunction_INNER();
}

int main(int argc, char **argv) 
{      
    CrashFunction_INNER();

    printf("did not crash?\n");   
    return 0;   
}
