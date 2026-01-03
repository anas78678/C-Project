// STUDENT MANAGEMENT RECORDS //
#include <stdio.h>
struct Student 
{
    int id;
    char name[50];
    int age;
    float marks;
};

FILE *fp;

void addStudent() 
{
    fp = fopen("students.dat", "ab");
    struct Student s;

    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %s", s.name);  
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}

void displayStudents() 
{
    fp = fopen("students.dat", "rb");
    struct Student s;

     if (fp == NULL) 
    {
      printf("No records found!\n");
      return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) 
    {
        printf("ID: %d\nName: %s\nAge: %d\nMarks: %.2f\n\n",
                           s.id, s.name, s.age, s.marks);
    }
    fclose(fp);
}

void searchStudent() 
{
    fp = fopen("students.dat", "rb");
    struct Student s;
    int id, found = 0;

    if (fp == NULL) 
    {
        printf("No records found!\n");
        return;
    }

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) 
    {
        if (s.id == id) 
        {
            printf("\nRecord Found:\n");

            printf("ID: %d\nName: %s\nAge: %d\nMarks: %.2f\n",
                   s.id, s.name, s.age, s.marks);

            found = 1;
            break;
        }
    }
        if (found == 0)
        {
        printf("Record not found \n");
        }

    fclose(fp);
       
}

void updateStudent() 
{
    fp = fopen("students.dat", "rb");
    struct Student arr[100]; 
    int count = 0, i, id, found = 0;

     if (fp == NULL) 
     {
        printf("No records found \n");
        return;
    }
    while (fread(&arr[count], sizeof(struct Student), 1, fp)) 
    {
        count++;
    }
    fclose(fp);

    printf("Enter ID to update: ");
    scanf("%d", &id);

     for (i = 0; i < count; i++) 
    {
        if (arr[i].id == id) 
        {
            printf("Enter new Name: ");
            scanf(" %s", arr[i].name);
            printf("Enter new Age: ");
            scanf("%d", &arr[i].age);
            printf("Enter new Marks: ");
            scanf("%f", &arr[i].marks);
            found = 1;
            break;
        }
    }
    if (found==1) 
    {
      fp = fopen("students.dat", "wb"); 
      fwrite(arr, sizeof(struct Student), count, fp);
      fclose(fp);
      printf("Record Updated!\n");
    } 
    else 
    {
      printf("Record not found!\n");
    }
}

void deleteStudent() 
{
    fp = fopen("students.dat", "rb");
    struct Student arr[100];
    int count = 0, i, id, found = 0;

    while (fread(&arr[count], sizeof(struct Student), 1, fp)) 
    {
        count++;
    }
    fclose(fp);

    printf("Enter ID to delete: ");
    scanf("%d", &id);

  for (i = 0; i < count; i++) 
  {
    if (arr[i].id == id) 
    {
       found = 1;
        for (int j = i; j < count - 1; j++) 
        {
                arr[j] = arr[j + 1]; 
        }
            count--;
            break;
    }
  }
 if (found==1) 
 {
        fp = fopen("students.dat", "wb");
        fwrite(arr, sizeof(struct Student), count, fp);
        fclose(fp);
        printf("Record Deleted!\n");
 } 
 else 
 {
    printf("Record not found!\n");
 }

}

int main() 
{
  int ch;
   
  do 
  {
     printf("\n--- Student Record Management System ---\n");
     printf("1. Add Student\n");
     printf("2. Display Students\n");
     printf("3. Search Student\n");
     printf("4. Update Student\n");
     printf("5. Delete Student\n");
     printf("6. Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &ch);

    switch (ch) 
    {
     case 1: 
     addStudent(); 
     break;
     case 2: 
     displayStudents(); 
     break;
     case 3: 
     searchStudent(); 
     break;
     case 4: 
     updateStudent(); 
     break;
     case 5: 
     deleteStudent(); 
     break; 
     case 6: 
     printf("Exiting program.\n"); 
     break;
     default: 
     printf("Invalid choice!\n");
    }

 } while (ch != 6);

    return 0;
}