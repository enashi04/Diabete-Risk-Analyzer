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