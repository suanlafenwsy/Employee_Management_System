#include "boss.h"

Boss :: Boss(int id, string name, int dId){
    this -> m_Id = id;
    this -> m_Name = name;
    this -> m_DeptId = dId;
}
    
void Boss :: showInfo(){
    cout << "Employee Number:" << this -> m_Id
         << "\tEmployee Name:" << this -> m_Name
         << "\ttitle:" << this -> getDeptName()
         << "\tManage all company affairs." << endl;
    return;
}
string Boss :: getDeptName(){
    return "boss";
}