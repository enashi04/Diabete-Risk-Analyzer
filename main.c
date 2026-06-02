#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

//menu + appels fonction
int main() {
    Patient patients[MAX_PATIENTS];
    int patientCount = readPatientsFromCSV("diabetes.csv", patients);
    printf("Number of patients read: %d\n", patientCount);
    //displayAllPatients(patients, patientCount);
    return 0;
}