#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Windows.h>
#include <QMessageBox>


#include <QMainWindow>
#include <QPlainTextEdit>
#include <QTime>

#include "Drives/drivepasport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///CTOR
    explicit MainWindow(QWidget *parent = nullptr);

    ///Appends to log same text
    void AppendLog(const QString& str);

    ///DTOR
    ~MainWindow();


private slots:
    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui = nullptr;
    Drives::DrivePasport _ddInfo;
};

#endif // MAINWINDOW_H
