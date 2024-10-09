#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to hold student data
struct Student
{
    char srn[20];
    char name[50];
    char branch[50];
    int sem;
    struct Student *prev;
    struct Student *next;
};
// Structure for header node
struct Header
{
    int numStudents;
    struct Student *first;
};
// Function to create a new student node
struct Student *createStudentNode()
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}
// Function to get Student data
struct Student *getStudentData()
{
    struct Student *newStudent = createStudentNode();
    printf("Enter SRN: ");
    scanf("%s", newStudent->srn);
    printf("Enter Name: ");
    scanf(" %[^\n]s", newStudent->name);
    printf("Enter Branch: ");
    scanf(" %[^\n]s", newStudent->branch);
    printf("Enter Semester: ");
    scanf("%d", &newStudent->sem);
    return newStudent;
}
// Function to insert a student at the front of the DLL
void insertAtFront(struct Header *header)
{
    struct Student *newStudent = getStudentData();
    if (header->first == NULL)
    {
        header->first = newStudent;
    }
    else
    {
        newStudent->next = header->first;
        header->first->prev = newStudent;
        header->first = newStudent;
    }
    header->numStudents++;
    printf("Student inserted at the front.\n");
}
// Function to display the DLL
void display(struct Header *header)
{
    if (header->first == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }
    printf("Number of students: %d\n", header->numStudents);
    printf("SRN\nBranch\nSemester\nName\n");
    struct Student *current = header->first;
    while (current != NULL)
    {
        printf("%s\n%s\n%d\n%s\n", current->srn, current->branch, current->sem, current->name);
        current = current->next;
    }
}
// Function to insert a student at the end of the DLL
void insertAtEnd(struct Header *header)
{
    struct Student *newStudent = getStudentData();
    if (header->first == NULL)
    {
        header->first = newStudent;
    }
    else
    {
        struct Student *current = header->first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newStudent;
        newStudent->prev = current;
    }
    header->numStudents++;
    printf("Student inserted at the end.\n");
}
// Function to insert a student at a given position in the DLL
void insertAtPosition(struct Header *header, int position)
{
    if (position < 1 || position > header->numStudents + 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1)
    {
        insertAtFront(header);
        return;
    }
    if (position == header->numStudents + 1)
    {
        insertAtEnd(header);
        return;
    }
    struct Student *newStudent = getStudentData();
    struct Student *current = header->first;
    for (int i = 1; i < position - 1; i++)
    {
        current = current->next;
    }
    newStudent->prev = current;
    newStudent->next = current->next;
    current->next->prev = newStudent;
    current->next = newStudent;
    header->numStudents++;
    printf("Student inserted at position %d.\n", position);
}
// Function to delete a student from the front of the DLL
void deleteFromFront(struct Header *header)
{
    if (header->first == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }
    struct Student *temp = header->first;
    header->first = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = NULL;
    }
    free(temp);
    header->numStudents--;
    printf("Student deleted from the front.\n");
}
// Function to delete a student from the end of the DLL
void deleteFromEnd(struct Header *header)
{
    if (header->first == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }
    if (header->first->next == NULL)
    {
        free(header->first);
        header->first = NULL;
    }
    else
    {
        struct Student *current = header->first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
    }
    header->numStudents--;
    printf("Student deleted from the end.\n");
}
// Function to delete a student based on SRN
void deleteBySRN(struct Header *header, const char *srn)
{
    if (header->first == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }
    struct Student *current = header->first;
    while (current != NULL)
    {
        if (strcmp(current->srn, srn) == 0)
        {
            if (current->prev == NULL)
            {
                header->first = current->next;
            }
            else
            {
                current->prev->next = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            header->numStudents--;
            printf("Student with SRN %s deleted.\n", srn);
            return;
        }
        current = current->next;
    }
    printf("Student with SRN %s not found.\n", srn);
}
int main()
{
    struct Header header;
    header.numStudents = 0;
    header.first = NULL;
    int choice;
    char srnToDelete[20];
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Display DLL\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Front\n");
        printf("6. Delete from End\n");
        printf("7. Delete by SRN\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtFront(&header);
            break;
        case 2:
            display(&header);
            break;
        case 3:
            insertAtEnd(&header);
            break;
        case 4:
        {
            int position;
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&header, position);
        }
        break;
        case 5:
            deleteFromFront(&header);
            break;
        case 6:
            deleteFromEnd(&header);
            break;
        case 7:
            printf("Enter SRN to delete: ");
            scanf("%s", srnToDelete);
            deleteBySRN(&header, srnToDelete);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    // Free allocated memory before exiting
    struct Student *current = header.first;
    while (current != NULL)
    {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}