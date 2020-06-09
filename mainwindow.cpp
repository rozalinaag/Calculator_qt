#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first; //для первого числа

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //переход к слоту прописываем тут

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_multiplay,SIGNAL(clicked()),this,SLOT(math_operation()));

    //для возможности установки сетчек
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiplay->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    ui->result_show->setText("");
    //для вывода в резалт шоу цифр

    double all_numbers; //double
    QString new_label;   //string, поэтому дальше сумма строк

    if (ui->result_show->text().contains(".") && button->text()=="0"){
        new_label = ui->result_show->text() + button->text();
    } else {

    all_numbers=(ui->result_show->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers,'g',10);
    }
    ui->result_show->setText(new_label);

}

//dotter pointer
void MainWindow::on_pushButton_dot_clicked()
{
    //чтобы точка была одна и больше не выводилась на экран несколько раз
    if (!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text()+".");
}
void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    //для вывода в резалт шоу цифр
    double all_numbers; //double
    QString new_label;   //string, поэтому дальше сумма строк

    //кнопка +-
    if (button->text()=="+/-"){
        all_numbers=(ui->result_show->text()).toDouble();
        all_numbers=all_numbers*-1;

        //конвертируем в строку
        new_label = QString::number(all_numbers,'g',10);

        ui->result_show->setText(new_label);
    }
    else if (button->text()=="%"){
        all_numbers=(ui->result_show->text()).toDouble();
        all_numbers=all_numbers*0.01;

        //конвертируем в строку
        new_label = QString::number(all_numbers,'g',10);

        ui->result_show->setText(new_label);
    }
}
void MainWindow::math_operation()
{
    QPushButton *button = (QPushButton *)sender();

    //помещаем первое число в переменную
    num_first= ui->result_show->text().toDouble();

    //QString lan=" ";
    //для того чтобы после нажатия знака окно отчищалось
    ui->result_show->setText("");
    button->setChecked(true);

}
void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiplay->setChecked(false);
    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_ravno_clicked()
{

    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble(); //второе значние

    if (ui->pushButton_plus->isChecked())
    {
        labelNumber= num_first + num_second;

        //снимаем флаг что кнопка нажата, чтобы потом можн было много раз нажимать плюс
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {

        labelNumber= num_first - num_second;


        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_divide->isChecked())
    {
        if (num_second == 0){
            ui->result_show->setText("error");
        }
        else{
        labelNumber= num_first / num_second;

        }
        ui->pushButton_divide->setChecked(false);
    }
    else if (ui->pushButton_multiplay->isChecked())
    {
        labelNumber= num_first * num_second;


        ui->pushButton_multiplay->setChecked(false);
    }
    new_label = QString::number(labelNumber,'g',10);

    ui->result_show->setText(new_label);
}


