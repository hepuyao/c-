#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!loadPlugin())
    {
        //如果无法加载插件
        QMessageBox::information(this,"Error","Could not load the plugin");
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::loadPlugin()
{
    QDir pluginsDir("/home/kylin/temp4/build-plugin-Imported_Kit-Release");

    //遍历插件目录
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        qDebug()<<fileName;
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if(plugin)
        {
            qDebug()<<"instance plugin";
            regExpInterface = qobject_cast<RegExpInterface*>(plugin);
            if(regExpInterface)
            {
                qDebug()<<"fint the plugin";
                return true;
            }
        }
        qDebug()<<"isn't the plugin";
    }
    return false;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = regExpInterface->regexp(ui->lineEdit->text());
    ui->label->setText(str);
}
