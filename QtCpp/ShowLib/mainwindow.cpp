#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QtSql>
#include <QFileDialog>
#include <stack>

const size_t code_file_suffix_size = 7;
QString code_file_suffix[] = {"cpp","h","cxx","hpp",
                              "js",
                              "py",
                              "c"
                             };
const size_t img_file_suffix_size = 5;
QString img_file_suffix[] = {"png","jpg","icon","svg","ico"};

bool isFileType(QString suffix,QString file_suffix_array[],const size_t count)
{
    bool ret = false;
    qDebug() << sizeof (file_suffix_array);
    for(size_t i = 0; i < count;i++)
    {
        if(suffix == file_suffix_array[i])
        {
            ret = true;
            break;
        }
    }
    return ret;
}

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


void MainWindow::on_actionOpen_triggered()
{
    const QString dirName(QFileDialog::getExistingDirectory(this, "Choose a directory", m_curDir));
    if (!dirName.isEmpty()) {
        QDir d(dirName);
        //setRepository(d.absolutePath());
        m_curDir = d.absolutePath();
        qDebug() << d.absolutePath();
        getfiles(m_curDir);
    }
}

void MainWindow::on_actionClose_triggered()
{

}

QStringList MainWindow::getfiles(const QString &dir_path)
{
    ui->treeWidget->clear();
    ui->treeWidget->update();
    QStringList get_files;
    QDir dir(dir_path);
    if(!dir.exists())
    {
        qDebug() << "it is not true dir_path";
    }
    QIcon icon_file = m_iconMap[FILE_FOLDER_TYPE];//(":res/resource/files.png");
    std::stack<std::pair<QString,QTreeWidgetItem *>> stack;
    QTreeWidgetItem *cur = new QTreeWidgetItem(ui->treeWidget);
    cur->setIcon(0,icon_file);
    cur->setText(0,dir.dirName());
    ui->treeWidget->setHeaderHidden(true);
    ui->treeWidget->setAnimated(true);
    ui->treeWidget->addTopLevelItem(cur);
    stack.push(std::make_pair(dir.absolutePath(),cur));
    while(!stack.empty())
    {
        auto pair = stack.top();
        stack.pop();
        QDir curDir(pair.first);
        auto pCurItem = pair.second;
        auto infoList = curDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
        qDebug()<< "root " <<pair.first;
        for(int i = 0; i < infoList.size(); i++)
        {
            QFileInfo subdir(infoList.at(i));
            if(subdir.absoluteFilePath() == pair.first)
            {
                qDebug()<< "continue" <<subdir.absoluteFilePath();
                continue;
            }
            qDebug()<<subdir.absoluteFilePath();
            QTreeWidgetItem *subItem = new QTreeWidgetItem(pCurItem);
            if(subdir.isDir())
            {
                subItem->setIcon(0,icon_file);
                qDebug()<< "push" <<subdir.absoluteFilePath();
                stack.push(std::make_pair(subdir.absoluteFilePath(),subItem));
            }
            else
            {
                auto suffix = subdir.suffix();
                if(isFileType(suffix,code_file_suffix,code_file_suffix_size))
                {
                    subItem->setIcon(0,m_iconMap[FILE_CODE_TYPE]);
                }
                else if(isFileType(suffix,img_file_suffix,img_file_suffix_size))
                {
                    subItem->setIcon(0,m_iconMap[FILE_IMG_TYPE]);
                }
                else
                {
                    subItem->setIcon(0,m_iconMap[FILE_BLANK_TYPE]);
                }
            }
            subItem->setText(0,subdir.fileName());
            pCurItem->insertChild(i,subItem);

        }
    }
    ui->treeWidget->update();
    return get_files;
}
