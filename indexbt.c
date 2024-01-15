#include <stdio.h>

#define STUDENTS 100
#define MAX_DIVISION_LENGTH 10

// Define credit values for each subject
#define MATH_CREDITS 5
#define PHY_CREDITS 4
#define CHEM_CREDITS 4
#define CS_CREDITS 4
#define BIO_CREDITS 3
#define ENG_CREDITS 2

// Define maximum CGPA
#define MAX_CGPA 10.0

int main() {
    int rollNumber[STUDENTS];
    char name[STUDENTS][50];
    float phymarks[STUDENTS], chemmarks[STUDENTS], mathmarks[STUDENTS], csmarks[STUDENTS], biomarks[STUDENTS], engmarks[STUDENTS], per[STUDENTS];
    char grade[STUDENTS];
    char division[STUDENTS][MAX_DIVISION_LENGTH + 1]; // +1 for the null terminator
    float cgpa[STUDENTS];

    int n, i, searchRoll;

    // Enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Input details for each student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &rollNumber[i]);
        printf("Name: ");
        scanf("%s", name[i]);
        printf("Physics Marks: ");
        scanf("%f", &phymarks[i]);
        printf("Chemistry Marks: ");
        scanf("%f", &chemmarks[i]);
        printf("Mathematics Marks: ");
        scanf("%f", &mathmarks[i]);
        printf("Computer Science Marks: ");
        scanf("%f", &csmarks[i]);
        printf("Biology Marks: ");
        scanf("%f", &biomarks[i]);
        printf("English Marks: ");
        scanf("%f", &engmarks[i]);

        // Calculate percentage
        per[i] = (phymarks[i] + chemmarks[i] + mathmarks[i] + csmarks[i] + biomarks[i] + engmarks[i]) / 600 * 100.0;

        // Calculate CGPA
        cgpa[i] = (phymarks[i] * PHY_CREDITS + chemmarks[i] * CHEM_CREDITS + mathmarks[i] * MATH_CREDITS +
                   csmarks[i] * CS_CREDITS + biomarks[i] * BIO_CREDITS + engmarks[i] * ENG_CREDITS) /
                  (PHY_CREDITS + CHEM_CREDITS + MATH_CREDITS + CS_CREDITS + BIO_CREDITS + ENG_CREDITS) / 10.0 * MAX_CGPA;

        // Divide CGPA by 10 to ensure it's within the range [0, 10]
        cgpa[i] /= 10.0;

        // Ensure CGPA is in the range [0, 10]
        if (cgpa[i] > MAX_CGPA) {
            cgpa[i] = MAX_CGPA;
        } else if (cgpa[i] < 0) {
            cgpa[i] = 0;
        }
    }

    // Calculate the grade and division for each student
    for (i = 0; i < n; i++) {
        // Calculate the grade and division for each student
        if (per[i] >= 90) {
            grade[i] = 'A';
            division[i][0] = '1';
            division[i][1] = 's';
            division[i][2] = 't';
            division[i][3] = '\0'; // Null terminator
        } else if (per[i] >= 80) {
            grade[i] = 'B';
            division[i][0] = '2';
            division[i][1] = 'n';
            division[i][2] = 'd';
            division[i][3] = '\0'; // Null terminator
        } else if (per[i] >= 70) {
            grade[i] = 'C';
            division[i][0] = '3';
            division[i][1] = 'r';
            division[i][2] = 'd';
            division[i][3] = '\0'; // Null terminator
        } else if (per[i] >= 60) {
            grade[i] = 'D';
            division[i][0] = '4';
            division[i][1] = 't';
            division[i][2] = 'h';
            division[i][3] = '\0'; // Null terminator
        } else if (per[i] >= 50) {
            grade[i] = 'E';
            division[i][0] = '5';
            division[i][1] = 't';
            division[i][2] = 'h';
            division[i][3] = '\0'; // Null terminator
        } else {
            grade[i] = 'F';
            division[i][0] = 'N';
            division[i][1] = 'A';
            division[i][2] = '\0'; // Null terminator
        }
    }

    // Search for a student by roll number
    printf("\nEnter the roll number to search: ");
    scanf("%d", &searchRoll);

    // Search for the student and display their details
    int found = 0;
    for (i = 0; i < n; i++) {
        if (rollNumber[i] == searchRoll) {
            found = 1;
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", rollNumber[i]);
            printf("Name: %s\n", name[i]);
            printf("Physics Marks: %.2f\n", phymarks[i]);
            printf("Chemistry Marks: %.2f\n", chemmarks[i]);
            printf("Mathematics Marks: %.2f\n", mathmarks[i]);
            printf("Computer Science Marks: %.2f\n", csmarks[i]);
            printf("Biology Marks: %.2f\n", biomarks[i]);
            printf("English Marks: %.2f\n", engmarks[i]);
            printf("Percentage obtained: %.2f%%\n", per[i]);
            printf("Grade obtained: %c\n", grade[i]);
            printf("Division obtained: %s\n", division[i]);
            printf("CGPA: %.2f\n", cgpa[i]);
            break; // Exit the loop when the student is found
        }
    }

    // If the student is not found
    if (!found) {
        printf("\nStudent with roll number %d not found.\n", searchRoll);
    }

    return 0;
}