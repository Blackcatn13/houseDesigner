#include "thothwindow.h"
#include "ui_thothwindow.h"
#include <QTreeWidget>
#include "Scenary.h"
//Important includes
#include <QModelIndex>
#include <QFileSystemModel>

ThothWindow::ThothWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThothWindow)
{
    ui->setupUi(this);
    // ALERT! Use the following code to get keyboard focus at your OpenGL widget
    ui->contextGL->setFocusPolicy(Qt::StrongFocus);
    ui->contextGL->setFocus();

    //Tree file.

    //treeview of tabs
    new TreeFile(ui->treeViewBuild, "Build");

    new TreeFile(ui->treeViewDecorate, "Decorate");

    new TreeFile(ui->treeViewFurnish, "Furnish");
}

ThothWindow::~ThothWindow()
{
    delete ui;
    delete m_buildModel;
    delete m_decorateModel;
    delete m_furnishModel;
}

void ThothWindow::on_pushButton_4_clicked()
{
    //Select build model

    QModelIndex indx = ui->treeViewBuild->currentIndex();
    QFileInfo info = m_buildModel->fileInfo(indx);
    if(info.isFile())
    {
        if(info.suffix() == QString("obj"))
        {
            qDebug("Create model with path: %s", qPrintable(info.absoluteFilePath()));
            if(info.absoluteFilePath().contains(QString("wall"),Qt::CaseInsensitive))
            {
                CScenary::getInstance()->setActiveModel(info.absoluteFilePath().toStdString());
                CScenary::getInstance()->setActiveType(WALL);
            }
        }
    }
}

void ThothWindow::on_pushButton_5_clicked()
{
    //Delete build model
    QModelIndex indx = ui->treeViewBuild->currentIndex();
    if(indx.isValid())
    {
        if(m_buildModel->fileInfo(indx).isFile())
        {
            qDebug("Delete model with path: %s", qPrintable(m_buildModel->fileInfo(indx).absoluteFilePath()));
        }
    }
}

void ThothWindow::on_pushButton_clicked()
{
    //Select furnish model
    QModelIndex indx = ui->treeViewFurnish->currentIndex();
    QFileInfo info = m_furnishModel->fileInfo(indx);
    if(info.isFile())
    {
        if(info.suffix() == QString("obj"))
        {
            qDebug("Create model with path: %s", qPrintable(info.absoluteFilePath()));
                CScenary::getInstance()->setActiveModel(info.absoluteFilePath().toStdString());
                CScenary::getInstance()->setActiveType(OBJECT);
        }
    }
}

void ThothWindow::on_pushButton_2_clicked()
{
    //Delete furnish model
    QModelIndex indx = ui->treeViewFurnish->currentIndex();
    if(indx.isValid())
    {
        if(m_furnishModel->fileInfo(indx).isFile())
        {
            qDebug("Delete model with path: %s", qPrintable(m_furnishModel->fileInfo(indx).absoluteFilePath()));
        }
    }
}

void ThothWindow::on_pushButton_6_clicked()
{
    //Select decorate model
    QModelIndex indx = ui->treeViewDecorate->currentIndex();
    if(indx.isValid())
    {
        if(m_decorateModel->fileInfo(indx).isFile())
        {
            qDebug("Create model with path: %s", qPrintable(m_decorateModel->fileInfo(indx).absoluteFilePath()));
        }
    }
}

void ThothWindow::on_pushButton_7_clicked()
{
    //Delete decorate model
    QModelIndex indx = ui->treeViewDecorate->currentIndex();
    if(indx.isValid())
    {
        if(m_decorateModel->fileInfo(indx).isFile())
        {
            qDebug("Delete model with path: %s", qPrintable(m_decorateModel->fileInfo(indx).absoluteFilePath()));
        }
    }
}
