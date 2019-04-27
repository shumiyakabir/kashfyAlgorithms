#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
char* dress[20]={"blue_jeans","black_jeans","brown_pants","black_pants",
                 "blue_shirt","red_shirt","sweatshirt","sweater",
                 "sandals","shoes","sneakers","boots",
                 "white_socks","black_socks","orange_socks","wool_socks",
                 "shorts","t_shirt","belt","jacket"};
int cold[7]={0,1,6,7,11,15,19},warm[9]={2,3,4,5,9,12,13,14,18},hot[4]={8,10,16,17};
int i,j,temperature,choice,count,clothing,w[20],dirty[3]={0,6,13},missing[2]={8,19};
void put_on();
bool is_missing();
bool is_dirty();
void cold_weather();
void warm_weather();
void hot_weather();
int main()
{
    do
    {
        printf("\nPress any to continue\t0 to exit \n");
        scanf("%d",&choice);
        if(choice==0)
        {
            exit(0);
        }
        else
        {
            printf("Enter temperature : ");
            scanf("%d",&temperature);
            if(temperature<=20)
            {
                count=-1;
                cold_weather();

            }
            else if(temperature>20&&temperature<40)
            {
                count=-1;
                warm_weather();
            }
            else
            {
                count=-1;
                hot_weather();
            }
        }
    }while(choice!=0);
}
void put_on()
{
    scanf("%d",&clothing);
}
void cold_weather()
{
    printf("\nIt's cold outside.You have to wear below items : \n");
    for(i=0;i<7;i++)
    {
        printf("%d. %s\t",i+1,dress[cold[i]]);
    }
    printf("\nSelect Dress \t 0 to complete\n");
    do
    {
        count++;
        put_on();
        if(cold[clothing-1]==dirty[0]||cold[clothing-1]==dirty[6]||cold[clothing-1]==dirty[19])
        {
            is_dirty();
            count--;
        }
        else if(cold[clothing-1]==missing[8]||cold[clothing-1]==missing[19])
        {
            is_missing();
            count--;
        }
        else
        {
            w[count]=cold[clothing-1];
        }
    }while(clothing!=0);
    if(count==0)
    {
        printf("None of them are selected\n");
    }
    else
    {
        printf("\nYou have worn bellow items .\n");

        for(i=0;i<count;i++)
        {
            printf("%d.  %s\t",i+1,dress[w[i]]);
        }
    }
}
void warm_weather()
{
    printf("\nIt's warm outside.You have to wear below items : \n");
    for(i=0;i<9;i++)
    {
        printf("%d. %s\t",i+1,dress[warm[i]]);
    }
    printf("\nSelect Dress \t 0 to complete\n");
    do
    {
        count++;
        put_on();
        if(warm[clothing-1]==dirty[0]||warm[clothing-1]==dirty[6]||warm[clothing-1]==dirty[19])
        {
            is_dirty();
            count--;
        }
        else if(warm[clothing-1]==missing[8]||warm[clothing-1]==missing[19])
        {
            is_missing();
            count--;
        }
        else
        {
            w[count]=warm[clothing-1];
        }
    }while(clothing!=0);
    printf("\nYou have worn bellow items .\n");
    if(count==0)
    {
        printf("None of them are selected\n");
    }
    else
    {
        for(i=0;i<count;i++)
        {
            printf("%d.  %s\t",i+1,dress[w[i]]);
        }
    }
}
void hot_weather()
{
    printf("\nIt's hot outside.You have to wear below items : \n");
    for(i=0;i<4;i++)
    {
        printf("%d. %s\t",i+1,dress[hot[i]]);
    }
    printf("\nSelect Dress \t 0 to complete\n");
    do
    {
        count++;
        put_on();
        if(hot[clothing-1]==dirty[0]||hot[clothing-1]==dirty[6]||hot[clothing-1]==dirty[19])
        {
            is_dirty();
            count--;
        }
        else if(hot[clothing-1]==missing[8]||hot[clothing-1]==missing[19])
        {
            is_missing();
            count--;
        }
        else
        {
            w[count]=hot[clothing-1];
        }
    }while(clothing!=0);
    printf("\nYou have worn bellow items .\n");
    if(count==0)
    {
        printf("None of them are selected\n");
    }
    else
    {
        for(i=0;i<count;i++)
        {
            printf("%d.  %s\t",i+1,dress[w[i]]);
        }
    }
}
bool is_dirty()
{
    printf("The cloth is_dirty\n");
    return true;
}
bool is_missing()
{
    printf("The cloth is missing \n");
    return true;
}

