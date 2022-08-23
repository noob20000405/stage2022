#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double determinant(double **, int);

double ** cofactor(double **, int);

double ** transpose(double **, double **, int);

int main(int argc, char * argv[]) {
    FILE * f1 = fopen("../output_dat/o_sol_sys_lin_f.txt", "a");
    FILE * f2 = fopen("../output_dat_log10/o_sol_sys_lin_f.txt", "a");

    int n = atoi(argv[1]);
    double ** M;
    double ** A;
    
    A = (double **)malloc(sizeof(double *) * n);
    M = (double **)malloc(sizeof(double *) * n);
    for (int i = 0 ; i < n ; i++) {
        A[i] = (double *)malloc(sizeof(double) * n);
        M[i] = (double *)malloc(sizeof(double) * n);
    }
    
    // initialiser M (matrice a decomposer), L (comme une matrice idem au debut) et b (vecteur)
    for (int i = 0 ; i < n ; i++) {
       for (int j = 0 ; j < n ; j++) {
            M[i][j] = strtod(argv[i * n + j + 2], NULL);
            A[i][j] = 0;
       }
    }
    
    A = cofactor(M, n);
    
    // produit
    double tmp = 0.0;
    double res = 0.0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            tmp = 0.0;
            for (int k = 0 ; k < n ; k++) {
                
                tmp += (fabs(A[i][k]) * fabs(M[k][j]));
            }
            if (tmp > res) res = tmp;
        }
    }
    
    printf("inverse = \n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("cond = %lf\n", res);
    fprintf(f1, "%lf\n", res);
    fprintf(f2, "%lf\n", log10(res));
    fclose(f1);
    fclose(f2);
        return 0;
}

/*For calculating Determinant of the Matrix */

double determinant(double ** a, int k)

{

  double s = 1, det = 0, (** b);

  int i, j, m, n, c;

  if (k == 1)

    {

     return (a[0][0]);

    }

  else

    {
    
    b = (double **)malloc(sizeof(double*) * k);
    for (i = 0 ; i < k ; i++) {
        b[i] = (double *)malloc(sizeof(double) * k);
    }

     det = 0;

     for (c = 0; c < k; c++)

       {

        m = 0;

        n = 0;

        for (i = 0;i < k; i++)

          {

            for (j = 0 ;j < k; j++)

              {

                b[i][j] = 0;

                if (i != 0 && j != c)

                 {

                   b[m][n] = a[i][j];

                   if (n < (k - 2))

                    n++;

                   else

                    {

                     n = 0;

                     m++;

                     }

                   }

               }

             }

          det = det + s * (a[0][c] * determinant(b, k - 1));

          s = -1 * s;

          }

    }

 

    return (det);

}

 

double ** cofactor(double ** num, int f)

{

 double (** b), (** fac);

 int p, q, m, n, i, j;
 
 b = (double **)malloc(sizeof(double *) * f);
 fac = (double **)malloc(sizeof(double *) * f);
 for (i = 0 ; i < f ; i++) {
    b[i] = (double *)malloc(sizeof(double) * f);
    fac[i] = (double *)malloc(sizeof(double) * f);
 }

 for (q = 0;q < f; q++)

 {

   for (p = 0;p < f; p++)

    {

     m = 0;

     n = 0;

     for (i = 0;i < f; i++)

     {

       for (j = 0;j < f; j++)

        {

          if (i != q && j != p)

          {

            b[m][n] = num[i][j];

            if (n < (f - 2))

             n++;

            else

             {

               n = 0;

               m++;

               }

            }

        }

      }

      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);

    }

  }

  return transpose(num, fac, f);

}

/*Finding transpose of matrix*/ 

double ** transpose(double ** num, double ** fac, int r)

{

    printf("num = \n");
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < r ; j++) {
            printf("%lf ", num[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("fac = \n");
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < r ; j++) {
            printf("%lf ", fac[i][j]);
        }
        printf("\n");
    }
    printf("\n");

  int i, j;

  double (** b), (**inverse), d;

  b = (double **)malloc(sizeof(double *) * r);
  inverse = (double **)malloc(sizeof(double *) * r);
  for (i = 0 ; i < r ; i++) {
    b[i] = (double *)malloc(sizeof(double) * r);
    inverse[i] = (double *)malloc(sizeof(double) * r);
  }

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

         b[i][j] = fac[j][i];

        }

    }

  d = determinant(num, r);

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

        inverse[i][j] = b[i][j] / d;

        }

    }

    return inverse;

}
