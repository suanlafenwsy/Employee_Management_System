#pragma once
#include <iostream>

using namespace std;

#include <string>

//职工抽象类
class Worker {
public:
    int m_Id;
    string m_Name;
    int m_DeptId;

    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
};