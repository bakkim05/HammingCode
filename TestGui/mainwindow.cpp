#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <qstring.h>
#include "ErrorDetection.h"
#include "Conversores.h"
#include "hamming.h"

#include <vector>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExpValidator * v = new QRegExpValidator(QRegExp("\(1|0){,12}$"));
    ui->lineEdit->setValidator(v);
    connect(ui->lineEdit, SIGNAL(textChanged(Qstring)) ,
            ui->label_BIN, SLOT(setText(Qstring))  );
    ui->tableView->showGrid();
//    disconnect(ui->lineEdit, SIGNAL(textEdited(Qstring)) ,
//            ui->label_BIN, SLOT(setText(Qstring))  );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Conversores C;
    QString text = ui->lineEdit->text();
    qInfo() << text.toInt();
    int decimal = C.binary2decimal(text.toInt());
    QString hex =  QString::fromStdString( C.decimal2hexa(decimal) );
    QString bcd =  QString::fromStdString( C.decimal2BDC(decimal) );

    ui->label_BIN->setText(text);
    ui->label_DEC->setText(QString::number(decimal));
    ui->label_HEX->setText(hex);
    ui->label_BCD_2->setText(bcd);
//    qInfo() << "TEST1";
}

