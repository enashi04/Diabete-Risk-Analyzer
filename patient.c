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

void displayPatient(Patient patient, int index){
    printf("Patient %d:\n", index + 1);
    printf("  Pregnancies: %d\n", patient.pregnancies);
    printf("  Glucose: %d\n", patient.glucose);
    printf("  Blood Pressure: %d\n", patient.bloodPressure);
    printf("  Skin Thickness: %d\n", patient.skinThickness);
    printf("  Insulin: %d\n", patient.insulin);
    printf("  BMI: %.2f\n", patient.bmi);
    printf("  Diabetes Pedigree Function: %.2f\n", patient.diabetesPedigreeFunction);
    printf("  Age: %d\n", patient.age);
    printf("  Outcome: %d\n", patient.outcome);
}

//all patients
void displayAllPatients(Patient patients[], int countPatients){
    for(int i = 0; i < countPatients; i++){
        displayPatient(patients[i], i);
    }
}

