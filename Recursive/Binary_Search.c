#include<stdio.h>

void search(int array[], int element, int L, int U, int N)
    {
        int M;

        if(L <= U)
        {
            M = (L+U)/2;

            if(element == array[M])
            {
                printf("Element found at index %d\n", M);
                
                return;
            }

            else if(element < array[M])
            {
                search(array, element, L, U - M, N);
            }

            else
            {
                search(array, element, L + M, U, N);
            }
        }

        else
        {
            printf("Element not found!\n");
        }
        
    }

    int main()
    {
        int A[5] = {1, 2, 3, 4, 5};
        int N = 5, ele;

        printf("Enter the element to be searched for\n");
        scanf("%d", &ele);

        search(A, ele, 0, N - 1, N);

        return 0;
    }
