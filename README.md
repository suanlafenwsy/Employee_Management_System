# 员工管理系统（Employee Management System）

这是一个使用 **C++** 编写的员工管理系统，实现以下功能：

- 添加员工
- 删除员工
- 修改员工信息
- 查找员工
- 显示所有员工
- 保存与读取员工数据

## 项目结构
- boss.cpp
- employee.cpp
- manager.cpp
- workerManager.cpp  
对于这句代码 ```Worker ** newSpace = new Worker*[newSize];```   
是在堆区开辟了一块空间，用来存放Worker类型的指针，数组大小是newSize，newSpace是指向该数组的指针，问题是：不论是数组中存储的指针，还是newSpace中存储的这个指针，在内存中都只是存储一个内存地址的值，那为什么类型不是int呢，为什么指针的类型定义为Worker类？  
类型决定**编译器如何解释内存**：  
```class Worker {
public:
    string name;   // 假设24字节
    int id;        // 4字节
    double salary; // 8字节
    // 总共约36字节
    
    void work() {
        cout << name << "在工作" << endl;
    }
};

int main() {
    Worker w("张三", 1001, 5000);
    
    // 假设 &w = 0x1000
    
    Worker* p1 = &w;
    int* p2 = (int*)&w;  // 强制转换，编译能通过但不推荐
    
    // 访问成员
    cout << p1->name << endl;     // 编译器知道从0x1000开始读取string
    // cout << p2->name << endl;  // 编译错误！int*没有->操作符
    
    // 指针运算
    p1++;  // 地址增加36字节（sizeof(Worker)）
    p2++;  // 地址增加4字节（sizeof(int)）
    
    // 解引用
    Worker w2 = *p1;    // 读取36字节，完整复制Worker对象
    int x = *p2;        // 读取4字节，解释为整数
    
    // 但下面这个完全错误：
    // Worker w3 = *p2;  // 编译错误！类型不匹配
}
```  
指针存储的是内存地址，而地址的范围决定了指针的大小，也就是说**指针本身在内存中的占用空间大小，与指向的对象类型无关，只取决于系统位数。**    
```
int newSize = this -> m_EmpNum + addNum;
        Worker ** newSpace = new Worker*[newSize];

        if(this -> m_EmpArray != NULL) {
            for(int i = 0; i < this -> m_EmpNum; i++) {
                newSpace[i] = this -> m_EmpArray[i];
            }
        }
```  
这段代码中，newSpace本身是一个指针变量（在栈上），它指向堆上的一块内存，这块内存是一个数组，数组的元素类型是Worker*（指向Worker的指针），但是**可以用下标newSpace[i]访问数组元素。**  


- 职工管理系统.cpp