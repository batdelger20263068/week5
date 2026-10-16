#include <stdio.h>
#include <string.h>

typedef struct {
    int number;
    char name[20];
    double grade;
} Student;

Student *find_student(Student a[], int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].name, name) == 0) {
            return &a[i];
        }
    }

    return NULL;
}

int main(void) {
    Student students[3] = {
        {1, "Kim", 4.3},
        {2, "Lee", 4.0},
        {3, "Park", 4.1}
    };

    char name[20];
    double new_grade;

    if (scanf("%19s %lf", name, &new_grade) != 2) {
        return 0;
    }

    Student *student = find_student(students, 3, name);

    if (student == NULL) {
        printf("not found\n");
    } else {
        student->grade = new_grade;

        for (int i = 0; i < 3; i++) {
            printf("%d %s %.1f\n",
                   students[i].number,
                   students[i].name,
                   students[i].grade);
        }
    }

    return 0;
}
