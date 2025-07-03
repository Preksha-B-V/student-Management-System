#include <stdio.h> 
#include <string.h> 
#define MAX_STUDENTS 100 
struct Student { 
    char usn[15]; 
    char firstName[30]; 
    float cgpa; 
    char phoneNumber[15]; 
    char email[50]; 
    int courses[5][50]; 
}; 
struct Student 
students[MAX_STUDENTS]; 
int totalStudents = 0; 
 
void addStudent() { 
    if (totalStudents < 
MAX_STUDENTS) { 
        struct Student newStudent; 
 
        printf("Enter USN: "); 
        scanf("%s", newStudent.usn); 
 
        printf("Enter First Name: "); 
             scanf("%s",&newStudent.firstname);  
printf("Enter CGPA: "); 
         scanf("%f", &newStudent.cgpa); 
 
printf("Enter Phone Number: "); 
 scanf("%s", newStudent.phoneNumber); 
 
  printf("Enter Email: "); 
        scanf("%s", newStudent.email); 
 
        printf("Enter how many courses:"); 
        scanf("%d",newStudent.courses); 
 
        students[totalStudents++] = newStudent; 
        printf("Student added successfully.\n"); 
    } else { 
        printf("Maximum number of students reached.\n"); 
    }
} 
void displayStudents() { 
      if (totalStudents == 0) { 
        printf("No students to display.\n"); 
    } else { 
        printf("Student Details:\n"); 
        printf("%-15s %-30s %-5s %-15s %-30s\n,%-5d,15d\n", "USN", "First Name", 
"CGPA", "Phone Number", "Email","courses"); 
        for (int i = 0; i < totalStudents; ++i) { 
            printf("%-15s %-30s %-5.2f %-15s %-30s\n,%-5d,15d\n", 
                   students[i].usn, students[i].firstName, students[i].cgpa, 
                   students[i].phoneNumber, students[i].email, students[i].courses); 
        } 
    } 
} 
void deleteStudent() { 
     char usnToDelete[15]; 
    printf("Enter the USN of the student to delete: "); 
    scanf("%s", usnToDelete); 
 
    for (int i = 0; i < totalStudents; ++i) { 
        if (strcmp(students[i].usn, usnToDelete) == 0) { 
            // Move all students after the deleted one up in the array 
            for (int j = i; j < totalStudents - 1; ++j) { 
                students[j] = students[j + 1]; 
            } 
            totalStudents--; 
            printf("Student deleted successfully.\n"); 
            return; 
        } 
    } 
 
    printf("Student with USN %s not found.\n", usnToDelete); 
} 
 
 
void updateStudent() { 
    char usnToUpdate[15]; 
    printf("Enter the USN of the student to update: "); 
    scanf("%s", usnToUpdate); 
     for (int i = 0; i < totalStudents; ++i) { 
        if (strcmp(students[i].usn, usnToUpdate) == 0) {
// Update student details 
            printf("Enter new First Name: "); 
            scanf("%s", students[i].firstName); 
 
            printf("Enter new CGPA: "); 
            scanf("%f", &students[i].cgpa); 
 
            printf("Enter new Phone Number: "); 
            scanf("%s", students[i].phoneNumber); 
 
            printf("Enter new Email: "); 
            scanf("%s", students[i].email); 
 
            printf("Enter how many courses:"); 
            scanf("%s",students[i].courses); 
 
            printf("Student updated successfully.\n"); 
            return; 
        } 
    } 
 
    printf("Student with USN %s not found.\n", usnToUpdate); 
} 
 
 
void displayStudentDetails(struct Student student) { 
    printf("USN: %s\n", student.usn); 
    printf("First Name: %s\n", student.firstName); 
    printf("CGPA: %.2f\n", student.cgpa); 
    printf("Phone Number: %s\n", student.phoneNumber); 
    printf("Email: %s\n", student.email); 
    printf("Courses:%s\n",student.courses); 
    printf("------------------------------\n"); 
} 
void displayStudentByName(char* name) { 
    int found = 0; 
    printf("Details of student(s) with the name '%s':\n", name); 
    for (int i = 0; i < totalStudents; ++i) { 
        if (strcmp(students[i].firstName, name) == 0) { 
            displayStudentDetails(students[i]); 
            found = 1; 
  }
 } 
    if (!found) { 
        printf("No students found with the name '%s'.\n", name); 
    } 
} 
 
void displayStudentByUSN(char* usn) { 
    int found = 0; 
    printf("Details of student with the USN '%s':\n", usn); 
    for (int i = 0; i < totalStudents; ++i) { 
        if (strcmp(students[i].usn, usn) == 0) { 
            displayStudentDetails(students[i]); 
            found = 1; 
            break; // Assuming USN is unique, so once found, break the loop. 
        } 
    } 
    if (!found) { 
        printf("No student found with the USN '%s'.\n", usn); 
    } 
} 
 
int main() { 
    int choice; 
do { 
        printf("\nStudent Management System\n"); 
        printf("1. Add Student\n"); 
        printf("2. Display Students\n"); 
        printf("3. Delete Student\n"); 
        printf("4. Update Student\n"); 
        printf("5. Display by Name or USN\n"); 
        printf("0. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                addStudent(); 
                break; 
  case 2: 
                displayStudents(); 
                break; 
            case 3: 
deleteStudent(); 
                break; 
            case 4: 
                updateStudent(); 
                break; 
            case 5: { 
                printf("Display student details:\n"); 
                printf("1. By Name\n"); 
                printf("2. By USN\n"); 
                printf("Enter your choice: "); 
                int displayChoice; 
                scanf("%d", &displayChoice); 
 
                switch (displayChoice) { 
                    case 1: { 
  char nameToSearch[30]; 
                        printf("Enter the name to search: "); 
                        scanf("%s", nameToSearch); 
                        displayStudentByName(nameToSearch); 
                        break; 
                    } 
                    case 2: { 
                        char usnToSearch[15]; 
                        printf("Enter the USN to search: "); 
                        scanf("%s", usnToSearch); 
                        displayStudentByUSN(usnToSearch); 
                        break; 
                    } 
                    default: 
                        printf("Invalid choice for display.\n"); 
                } 
                break; 
            } 
            case 0: 
                printf("Exiting program.\n"); 
                break; 
default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } while (choice != 0); 
    return 0; 
}
