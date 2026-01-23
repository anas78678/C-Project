// STUDENT MANAGEMENT RECORDS //
#include <stdio.h>
struct Student 
{
    int Roll_Number;
    char Full_Name[50];
    char Father_Name[50];
    char Mother_Name[50];
    int age;
    char Gender[10];
    char Email[50];
    long int Phone_Number;
    char Address[100];
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

    printf("Enter Roll Number : ");
    scanf("%d", &s.Roll_Number);
    printf("Enter Full Name : ");
    scanf(" %s", s.Full_Name);  
    printf("Enter Father Name : ");
    scanf("%d", &s.Father_Name);
    printf("Enter Mother Name : ");
    scanf(" %s", s.Mother_Name);
    printf("Enter Age : ");
    scanf("%d", &s.age);
    printf("Enter Gender : ");
    scanf(" %s", s.Gender);
    printf("Enter Email : ");
    scanf(" %s", s.Email);
    printf("Enter Phone Number : ");
    scanf("%ld", &s.Phone_Number);
    printf("Enter Address : ");
    scanf(" %s", s.Address);

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
        printf("Roll Number : %d\n", s.Roll_Number);
        printf("Full Name : %s\n", s.Full_Name);
        printf("Father Name : %s\n", s.Father_Name);
        printf("Mother Name : %s\n", s.Mother_Name);
        printf("Age : %d\n", s.age);
        printf("Gender : %s\n", s.Gender);
        printf("Email : %s\n", s.Email);
        printf("Phone Number : %ld\n", s.Phone_Number);
        printf("Address : %s\n", s.Address);
        printf("-----------------------\n");

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

    printf("Enter Roll number to search: ");
    scanf("%d", &id);
    

    while (fread(&s, sizeof(s), 1, fp)) 
    {
        if (s.Roll_Number == id) 
        {
            printf("\nRecord Found:\n");

            printf("Roll Number : %d\n", s.Roll_Number);
            printf("Full Name : %s\n", s.Full_Name);
            printf("Father Name : %s\n", s.Father_Name);
            printf("Mother Name : %s\n", s.Mother_Name);
            printf("Age : %d\n", s.age);
            printf("Gender : %s\n", s.Gender);
            printf("Email : %s\n", s.Email);
            printf("Phone Number : %ld\n", s.Phone_Number);
            printf("Address : %s\n", s.Address);

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

    printf("Enter Roll number to update: ");
    scanf("%d", &id);

     for (i = 0; i < count; i++) 
    {
        if (arr[i].Roll_Number == id) 
        {
            printf("Enter new Full Name : ");
            scanf(" %s", arr[i].Full_Name);
            printf("Enter new Father Name : ");
            scanf(" %s", arr[i].Father_Name);
            printf("Enter new Mother Name : ");
            scanf(" %s", arr[i].Mother_Name);
            printf("Enter new Age : ");
            scanf("%d", &arr[i].age);
            printf("Enter new Gender : ");
            scanf(" %s", arr[i].Gender);
            printf("Enter new Email : ");   
            scanf(" %s", arr[i].Email);
            printf("Enter new Phone Number : ");
            scanf("%ld", &arr[i].Phone_Number);
            printf("Enter new Address : ");
            scanf(" %s", arr[i].Address);

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

    printf("Enter Roll number to delete: ");
    scanf("%d", &id);

  for (i = 0; i < count; i++) 
  {
    if (arr[i].Roll_Number == id) 
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