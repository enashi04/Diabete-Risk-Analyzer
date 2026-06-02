#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

int  readPatientsFromCSV(const char* filename, Patient patients[]){
    FILE *file = fopen(filename, "r");
    //check if file exists
    if (file == NULL) {
        printf("Unable to open file : %s\n", filename);
        return 0;
    }

    char line[1024];
    int patientCount = 0;

    fgets(line, sizeof(line), file); // Skip the header line

    while(fgets(line, sizeof(line), file)!=NULL && patientCount < MAX_PATIENTS) {
         sscanf(
            line,
            "%d,%d,%d,%d,%d,%f,%f,%d,%d",
            &patients[patientCount].pregnancies,
            &patients[patientCount].glucose,
            &patients[patientCount].bloodPressure,
            &patients[patientCount].skinThickness,
            &patients[patientCount].insulin,
            &patients[patientCount].bmi,
            &patients[patientCount].diabetesPedigreeFunction,
            &patients[patientCount].age,
            &patients[patientCount].outcome
        );

        patientCount++;
    }

    fclose(file);

    return patientCount;
}

