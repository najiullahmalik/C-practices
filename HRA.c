#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[40];
    int age, bpm, activity;
    float max_hr, target_hr;
    FILE *fprt;

    printf("========================================\n");
    printf("   HEART RATE HEALTH ANALYZER (basic.v)    \n");
    printf("========================================\n\n");

    printf("Enter Name :");
    scanf("%s", name);
    printf("Enter Age:");
    scanf("%d", &age);
    printf("Heart Rate(BPM):");
    scanf("%d", &bpm);

    printf("------->Select Active Status<-------\n");
    printf("IN Rest Press '1'.\n");
    printf("Post workout Press '2' .\n ");
    scanf("%d", &activity);

    max_hr = 220 - age;
    target_hr = max_hr * 0.70;
    printf("\n------->Diagnostic Report<-------\n ");
    if (age <= 0 || bpm <= 0)
    {
        printf(" Wrong Input <--- Error");
    }
    else
    {
        if (bpm > max_hr)
        {
            printf(" \t'''Danger Detected'''\n\t call----> 1122 'immediately' \n\t 'stay calm as much you can'   ");
        }
        else if (activity == 2 && bpm >= target_hr)
        {
            printf("\t Oh NICE : You are in your Target workout Zone .KEEP IT UP ! \n");
        }
        else if (activity == 1 && bpm <= 100)
        {
            printf("'''It seems fine but contact with your doctor and drink water''' \n  ");
        }
        printf("=====Your Max Heart Rate: %.0f BPM=====\n", max_hr);
        printf("=====your Ideal Workout Heart Rate: %.1f BPM=====\n", target_hr);
    }
    fprt = fopen("Heart Rate.txt", "a");
    if (fprt == NULL)
    {
        printf("FILE ERROR!!!");
        return 1;
    }
    fprintf(fprt, "Name | %s ,Age | %d , BPM | %d , Activity | %d ", name, age, bpm, activity);
    printf("=======================================\n");
    printf(" \n===DATA SAVED IN Heart Rate.txt===\n");
    printf("=======================================\n");
    system("pause");
    return 0;
}