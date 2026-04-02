#include "employee.h"

Employee :: Employee(int id, string name, int dId) {
    this -> m_Id = id;
    this -> m_Name = name;
    this -> m_DeptId = dId;
}

void Employee :: showInfo() {
    cout << "Employee Number:" << this -> m_Id
         << "\tEmployee Name:" << this -> m_Name
         << "\ttitle:" << this->getDeptName()
         << "\tComplete the tasks assigned by the manager" << endl;
    return;
}
string Employee :: getDeptName() {
    return "employee";
}