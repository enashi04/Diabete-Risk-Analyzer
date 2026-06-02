#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "analyze.h"

int main() {
    Patient patients[MAX_PATIENTS];
    int nbPatient = readPatientsFromCSV("diabetes.csv", patients);
    // printf("Number of patients read: %d\n", nbPatient);
    if (nbPatient == 0) {
        fprintf(stderr, "Error reading patient data.\n");
        return EXIT_FAILURE;
    }

    int choice ;

     do {
        printf("\n===== Diabetes Risk Analyzer =====\n");
        printf("1. Display all patients\n");
        printf("2. Display general statistics\n");
        printf("3. Display high-risk patients\n");
        printf("4. Generate report\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllPatients(patients, nbPatient);
                break;

            case 2:
                displayGeneralStatistics(patients, nbPatient);
                break;

            case 3:
                displayHighRiskPatients(patients, nbPatient);
                break;

            case 4:
                generateReport(patients, nbPatient, "report.csv");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}