#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Utilites/memory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->AppendLog("Запуск программы...");
}

void MainWindow::AppendLog(const QString& str)
{
    QString* _str = new QString("[");

    _str->append(QTime::currentTime().toString());
    _str->append("]: ");
    _str->append(str);
    _str->append('\n');
    _str->append(this->ui->tbLog->toPlainText());
    this->ui->tbLog->setPlainText(*_str);

    delete _str;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    QMessageBox box;

    switch(index)
    {
        case 0:
            break;
        case 1:
            if(!this->_ddInfo.IsInitialized())
                this->_ddInfo.Initialize();
            box.setText(QString::number(this->_ddInfo.GetCountDrives()));
            box.exec();
            break;
    }
}
