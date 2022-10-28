#include<bits/stdc++.h>
// #include <bprinter/table_printer.h>
using namespace std;


int ts = 0;

struct student{    //Structure student is made to store student attributes.
    int cls;
    string name;
    int subject[3] = {0};
    int marks[3] = {0};
    int taught[3] = {0};
    int earn = 0;
    int live = 0;
    int avg_marks = 0;
    int total_days = 0;
};

student rec[50];




void StRT(){
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------Student record Table------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "ID       " << "Name        " << "Math       " << "English     " << "Bangla     " << "T_Math    " << "T_English     " << "T_Bangla    "  << "Earning\n\n";
    cout << "---------------------------------------------------------------------------------------" << endl;
}
void ScRT(){
    cout << "-----------------------------------------------------------" << endl;
    cout << "--------------------Subject record Table-------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "ID       " << "Name      " << "Earning    " << "Avg Marks\n\n";
    cout << "-----------------------------------------------------------" << endl;
}


void get_data(int i){       //Function for receiving data from user and populatiing the variables with values.
    cout << "Choice class:\n";
    cout << "1. Class 8\n";
    cout << "2. Class 9\n";
    cout << "3. class 10\n";
    int cls;
    cin >> cls;
    rec[i].cls = cls;
    cout<<"Enter student name: ";
    cin>>rec[i].name;
    cout<<"Enter student's subject choice (1 for yes and 0 for no): \n";
    cout << "Math: ";
    cin >> rec[i].subject[0];
    cout << "English: ";
    cin >> rec[i].subject[1];
    cout << "Bangla: ";
    cin >> rec[i].subject[2];

    rec[i].live = 1;
}



void show_data(int searchkey){    //Function for showing data on the screen.
    int i = searchkey;
    cout << setw(2) << i;
    cout << setw(10) << rec[i].name;
    // cout << setw(10) << rec[i].earn;
    cout << setw(10) << (rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2]);
    cout << setw(10) << float((rec[i].marks[0] + rec[i].marks[1] + rec[i].marks[2]) / 3.0)   <<"\n";
    system("clear");
}

void show_data_indv(int searchkey){
    int i = searchkey;
    cout << setw(2) << i;
    cout << setw(12) << rec[i].name;
    (rec[i].subject[0] == 1)? cout << setw(12) << "Yes":cout << setw(12) << "No";
    (rec[i].subject[1] == 1)? cout << setw(12) << "Yes":cout << setw(12) << "No";
    (rec[i].subject[2] == 1)? cout << setw(12) << "Yes":cout << setw(12) << "No";
    (rec[i].subject[0] == 1)? cout << setw(12) << rec[i].taught[0]:cout << setw(12) << "------- ";
    (rec[i].subject[1] == 1)? cout << setw(12) << rec[i].taught[1]:cout << setw(12) << "------- ";
    (rec[i].subject[2] == 1)? cout << setw(12) << rec[i].taught[2]:cout << setw(12) << "------- ";
    // cout << setw(12) << rec[i].earn << "\n";
    cout << setw(12) << (rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2])  <<"\n";
    system("clear");
}




void add_student(){
    cout << "Number of student will be added: ";
    int stdnt;
    cin >> stdnt;
    int i = 0;
    for(i = ts;i < stdnt + ts && i < 50;i ++)
        get_data(i);
    ts = i;
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
    system("clear");
}


void edit_student(){
    cout << "Enter Student ID: \n";
    int id;
    cin >> id;
    if(id >= 0 && id < 50){
        if(rec[id].live == 1){
            StRT();
            show_data_indv(id);
            cout << "Number of days taught for each subject\n";
            if(rec[id].subject[0] == 1){
                cout << "For Math: ";
                cin >> rec[id].taught[0];
            }
            if(rec[id].subject[1] == 1){
                cout << "For English: ";
                cin >> rec[id].taught[1];
            }
            if(rec[id].subject[2] == 1){
                cout << "For Bangla: ";
                cin >> rec[id].taught[2];
            }
            cout << "\nNumber of marks for each subject\n";
            if(rec[id].subject[0] == 1){
                cout << "For Math: ";
                cin >> rec[id].marks[0];
            }
            if(rec[id].subject[1] == 1){
                cout << "For English: ";
                cin >> rec[id].marks[1];
            }
            if(rec[id].subject[2] == 1){
                cout << "For Bangla: ";
                cin >> rec[id].marks[2];
            }
        }
        else
            cout << "Not found\n";
    }
    else
        cout << "Out of bound\n";
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
    system("clear");
}




void delete_student(){
    cout <<"--------Delete---------\n";
    cout << "Enter student id: ";
    int id;
    cin >> id;
    if(id >= 0 && id < 50){
        rec[id].live = 0;
        cout << "Successfully deleted\n";
    }
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
    system("clear");
}



void show_individual(){
    cout << "Choose class:\n1. Class 8\n2. Class 9\n3. Class 10\n";
    int cls;
    cin >> cls;
    ScRT();
    for(int i = 0;i < ts;i ++){
        if(rec[i].live == 1 && rec[i].cls == cls){
            show_data(i);
        }
    }
    cout << "Want to show details: (y or n)\n";
    char dt;
    cin >> dt;
    if(dt == 'y'){
        cout << "Enter student ID: ";
        int id;
        cin >> id;
        StRT();
        for(int i = 0;i < ts;i ++){
            if(rec[i].live == 1 && rec[i].cls == cls){
                show_data_indv(i);
            }
        }
    }
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
}

void show_overall_info(){
    int class_overall[3] = {0};
    int earning_sub_overall[3] = {0};
    int mrks = 0;
    int tot_sub = 0;
    for(int i = 0;i < ts;i ++){
        // if(rec[i].live == 1){
            if(rec[i].cls == 1)
                class_overall[0] += rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2];
            if(rec[i].cls == 2)
                class_overall[1] += rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2];
            if(rec[i].cls == 3)
                class_overall[2] += rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2];
            earning_sub_overall[0] += rec[i].taught[0];
            earning_sub_overall[1] += rec[i].taught[1];
            earning_sub_overall[2] += rec[i].taught[2];

            if(rec[i].subject[0] == 1){
                mrks += rec[i].marks[0];
                tot_sub += 1;
            }
            if(rec[i].subject[1] == 1){
                mrks += rec[i].marks[1];
                tot_sub += 1;
            }
            if(rec[i].subject[2] == 1){
                mrks += rec[i].marks[2];
                tot_sub += 1;
            }
        // }     
    }
    cout << "Total days taught across all classes:  " << class_overall[0] + class_overall[1] + class_overall[2] << "\n";
    cout << "Individual days taught in each class ::  Class 8: " << class_overall[0] << "  ::  Class 9: " << class_overall[1] << "  :: Class 10: " << class_overall[2] << "\n";

    cout << "Total earnings:  " << class_overall[0] + class_overall[1] + class_overall[2] << "\n";
    cout << "Individual earnings of each class ::  Class 8: " << class_overall[0] << "  ::  Class 9: " << class_overall[1] << "  ::  Class 10: " << class_overall[2] << "\n";


    cout << "Individual earnings of each subject ::  Math: " << earning_sub_overall[0] << "  ::  English: " << earning_sub_overall[1] << "  ::  Bangla: " << earning_sub_overall[2] << "\n";


    cout << "Average marks of all students:  " << float((mrks * 1.0) / tot_sub) << "\n";

    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
    system("clear");

}


int control_panel(){
    // cout << "Control Panel\n";
    cout <<"\n\t\tWhat do you want to do?"<<endl;
    cout <<"\t\t----------------------"<<endl;
    cout <<"\t\t1-Add student"<<endl;
    cout <<"\t\t2-Edit student"<<endl;
    cout <<"\t\t3-Delete student"<<endl;
    cout <<"\t\t4-Individual Information"<<endl;
    cout <<"\t\t5-Overall Information"<<endl;
    cout <<"\t\t6-Exit"<<endl;
    cout <<"\t\t----------------------"<<endl;
    cout <<"Enter your choice: ";
    int t;
    cin >> t;
    return t;
}






int main(){
    while(1){
        int terminate = control_panel();
        // cout << terminate;
        if(terminate == 1)
            add_student();
        if(terminate == 2)
            edit_student();
        if(terminate == 3)
            delete_student();
        if(terminate == 4)
            show_individual();
        if(terminate == 5)
            show_overall_info();
        if(terminate == 6)
            return 0;
    }

}