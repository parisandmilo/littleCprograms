#include <stdio.h>
#include <stdlib.h>

 // recursive Tower of Hanoi
 // not only does it tell you which disks to move, it also shows you where
 // good tool if you're learning how to play or want to visualise the actual disks moving
 // limited to 3 pegs

/* this code is currently quite ugly
 to do:
- hide ''empty" arrays - i.e. arrays with no pegs
- clean up print statements and put them into a function
- make variable names more obvious
- extend to n pegs
- choose final peg
*/
void solve(int, int, char, char, char,int[],int[],int[]);

int main()
{
    int numberOfPegs, i, j, k, l, m;
    char start, aux = '\0', final = '\0';

    printf("How many pegs do you want to play with? \n");
    scanf("%d", &numberOfPegs);

    printf("Which peg do you want to start on? (Enter A, B or C)\n");
    scanf("%s", &start);

    int A[numberOfPegs];  //creates arrays for each peg
    int B[numberOfPegs];
    int C[numberOfPegs];

    for (m = 0; m < numberOfPegs; m++)
    {
        A[m] = 0;
        B[m] = 0;
        C[m] = 0;
    }

    switch (start) {
        case 'A':
            for (i = 0; i < numberOfPegs; i++)   //fills starting peg
            {
                A[i] = i+1;
            }
            aux = 'B';
            final = 'C';
            break;
        case 'B':
            for (i = 0; i < numberOfPegs; i++)
            {
                B[i] = i+1;
            }
            aux = 'A';
            final = 'C';
            break;
        case 'C':
            for (i = 0; i < numberOfPegs; i++)
            {
                C[i] = i+1;
            }
            aux = 'B';
            final = 'A';
            break;
        default:
            printf("Invalid peg. \n" );
    }
    printf("Starting pegs on A: \n");
    for (j = 0; j < numberOfPegs;  j++)   //PRINT starting peg
    {
        printf("%d \t", A[j]);
    }
    printf("\nStarting pegs on B: \n");
    for (k = 0; k < numberOfPegs;  k++)   //PRINT starting peg
    {
        printf("%d \t", B[k]);
    }
    printf("\nStarting pegs on C: \n");
    for (l = 0; l < numberOfPegs;  l++)   //print starting peg
    {
        printf("%d \t", C[l]);
    }

    printf("\nSolve the Tower of Hanoi:\n");
    solve(numberOfPegs, numberOfPegs, start, final, aux, A, B, C);
    switch (final) {
      case 'A':
          printf("\nYour disks are now on peg A: \n");
          for (j = 0; j < numberOfPegs;  j++)   //print pegs
          {

              printf("%d \t", A[j]);
          }
      case 'B':
          printf("\nYour disks are now on peg B: \n");
          for (k = 0; k < numberOfPegs;  k++)   //print pegs
          {
              printf("%d \t", B[k]);
          }
      case 'C':
          printf("\nYour disks are now on peg C: \n");
          for (l = 0; l < numberOfPegs;  l++)   //print pegs
          {
              printf("%d \t", C[l]);
          }
        }
    printf("\nSUCCESS!\n");
    return 0;
}

void solve(int numberOfPegs, int fixed, char startpeg, char finalpeg, char auxpeg, int a[], int b[], int c[])   // a b c are the arrays representing the pegs
{
    int i, j, k, l, p, q, r;
    int temp = numberOfPegs;
    if (temp == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c", startpeg, finalpeg);
        if (startpeg == 'A' && finalpeg == 'C')
        {
            for (i = 0; i < numberOfPegs; i++)   //finds first nonzero integer in array and transfers it
            {
                if (a[i] != 0)
                {
                    c[i] = a[i];
                    a[i] = 0;
                    break;
                }
            }
        }
        if (startpeg == 'A' && finalpeg == 'B')
        {
            for (i = 0; i < numberOfPegs; i++)   //finds first nonzero integer in array and transfers it
            {
                if (a[i] != 0)
                {
                    b[i] = a[i];
                    a[i] = 0;
                    break;
                }
            }
        }
        if (startpeg == 'B' && finalpeg == 'C')
        {
            for (i = 0; i < numberOfPegs; i++)   //finds first nonzero integer in array and transfers it
            {
                if (b[i] != 0)
                {
                    c[i] = b[i];
                    b[i] = 0;
                    break;
                }
            }
        }
        if (startpeg == 'B' && finalpeg == 'A')
        {
            for (i = 0; i < numberOfPegs; i++)   //finds first nonzero integer in array and transfers it
            {
                if (b[i] != 0)
                {
                    a[i] = b[i];
                    b[i] = 0;
                    break;
                }
            }
        }
        if (startpeg == 'C' && finalpeg == 'A')
        {
            for (i = 0; i < numberOfPegs; i++)   //finds first nonzero integer in array and transfers it
            {
                if (c[i] != 0)
                {
                    a[i] = c[i];
                    c[i] = 0;
                    break;
                }
            }
        }
        if (startpeg == 'C' && finalpeg == 'B')
        {
            for (i = 0; i < numberOfPegs; i++)   //finds first nonzero integer in array and transfers it
            {
                if (c[i] != 0)
                {
                    b[i] = c[i];
                    c[i] = 0;
                    break;
                }
            }
        }
        printf("\nA: \n");
        for (p = 0; p < fixed;  p++)   //print pegs
        {
            if (a[p] != 0)
            {
              printf("%d \t", a[p]);
            }
        }
        printf("\nB: \n");
        for (q = 0; q < fixed;  q++)   //print pegs
        {
            if (b[q] != 0)
            {
              printf("%d \t", b[q]);
            }
        }
        printf("\nC: \n");
        for (r = 0; r < fixed;  r++)   //print pegs
        {
            if (c[r] != 0)
            {
              printf("%d \t", c[r]);
            }
        }
        return;
    }
    solve(temp - 1, fixed, startpeg, auxpeg, finalpeg, a, b, c);
    printf("\nMove disk %d from peg %c to peg %c", temp, startpeg, finalpeg);

    if (startpeg == 'A' && finalpeg == 'C')
    {
        c[numberOfPegs-1] = numberOfPegs;
        for (i = 0; i <= numberOfPegs; i++) {
            if (a[i] == numberOfPegs) {
                a[i] = 0;
                break;
            }
        }

    }
    if (startpeg == 'A' && finalpeg == 'B')
    {
        b[numberOfPegs-1] = numberOfPegs;
        for (i = 0; i <= numberOfPegs; i++) {
            if (a[i] == numberOfPegs) {
                a[i] = 0;
                break;
            }
        }
    }
    if (startpeg == 'B' && finalpeg == 'C')
    {
        c[numberOfPegs-1] = numberOfPegs;
        for (i = 0; i <= numberOfPegs; i++) {
            if (b[i] == numberOfPegs) {
                b[i] = 0;
                break;
            }
        }
    }
    if (startpeg == 'B' && finalpeg == 'A')
    {
        a[numberOfPegs-1] = numberOfPegs;
        for (i = 0; i <= numberOfPegs; i++) {
            if (b[i] == numberOfPegs) {
                b[i] = 0;
                break;
            }
        }
    }
    if (startpeg == 'C' && finalpeg == 'A')
    {
        a[numberOfPegs-1] = numberOfPegs;
        for (i = 0; i <= numberOfPegs; i++) {
            if (c[i] == numberOfPegs) {
                c[i] = 0;
                break;
            }
        }
    }
    if (startpeg == 'C' && finalpeg == 'B')
    {
        b[numberOfPegs-1] = numberOfPegs;
        for (i = 0; i <= numberOfPegs; i++) {
            if (c[i] == numberOfPegs) {
                c[i] = 0;
                break;
            }

        }

    }


          printf("\nA: \n");
          for (j = 0; j < fixed;  j++)   //print pegs
          {
              if (a[j] != 0)
              {
                printf("%d \t", a[j]);
              }
          }
          printf("\nB: \n");
          for (k = 0; k < fixed;  k++)   //print pegs
          {
              if (b[k] != 0)
              {
                printf("%d \t", b[k]);
              }
          }
          printf("\nC: \n");
          for (l = 0; l < fixed;  l++)   //print pegs
          {
              if (c[l] != 0)
              {
                printf("%d \t", c[l]);
              }
          }


    solve(temp - 1, fixed, auxpeg, finalpeg, startpeg, a, b, c);

}
