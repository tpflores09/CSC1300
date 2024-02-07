#include <iostream> 
#include <string>
using namespace std;

const int SIZE = 5
void enterData(Student *);

struct Course{
    int courses;
    int *creditHours;
};

struct Student{
    string name;
    string house;
    Course courseinfo;
};

void enterData(Student *);
int calculateHours (Student);

int main (){
    Student stuArray[SIZE];
    cout << "Which of the five students can work in addition to going to school?";
    enterData(stuArray);
    for (int i = 0; i< SIZE; i++){
        int totalHours = calculateHours(stuArray[i]);
        if (totalHours>30){
            cout << " is already going to class and studying " << totalHours << " hours, so they should not take a job this semester." << endl;
        } else {
            cout <<  " is going to class and studying " << totalHours << " hours, so they could take a part-time job. " << endl;
        }
    }
    for (int i = 0; i < SIZE; i++ ){
        delete [] stuArray[i].courseinfo.courses;
    }

    return 0;
}

void enterData(Student *arr){
    cout << "Enter each student's information: " << endl;
    for (int i = 0; i < SIZE; i++){
        cout << "STUDENT " << i+1<< endl;
        cout << "Name: ";
        getline(cin,arr[i].name);
        cout << "House: ";
        cin >> arr[i].house;
        cout << "Number of classes this semester: ";
        cin >> arr[i].courseinfo.courses;
        arr[i].courseinfo.creditHours = new int [arr[i].courseinfo.courses];
        
        for (int j = 0; j < arr[i].courseinfo.courses; j++){
            cout << "Credit hours for each course: " << endl;
            cout << "Course " << j+1 << " - "; 
            cin >> arr[i].courseinfo.courses[j];
    }
}
}
int calculateHours (Student student){
    int total = 0;
    for (int i = 0;i < student.courseinfo.courses; i++){
        total += student.courseinfo.creditHours[i] + (student.courseinfo.creditHours[i] * 3);
    }
    return total;
}