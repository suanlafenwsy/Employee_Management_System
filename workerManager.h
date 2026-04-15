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
    bool m_FileIsEmpty; //记录文件是否为空

    //构造函数
    WorkerManager();

    void Show_Menu();

    void ExitSystem();

    void Add_Emp();

    void save();

    int get_EmpNum();

    void init_Emp();

    void Show_Emp();
    
    //根据id判断该职工是否存在
    int IsExist(int id);

    void Del_Emp();

    void Mod_Emp();

    void Find_Emp();

    void Sort_Emp();

    void Clean_File();

    //析构函数
    ~WorkerManager();
};

//这是C++项目组织的核心惯例 头文件声明＋源文件定义