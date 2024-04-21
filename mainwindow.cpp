#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <time.h>
#include <QMessageBox>
#include "MergeSort.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "BinarySearch.h"
#include "NormalflatSearch.h"
#include <chrono>
#include <QTimer>

//using namespace std;


int sorttime;
int sorttime2;
int searchtime;
int searchtime2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->clear();
    srand(time(0));
    QString strr = ui->textEdit_2->toPlainText();
    QString dd;
    for(int i=0;i< strr.toInt();i++)
    {
        int ss= rand()% 2000;
        dd= QString :: number(ss);
        ui->listWidget->addItem(dd);
    }
    ui->label_5->setText("Dataset not sorted");
    ui->label_2->setText("Dataset size:"+ strr);

}


void MainWindow::on_pushButton_5_clicked()
{

    int c = ui->listWidget->count();
    int dd[c];
    for (int i = 0; i < c ; ++i){

        QString s = QString::number(i);
        QModelIndex *model_index = new QModelIndex(ui->listWidget->model()->index(i,0) );
       dd[i]= model_index->data(Qt::DisplayRole).toInt();
    }
    mergesortt ss;
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    ss.mergeSort(dd,0,c-1);
    std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
    sorttime= std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();



    ui->listWidget->clear();
    for(int i=0;i< c;i++)
    {
        QString tt;
        tt= QString :: number(dd[i]);
        ui->listWidget->addItem(tt);
    }
    ui->label_5->setText("Dataset sorted");
    ui->label_3->setText("Sorting using Merge sort");

}


void MainWindow::on_pushButton_6_clicked()
{
    int c = ui->listWidget->count();
    vector<int> dd;
    for (int i = 0; i < c ; ++i){

        QString s = QString::number(i);
        QModelIndex *model_index = new QModelIndex(ui->listWidget->model()->index(i,0) );
       dd.push_back(model_index->data(Qt::DisplayRole).toInt());
    }
    vector<int>::iterator it;
    vector<int>::iterator am;
    it= dd.begin()+c;
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    sort(dd.begin(),it);
    std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
    sorttime2= std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();
    ui->listWidget->clear();
    for(am=dd.begin();am< it;am++)
    {
        QString tt;
        tt= QString :: number(*am);
        ui->listWidget->addItem(tt);
    }
    ui->label_5->setText("Dataset sorted");
    ui->label_3->setText("Sorting using STL sort");

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_4->setText("Using Normal search");
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_4->setText("Using Binary search");
}


void MainWindow::on_pushButton_3_clicked()
{
    QString s =ui->label_4->text();
    if(s=="Using Binary search")
    {
        binary tt;
        int c = ui->listWidget->count();
        int dd[c];
        for (int i = 0; i < c ; ++i){

            QString s = QString::number(i);
            QModelIndex *model_index = new QModelIndex(ui->listWidget->model()->index(i,0) );
           dd[i]= model_index->data(Qt::DisplayRole).toInt();
        }
        QString ff=ui->textEdit->toPlainText();
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        int check=tt.binarySearch(dd,0,c,ff.toInt());
        std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
        searchtime= std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();
        QString num;
        QString num2;
        QString num3;
        num= QString :: number(sorttime);
        num2=QString :: number(searchtime);
        num3= QString:: number(sorttime2);
        QMessageBox dis;
        dis.setInformativeText("time in nanosecond");
        if(check==true)
        {
           if(ui->label_3->text()=="Using Algorithm")
           {
                dis.setText("Using Binary search\nThe item was found\nThe search time:"+num2+"\n"+"The sort time using Merge:"+num+"\n");
           }
           if(ui->label_3->text()=="Sorting using Merge sort")
           {
               dis.setText("Using Binary search\nThe item was found\nThe search time:"+num2+"\n"+"The sort time using Merge:"+num+"\n");
           }
           else
           {
               dis.setText("Using Binary search\nThe item was found\nThe search time:"+num2+"\n"+"The sort time using STl:"+num3);
           }
           dis.exec();
        }
        else{
           if(ui->label_3->text()=="Sorting using Merge sort")
           {
               dis.setText("Using Binary search\nThe item was not found\nThe search time:"+num2+"\n"+"The sort time using Merge:"+num+"\n");
           }
           else
           {
               dis.setText("Using Binary search\nThe item was not found\nThe search time:"+num2+"\n"+"The sort time using STl:"+num3);
           }
           dis.exec();
        }

    }
    else{

        normalsearch tt;
        int c = ui->listWidget->count();
        int dd[c];
        for (int i = 0; i < c ; ++i){

            QString s = QString::number(i);
            QModelIndex *model_index = new QModelIndex(ui->listWidget->model()->index(i,0) );
           dd[i]= model_index->data(Qt::DisplayRole).toInt();
        }
        QString ff=ui->textEdit->toPlainText();
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        int check=tt.search(dd,c,ff.toInt());
        std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
        searchtime2= std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();
        QString num;
        QString num3;
        QString num4;
        num= QString :: number(sorttime);
        num3= QString:: number(sorttime2);
        num4= QString:: number(searchtime2);
        QMessageBox dis;
        dis.setInformativeText("time in nanosecond");
        if(check==1)
        {

           if(ui->label_3->text()=="Sorting using Merge sort")
           {
               dis.setText("Using flat search\nThe item was found\nThe search time:"+num4+"\n"+"The sort time using Merge:"+num+"\n");
           }
           else
           {
               dis.setText("Using flat search\nThe item was found\nThe search time:"+num4+"\n"+"The sort time using STl:"+num3);
           }
           dis.exec();
        }
        else{
           if(ui->label_3->text()=="Sorting using Merge sort")
           {
               dis.setText("Using flat search\nThe item was not found\nThe search time:"+num4+"\n"+"The sort time using Merge:"+num+"\n");
           }
           else
           {
               dis.setText("Using flat search\nThe item was not found\nThe search time:"+num4+"\n"+"The sort time using STl:"+num3);
           }
           dis.exec();
        }

    }





}

