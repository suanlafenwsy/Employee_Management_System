#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() {
    this -> m_EmpNum = 0;
    this -> m_EmpArray = NULL;
}

void WorkerManager::Show_Menu() {
    cout << "***************************************" << endl;
    cout << "************** welcome! **************" <<endl;
    cout << "************** 0.exit  ***************" <<endl;
    cout << "************** 1.add   ***************" <<endl;
    cout << "************** 2.show  ***************" <<endl;
    cout << "************** 3.delete***************" <<endl;
    cout << "************** 4.modify***************" <<endl;
    cout << "************** 5.search***************" <<endl;
    cout << "************** 6.sort  ***************" <<endl;
    cout << "**************7.clear all***************" <<endl;
    cout << "***************************************" << endl;
    cout << endl;
}

void WorkerManager :: ExitSystem() {
    cout << " Welcome to use it again." << endl;
    system("pause");

    //C标准库函数 C++继承了
    //立即结束整个程序 并返回状态码给操作系统
    exit(0);
}

void WorkerManager :: Add_Emp() {
    cout << "Please enter the number of employees to add." << endl;

    int addNum = 0;
    cin >> addNum;

    if(addNum) {
        int newSize = this -> m_EmpNum + addNum;
        Worker ** newSpace = new Worker*[newSize];

        if(this -> m_EmpArray != NULL) {
            for(int i = 0; i < this -> m_EmpNum; i++) {
                newSpace[i] = this -> m_EmpArray[i];
            }
        }

        for(int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;

            cout << "Please enter the ID of the " << i + 1 << "-th employee." <<endl;
            cin >> id;

            cout << "Please enter the name of the " << i + 1 << "-th employee." <<endl;
            cin >> name;

            cout << "Please select the employee's position." <<endl;
            cout << "1.employee" << endl;
            cout << "2.manager" << endl;
            cout << "3.boss" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch(dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                case 2:
                    worker = new Manager(id, name, 2);
                case 3:
                    worker = new Boss(id, name, 3);
            }

            newSpace[this -> m_EmpNum + i] = worker;
        }

        delete[] this -> m_EmpArray; //?
        this -> m_EmpArray = newSpace;
        this -> m_EmpNum = newSize;

        cout << "Successfully added " << addNum << "employees." << endl;

        this -> save();

        system("pause");
        system("cls");
    }
    else {
        cout << "input error" << endl;
    }
}

void WorkerManager :: save() {
    ofstream ofs;
    ofs.open(FILENAME, ios :: out);

    for (int i = 0; i < this -> m_EmpNum; i++) {
        ofs << this -> m_EmpArray[i] -> m_Id << " "
            << this -> m_EmpArray[i] -> m_Name << " "
            << this -> m_EmpArray[i] -> m_DeptId << endl;
    }

    ofs.close();
}

WorkerManager::~WorkerManager() {
    if (this -> m_EmpArray != NULL) {
        delete[] this -> m_EmpArray;
        this -> m_EmpArray = NULL;
    }
}