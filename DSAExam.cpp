#include <bits/stdc++.h>
using namespace std;


struct PatientsLL {
    int patient_id;
    string name;
    string dob;
    string gender;
    PatientsLL* next;
};

struct DoctorsLL {
    int doctor_id;
    string name;
    string specialization;
    DoctorsLL* next;
};

struct Appointments {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointments* next;
};


PatientsLL* patientsHead = nullptr;
DoctorsLL* doctorsHead = nullptr;
Appointments* appointmentsHead = nullptr;

bool patientExists(int p_id) {
    PatientsLL* temp = patientsHead;
    while (temp != nullptr) {
        if (temp->patient_id == p_id) return true;
        temp = temp->next;
    }
    return false;
}


bool doctorExists(int d_id) {
    DoctorsLL* temp = doctorsHead;
    while (temp != nullptr) {
        if (temp->doctor_id == d_id) return true;
        temp = temp->next;
    }
    return false;
}

bool appointmentExists(int id) {
    Appointments* temp = appointmentsHead;
    while (temp != nullptr) {
        if (temp->appointment_id == id) return true;
        temp = temp->next;
    }
    return false;
}

string readString(const string& ask) {
    string input;
    cout << ask;
    cin >> ws; 
    getline(cin, input);
    return input;
}


void registerPatient() {
    int p_id;
    cout << "Enter Patient ID: ";
    cin >> p_id;

    if (patientExists(p_id)) {
        cout << "Patient with ID: " << p_id << " already exists" << endl;
        return;
    }

    string name = readString("Enter Name: ");
    string dob = readString("Enter Date of Birth (YYYY-MM-DD): ");
    string gender = readString("Enter Gender: ");

    PatientsLL* newPatient = new PatientsLL{p_id, name, dob, gender, nullptr};
    newPatient->next = patientsHead;
    patientsHead = newPatient;

    cout << "Patient registered successfully" << endl;
}

void registerDoctor() {
    int d_id;
    cout << "Enter Doctor ID: ";
    cin >> d_id;

    if (doctorExists(d_id)) {
        cout << "Doctor with ID " << d_id << " already exists" << endl;
        return;
    }

    string name = readString("Enter Doctor's Name: ");
    string specialization = readString("Enter Specialization: ");

    DoctorsLL* newDoctor = new DoctorsLL{d_id, name, specialization, nullptr};

    newDoctor->next = doctorsHead;
    doctorsHead = newDoctor;

    cout << "Doctor registered successfully" << endl;
}

void registerAppointment() {
    int appointment_Id, patient_Id, doctor_Id;
    
    cout << "Enter Appointment ID: " << endl;
    cin >> appointment_Id;

    if (appointmentExists(appointment_Id)) {
        cout << "Appointment with ID " << appointment_Id << " already exists" << endl;
        return;
    }

    cout << "Enter Patient ID: ";
    cin >> patient_Id;
    if (!patientExists(patient_Id)) {
        cout << "Patient with ID: " << patient_Id << " does not exist " << endl;
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> doctor_Id;
    if (!doctorExists(doctor_Id)) {
        cout << "Doctor with ID: " << doctor_Id << " does not exist " << endl;
        return;
    }

    string date = readString("Enter Appointment Date (YYYY-MM-DD): ");

    Appointments* newAppt = new Appointments{appointment_Id, patient_Id, doctor_Id, date, nullptr};

    newAppt->next = appointmentsHead;
    appointmentsHead = newAppt;

    cout << "Appointment registered successfully " << endl ;
}


void displayPatients() {
    if (patientsHead == nullptr) {
        cout << "No patients registered by now." << endl;
        return;
    }
    
    cout << "--- Patient List --- " << endl; 
    
    PatientsLL* temp = patientsHead;
    while (temp != nullptr) {
        cout<< "Patient ID: " << temp->patient_id << ", "
            << "Patient's name: " << temp->name << ", "
            << "Date of Birth: " << temp->dob << ", "
            << "Gender: " << temp->gender << endl;
        temp = temp->next;
    }
    cout << "---------------------------------------------------------------------" << endl;
}

// 5. Display Doctors
void displayDoctors() {
    if (doctorsHead == nullptr) {
        cout << "No doctors registered by now." << endl;
        return;
    }
    
    cout << "--- Doctor List ---";

    
    DoctorsLL* temp = doctorsHead;
    while (temp != nullptr) {
        cout<< "Doctor ID: " << temp->doctor_id << " ,"
           << "Doctor's Name : "<<temp->name << " ,"
           << "Specialisation: "<< temp->specialization << endl;
        temp = temp->next;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

void displayAppointments() {
    if (appointmentsHead == nullptr) {
        cout << "No appointments registered yet." ;
        return;
    }
    
    cout << "--- Appointment List ---"<< endl;
   
    
    Appointments* temp = appointmentsHead;
    while (temp != nullptr) {
        cout << "Appointment ID: "<< temp->appointment_id << ", "
            << "Patient ID: " << temp->patient_id << ", "
            << "Doctor ID: " << temp->doctor_id << ", "
            << " Date : " << temp->appointment_date << endl;
        temp = temp->next;
    }
    cout << "------------------------------------------------------------------" << endl;
}


void cleanupMemory() {
    while (patientsHead != nullptr) {
        PatientsLL* temp = patientsHead;
        patientsHead = patientsHead->next;
        delete temp;
    }
    while (doctorsHead != nullptr) {
        DoctorsLL* temp = doctorsHead;
        doctorsHead = doctorsHead->next;
        delete temp;
    }
    while (appointmentsHead != nullptr) {
        Appointments* temp = appointmentsHead;
        appointmentsHead = appointmentsHead->next;
        delete temp;
    }
}

int main() {
    int choice;
    do {
    	cout << "______ WELCOME TO RUHENGERI REFERRAL HOSPITAL ______" << endl;
        cout << "Menu: "<< endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Register Doctor" << endl;
        cout << "3. Register Appointment" << endl;
        cout << "4. Display Patients " << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments " << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerPatient(); break;
            case 2: registerDoctor(); break;
            case 3: registerAppointment(); break;
            case 4: displayPatients(); break;
            case 5: displayDoctors(); break;
            case 6: displayAppointments(); break;
            case 7: 
                cout << "Bye...";
                cleanupMemory();
                break;
            default: cout << "Invalid choice. Please try again"<< endl;
        }
    } while (choice != 7);

    return 0;
}