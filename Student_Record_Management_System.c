// STUDENT RECORD MANAGEMENT SYSTEM

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
    char Phone_Number[15];
    char Address[100];
};

FILE *fp;


void clearInputBuffer()
{
    while (getchar() != '\n');
}


void addStudent()
{
    struct Student s;
    fp = fopen("students.dat", "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll Number : ");
    scanf("%d", &s.Roll_Number);
    clearInputBuffer();

    printf("Enter Full Name : ");
    fgets(s.Full_Name, sizeof(s.Full_Name), stdin);

    printf("Enter Father Name : ");
    fgets(s.Father_Name, sizeof(s.Father_Name), stdin);

    printf("Enter Mother Name : ");
    fgets(s.Mother_Name, sizeof(s.Mother_Name), stdin);

    printf("Enter Age : ");
    scanf("%d", &s.age);
    clearInputBuffer();

    printf("Enter Gender : ");
    fgets(s.Gender, sizeof(s.Gender), stdin);

    printf("Enter Email : ");
    fgets(s.Email, sizeof(s.Email), stdin);

    printf("Enter Phone Number : ");
    fgets(s.Phone_Number, sizeof(s.Phone_Number), stdin);

    printf("Enter Address : ");
    fgets(s.Address, sizeof(s.Address), stdin);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}


void displayStudents()
{
    struct Student s;
    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("Roll Number : %d\n", s.Roll_Number);
        printf("Full Name   : %s", s.Full_Name);
        printf("Father Name : %s", s.Father_Name);
        printf("Mother Name : %s", s.Mother_Name);
        printf("Age         : %d\n", s.age);
        printf("Gender      : %s", s.Gender);
        printf("Email       : %s", s.Email);
        printf("Phone : %s\n", s.Phone_Number);
        printf("Address     : %s", s.Address);
        printf("---------------------------\n");
    }

    fclose(fp);
}


void searchStudent()
{
    struct Student s;
    int id, found = 0;

    fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.Roll_Number == id)
        {
            printf("\nRecord Found:\n");
            printf("Roll Number : %d\n", s.Roll_Number);
            printf("Full Name   : %s", s.Full_Name);
            printf("Father Name : %s", s.Father_Name);
            printf("Mother Name : %s", s.Mother_Name);
            printf("Age         : %d\n", s.age);
            printf("Gender      : %s", s.Gender);
            printf("Email       : %s", s.Email);
            printf("Phone       : %d\n", s.Phone_Number);
            printf("Address     : %s", s.Address);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");

    fclose(fp);
}


void updateStudent()
{
    struct Student s;
    FILE *temp;
    int id, found = 0;

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll Number to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.Roll_Number == id)
        {
            printf("Enter New Full Name : ");
            fgets(s.Full_Name, sizeof(s.Full_Name), stdin);

            printf("Enter New Father Name : ");
            fgets(s.Father_Name, sizeof(s.Father_Name), stdin);

            printf("Enter New Mother Name : ");
            fgets(s.Mother_Name, sizeof(s.Mother_Name), stdin);

            printf("Enter New Age : ");
            scanf("%d", &s.age);
            clearInputBuffer();

            printf("Enter New Gender : ");
            fgets(s.Gender, sizeof(s.Gender), stdin);

            printf("Enter New Email : ");
            fgets(s.Email, sizeof(s.Email), stdin);

            printf("Enter New Phone Number : ");
            scanf("%ld", &s.Phone_Number);
            clearInputBuffer();

            printf("Enter New Address : ");
            fgets(s.Address, sizeof(s.Address), stdin);

            found = 1;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Record updated successfully!\n");
    else
        printf("Record not found!\n");
}


void deleteStudent()
{
    struct Student s;
    FILE *temp;
    int id, found = 0;

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll Number to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.Roll_Number == id)
        {
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Record deleted successfully!\n");
    else
        printf("Record not found!\n");
}


int main()
{
    int choice;

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
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: addStudent(); 
        break;
        case 2: displayStudents(); 
        break;
        case 3: searchStudent(); 
        break;
        case 4: updateStudent(); 
        break;
        case 5: deleteStudent(); 
        break;
        case 6: printf("Exiting program...\n"); 
        break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
