#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Missing arguments, Usage: %s size_of_array operator\n", argv[0]);
        return 0;
    }

    int size = atoi(argv[1]);
    char op = *argv[2];
    int arr[size];

    printf("Enter the elements of the array!\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int result = 0;  
    if (op == '+') {
        for (int i = 0; i < size; i++) 
        {
            result += arr[i];
        }
        printf("The sum is: %d\n", result);
    } 
    else if (op == '*') 
    {
        result = 1;  
        for (int i = 0; i < size; i++) 
        {
            result *= arr[i];
        }
        printf("The multiplication is: %d\n", result);
    } 
    else if (op == '-')
    {
        int num;
        printf("Enter a large number to subtract the array numbers from it:\n");
        scanf("%d",&num);
        for (int i = 0; i < size; i++) 
        {
            num = num - arr[i];
        }
        printf("The result from subtraction is: %d\n", num);
    }
    else 
    {
        printf("Operation not permitted\n");
    }

    return 0;
}
