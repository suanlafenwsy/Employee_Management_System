#include <iostream>
#include <cstdlib>

using namespace std;

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

    //实例化一个管理者对象
    WorkerManager wm;

    //用来存储用户的选项
    int choice = 0;

    while(1) {
        wm.Show_Menu();
        cout << "please input:" << endl;

        cin >> choice;

        switch(choice) {
            case 0:  //退出系统
                wm.ExitSystem();
                break;
            case 1:  //增加职工
                wm.Add_Emp();
                break;
            case 2:  //显示职工
                wm.Show_Emp();
                break;
            case 3:  //删除职工
                wm.Del_Emp();
                break;
            case 4:  //修改职工
                wm.Mod_Emp();
                break;
            case 5:  //查找职工
                wm.Find_Emp();
                break;
            case 6:  //排序职工
                wm.Sort_Emp();
                break;
            case 7:  //清空文档
                break;
            default:
                system("cls");
        }
    }

    system("pause");

    return 0;
}