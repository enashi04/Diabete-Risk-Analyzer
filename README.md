<div align="center">

<img src="https://img.shields.io/badge/-%F0%9F%A9%BA%20Diabetes%20Risk%20Analyzer-0B1F3A?style=for-the-badge&logoColor=white" alt="Diabetes Risk Analyzer" height="40"/>

<br/>

![C](https://img.shields.io/badge/C-Language-DBEAFE?style=flat-square&logo=c&logoColor=0B1F3A)
![CSV](https://img.shields.io/badge/Data-CSV-1D4ED8?style=flat-square&logoColor=white)
![Healthcare](https://img.shields.io/badge/Domain-Healthcare-0B1F3A?style=flat-square)
![Makefile](https://img.shields.io/badge/Build-Makefile-1E3A8A?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-DBEAFE?style=flat-square)

<br/>

> **A simple medical risk analysis project written in C**  
> designed to practice file handling, structures, arrays and basic statistical analysis  
> using a diabetes dataset.

<br/>

</div>

---

## Overview

**Diabetes Risk Analyzer** is a small C project built to analyze a medical dataset related to diabetes.

The main goal of this project is to **get back into the C programming language** after a long break, while working on a healthcare-oriented data analysis use case.

The program reads a CSV file containing patient medical indicators, stores the data in C structures, calculates basic statistics and identifies patients who may present a higher risk of diabetes using a simple rule-based score.

> This project is not intended to provide a real medical diagnosis.  
> It is a programming and data analysis exercise!!!!

---

## Features

| Feature | Description |
|---|---|
| **CSV Reading** | Loads patient records from a `diabetes.csv` file |
| **C Structures** | Stores each patient using a dedicated `Patient` struct |
| **General Statistics** | Calculates average age, glucose level and BMI |
| **Patient Counting** | Counts diabetic and non-diabetic patients |
| **Risk Score** | Assigns a simple risk score based on medical indicators |
| **High-Risk Detection** | Displays patients with a high diabetes risk score |
| **CSV Report Export** | Generates a report containing patient data and risk scores |

---

## Project Structure

```txt
diabetes-risk-analyzer-c/
│
├── main.c              # Main program and interactive menu
├── patient.h           # Patient structure and function prototypes
├── patient.c           # CSV loading and patient display functions
├── analyse.h           # Analysis function prototypes
├── analyse.c           # Statistics, risk score and report generation
├── diabetes.csv        # Diabetes dataset
├── Makefile            # Build and run commands
└── README.md
```

---

## Dataset

The project uses a diabetes dataset with the following columns:

```csv
Pregnancies,Glucose,BloodPressure,SkinThickness,Insulin,BMI,DiabetesPedigreeFunction,Age,Outcome
```

| Column | Description |
|---|---|
| `Pregnancies` | Number of pregnancies |
| `Glucose` | Plasma glucose concentration |
| `BloodPressure` | Diastolic blood pressure |
| `SkinThickness` | Triceps skin fold thickness |
| `Insulin` | Serum insulin level |
| `BMI` | Body Mass Index |
| `DiabetesPedigreeFunction` | Diabetes pedigree function |
| `Age` | Patient age |
| `Outcome` | `0` = non-diabetic, `1` = diabetic |

---

## Risk Score Logic

A simple rule-based score is used to estimate potential diabetes risk.

```txt
+1 if Glucose > 140
+1 if BloodPressure > 90
+1 if BMI > 30
+1 if Age > 45
+1 if DiabetesPedigreeFunction > 0.5
```

The final score ranges from **0 to 5**.

| Score | Risk Level |
|---|---|
| `0 - 1` | Low Risk |
| `2 - 3` | Moderate Risk |
| `4 - 5` | High Risk |

Again, this score is only used for programming practice and should not be interpreted as a real medical diagnosis.

---

## Quick Start

### 1 — Clone the repository

```bash
git clone git@github.com:enashi04/Diabete-Risk-Analyzer.git
cd diabetes-risk-analyzer
```

### 2 — Compile the project

```bash
make
```

### 3 — Run the program

```bash
make run
```

Or manually:

```bash
./diabetes_analyzer
```

On Windows, depending on your environment:

```bash
diabetes_analyzer.exe
```

---

## Makefile Commands

| Command | Description |
|---|---|
| `make` | Compiles the project |
| `make run` | Compiles and runs the program |
| `make clean` | Removes compiled files |
| `make rebuild` | Cleans and recompiles the whole project |

---

## Program Menu

When running the program, an interactive menu is displayed:

```txt
===== Diabetes Risk Analyzer =====

1. Display all patients
2. Display general statistics
3. Display high-risk patients
4. Generate report
0. Exit
```

---

## Example Output

```txt
===== Diabetes Risk Analyzer =====
1. Display all patients
2. Display general statistics
3. Display high-risk patients
4. Generate report
0. Exit
Your choice: 2

General Statistics:
Average Age: 33.24
Average Glucose: 120.89
Average BMI: 31.99
Number of Diabetic Patients: 268
Number of Non-Diabetic Patients: 500
```

---

## Report Generation

The program can generate a CSV report named:

```txt
report.csv
```

The report contains:

```csv
ID,Pregnancies,Glucose,BloodPressure,SkinThickness,Insulin,BMI,DiabetesPedigreeFunction,Age,Outcome,RiskScore
```

This makes it possible to reuse the output later for analysis or visualization.

---

## Learning Objectives

This project was created as a small practice project to get back into the C language.

The main objectives are to review:

| Concept | Practice |
|---|---|
| **Structs** | Representing patients with a custom data structure |
| **Arrays** | Storing multiple patient records |
| **File Handling** | Opening, reading and writing CSV files |
| **Functions** | Splitting the program into reusable functions |
| **Headers** | Organizing code with `.h` and `.c` files |
| **Makefile** | Compiling a multi-file C project |
| **Basic Data Analysis** | Computing statistics and simple risk scores |

---

## Possible Improvements

Future improvements could include:

- Adding data validation for missing or invalid values
- Sorting patients by risk score
- Searching patients by ID
- Exporting only high-risk patients
- Adding more advanced statistical indicators
- Comparing the rule-based risk score with the real `Outcome`
- Creating a confusion matrix
- Adding unit tests

---

## Disclaimer

This project is for educational purposes only.

The risk score implemented in this program is a simplified rule-based system and must not be used for medical decision-making.

For any health-related concern, medical advice should always come from qualified healthcare professionals.

---

## License

This project is licensed under the **MIT License** — free to use, modify and distribute.

---

<div align="center">

<img src="https://img.shields.io/badge/Made%20with-C%20%26%20Healthcare%20Data-0B1F3A?style=for-the-badge&logo=c&logoColor=white" alt="Made with C and Healthcare Data"/>

</div>
