#include "analyze.h"

float meanAge(Patient patients[], int nbPatients){
    int sumAge = 0;
    for(int i = 0; i < nbPatients; i++){
        sumAge += patients[i].age;
    }
    return (float)sumAge / nbPatients;
}

float meanGlucose(Patient patients[], int nbPatients){
    int sumGlucose = 0;
    for(int i = 0; i < nbPatients; i++){
        sumGlucose += patients[i].glucose;
    }
    return (float)sumGlucose / nbPatients;
}

float meanBmi(Patient patients[], int nbPatients){
    float sumBmi = 0;
    for(int i = 0; i < nbPatients; i++){
        sumBmi += patients[i].bmi;
    }
    return sumBmi / nbPatients;
}

int countDiabeticPatients(Patient patients[], int nbPatients){
    int count = 0;
    for(int i = 0; i < nbPatients; i++){
        if(patients[i].outcome == 1){
            count++;
        }
    }
    return count;
}

int countNonDiabeticPatients(Patient patients[], int nbPatients){
    int count = 0;
    for(int i = 0; i < nbPatients; i++){
        if(patients[i].outcome == 0){
            count++;
        }
    }
    return count;
}

int calculateRiskScore(Patient p){
    int score = 0;
    if (p.glucose > 140) {
        score++;
    }

    if (p.bloodPressure > 90) {
        score++;
    }

    if (p.bmi > 30) {
        score++;
    }

    if (p.age > 45) {
        score++;
    }

    if (p.diabetesPedigreeFunction > 0.5) {
        score++;
    }

    return score;
}

/*Risk level for a patient who could be at risk of diabetes */
void displayRiskLevel(Patient p, int index){
    int score = calculateRiskScore(p);
    printf("Patient %d: Risk Score = %d - ", index + 1, score);
    if (score >= 4) {
        printf("High Risk\n");
    } else if (score >= 2) {
        printf("Moderate Risk\n");
    } else {
        printf("Low Risk\n");
    }
}

void displayHighRiskPatients(Patient patients[], int nbPatients){
    printf("Patients at Risk of Diabetes:\n");
    for(int i = 0; i < nbPatients; i++){
        if(calculateRiskScore(patients[i]) >= 4){
            displayPatient(patients[i], i);
        }
    }
}

void displayGeneralStatistics(Patient patients[], int nbPatients){
    printf("General Statistics:\n");
    printf("Average Age: %.2f\n", meanAge(patients, nbPatients));
    printf("Average Glucose: %.2f\n", meanGlucose(patients, nbPatients));
    printf("Average BMI: %.2f\n", meanBmi(patients, nbPatients));
    printf("Number of Diabetic Patients: %d\n", countDiabeticPatients(patients, nbPatients));
    printf("Number of Non-Diabetic Patients: %d\n", countNonDiabeticPatients(patients, nbPatients));
}

void generateReport(Patient patients[], int nbPatients, const char *filename){
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    fprintf(file, "Patient Report\n");
    fprintf(file, "ID, Pregnancies, Glucose, Blood Pressure, Skin Thickness, Insulin, BMI, Diabetes Pedigree Function, Age, Outcome, Risk Score\n");
    for(int i = 0; i < nbPatients; i++){
        int riskScore = calculateRiskScore(patients[i]);
        fprintf(file, "%d, %d, %d, %d, %d, %d, %.2f, %.2f, %d, %d, %d\n", 
                i + 1,
                patients[i].pregnancies,
                patients[i].glucose,
                patients[i].bloodPressure,
                patients[i].skinThickness,
                patients[i].insulin,
                patients[i].bmi,
                patients[i].diabetesPedigreeFunction,
                patients[i].age,
                patients[i].outcome,
                riskScore);
    }
    fclose(file);
    printf("Report generated successfully: %s\n", filename);
}