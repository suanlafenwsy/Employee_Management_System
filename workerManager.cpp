#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() {
    
    ifstream ifs;

    //文件不存在
    ifs.open(FILENAME, ios :: in);

    if(!ifs.is_open()){

        //cout << "The file does not exist." << endl;

        this -> m_EmpNum = 0;
        this -> m_EmpArray = NULL;
        this -> m_FileIsEmpty = true;

        ifs.close();

        return;
    }

    //文件存在，但数据为空
    char ch;
    ifs >> ch; //从文件中读一个字符
    if(ifs.eof()) {

        //cout << "The file is empty." << endl;

        this -> m_EmpNum = 0;
        this -> m_EmpArray = NULL;
        this -> m_FileIsEmpty = true;

        ifs.close();

        return;
    }

    //文件存在且有数据
    int num = this -> get_EmpNum();

    //cout << "The number of employee is:" << num << endl;

    this -> m_EmpNum = num;
    //开辟空间
    this -> m_EmpArray = new Worker*[this -> m_EmpNum];
    //将文件中的数据存到数组中
    this -> init_Emp();

    this -> m_FileIsEmpty = false;
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
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
            }

            newSpace[this -> m_EmpNum + i] = worker;
        }

        delete[] this -> m_EmpArray; //?
        this -> m_EmpArray = newSpace;
        this -> m_EmpNum = newSize;

        cout << "Successfully added " << addNum << "employees." << endl;

        this -> m_FileIsEmpty = false;
        this -> save();

    }
    else {
        cout << "input error" << endl;
    }

    system("pause");
    system("cls");
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

int WorkerManager :: get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios :: in);

    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId) num++;

    ifs.close();

    return num;
}

void WorkerManager :: init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios :: in);

    int id;
    string name;
    int dId;

    int index = 0;

    while(ifs >> id && ifs >> name && ifs >> dId) {
        Worker * worker = NULL;

        if(dId == 1) {
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2) {
            worker = new Manager(id, name, dId);
        }
        else {
            worker = new Boss(id, name, dId);
        }

        this -> m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

void WorkerManager :: Show_Emp() {

    if(this -> m_FileIsEmpty) {
        cout << "The file does not exist or the record is empty." << endl;
    }

    else {
        for (int i = 0; i < m_EmpNum; i++) {
            
            //利用多态调用接口
            this -> m_EmpArray[i] -> showInfo();
        }
    }

    system("pause");
    system("cls");
}

int WorkerManager :: IsExist(int id) {
    int index = -1;
    
    for (int i = 0; i < this -> m_EmpNum; i++) {
        if(this -> m_EmpArray[i] -> m_Id == id) {
            index = i;
            break;
        }
    }

    return index;
}

void WorkerManager :: Del_Emp() {

    if(this -> m_FileIsEmpty) {
        cout << "The file does not exist or is empty." << endl;
    }

    else {
        cout << "Please enter the employee ID you wish to delete：" << endl;

        int id;
        cin >> id;

        int index = IsExist(id);

        if(index != -1) {

            //通过数据前移的方式达到删除职工的效果
            for(int i = index; i < this -> m_EmpNum - 1; i++) {
                this -> m_EmpArray[i] = this -> m_EmpArray[i + 1];
            }
            this -> m_EmpNum -= 1;

            this -> save();

            cout << "Deletion successful!" << endl;
        }
        else {
            cout << "Deletion failed,the employee could not be found." << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager :: Mod_Emp() {

    if(this -> m_FileIsEmpty) {
        cout << "The file does not exist or is empty." << endl;
    }

    else {

        int id;

        cout << "Please enter the employee ID you wish to modify：" << endl;
        cin >> id;

        int ret = this -> IsExist(id);

        if(ret != -1) {
            delete this -> m_EmpArray[ret];

            int newId;
            string newName;
            int dSelect;

            cout << "Please enter the new employee's ID:" << endl;
            cin >> newId;
            cout << "Please enter the new employee's name:" << endl;
            cin >> newName;
            cout << "Please enter the new employee's job title:" << endl;
            cout << "1.employee" << endl;
            cout << "2.manager" << endl;
            cout << "3.boss" << endl;
            cin >> dSelect;

            Worker *worker = NULL;

            switch(dSelect) {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            this -> m_EmpArray[ret] = worker;

            cout << "Modification successful!" << endl;

            this -> save();
        }
        else {
            cout << "Modification failed, no such person found." << endl;
        }
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager() {
    if (this -> m_EmpArray != NULL) {
        delete[] this -> m_EmpArray;
        this -> m_EmpArray = NULL;
    }
}