#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_NUM_ENROLLMENTS 1000
#define MAXR 1000

void readFileStudents(char fileName[1000]);
void readFileEnrollment(char fileName[1000]);
void readFileCourses(char fileName[1000]);
char calculateGrade(float num);
void printResult(int i);
void printCourse(int i);
void menu();

struct Student {
    int id;
    int day;
    int month;
    int year;
    char fname[100];
    char lname[100];
};

struct Student students[100];

struct Enrollment {
    int stud_id;
    char course_id[100];
    char semester[100];
    float score;
};

struct Enrollment enroll[100];

struct Course {
    char course_id[100];
    char course_name[100];
    int credit;
};

struct Course courses[100];

int main() {

    menu();

    return 0;
}

void loadStudents(struct Student st[], int * numStudents) {

    FILE * readF = fopen("students.txt", "r");

    if (readF == NULL) {
        puts("ERR. Can not open file.");
        exit(0);
    }

    while (!feof(readF)) {
        fscanf(readF, "%d%s%s%d%d%d", & st[ * numStudents].id, st[ * numStudents].fname,
            st[ * numStudents].lname, & st[ * numStudents].day, & st[ * numStudents].month, &
            st[ * numStudents].year);

        * numStudents = * numStudents + 1;
    }

    fclose(readF);
}

int loadCourses(struct Course co[]) {
    int numCourse = 0;

    FILE * readF = fopen("courses.txt", "r");

    if (readF == NULL) {
        puts("ERR. Can not open file.");
        exit(0);
    }

    while (!feof(readF)) {

        fscanf(readF, "%s%s%d", co[numCourse].course_id, co[numCourse].course_name, &
            co[numCourse].credit);

        numCourse++;
    }

    fclose(readF);

    return numCourse;
}

int loadEnrollment(struct Enrollment en[]) {
    int numEnrollment = 0;

    FILE * readF = fopen("enrollment.txt", "r");

    if (readF == NULL) {
        puts("ERR. Can not open file.");
        exit(0);
    }

    while (!feof(readF)) {
        fscanf(readF, "%d%s%s%f", & en[numEnrollment].stud_id, en[numEnrollment].course_id,
            en[numEnrollment].semester, & en[numEnrollment].score);

        numEnrollment++;
    }

    fclose(readF);

    return numEnrollment;
}

void substring(char str[], char sub[], int p, int l) {
    int c = 0;

    while (c < l) {
        sub[c] = str[p + c - 1];
        c++;
    }
    sub[c] = '\0';
}

void countStudentSemester(struct Enrollment en[], int numEnrollment) {
    int i, j;
    int numFound = 0;
    int semesterCounter;
    int found;

    struct uniqueSem {
        char sem[20];
    };

    struct uniqueSem us[MAX_NUM_ENROLLMENTS];

    for (i = 0; i < numEnrollment; i++) {
        found = -1;

        for (j = 0; j < numFound; j++) {

            if (strcmp(en[i].semester, us[j].sem) == 0) {
                found = 1;
                break;
            }
        }

        if (found == -1)
            strcpy(us[numFound++].sem, en[i].semester);
    }

    for (i = 0; i < numFound; i++) {
        semesterCounter = 0;

        for (j = 0; j < numEnrollment; j++)

            if (strcmp(en[j].semester, us[i].sem) == 0)
                semesterCounter++;

        printf("\n%s %d", us[i].sem, semesterCounter);

    }

}

void menu() {
    char * fileName = "students.txt";
    readFileStudents(fileName);
    readFileEnrollment("enrollment.txt");
    readFileCourses("courses.txt");

    struct Student st[MAXR];
    struct Course co[MAXR];
    struct Enrollment en[MAXR];

    int numStudents = 0;
    int numCourse = 0;
    int numEnrollment = 0;

    loadStudents(st, & numStudents);

    numCourse = loadCourses(co);
    numEnrollment = loadEnrollment(en);

    printf("==================");
    
    int index1 = 8;
    int index2 = 10;
    int subIndex = 7;

    while (1) {
        char option[100];
        printf("\n");
        scanf(" %[^\n]%*c", option);
        if ((option[0] == 's') && (option[1] == 'o')) {
            int arr[8];
            for (int i = 0; i < index1; i++) {
                arr[i] = students[i].id;
            }
            for (int i = 0; i < subIndex; i++) {
                for (int j = i + 1; j < index1; j++) {
                    if (arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            printf("\n------------------");

            for (int i = 0; i < index1; i++) {
                for (int j = 0; j < index1; j++) {
                    if (arr[i] == students[j].id) {
                        int index = j;

                        printf("\n%d %s %s %d/%d/%d", students[index].id, students[index].fname, students[index].lname, students[index].month, students[index].day, students[index].year);
                    }
                }
            }

            printf("\n------------------");
            printf("\n==================");

            printf("\n");

        } else if ((option[0] == 's') && (option[7] == 's')) {
            char lname[50];
            char fname[50];
            int id;
            int byear;
            if (option[16] == 'l') {
                int c = 0;
                int l = strlen(option) - 21;
                while (c < l) {
                    lname[c] = option[23 + c - 1];
                    c++;
                }
                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (strcmp(lname, students[i].lname) == 0) {
                        index = i;
                        printResult(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================");
            } else if (option[16] == 'f') {
                int c = 0;
                int l = strlen(option) - 21;
                while (c < l) {
                    fname[c] = option[23 + c - 1];
                    c++;
                }
                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (strcmp(fname, students[i].fname) == 0) {
                        index = i;
                        printResult(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================");
            } else if (option[16] == 'i') {
                int c = 0;
                char ids[20];
                int l = strlen(option) - 18;
                while (c < l) {
                    ids[c] = option[20 + c - 1];
                    c++;
                }
                id = atoi(ids);

                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (students[i].id == id) {
                        index = i;
                        printResult(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================");
            } else if (option[16] == 'b') {
                int c = 0;
                char ids[20];
                int l = strlen(option) - 21;
                while (c < l) {
                    ids[c] = option[23 + c - 1];
                    c++;
                }
                byear = atoi(ids);

                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (students[i].year == byear) {
                        index = i;
                        printResult(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================\n");
            }
        } else if (option[0] == 'e') {

            printf("\n------------------");
            printf("\nBye!");
            break;
        } else if ((option[0] == 's') && (option[7] == 'c')) {
            char cid[5];
            char semester[20];
            char c2[20];
            int c = 0;
            int l = 12;
            while (c < l) {
                c2[c] = option[15 + c - 1];
                c++;
            }

            if (strcmp(c2, "cid_semester") == 0) {
                c = 0;
                l = 2;
                while (c < l) {
                    cid[c] = option[28 + c - 1];
                    c++;
                }
                cid[c] = '\0';
                c = 0;
                l = strlen(option) - 29;
                while (c < l) {
                    semester[c] = option[31 + c - 1];
                    c++;
                }

                printf("-----------");
                int index = -1;
                int cIndex = 0;
                int eIndex = 0;
                for (int j = 0; j < index2; j++) {
                    if (strcmp(cid, courses[j].course_id) == 0) {
                        cIndex = j;
                    }
                }
                printf("\n%s %d", courses[cIndex].course_name, (int) courses[cIndex].credit);
                for (int i = 0; i < 15; i++) {

                    if ((strcmp(semester, enroll[i].semester) == 0) && (strcmp(cid, enroll[i].course_id) == 0)) {

                        eIndex = i;
                        index++;
                        for (int k = 0; k < index2; k++) {
                            if (students[k].id == enroll[eIndex].stud_id) {
                                char grade = calculateGrade(enroll[eIndex].score);
                                printf("\n%s %s %s %d %c", students[k].fname, students[k].lname, enroll[eIndex].semester, (int) enroll[eIndex].score, grade);
                            }
                        }
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                }
                printf("\n------------------");
            } else if (option[14] == 'c' && option[17] == ' ') {
                int c = 0;
                int l = strlen(option) - 17;
                while (c < l) {
                    cid[c] = option[19 + c - 1];
                    c++;
                }

                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (strcmp(cid, courses[i].course_id) == 0) {
                        index = i;
                        printCourse(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================");
            } else if (option[14] == 'c' && option[30] == 'f') {
                int c = 0;
                int l = strlen(option) - 17;
                while (c < l) {
                    cid[c] = option[19 + c - 1];
                    c++;
                }

                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (strcmp(cid, courses[i].course_id) == 0) {
                        index = i;
                        printCourse(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================");
            } else if (option[14] == 'c' && option[30] == 's') {
                int c = 0;
                int l = strlen(option) - 17;
                while (c < l) {
                    cid[c] = option[19 + c - 1];
                    c++;
                }

                printf("------------------");
                int index = -1;
                for (int i = 0; i < index2; i++) {
                    if (strcmp(cid, courses[i].course_id) == 0) {
                        index = i;
                        printCourse(index);
                    }
                }
                if (index == -1) {
                    printf("\nnot found");
                    printf("\n------------------");
                }
                printf("\n==================");
            }

        } else if (option[0] == 'a') {
            char course_id[5];
            char course_name[20];
            float credit;
            int c = 0;
            int l = 2;
            while (c < l) {
                course_id[c] = option[12 + c - 1];
                c++;
            }
            course_id[c] = '\0';
            c = 0;
            int l2 = 0;
            for (int j = 14; j < strlen(option); j++) {
                course_name[c] = option[j];
                if (option[j] == ' ') {
                    l2 = j;
                    break;
                }
               }
            course_name[c] = '\0';

            c = 0;
            l = strlen(option) - l2;
            char temp[20];
            while (c < l) {
                temp[c] = option[(l2 + 2) + c - 1];
                c++;
            }
            credit = atof(temp);
            printf("------------------");
            int index = -1;

            for (int i = 0; i < index2; i++) {
                if (strcmp(course_id, courses[i].course_id) == 0) {
                    index = i;
                    printf("\n\"violation of course id uniqueness. Cannot add the record.\"");
                    printf("\n------------------");
                    printf("\n==================");
                    break;
                }
            }
            if (index == -1) {
                FILE * fp;
                fp = fopen("courses.txt", "a");
                fprintf(fp, "%s %s %f", course_id, course_name, credit);
                fclose(fp);
                
                readFileCourses("courses.txt");

                printf("\nrecord added");
                printf("\n------------------");
                printf("\n==================");
            }

        } else if (option[0] == 'c') {
            char type[90];
            int c = 0;
            int l = strlen(option) - 5;
            while (c < l) {
                type[c] = option[7 + c - 1];
                c++;
            }
            if (strcmp(type, "students") == 0) {
                int count = 0;
                for (int i = 0; i < 15; i++) {
                    if (students[i].id != 0) {
                        count++;
                    }
                }
                printf("\n------------------");
                printf("\ntotal students %d", count);
                printf("\n------------------");
                printf("\n==================");

            } else if (strcmp(type, "students_course") == 0) {
                printf("\n------------------");
                for (int i = 0; i < index1; i++) {
                    int count = 0;
                    for (int j = 0; j < 15; j++) {
                        if (strcmp(courses[i].course_id, enroll[j].course_id) == 0) {
                            count++;
                        }
                    }
                    if (strlen(courses[i].course_id) != 0) {
                        printf("\n%s %d", courses[i].course_id, count);
                    }
                }
                printf("\n------------------");
                printf("\n==================");
            } else if (strcmp(type, "students_semester") == 0) {

                printf("\n------------------");
                countStudentSemester(en, numEnrollment);
                printf("\n------------------");
                printf("\n==================");

            }
            
            
        }
        
        
        else
            
            printf("\nInvalid input.");

    }

}       c++;
      
void printCourse(int i) {
    printf("\n%s %d", courses[i].course_name, (int) courses[i].credit);
    int sIndex = -1;
    int eIndex = -1;
    for (int j = 0; j < 15; j++) {
        if (strcmp(enroll[j].course_id, courses[i].course_id) == 0) {
            eIndex = j;
            for (int k = 0; k < 15; k++) {
                if (students[k].id == enroll[eIndex].stud_id) {
                    sIndex = k;
                    char grade = calculateGrade(enroll[eIndex].score);
                    printf("\n%s %s %s %d %c", students[sIndex].fname, students[sIndex].lname, enroll[eIndex].semester, (int) enroll[eIndex].score, grade);
                }
            }
        }
    }
    printf("\n------------------");
}

void printResult(int index) {
    printf("\n%d %s %s %d/%d/%d", students[index].id, students[index].fname, students[index].lname, students[index].month, students[index].day, students[index].year);
    int cindex = 0;
    int k = 0;
    for (int i = 0; i < 15; i++) {
        if (students[index].id == enroll[i].stud_id) {
            k = i;
            for (int j = 0; j < 15; j++) {
                if (strcmp(courses[j].course_id, enroll[k].course_id) == 0) {
                    cindex = j;
                }
            }
            char grade = calculateGrade(enroll[k].score);
            printf("\n%s %s %s %d %c", enroll[k].course_id, courses[cindex].course_name, enroll[k].semester, (int) enroll[k].score, grade);
        }
    }
    printf("\n------------------");
}

char calculateGrade(float grade) {

    if (grade >= 90.0)
        return 'A';
    else if (grade >= 80.0)
        return 'B';
    else if (grade >= 70.0)
        return 'C';
    else if (grade >= 60.0)
        return 'D';
    else
        return 'F';
}

void readFileEnrollment(char fileName[1000]) {
    FILE * filePtr;
    int stud_id = 0;
    float score = 0.0;
    int position = 0;
    filePtr = fopen(fileName, "r");
    while (fscanf(filePtr, "%d %s %s %f", & stud_id, enroll[position].course_id, enroll[position].semester, & score) != EOF) {
        enroll[position].stud_id = stud_id;
        enroll[position].score = score;
        position++;
    }

    fclose(filePtr);
}

void readFileCourses(char fileName[1000]) {
    FILE * filePtr;
    float credit = 0.0;
    int position = 0;
    filePtr = fopen(fileName, "r");
    while (fscanf(filePtr, "%s %s %f", courses[position].course_id, courses[position].course_name, & credit) != EOF) {
        courses[position].credit = credit;
        position++;

    }

    fclose(filePtr);
}

void readFileStudents(char fileName[1000]) {
    FILE * filePtr;

    char fname[1000];
    char lname[1000];
    int day = 0;
    int month = 0;
    int year = 0;
    int position = 0;
    int id = 0;

    filePtr = fopen(fileName, "r");
    while (fscanf(filePtr, "%d %s %s %d %d %d", & id, students[position].fname, students[position].lname, & day, & month, & year) != EOF) {
        students[position].id = id;
        students[position].day = day;
        students[position].month = month;
        students[position].year = year;
        position++;

    }

    fclose(filePtr);
}
