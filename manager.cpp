#include "manager.h"

Manager :: Manager(int id, string name, int dId){
    this -> m_Id = id;
    this -> m_Name = name;
    this -> m_DeptId = dId;
}
    
void Manager :: showInfo(){
    cout << "Employee Number:" << this -> m_Id
         << "\tEmployee Name:" << this -> m_Name
         << "\ttitle:" << this->getDeptName()
         << "\tComplete the tasks assigned by the boss and then distribute the tasks to the employees." << endl;
    return;
}
string Manager :: getDeptName(){
    return "manager";
}