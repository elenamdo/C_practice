/* Maria Maldonado 1000061100 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHARACTERS 10
#define ARRAY_SIZE 6

void Print_Menu();
void Exit_Choice();
void Print_Records();
void Search_First_Name();
void Search_Last_Name();
void Search_Grade();
void American_Students();
void British_Students();
void Sort_First_Name();
void Sort_Last_Name();
void Sort_Score();

struct array
{
      char first_name[MAX_CHARACTERS];
      char last_name[MAX_CHARACTERS];
      float score;
      char nationality[MAX_CHARACTERS];
};

void Print_Menu()
{
printf("\nSelect a numeric choice from the given menu:\n");
printf("\n0) Exit the program.\n");
printf("\n1) Clear screen.\n");
printf("\n2) Print all student records.\n");
printf("\n3) Search records by first name.\n");
printf("\n4) Search records by last name.\n");
printf("\n5) Search records by Grade (>=).\n");
printf("\n6) Print List, total, count, and average score for all American students.\n");
printf("\n7) Save the records of British students in British.txt.\n");
printf("\n8) Sort all records by First name.\n");
printf("\n9) Sort all records by Last name.\n");
printf("\n10) Sort all records by scores.\n");
};

void Exit_Choice()
{
    printf("Process returned 0 (0x0)\nPress any key to continue.\n\n");
};

void Print_Records(struct array student[])
{
    int i;
    printf("\n\n");
    for (i=0;i<ARRAY_SIZE;i++)
    {
        printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
};

void Search_First_Name(struct array student[])
{
    int i;
    char input[MAX_CHARACTERS];
    printf("\n\nEnter student's first name: ");
    scanf("%s", input);
    for (i=0;i<ARRAY_SIZE;i++)
    {
        if (strcmp(input, student[i].first_name) == 0)
            printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
}

void Search_Last_Name(struct array student[])
{
    int i;
    char input[MAX_CHARACTERS];
    printf("\n\nEnter student's last name: ");
    scanf("%s", input);
    for (i=0;i<ARRAY_SIZE;i++)
    {
        if (strcmp(input, student[i].last_name) == 0)
            printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
}

void Search_Grade(struct array student[])
{
    int i;
    float input;
    printf("\n\nEnter grade: ");
    scanf("%f", &input);
    for (i=0;i<ARRAY_SIZE;i++)
    {
        if (input == student[i].score)
            printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
}

void American_Students(struct array student[])
{
      int i, count=0;
      float sum=0;
      printf("\n");
      for (i=0;i<ARRAY_SIZE;i++)
      {
          if (strcmp(student[i].nationality, "American") == 0)
          {
              count++;
              sum += student[i].score;
              printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
          }
      }
      printf("\nTotal = %0.1f\tCount = %d\tAverage = %0.1f\n", sum, count, sum/count);
}

void British_Students(struct array student[])
{
    int i;
    FILE *fw = fopen("British.txt","w");
    for (i=0;i<ARRAY_SIZE;i++)
    {
        if (strcmp(student[i].nationality, "British") == 0)
        {
            fw = fopen("British.txt","a");
            fputs(student[i].first_name, fw);
            fputs("\t\t", fw);
            fputs(student[i].last_name, fw);
            fputs("\t\t", fw);
            fprintf(fw, "%0.1f", student[i].score);
            fputs("\n", fw);
            fclose(fw);
        }
    }
    printf("\nBritish.txt\n");
    fw = fopen("British.txt", "r");
    char ch;
    int file;
    while ((file = fgetc(fw)) != EOF)
    {
        putchar(file);
    }
}

void Sort_First_Name(struct array student[])
{
    int i,j,k, return_value;
    struct array temp_student;
    for (i=0;i<ARRAY_SIZE-1;i++)
    {
        for(j=0;j<ARRAY_SIZE-i-1;j++)
        {
            return_value = strcmp(student[j].first_name, student[j+1].first_name  );
            if (return_value > 0)
            {
                strcpy(temp_student.first_name, student[j].first_name);
                strcpy(temp_student.last_name, student[j].last_name);
                temp_student.score = student[j].score;
                strcpy(temp_student.nationality, student[j].nationality);
                strcpy(student[j].first_name, student[j+1].first_name);
                strcpy(student[j].last_name, student[j+1].last_name);
                student[j].score = student[j+1].score;
                strcpy(student[j].nationality, student[j+1].nationality);
                strcpy(student[j+1].first_name, temp_student.first_name);
                strcpy(student[j+1].last_name, temp_student.last_name);
                student[j+1].score = temp_student.score;
                strcpy(student[j+1].nationality, temp_student.nationality);
            }
        }
    }
    printf("\n\n");
    for (i=0;i<ARRAY_SIZE;i++)
    {
        printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
}

void Sort_Last_Name(struct array student[])
{
    int i,j,k, return_value;
    struct array temp_student;
    for (i=0;i<ARRAY_SIZE-1;i++)
    {
        for(j=0;j<ARRAY_SIZE-i-1;j++)
        {
            return_value = strcmp(student[j].last_name, student[j+1].last_name  );
            if (return_value > 0)
            {
                strcpy(temp_student.first_name, student[j].first_name);
                strcpy(temp_student.last_name, student[j].last_name);
                temp_student.score = student[j].score;
                strcpy(temp_student.nationality, student[j].nationality);
                strcpy(student[j].first_name, student[j+1].first_name);
                strcpy(student[j].last_name, student[j+1].last_name);
                student[j].score = student[j+1].score;
                strcpy(student[j].nationality, student[j+1].nationality);
                strcpy(student[j+1].first_name, temp_student.first_name);
                strcpy(student[j+1].last_name, temp_student.last_name);
                student[j+1].score = temp_student.score;
                strcpy(student[j+1].nationality, temp_student.nationality);
            }
        }
    }
    printf("\n\n");
    for (i=0;i<ARRAY_SIZE;i++)
    {
        printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
}

void Sort_Score(struct array student[])
{
    int i,j,k, return_value;
    struct array temp_student;
    for (i=0;i<ARRAY_SIZE-1;i++)
    {
        for(j=0;j<ARRAY_SIZE-i-1;j++)
        {
            if (student[j].score > student[j+1].score)
            {
                strcpy(temp_student.first_name, student[j].first_name);
                strcpy(temp_student.last_name, student[j].last_name);
                temp_student.score = student[j].score;
                strcpy(temp_student.nationality, student[j].nationality);
                strcpy(student[j].first_name, student[j+1].first_name);
                strcpy(student[j].last_name, student[j+1].last_name);
                student[j].score = student[j+1].score;
                strcpy(student[j].nationality, student[j+1].nationality);
                strcpy(student[j+1].first_name, temp_student.first_name);
                strcpy(student[j+1].last_name, temp_student.last_name);
                student[j+1].score = temp_student.score;
                strcpy(student[j+1].nationality, temp_student.nationality);
            }
        }
    }
    printf("\n\n");
    for (i=0;i<ARRAY_SIZE;i++)
    {
        printf("%-15s%-15s%.1f\n", student[i].first_name, student[i].last_name, student[i].score);
    }
}

int main(void)
{
    struct array student[ARRAY_SIZE]= {
                                {"Henry", "Ford", 3.9, "American"},
                                {"Isaac", "Newton", 3.7, "British"},
                                {"Albert", "Einstein", 4.1, "American"},
                                {"Marie", "Curie", 4.2, "French"},
                                {"Charles", "Darwin", 3.7, "British"},
                                {"Nikola", "Tesla", 3.8, "American"}
                              };
    int choice;
    Print_Menu();

    do
    {
        printf("\n\nEnter a choice.\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                Exit_Choice();
                break;
            case 1:
                Print_Menu();
                break;
            case 2:
                Print_Records(student);
                break;
            case 3:
                Search_First_Name(student);
                break;
            case 4:
                Search_Last_Name(student);
                break;
            case 5:
                Search_Grade(student);
                break;
            case 6:
                American_Students(student);
                break;
            case 7:
                British_Students(student);
                break;
            case 8:
                Sort_First_Name(student);
                break;
            case 9:
                Sort_Last_Name(student);
                break;
            case 10:
                Sort_Score(student);
                break;
      }
    } while(choice!=0);

};
