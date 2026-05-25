#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString m_currentFile;
    QLabel *m_statusLabel;
    QLabel *m_wordCountLabel;

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void updateWordCount();

};
#endif // MAINWINDOW_H
