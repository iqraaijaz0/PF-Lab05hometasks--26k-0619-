#include <stdio.h>

int main() {
    int dept_choice;
    int theory_marks, practical_marks;
    double attendance;
    
    printf("Select Department (1: Computer Science, 2: Mathematics): ");
    scanf("%d", &dept_choice);
    
    printf("Enter Theory Marks: ");
    scanf("%d", &theory_marks);
    
    printf("Enter Practical Marks: ");
    scanf("%d", &practical_marks);
    
    printf("Enter Attendance Percentage: ");
    scanf("%lf", &attendance);
    
    int is_passed = 0;
    
    switch(dept_choice) {
        case 1:
            if(theory_marks >= 50 && practical_marks >= 50 && attendance >= 80.0) {
                is_passed = 1;
            }
            break;
        case 2:
            if(theory_marks >= 60 && practical_marks >= 40 && attendance >= 75.0) {
                is_passed = 1;
            }
            break;
    }
    
    int is_distinct = (theory_marks >= 85 && practical_marks >= 80 && attendance >= 90.0);
    
    int seat_remainder = theory_marks % 3;
    
    printf("\n--- Final Examination Report ---\n");
    
    if(dept_choice == 1) {
        printf("Selected Department: Computer Science\n");
        printf("Applicable Passing Requirements: Theory >= 50, Practical >= 50, Attendance >= 80%%\n");
    } else if(dept_choice == 2) {
        printf("Selected Department: Mathematics\n");
        printf("Applicable Passing Requirements: Theory >= 60, Practical >= 40, Attendance >= 75%%\n");
    }
    
    printf("Theory Marks: %d\n", theory_marks);
    printf("Practical Marks: %d\n", practical_marks);
    printf("Attendance: %.1f%%\n", attendance);
    
    printf("Final Examination Result: %s\n", is_passed ? "Passed" : "Failed");
    printf("Distinction Eligibility: %s\n", is_distinct ? "Eligible for Distinction" : "Not Eligible for Distinction");
    
    if(seat_remainder == 0) {
        printf("Seat Category: Seat Category A\n");
    } else if(seat_remainder == 1) {
        printf("Seat Category: Seat Category B\n");
    } else if(seat_remainder == 2) {
        printf("Seat Category: Seat Category C\n");
    }
    
    return 0;
}
