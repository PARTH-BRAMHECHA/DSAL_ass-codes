#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Patient {
    string name;
    int enrono;
    double bill;
};

class PCQueue {
private:
    vector<Patient> queue;
    int front, rear, size;

public:
    PCQueue(int s) {
        front = -1;
        rear = -1;
        size = s;
        queue.resize(size);
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || ((rear + 1) % size == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enQueue(string name, int enrono, double bill);//function to enqueue in a given ciruclar queue 
    void deQueue();//function to dequeue from a given ciruclar queue  
    void display();//function to display a given ciruclar queue};
    bool validated_input(int);//function to validate enrollment number is unique
};

    // Adding an element
void PCQueue::enQueue(string name, int enrono, double bill) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    queue[rear].name = name;
    queue[rear].enrono = enrono;
    queue[rear].bill = bill;
}

    // Removing an element
    //here we physically are not removing an elemnet but logical
void PCQueue::deQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
}
        //displaying the queue
void PCQueue::display() {
    if (isEmpty()) {
        cout << "Empty Queue" << endl;
    } else {
        cout << "Name\t\tEnrollment number\tBill" << endl;
        int i = front;
        do {
            cout << queue[i].name << "\t\t" << queue[i].enrono << "\t\t\t" << queue[i].bill << endl;
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }
    cout << endl;
}

bool PCQueue::validated_input(int enro) {
    for (int i = 0; i < size; i++) {
        if (queue[i].enrono == enro)
            return false; // Return false if the enrollment number is not unique
    }
    return true; // Return true if the enrollment number is unique
}

int main() {

    int s;
    while (true) {
        cout << "Please enter the number of patients the hospital can handle: ";
        cin >> s;
        if (s >= 0)
            break;
        else
            cout << "Wrong input\nInput must be non-negative" << endl;
    }

    PCQueue P(s);
    int choice;

    while (true) {
        cout << "Please enter :\n1 for enqueue\n2 for dequeue\n3 for displaying the queue\n4 to exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int enrono;
                double bill_loc;
                if (P.isFull()) {
                    cout << "The Queue is full" << endl;
                } else {
                    cout << "Enter the name of the patient: ";
                    cin >> name;

                    //enrollmentnumber must be unique
                    while (true) {
                        cout << "Please enter enrollment number: ";
                        cin >> enrono;
                        if (enrono > 0 && P.validated_input(enrono))
                            break;
                        else if (enrono <= 0)
                            cout << "Enrollment number must be positive." << endl;
                        else
                            cout << "Please enter a unique number" << endl;
                    }
                    
                    //bill must be positive
                    while(true){
                        cout << "Enter the bill of the patient: ";
                        cin >> bill_loc;
                        if(bill_loc>=0)
                            break;
                        else
                            cout<<"Bill must be positive"<<endl;
                    }

                    P.enQueue(name, enrono, bill_loc);
                }
                break;
            }

            case 2:
                P.deQueue();
                break;

            case 3:
                P.display();
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
