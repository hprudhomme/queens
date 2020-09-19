#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

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

bool hg (int grille[10][10], int i, int j)
{
    int ci;
    int cj;

    if (i == 0 || j == 0)
    {
        return true;
    }
    
    ci = i - 1;
    cj = j - 1;

    while (ci != - 1 && cj != -1)
    {   
        if (grille[ci][cj] == 6)
        {
            return false;
        }
        
        ci--;
        cj--;
    }
    return true;
}

bool hd (int grille[10][10], int i, int j)
{
    int ci;
    int cj;

    if (i == 0 || j == 9)
    {
        return true;
    }

    ci = i - 1;
    cj = j + 1;

    while (ci != -1 && cj != 10)
    {   
        if (grille[ci][cj] == 6)
        {
            return false;
        }
        
        ci--;
        cj++;
    }
    return true;
}

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
    for(k=0;k<10;k++)
    {
        for(l=0;l<10;l++)
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


bool estValide (int grille[10][10], int position)
{   
    int n;
    n = 0;

    if (position == 98)
        return true;

    int i = position/10, j = position%10;

            if (absentSurLigne(grille,i) && absentSurColonne(grille,j) && absentSurDiag(grille,i,j))
            {
                grille[i][j] = 6;
                while (position % 10 != 0)
                    n++;
                if (j == 0)
                {
                    if (estValide (grille, position + 10))
                    return 1;
                }
                else
                {
                    if (estValide (grille, position + n))
                    return 1;
                }
                grille[i][j] = 0;
            }
            estValide (grille, position + 1);
            
    return 0;
                     
}

int main (void)
{
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

    int n  = 10;

    printf("Grille avant\n");
    affichage(grille);

    estValide(grille, 0);

    printf("Grille apres\n");
    affichage(grille);
}