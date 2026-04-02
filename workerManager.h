#pragma once //防止头文件重复包含 效果和#ifndef #define #endif一样
#include <iostream>
#include <fstream>

using namespace std;

#define FILENAME "empFile.txt"

#include "worker.h"

class WorkerManager {
public:

    int m_EmpNum; //记录职工人数
    Worker ** m_EmpArray; //职工数组指针

    //构造函数
    WorkerManager();

    void Show_Menu();

    void ExitSystem();

    void Add_Emp();

    void save();

    //析构函数
    ~WorkerManager();
};

//这是C++项目组织的核心惯例 头文件声明＋源文件定义