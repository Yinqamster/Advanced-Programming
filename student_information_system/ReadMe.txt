学号 14122132
编译环境：VS2015
代码实现功能：学生信息管理系统

具体功能介绍：
1.登陆界面
  管理员登录  用户名密码均为admin
  学生登录    已导入的学生可以登录(已导入的学生信息在student.txt中)， 用户名密码均为学号

2.学生登录
  点击个人信息查看可查看学号为登录名的学生的个人信息
  点击选课信息可查看学号为登录名的学生的选课信息

3.管理员登录
  3.1学生信息管理
    信息导入：从student.txt中读入学生信息
    信息导出：将学生信息表中的数据存入student.txt中
    信息查看：查看系统中所有学生的信息，可选择按照学号或姓名排序
    增加学生信息：每项均不能为空， 不能重复添加
    删除学生信息：须提供要删除学生的学号
    查找学生信息：须提供要查找学生的学号，可查看该学生的所有个人信息

  3.2课程信息管理
    课程导入：从course.txt中读入课程信息
    课程导出：将所有课程的信息存入course.txt中
    课程查看：可查看所有课程的课程信息
    增加课程：按照要求添加课程，每项均不能为空，课程编号课程名均不能重复
    删除课程：须提供课程名或课程编号

  3.3选课信息管理
    指定学生选课：须提供学号和课程名或课程编号
    指定学生退选：须提供学号和课程名或课程编号
    查询学生选修情况：提供学号可查询该学生选课情况
    查询课程选修情况：提供课程名或课程编号可查询选修该课程的学生
    查询所有选课信息：可以查询所有学生的选课记录

  注：在删除学生时会把他的选课记录全部删除
      在删除课程时会把选课记录中该课程都删除


文件功能介绍：

AddCourseDlg.h  AddCourseDlg.c       //添加课程信息
AddDlg.h AddDlg.c                    //添加学生信息
AllSelectionDlg.h AllSelectionDlg.c  //所有学生的选课记录
DelCourseDlg.h DelCourseDlg.c        //删除课程信息
DelDlg.h DelDlg.c                    //删除学生信息
DropCourseDlg.h DropCourseDlg.c      //指定学生退选
MenuDlg.h MenuDlg.c                  //管理员登录后的控制面板
QueryCourseDlg.h QueryCourseDlg.c    //查询某课程选修情况
QueryStudentDlg.h QueryStudent.c     //查询某学生选课信息
SearchDlg.h SearchDlg.c              //查找学生信息
SelectCourseDlg.h SelectCourseDlg.c  //指定学生选课
ShowCourseDlg.h ShowCourseDlg.c      //查看所有课程信息 
ShowDlg.h ShowDlg.c                  //查看所有排序的学生信息
StudentInformation.h StudentInformation.c  //初始文件  选课和退课
StudentInformationDlg.h StudentInformationDlg.c  //登录界面
stuInfoDlg.h stuInfoDlg.h            //学生身份登录