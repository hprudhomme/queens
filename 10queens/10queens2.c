#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//Number of queens
int N = 10;
int sol = 0;

//chessboard
int grille[10][10] =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
        
    };

void ft_putchar (char c)
{
    write(1, &c, 1);
}

// Fonction d'affichage
void affichage (int grille[10][10])
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            printf( ((j+1)%1) ? "%d " : "%d|", grille[i][j]);
        }
        putchar('\n');
        if (!((i+1)%1))
            puts("------------------");
    }
    puts("\n\n");
}

bool absentSurLigne (int grille[10][10], int i)
{
    for (int j=0; j < 10; j++)
        if (grille[i][j] == 6)
            return false;
    return true;
}

bool absentSurColonne (int grille[10][10], int j)
{
    for (int i=0; i < 10; i++)
        if (grille[i][j] == 6)
            return false;
    return true;
}

// bool hg (int grille[10][10], int i, int j)
// {
//     int ci;
//     int cj;

//     if (i == 0 || j == 0)
//     {
//         return true;
//     }
    
//     ci = i - 1;
//     cj = j - 1;

//     while (ci != - 1 && cj != -1)
//     {   
//         if (grille[ci][cj] == 6)
//         {
//             return false;
//         }
        
//         ci--;
//         cj--;
//     }
//     return true;
// }

// bool hd (int grille[10][10], int i, int j)
// {
//     int ci;
//     int cj;

//     if (i == 0 || j == 9)
//     {
//         return true;
//     }

//     ci = i - 1;
//     cj = j + 1;

//     while (ci != -1 && cj != 10)
//     {   
//         if (grille[ci][cj] == 6)
//         {
//             return false;
//         }
        
//         ci--;
//         cj++;
//     }
//     return true;
// }

// bool bd (int grille[10][10], int i, int j)
// {
//     int ci;
//     int cj;

//     if (i == 9 || j == 9)
//     {
//         return true;
//     }

//     ci = i + 1;
//     cj = j + 1;

//     while (ci != 10 && cj != 10)
//     {   
//         if (grille[ci][cj] == 6)
//         {
//             return false;
//         }
        
//         ci++;
//         cj++;
//     }
//     return true;
// }

// bool bg (int grille[10][10], int i, int j)
// {
//     int ci;
//     int cj;

//     if (i == 9 || j == 0)
//     {
//         return true;
//     }

//     ci = i + 1;
//     cj = j - 1;

//     while (ci != 10 && cj != -1)
//     {   
//         if (grille[ci][cj] == 6)
//         {
//             return false;
//         }
        
//         ci++;
//         cj--;
//     }
//     return true;
// }

bool absentSurDiag (int grille[10][10], int i, int j)
{   
    int k,l;
    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(grille[k][l] == 6)
                    return 0;
            }
        }
    }
    return 1;
}

bool estValide (int n)
{
    int i, j;
    //if n is 0, solution found
    if (sol == 724);

    if(n==0)
        {
             for(i=0;i<N;i++)
             {
                 for(j=0;j<N;j++)
                 {
                     if (grille[i][j] == 6)
                     {
                         ft_putchar(j + 48);
                     }               
                 }
             }
            ft_putchar('\n');
            ft_putchar('\n');
            return 1;
        }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            //checking if we can place a queen here or not
            //queen will not be placed if the place is being attacked
            //or already occupied
            if(absentSurLigne(grille,i) && absentSurColonne(grille,j) && absentSurDiag(grille,i,j) && (grille[i][j]!=1))
            {
                grille[i][j] = 6;
                //recursion
                //wether we can put the next queen with this arrangment or not
                if(estValide(n-1))
                {
                    return 1;
                }
                grille[i][j] = 0;
            }
        }
    }
    return 0;
}

int main (void)
{
    int i, j;

    printf("Grille avant\n");
    affichage(grille);
    
    estValide(N);

    
    printf("Grille apres\n");
    affichage(grille);
}