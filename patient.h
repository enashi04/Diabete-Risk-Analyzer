#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 1000

typedef struct {
    int pregnancies;
    int glucose;
    int bloodPressure;
    int skinThickness;
    int insulin;
    float bmi;
    float diabetesPedigreeFunction;
    int age;
    int outcome;
} Patient;

//read csv file
int readPatientsFromCSV(const char* filename, Patient patients[]);

//display only one patient data
void displayPatient(Patient patient, int index);

//all patients
void displayAllPatients(Patient patients[], int countPatients);

#endif // PATIENT_H