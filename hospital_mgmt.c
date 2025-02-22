//Header files
#include <stdio.h>
#define max 50
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "pharmacy_data.txt"


// Patient details
typedef struct {
    char name[50];
    int patientid;
    int age;
    int roomno;
    char gender[10];
    char disease[50];
    int discharge;
} patient;
// Structure for medicine details
struct medicine {
    int id, quantity;
    char name[30];
    float price;
};
//Structure for staff management
struct staff {
    int ID;
    char name[100];
    char address[200];
    char DOB[20];
    char post[50];
    char Qualification[100];
    char phone[20]; 
};
// Structure to store appointment details
typedef struct {
    int id;
    char name[50];
    char date[15]; // Format: YYYY-MM-DD
    char time[10]; // Format: HH:MM
    char doctor[50];
} Appointment;
//Function prototypes
void addp(patient p[], int *patientcount, int *patientid);
void save(patient p[], int patientcount);
void displayp(patient p[], int patientcount);
void searchp(patient p[], int patientcount);
void updatep(patient p[], int patientcount);
void dischargep(patient p[], int *patientcount);
void load(patient p[], int *patientcount, int *patientid);
void patientmgmt();
void pharmacymgmt();
void addmed();
void dismed();
void dispensemed() ;
void searchmed();
void add_staff();
void display_staff();
void searchbyid();
void searchbypost();
void deletestaff();
void staffmgmt();
void add(Appointment apps[], int *count);
void showAll(Appointment apps[], int count);
void searchById(Appointment apps[], int count);
void searchByDoctor(Appointment apps[], int count);
void appoint();
void clearScreen(); 
int lastId = 0;
//Main Function
int main(){
    clearScreen(); 
    int choice;
    while(1){
        printf("\n-----Hospital Management System----\n");
        printf("1. Patient Management\n");
        printf("2. Pharmacy Management\n");
        printf("3. Staff Management\n");
        printf("4. Appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                patientmgmt();
               break;
        
             case 2:
                pharmacymgmt();
               break;
            case 3:
               staffmgmt();
             break;
             case 4:
              appoint();
             break;
             case 5:
              exit(0);  // Exit the program
              break;
            default:
              printf("Invalid choice! Please try again.");
  
        }
    }

}
//Patient Management system function
void patientmgmt() {
    clearScreen(); 
    int choice;
    int patientcount = 0;
    int patientid = 101;
    patient p[max];
    load(p, &patientcount, &patientid);

    while (1) {
        printf("\n-----Patient Management System----\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Update Patient Information\n");
        printf("5. Discharge Patient\n");
        printf("6. Return to main menu.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addp(p, &patientcount, &patientid);
                break;
            case 2:
                displayp(p, patientcount);
                break;
            case 3:
                searchp(p, patientcount);
                break;
            case 4:
                updatep(p, patientcount);
                break;
            case 5:
                dischargep(p, &patientcount);
                break;
            case 6:
               
                main();
            default:
                printf("Invalid choice! Please try again.");
        }
    }
}
//Function for staff management
void staffmgmt() {
    clearScreen(); 
    int choice;
    printf("%85s\n\n", "**Welcome to staff management section**");

    // Infinite loop to keep showing the menu until the user exits
    while(1) {
        printf("Choose one option:\n");
        printf("1. Add staff.\n");
        printf("2. Display details of all staffs.\n");
        printf("3. Search staff by ID.\n");
        printf("4. Search staff by post.\n");
        printf("5. Delete staff by staff id.\n");
        printf("6. Return to main menu.\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to execute corresponding function based on user choice
        switch (choice) {
            case 1: 
                add_staff();  // Add new staff
                break;
            case 2:
                display_staff();  // Display all staff details
                break;
            case 3:
                searchbyid();  // Search staff by ID
                break;
            case 4:
                searchbypost();  // Search staff by post
                break;
            case 5:
                deletestaff();  // Delete a staff record
                break;
            case 6:
                main();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
// Pharmacy Management System function
void pharmacymgmt() {
    clearScreen(); 
    int choice;
    do {
        printf("\n--- Pharmacy Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Dispense Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addmed(); break;
            case 2: dismed(); break;
            case 3: dispensemed(); break;
            case 4: searchmed(); break;
            case 5: main();
             break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
}
//Function to add appointment
void appoint() {
    clearScreen(); 
    Appointment apps[max];
    int count = 0;
    int choice;

    do {
        printf("\n--- Appointment Management ---\n");
        printf("1. Add Appointment\n");
        printf("2. Show All Appointments\n");
        printf("3. Search by ID\n");
        printf("4. Search by Doctor\n");
        printf("5. Return to main menu \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(apps, &count);
                break;
            case 2:
                showAll(apps, count);
                break;
            case 3:
                searchById(apps, count);
                break;
            case 4:
                searchByDoctor(apps, count);
                break;
            case 5:
                main();
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while (choice != 5);
}
// Function to add a new staff member
void add_staff() {
    FILE *fp;
    struct staff s;

    // Prompt user for staff details
    printf("\nEnter details of staff:\n\n");
    printf("Enter staff ID: ");
    scanf("%d", &s.ID);
    fflush(stdin);

    printf("Enter staff name: ");
    scanf("%[^\n]", s.name);
    fflush(stdin);

    printf("Enter Address: ");
    scanf("%[^\n]", s.address);
    fflush(stdin);

    printf("Enter Date of birth(YYYY/MM/DD): ");
    scanf("%[^\n]", s.DOB);
    fflush(stdin);

    printf("Enter Post: ");
    scanf("%[^\n]", s.post);  
    fflush(stdin);

    printf("Enter Qualification: ");
    scanf("%[^\n]", s.Qualification);
    fflush(stdin);

    printf("Enter Phone: ");
    scanf("%s", s.phone);    
    fflush(stdin);

    // Open the staff.txt file in append mode
    fp = fopen("staff.txt", "a");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    // Write the new staff details to the file
    fprintf(fp, "%d\t %s\t %s\t %s\t %s\t %s\t %s\n", s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone);
    fclose(fp);  // Close the file

    printf("\nStaff successfully added!\n\n\a");
    getchar();  // To pause the console window
}

// Function to display the details of all staff members
void display_staff() {
    struct staff s;
    FILE *fp;

    // Display column headers
    printf("\n\nDetails of all staffs:\n\n");
    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");
    printf("| ID  |       Name         |           Address            |    DOB       |     Post      |  Qualification |   Phone   |\n");
    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");

    // Open the staff.txt file in read mode
    fp = fopen("staff.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    // Read each staff record and print the details in a tabular format
    while (fscanf(fp, "%d %[^\t] %[^\t] %s %s %s %s", &s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone) != EOF) {
        printf("| %-4d| %-18s | %-29s| %-12s | %-13s | %-14s | %-10s|\n", s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone);
    }

    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");
    fclose(fp);  // Close the file
    getchar();  // To pause the console window
}

// Function to search for a staff member by their ID
void searchbyid() {
    struct staff s;
    FILE *fp;
    int search_ID;

    // Ask the user to input the staff ID
    printf("Enter ID to search: ");
    scanf("%d", &search_ID);

    // Display column headers for the search results
    printf("\n\nDetails of searched staff:\n\n");
    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");
    printf("| ID  |       Name         |           Address            |    DOB       |     Post      |  Qualification |   Phone   |\n");
    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");

    // Open the staff.txt file in read mode
    fp = fopen("staff.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    int found = 0;
    // Search for the staff record with the specified ID
    while (fscanf(fp, "%d %[^\t] %[^\t] %s %s %s %s", &s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone) != EOF) {
        if (s.ID == search_ID) {
            printf("| %-4d| %-18s | %-29s| %-12s | %-13s | %-14s | %-10s|\n", s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone);
            found = 1;  // Mark as found
            break;
        }
    }

    // If not found, inform the user
    if (!found) {
        printf("No staff found with ID %d.\n", search_ID);
    }

    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");
    fclose(fp);  // Close the file
    getchar();  // To pause the console window
}

// Function to search for a staff member by their post
void searchbypost() {
    struct staff s;
    FILE *fp;
    char search_post[30];

    fflush(stdin);  // Clear input buffer before taking new input
    printf("Enter post to search: ");
    scanf("%[^\n]", search_post);

    // Display column headers for the search results
    printf("\n\nDetails of searched staff:\n\n");
    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");
    printf("| ID  |       Name         |           Address            |    DOB       |     Post      |  Qualification |   Phone   |\n");
    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");

    // Open the staff.txt file in read mode
    fp = fopen("staff.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    int found = 0;
    // Search for the staff record with the specified post
    while (fscanf(fp, "%d %[^\t] %[^\t] %s %s %s %s", &s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone) != EOF) {
        if (strcmp(search_post, s.post) == 0) {
            printf("| %-4d| %-18s | %-29s| %-12s | %-13s | %-14s | %-10s|\n", s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone);
            found = 1;
        }
    }

    // If no records found, inform the user
    if (!found) {
        printf("No staff found with the post %s.\n", search_post);
    }

    printf("+-----+--------------------+------------------------------+--------------+---------------+----------------+-----------+\n");
    fclose(fp);  // Close the file
    getchar();  // To pause the console window
}

// Function to delete a staff member by their ID
void deletestaff() {
    int delid, found = 0;
    struct staff s;

    // Ask the user for the staff ID to delete
    printf("Enter staff ID to delete: ");
    scanf("%d", &delid);

    // Open the staff.txt file for reading and a temporary file for writing
    FILE *fp1 = fopen("staff.txt", "r");
    if (fp1 == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    FILE *fp2 = fopen("temp.txt", "w");
    if (fp2 == NULL) {
        printf("Unable to open temporary file.\n");
        fclose(fp1);
        return;
    }

    // Read each staff record, and if the ID matches the one to delete, skip it
    while (fscanf(fp1, "%d %[^\t] %[^\t] %s %s %s %s", &s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone) != EOF) {
        if (s.ID == delid) {
            found = 1;  // Mark as found
            continue;  // Skip this record
        } else {
            // Copy the remaining records to the temp file
            fprintf(fp2, "%d\t %s\t %s\t %s\t %s\t %s\t %s\n", s.ID, s.name, s.address, s.DOB, s.post, s.Qualification, s.phone);
        }
    }

    // Inform the user if no staff member was found to delete
    if (found == 0) {
        printf("No staff found with ID %d.\n", delid);
    } else {
        printf("Staff with ID %d removed successfully.\n", delid);
    }

    // Close both files and delete the original file
    fclose(fp1);
    fclose(fp2);

    // Replace the original file with the temp file
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
    getchar();  // To pause the console window
}
//Function to add patient details
void addp(patient p[], int *patientcount, int *patientid) {
    printf("Enter the name of patient: ");
    scanf(" %[^\n]", p[*patientcount].name);
    printf("Enter patient age: ");
    scanf("%d", &p[*patientcount].age);
    getchar();
    printf("Enter Gender: ");
    scanf(" %[^\n]", p[*patientcount].gender);
    printf("Enter disease: ");
    scanf(" %[^\n]", p[*patientcount].disease);
    printf("Enter the Room No.: ");
    scanf("%d", &p[*patientcount].roomno);
    p[*patientcount].patientid = *patientid;
    (*patientcount)++;
    (*patientid)++;
    save(p, *patientcount);
    printf("Patient added successfully!!!");
}
//Function to save patient details

void save(patient p[], int patientcount) {
    FILE *fptr = fopen("patient.txt", "w");
    if (fptr == NULL) {
        printf("Error saving data!\n");
        return;
    }
    for (int i = 0; i < patientcount; i++) {
        fprintf(fptr, "%s,%d,%d,%s,%s,%d,%d\n", p[i].name, p[i].patientid, p[i].age,
                p[i].gender, p[i].disease, p[i].roomno, p[i].discharge);
    }
    fclose(fptr);
}
//Function to load patient details
void load(patient p[], int *patientcount, int *patientid) {
    FILE *fptr = fopen("patient.txt", "r");
    if (fptr == NULL) {
        printf("No existing patient records found.\n");
        return;
    }
    while (fscanf(fptr, "%49[^,],%d,%d,%9[^,],%49[^,],%d,%d\n",
                  p[*patientcount].name, &p[*patientcount].patientid, &p[*patientcount].age, p[*patientcount].gender,
                  p[*patientcount].disease, &p[*patientcount].roomno, &p[*patientcount].discharge) == 7) {

        (*patientcount)++;
        if (p[*patientcount - 1].patientid >= *patientid) {
            *patientid = p[*patientcount - 1].patientid + 1;
        }
    }
    fclose(fptr);
}
//Function to dispaly patient details
void displayp(patient p[], int patientcount) {
    if (patientcount == 0) {
        printf("No patient records available!\n");
        return;
    }

    printf("\nPatient Details:\n");
    printf("\n%-5s | %-15s | %-3s | %-8s | %-15s | %-4s | %-10s\n",
           "ID", "Name", "Age", "Gender", "Disease", "Room", "Discharged");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < patientcount; i++) {
        if (p[i].discharge == 0) {
            printf("%-5d | %-15s | %-3d | %-8s | %-15s | %-4d | %-10s\n",
                   p[i].patientid, p[i].name, p[i].age, p[i].gender, p[i].disease, p[i].roomno, "No");
        } else {
            printf("%-5d | %-15s | %-3d | %-8s | %-15s | %-4d | %-10s\n",
                   p[i].patientid, p[i].name, p[i].age, p[i].gender, p[i].disease, p[i].roomno, "Yes");
        }
    }
}
//Function to search patient by ID
void searchp(patient p[], int patientcount) {
    int id;
    printf("\nEnter patient's id:");
    scanf("%d", &id);
    for (int i = 0; i < patientcount; i++) {
        if (p[i].patientid == id) {
            printf("\nThe Patient's details are:!\n");
            printf("\n%-5s | %-15s | %-3s | %-8s | %-15s | %-4s | %-10s\n",
                   "ID", "Name", "Age", "Gender", "Disease", "Room", "Discharged");
            printf("-------------------------------------------------------------------------\n");
            if (p[i].discharge == 0) {
                printf("%-5d | %-15s | %-3d | %-8s | %-15s | %-4d | %-10s\n",
                       p[i].patientid, p[i].name, p[i].age, p[i].gender, p[i].disease, p[i].roomno, "No");
            } else {
                printf("%-5d | %-15s | %-3d | %-8s | %-15s | %-4d | %-10s\n",
                       p[i].patientid, p[i].name, p[i].age, p[i].gender, p[i].disease, p[i].roomno, "Yes");
            }
            return;
        }
    }
    printf("Patient with ID %d not found!\n", id);
}
//Function to update patient details 
void updatep(patient p[], int patientcount) {
    int id;
    printf("\nEnter patient's id:");
    scanf("%d", &id);
    for (int i = 0; i < patientcount; i++) {
        if (p[i].patientid == id) {
            printf("\nUpdating Patient: %s\n", p[i].name);
            printf("Enter the name of patient: ");
            scanf(" %[^\n]", p[i].name);
            printf("Enter patient's new age: ");
            scanf("%d", &p[i].age);
            getchar();
            printf("Enter new Gender: ");
            scanf(" %[^\n]", p[i].gender);
            printf("Enter new disease: ");
            scanf(" %[^\n]", p[i].disease);
            printf("Enter the new Room No.: ");
            scanf("%d", &p[i].roomno);
            save(p, patientcount);
            printf("Patient updated successfully!!!");
            return;
        }
    }
}
//Function to discharge patient
void dischargep(patient p[], int *patientcount) {
    int id;
    printf("\nEnter patient's id:");
    scanf("%d", &id);
    for (int i = 0; i < *patientcount; i++) {
        if (p[i].patientid == id) {
            if (p[i].discharge == 1) {
                printf("Patient %s is already discharged.\n", p[i].name);
            } else {
                p[i].discharge = 1;
                save(p, *patientcount);
                printf("Patient %s has been discharged.\n", p[i].name);
            }
            return;
        }
    }
    printf("Patient with ID %d not found or already discharged!\n", id);
}
// Function to add medicine
void addmed() {
    FILE *file = fopen(FILE_NAME, "a");
    struct medicine med;
    printf("Enter Medicine ID: ");
    scanf("%d", &med.id);
    printf("Enter Medicine Name: ");
    scanf("%s", med.name);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter Medicine Price per unit: ");
    scanf("%f", &med.price);
    fprintf(file, "%d %s %d %.2f\n", med.id, med.name, med.quantity, med.price);
    fclose(file);
    printf("Medicine is successfully added\n");
}

// Function to display all medicines
void dismed() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No data found!\n");
        return;
    }
    struct medicine med;
    printf("\nID    | Name                | Quantity | Price per Unit\n");
    printf("----------------------------------------------------------\n");
    while (fscanf(file, "%d %s %d %f", &med.id, med.name, &med.quantity, &med.price) != EOF) {
        printf("%-5d | %-30s | %-8d | $%.2f\n", med.id, med.name, med.quantity, med.price);
    }
    fclose(file);
}

// Function to dispense medicine
void dispensemed() {
    int id, qty;
    printf("Enter Medicine ID to dispense: ");
    scanf("%d", &id);
    printf("Enter Quantity to dispense: ");
    scanf("%d", &qty);

    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No data found!\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");

    struct medicine med;
    int found = 0;
    while (fscanf(file, "%d %s %d %f", &med.id, med.name, &med.quantity, &med.price) != EOF) {
        if (med.id == id) {
            found = 1;
            if (med.quantity >= qty) {
                med.quantity -= qty;
                printf("Dispensed %d units of %s. Remaining stock: %d\n", qty, med.name, med.quantity);
            } else {
                printf("Insufficient stock!\n");
            }
        }
        fprintf(temp, "%d %s %d %.2f\n", med.id, med.name, med.quantity, med.price);
    }
    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found) printf("Medicine ID not found!\n");
}

// Function to search medicine
void searchmed() {
    int id;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);

    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No data found!\n");
        return;
    }
    struct medicine med;
    int found = 0;
    while (fscanf(file, "%d %s %d %f", &med.id, med.name, &med.quantity, &med.price) != EOF) {
        if (med.id == id) {
            found = 1;
            printf("\nMedicine Found!\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice per Unit: $%.2f\n", med.id, med.name, med.quantity, med.price);
            break;
        }
    }
    fclose(file);
    if (!found) printf("Medicine ID not found!\n");
}
// Function to add an appointment
void add(Appointment apps[], int *count) {
    if (*count >= max) {
        printf("Appointment limit reached! Cannot add more.\n");
        return;
    }

    // Automatically generate a unique ID
    apps[*count].id = ++lastId;

    printf("\nEnter Patient Name: ");
    scanf(" %[^\n]s", apps[*count].name);

    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", apps[*count].date);

    printf("Enter Time (HH:MM): ");
    scanf("%s", apps[*count].time);

    printf("Enter Doctor's Name: ");
    scanf(" %[^\n]s", apps[*count].doctor);

    (*count)++;
    printf("Appointment added successfully with ID: %d!\n", lastId);
}

// Function to display all appointments
void showAll(Appointment apps[], int count) {
    if (count == 0) {
        printf("No appointments available!\n");
        return;
    }

    printf("\nAppointments List:\n");
    printf("ID    | Name           | Date       | Time  | Doctor\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-15s | %-10s | %-5s | %-10s\n",
               apps[i].id, apps[i].name, apps[i].date, apps[i].time, apps[i].doctor);
    }
}

// Function to search for an appointment by ID
void searchById(Appointment apps[], int count) {
    int searchId;
    printf("\nEnter Appointment ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (apps[i].id == searchId) {
            printf("\nAppointment Found!\n");
            printf("ID: %d\n", apps[i].id);
            printf("Name: %s\n", apps[i].name);
            printf("Date: %s\n", apps[i].date);
            printf("Time: %s\n", apps[i].time);
            printf("Doctor: %s\n", apps[i].doctor);
            return;
        }
    }
    printf("Appointment with ID %d not found!\n", searchId);
}

// Function to search for appointments by doctor's name
void searchByDoctor(Appointment apps[], int count) {
    char searchDoctor[50];
    int found = 0;

    printf("\nEnter Doctor's Name to search: ");
    scanf(" %[^\n]s", searchDoctor);

    printf("\nAppointments with Dr. %s:\n", searchDoctor);
    printf("ID    | Name           | Date       | Time  | Doctor\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(apps[i].doctor, searchDoctor) == 0) {
            printf("%-5d | %-15s | %-10s | %-5s | %-10s\n",
                   apps[i].id, apps[i].name, apps[i].date, apps[i].time, apps[i].doctor);
            found = 1;
        }
    }

    if (!found) {
        printf("No appointments found with Dr. %s\n", searchDoctor);
    }
}
void clearScreen() {
    system("clear");
}