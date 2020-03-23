#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <map>
#include "common.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionOpen_triggered();

    void on_actionClose_triggered();
private:
    void loadIcon();
    void readSqlite();
    QStringList getfiles(const QString &dir_path);
private:
    Ui::MainWindow *ui;
    QString             m_curDir;
    std::map<ENUM_FILE_TYPE,QIcon>  m_iconMap;
};
#endif // MAINWINDOW_H
