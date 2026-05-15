#include <stdio.h>
#include <stdlib.h>

int main()

{
    int age;
    char name[40], gender[20], disease[70];
    float temp;
    FILE *filePtr;

    printf("Enter Patient Name: ");
    scanf("\n %s", name);

    printf("Enter Patient's Age: ");
    scanf("%d", &age);

    printf("Enter Patient's Gender: ");
    scanf("%s", gender);

    printf("Enter Disease Name: ");
    scanf("%s", disease);

    printf("Enter body temperature (celsius): ");
    scanf("%f", &temp);

    filePtr = fopen("patient_data.txt", "a");

    if (filePtr == NULL)
    {
        printf("Error: File opening failed!\n");
        return 1;
    }

    char status[30];
    if (temp < 37.0)
    {
        sprintf(status, "Stable");
    }
    else if (temp >= 37.0 && temp < 38.0)
    {
        sprintf(status, "Mid Fever");
    }
    else
    {
        sprintf(status, "High Fever");
    }

    printf("\n--- Final Medical Report ---");
    printf("\nName: %s\nAGE: %d\nGENDER: %s\nDISEASE: %s\nTEMP: %.1f\nSTATUS: %s\n", name, age, gender, disease, temp, status);

    fprintf(filePtr, "Name: %s | AGE: %d | GENDER: %s | DISEASE: %s | STATUS: %s\n", name, age, gender, disease, status);

    fclose(filePtr);
    printf("\nData saved in 'patient_data.txt'\n");

    system("pause");
    return 0;
}