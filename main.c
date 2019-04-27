#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *file;
int main()
{
    int number,num[100000],i,j,key,n;
    srand(time(0));

    printf("Array size : ");
    scanf("%d",&number);
    file=fopen("input.txt","w");
    for(i=0;i<number;i++)
    {
        num[i]=rand();
    }
    printf("Array before sorting :\n\n");
    for(i=0;i<number;i++)
    {
        fprintf(file,"%ld\t",num[i]);
        printf("%d\t",num[i]);
    }
    fclose(file);
    clock_t ts,te;
    ts=clock();
    for(i=1;i<number;i++)
    {
        key=num[i];
        j=i-1;
        while(j>=0&&num[j]>key)
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
    }
    te=clock();
    double time_taken=(double)(te-ts)/CLOCKS_PER_SEC;

    file=fopen("output.txt","w");
    printf("\nArray after sorting :\n");
    for(i=0;i<number;i++)
    {
        fprintf(file,"%d\t",num[i]);
        printf("%d\t",num[i]);
    }
    printf("\n");
    fclose(file);
    printf("\n\nThe Insertion sort  %lf seconds to execute .\n",time_taken);
    return 0;
}
