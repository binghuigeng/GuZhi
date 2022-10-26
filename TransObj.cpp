#include "TransObj.h"
#include <QDebug>
#include <Eigen/Dense>
#include <iostream>

using namespace std;

void GuZhiRebot::getValFromQml(QString inputData)
{
//    qDebug() << "value from qml is :" << inputData;
//    emit valueFromCpp(456);
    if (inputData.size() == 16)
    {
//        qDebug("输入数字个数正确");
        if (check_input(inputData))
        {
//            qDebug("输入数字正确");
            print_output(inputData);
        }
        else {
            qDebug("输入数字有误，请重新输入");
        }
    }
    else
    {
        qDebug("输入数字个数有误，请重新输入");
    }

}

bool GuZhiRebot::check_input(QString data)
{
    for(int i=0; i<16; i++)
    {
        char ch = data.at(i).toLatin1();
//        qDebug() << ch;
        if (((ch >= 0x30) && (ch <= 0x39)) || ((ch >= 0x41) && (ch <= 0x46)) || ((ch >= 0x61) && (ch <= 0x66))) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

void GuZhiRebot::print_output(QString data)
{
    Eigen::Matrix4d rot;
    Eigen::Matrix4d rot2;

    //矩阵的赋值
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            switch (data.at(i*4+j).toLatin1()) {
            case 'A':
            case 'a':
                rot(i,j) = 10;
                break;
            case 'B':
            case 'b':
                rot(i,j) = 11;
                break;
            case 'C':
            case 'c':
                rot(i,j) = 12;
                break;
            case 'D':
            case 'd':
                rot(i,j) = 13;
                break;
            case 'E':
            case 'e':
                rot(i,j) = 14;
                break;
            case 'F':
            case 'f':
                rot(i,j) = 15;
                break;
            default:
                rot(i,j) = QString(data.at(i*4+j)).toDouble();
                break;
            }
        }
    }
    cout << "Matrix4d is :" << endl  << rot << endl;


    //矩阵点乘
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            rot2(i,j) = rot(i,j) * rot(i,j);
        }
    }
    cout << "Matrix4d's Point Multipllication is :" << endl << rot2 << endl;
}
