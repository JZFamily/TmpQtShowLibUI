#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum FILE_TYPE
{
EMPTY_TYPE = 0,
FILE_AI_TYPE ,
FILE_BLANK_TYPE,
FILE_CODE_TYPE ,
FILE_EXE_TYPE ,
FILE_IMG_TYPE,
FILE_MUSIC_TYPE ,
FILE_PDF_TYPE,
FILE_TXT_TYPE,
FILE_VIDEO_TYPE,
FILE_ZIP_TYPE,
FILE_FOLDER_TYPE,
};

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
    void readSqlite();
    QStringList getfiles(const QString &dir_path);
private:
    Ui::MainWindow *ui;
    QString             m_curDir;
    std::map<FILE_TYPE,QIcon>  m_iconMap;
};
#endif // MAINWINDOW_H
