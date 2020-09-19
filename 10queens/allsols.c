#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//Number of queens
int N = 6;
int sol = 0;

//chessboard
// int grille[10][10] =
//     {
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0}
        
//     };

int grille[6][6] =
    {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

void ft_putchar (char c)
{
    write(1, &c, 1);
}

// Fonction d'affichage
void affichage (int grille[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf( ((j+1)%1) ? "%d " : "%d|", grille[i][j]);
        }
        putchar('\n');
        if (!((i+1)%1))
            puts("------------------");
    }
    puts("\n\n");
}

bool absentSurLigne (int grille[N][N], int i)
{
    for (int j=0; j < 10; j++)
        if (grille[i][j] == 6)
            return false;
    return true;
}

bool absentSurColonne (int grille[N][N], int j)
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

bool absentSurDiag (int grille[N][N], int i, int j)
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

bool solIsValide(int *s, int newsol)
{   
    int i = 0;
    while (i != 10)
    {
        if (s[i] == newsol)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

bool estValide (int n)
{
    int i, j;
    int s[724];
    int newsol;
    newsol = 0;

    if (sol == 10)
        {   
            printf("Il y a %d solutions\n", sol);
            return 1;
        }

    // if (n == 0)

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {   
            if(n==0)
            {
                for(i=0;i<N;i++)
                {
                    for(j=0;j<N;j++)
                    {
                        if (grille[i][j] == 6)
                        {
                            ft_putchar(j + 48);
                            newsol = newsol * 10 + j;
                        }               
                    }
                }
                ft_putchar('\n');
                printf("newsol : %d\n", newsol);
                ft_putchar('\n');
                if (solIsValide)
                {
                    s[sol] = newsol;
                    printf("tab %d\n", s[sol]);
                    sol++;
                    n = N;                   
                }
                if (!solIsValide)
                {
                    return 0;
                }
                
            }
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

    // printf("Grille avant\n");
    // affichage(grille);
    
    estValide(N);

    
    printf("Grille apres\n");
    affichage(grille);
}