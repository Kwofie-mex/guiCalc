#include "calculator.h"
#include "ui_calculator.h"


 double calcVal = 0.0;
 bool divTrigger = false;
 bool multTrigger = false;
 bool addTrigger = false;
 bool subTrigger = false;


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i=0; i<10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()==0)|| (displayVal.toDouble()==0.0)){
        ui->Display->setText(butVal);
    }else{
        QString newVal = displayVal +butVal;
        double dblnewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblnewVal, 'g', 16));

    }
}





void Calculator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "÷", Qt::CaseInsensitive)==0){
        divTrigger = true;
          ui->Display->setText(butVal);
    } else if(QString::compare(butVal, "x", Qt::CaseInsensitive)==0){
        multTrigger = true;
         ui->Display->setText(butVal);
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive)==0){
        addTrigger = true;
         ui->Display->setText(butVal);
    } else if(QString::compare(butVal, "-", Qt::CaseInsensitive)==0){
        subTrigger = true;
         ui->Display->setText(butVal);
    }




}
