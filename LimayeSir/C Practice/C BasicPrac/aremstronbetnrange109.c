#include <stdio.h>
void main()
{
    int no, tmp, dig, tot = 0;
    system("cls");

    for (no = 100; no < 1000; no++)
    {
        for (tmp = no, tot = 0; tmp > 0; tmp /= 10)
        {
            dig = tmp % 10;
            tot += (dig * dig * dig);
        }
        if (no == tot)
            printf("\nArmstrong numbers:%d", no);
    }
    return;
}
// when we wronly place condition like forgot to mention no==tot then all no from 100 to 999 get printed