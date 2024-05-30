#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTD 100 
#define MAXITEMS 10 
#define STLEN 51 

char getLetterGrade(float score) {
    if(score > 90.00)
        return 'A';
    else if(score >= 80.00)
        return 'B';
    else if(score >= 70.00)
        return 'C';
    return 'F';
}

int getMaxTotalIdx(float totals[], int n) {
    int c, index = 0;
    for (c = 1; c < n; c++) {
        if (totals[c] > totals[index]) {
            index = c;
        }
    }
    return index;
}

int lookup(char names[][STLEN], char key[STLEN], int n) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        if (key[i] >= 65 && key[i] <= 90) {
            key[i] = key[i] + 32;
        }
    }

    for (i = 0; i < n; i++) {
        if (strcmp(names[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

void writeData(FILE *out, char ids[][STLEN], char names[][STLEN], float totals[], int n) {
    int i, maxIndex;
    char c;

    fprintf(out, "Summary of students:\n========\n");

    for (i = 0; i < n; i++) {
        c = getLetterGrade(totals[i]);
        fprintf(out, "ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i], totals[i], c);
    }

    fprintf(out, "========\n");

    maxIndex = getMaxTotalIdx(totals, n);
    fprintf(out, "First student with the highest total is %s %s %.2f\n", ids[maxIndex], names[maxIndex], totals[maxIndex]);
}

int main() {
    char ids[MAXSTD][STLEN]; 
    char names[MAXSTD][STLEN];
    float grades[MAXSTD][MAXITEMS]; 
    float totals[MAXSTD]; 
    int numOfStudents, totalQuiz, maxIndex, pos, i, j;
    float totalScore = 0, sum = 0;
    char letterGrade, searchName[STLEN];

    FILE *fIN = fopen("grades.txt", "r");
    FILE *fOUT = fopen("summary.txt", "w");

    if (fOUT == NULL) {
        printf("Error: Cannot open file.");
        exit(1);
    }

    if (fIN == NULL) {
        printf("Error: Cannot open file.");
        exit(1);
    }

    fscanf(fIN, "%d %d", &numOfStudents, &totalQuiz);

    for (i = 0; i < numOfStudents; i++) {
        fscanf(fIN, "%s %s %f %f", ids[i], names[i], &grades[i][0], &grades[i][1]);

        for (j = 2; j < totalQuiz + 2; j++) {
            fscanf(fIN, "%f", &grades[i][j]);
        }
    }

    for (i = 0; i < numOfStudents; i++) {
        totalScore = 0;
        sum = 0;
        totalScore += grades[i][0] * 0.35 + grades[i][1] * 0.40;
      
        for (j = 2; j < totalQuiz + 2; j++) {
            sum += grades[i][j];
        }
      
        totalScore += ((sum / totalQuiz) * 0.25);
        totals[i] = totalScore; 
    }

    printf("Summary of students: \n========\n");

    for (i = 0; i < numOfStudents; i++) { 
        letterGrade = getLetterGrade(totals[i]);
        printf("ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i], totals[i], letterGrade);
    }

    printf("========\n");
    maxIndex = getMaxTotalIdx(totals, numOfStudents);
    printf("First student with the highest total is %s %s %.2f\n", ids[maxIndex], names[maxIndex], totals[maxIndex]);
    printf("Data written in summary.txt file\n");
    printf("Enter a last name to search: ");
    scanf("%s", searchName);

    pos = lookup(names, searchName, numOfStudents);

    if (pos >= 0) {
        printf("%s was found in the list. Here is the details: \n", names[pos]);
        printf("ID: %s Lname: %s Total: %.2f\n", ids[pos], names[pos], totals[pos]);
        printf("Grades: \nMidterm: %.2f, Final term: %.2f, quizzes: \n", grades[pos][0], grades[pos][1]);

        for (i = 2; i < totalQuiz + 2; i++) {
            printf("%.2f ", grades[pos][i]);
        }
        printf("\n\n");
    } else {
        printf("%s not found in the list.\n\n", searchName);
    }

    writeData(fOUT, ids, names, totals, numOfStudents);

    fclose(fIN);
    fclose(fOUT);
    
    return 0;
}
