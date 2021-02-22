#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;
double save_number = 0.0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_change,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operation()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(math_operation()));
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_division->setCheckable(true);

    connect(ui->pushButton_pow2,SIGNAL(clicked()),this,SLOT(power2()));
    connect(ui->pushButton_sqrt2,SIGNAL(clicked()),this,SLOT(power2()));

    connect(ui->pushButton_memoryAdd,SIGNAL(clicked()),this,SLOT(memory_work()));\
    connect(ui->pushButton_memoryClear,SIGNAL(clicked()),this,SLOT(memory_work()));
    connect(ui->pushButton_memoryGet,SIGNAL(clicked()),this,SLOT(memory_work()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button =(QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->label->text().contains(".") && button->text()== "0"){
        new_label = ui->label->text()+button->text();
    }else{
        all_numbers = (ui->label->text()+button->text()).toDouble();
        new_label = QString::number(all_numbers,'g', 15);
    }
    ui->label ->setText(new_label);
}


void MainWindow::on_pushButton_dot_clicked(){
    if(!(ui->label->text().contains('.')))
        ui->label ->setText(ui->label->text()+".");
}

void MainWindow::operation(){
    QPushButton *button =(QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text()=="+/-"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers *= (-1);
        new_label = QString::number(all_numbers,'g', 15);
        ui->label ->setText(new_label);
    }
    else if(button->text()=="%"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers *= 0.01;
        new_label = QString::number(all_numbers,'g', 15);
        ui->label ->setText(new_label);
    }
}

void MainWindow::math_operation()
{
    QPushButton *button =(QPushButton *)sender();

    num_first = ui->label->text().toDouble();
    ui->label->setText("0");
    button->setChecked(true);
}

void MainWindow::on_pushButton_clear_clicked()
{
    QPushButton *button =(QPushButton *)sender();
    ui->label->setText("0");
    button->setChecked(true);
}

void MainWindow::on_pushButton_equel_clicked()
{
    double labelNumber, num_second;
    QString new_label;
    num_second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber,'g', 15);
        ui->label ->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber,'g', 15);
        ui->label ->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_mult->isChecked()){
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber,'g', 15);
        ui->label ->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }else if(ui->pushButton_division->isChecked()){
        if(num_second ==0){
            ui->label ->setText("ERROR");
        }else{
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber,'g', 15);
            ui->label ->setText(new_label);
        }
        ui->pushButton_division->setChecked(false);
    }
}

void MainWindow::power2(){
    QPushButton *button =(QPushButton *)sender();
    double numbers;
    QString power_number;
    if(button->text() == "pow(2)"){
        numbers = ui->label->text().toDouble();
        numbers = pow(numbers,2);
        power_number = QString::number(numbers,'g', 15);
        ui->label->setText(power_number);
    }
    else if (button->text() == "sqrt()"){
        numbers = ui->label->text().toDouble();
        numbers = sqrt(numbers);
        power_number = QString::number(numbers,'g', 15);
        ui->label->setText(power_number);
    }
}

void MainWindow::memory_work(){
    QPushButton *button =(QPushButton *)sender();
    QString out_save_number;

    if (button->text() == "M+"){
        save_number = ui->label->text().toDouble();
        out_save_number = QString::number(save_number,'g', 15);
    }
    else if (button->text() == "M-"){
        save_number = 0.0;
        out_save_number = QString::number(save_number,'g', 15);
        ui->label->setText(out_save_number);
    }
    else if (button->text() == "M"){
        out_save_number = QString::number(save_number,'g', 15);
        ui->label->setText(out_save_number);
    }
}



















