#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>
#include <mpfr.h>

mpfr_t * determinant(mpfr_t **, int);

mpfr_t ** cofactor(mpfr_t **, int);

mpfr_t ** transpose(mpfr_t **, mpfr_t **, int);

int main(int argc, char * argv[]) {
    FILE * f1 = fopen("../output_dat/o_sol_sys_lin_MPFR.txt", "a");
    FILE * f2 = fopen("../output_dat_log10/o_sol_sys_lin_MPFR.txt", "a");

    int n = atoi(argv[1]);
    mpfr_t ** M;
    mpfr_t ** A;
    
    A = (mpfr_t **)malloc(sizeof(mpfr_t *) * n);
    M = (mpfr_t **)malloc(sizeof(mpfr_t *) * n);
    for (int i = 0 ; i < n ; i++) {
        A[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * n);
        M[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * n);
    }
    
    // initialiser M (matrice a decomposer), L (comme une matrice idem au debut) et b (vecteur)
    for (int i = 0 ; i < n ; i++) {
       for (int j = 0 ; j < n ; j++) {
            mpfr_init2(M[i][j], 200);
            mpfr_set_d(M[i][j], strtod(argv[i * n + j + 2], NULL), MPFR_RNDD);
            mpfr_init2(A[i][j], 200);
            mpfr_set_d(A[i][j], 0, MPFR_RNDD);
       }
    }
    
    A = cofactor(M, n);
    
        printf("inverse = \n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            mpfr_out_str(stdout, 10, 0, A[i][j], MPFR_RNDD);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    
    // produit
    mpfr_t tmp1, tmp2, res;
    mpfr_init2(tmp1, 200);
    mpfr_init2(tmp2, 200);
    mpfr_init2(res, 200);
    mpfr_set_d(tmp1, 0, MPFR_RNDD);
    mpfr_set_d(tmp2, 0, MPFR_RNDD);
    mpfr_set_d(res, 0, MPFR_RNDD);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            mpfr_set_d(tmp1, 0, MPFR_RNDD);
            mpfr_set_d(tmp2, 0, MPFR_RNDD);
            for (int k = 0 ; k < n ; k++) {
                mpfr_abs(A[i][k], A[i][k], MPFR_RNDD);
                mpfr_abs(M[k][j], M[k][j], MPFR_RNDD);
                mpfr_mul(tmp1, A[i][k], M[k][j], MPFR_RNDU);
                mpfr_add(tmp2, tmp2, tmp1, MPFR_RNDD);
            }
            if (mpfr_cmp(tmp2, res)) mpfr_set(res, tmp2, MPFR_RNDD);
        }
    }
    

    
    printf("conditionnement = ");
    mpfr_out_str(stdout, 10, 0, res, MPFR_RNDD);
    printf("\n");
    
    double res_d = mpfr_get_d(res, MPFR_RNDD);
    fprintf(f1, "%lf\n", res_d);
    fprintf(f2, "%lf\n", log10(res_d));
    
    fclose(f1);
    fclose(f2);
    return 0;
}

/*For calculating Determinant of the Matrix */

mpfr_t * determinant(mpfr_t ** a, int k)

{

  mpfr_t s, (* det), (** b), tmp;
  mpfr_init2(s, 200);
  mpfr_init2(tmp, 200);
  mpfr_set_d(s, 1, MPFR_RNDD);
  mpfr_set_d(tmp, 0, MPFR_RNDD);
  
  det = (mpfr_t *)malloc(sizeof(mpfr_t));
  mpfr_init2(*det, 200);
  mpfr_set_d(*det, 0, MPFR_RNDD);

  int i, j, m, n, c;

  if (k == 1)

    {

     return &(a[0][0]);

    }

  else

    {
    
    b = (mpfr_t **)malloc(sizeof(mpfr_t*) * k);
    for (i = 0 ; i < k ; i++) {
        b[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * k);
    }

     mpfr_set_d(*det, 0, MPFR_RNDD);

     for (c = 0; c < k; c++)

       {

        m = 0;

        n = 0;

        for (i = 0;i < k; i++)

          {

            for (j = 0 ;j < k; j++)

              {
                
                mpfr_init2(b[i][j], 200);
                mpfr_set_d(b[i][j], 0.0, MPFR_RNDD);

                if (i != 0 && j != c)

                 {
                    
                   mpfr_set(b[m][n], a[i][j], MPFR_RNDD);

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
             
          mpfr_mul(tmp, a[0][c], *determinant(b, k - 1), MPFR_RNDU);
          mpfr_mul(tmp, tmp, s, MPFR_RNDU);
          mpfr_add(*det, *det, tmp, MPFR_RNDD);
          mpfr_mul_si(s, s, -1, MPFR_RNDD);

          }

    }

    return det;

}

 

mpfr_t ** cofactor(mpfr_t ** num, int f)

{

 mpfr_t (** b), (** fac), tmp;

 int p, q, m, n, i, j;
 
 b = (mpfr_t **)malloc(sizeof(mpfr_t *) * f);
 fac = (mpfr_t **)malloc(sizeof(mpfr_t *) * f);
 for (i = 0 ; i < f ; i++) {
    b[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * f);
    fac[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * f);
 }
 
 mpfr_init2(tmp, 200);

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
            
            mpfr_init2(b[m][n], 200);
            mpfr_set(b[m][n], num[i][j], MPFR_RNDD);

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
      
      mpfr_set(tmp, *determinant(b, f - 1), MPFR_RNDD);
      mpfr_mul_d(tmp, tmp, pow(-1, q + p), MPFR_RNDU);
      mpfr_init2(fac[q][p], 200);
      mpfr_set(fac[q][p], tmp, MPFR_RNDD);

    }

  }

  return transpose(num, fac, f);

}

/*Finding transpose of matrix*/ 

mpfr_t ** transpose(mpfr_t ** num, mpfr_t ** fac, int r)

{
    printf("num = \n");
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < r ; j++) {
        mpfr_out_str(stdout, 10, 0, num[i][j], MPFR_RNDD);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    printf("fac = \n");
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < r ; j++) {
        mpfr_out_str(stdout, 10, 0, fac[i][j], MPFR_RNDD);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");

  int i, j;

  mpfr_t (** b), (**inverse), d, tmp;
  
  mpfr_init2(tmp, 200);

  b = (mpfr_t **)malloc(sizeof(mpfr_t *) * r);
  inverse = (mpfr_t **)malloc(sizeof(mpfr_t *) * r);
  for (i = 0 ; i < r ; i++) {
    b[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * r);
    inverse[i] = (mpfr_t *)malloc(sizeof(mpfr_t) * r);
  }

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {
         
         mpfr_init2(b[i][j], 200);
         mpfr_set(b[i][j], fac[j][i], MPFR_RNDD);

        }

    }   
  
  mpfr_init2(d, 200);
  mpfr_set(d, *determinant(num, r), MPFR_RNDD);

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {
        
        mpfr_div(tmp, b[i][j], d, MPFR_RNDD);
        mpfr_init2(inverse[i][j], 200);
        mpfr_set(inverse[i][j], tmp, MPFR_RNDD);

        }

    }
    printf("inverse = \n");
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < r ; j++) {
        mpfr_out_str(stdout, 10, 0, inverse[i][j], MPFR_RNDD);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    return inverse;

}
