#ifndef ANALYSE_H
#define ANALYSE_H

#include "patient.h"

float meanAge(Patient patients[], int nbPatients);

float meanGlucose(Patient patients[], int nbPatients);

float meanBmi(Patient patients[], int nbPatients);

int countDiabeticPatients(Patient patients[], int nbPatients);

int countNonDiabeticPatients(Patient patients[], int nbPatients);

int calculateRiskScore(Patient p);

void displayRiskLevel(Patient p, int index);

void displayHighRiskPatients(Patient patients[], int nbPatients);

void displayGeneralStatistics(Patient patients[], int nbPatients);

void generateReport(Patient patients[], int nbPatients, const char *filename);
