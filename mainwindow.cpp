#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_statusLabel = new QLabel("Ready", this);
    m_statusLabel->setAlignment(Qt::AlignCenter);
    m_statusLabel->setStyleSheet(
        "color: white;"
        "font-size: 13px;"
        "font-weight: bold;"
        );
    statusBar()->addPermanentWidget(m_statusLabel, 1);

    m_wordCountLabel = new QLabel(this);
    m_wordCountLabel->setStyleSheet(
        "color: white;"
        "font-size: 12px;"
        );
    statusBar()->addWidget(m_wordCountLabel);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered,this, &MainWindow::saveFile);
    connect(ui->textEditor, &QTextEdit::textChanged, this, &MainWindow::updateWordCount);
    updateWordCount();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    ui->textEditor->clear();
    m_currentFile.clear();
    m_statusLabel->setText("New file created");
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, "Open File", "", "Text Files (*.txt);;All Files (*)"
    );

    if (fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(
            this, "Error", "Failed to open file"
        );

        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEditor->setPlainText(text);
    file.close();
    m_currentFile = fileName;
    m_statusLabel->setText("File opened successfully");
}

void MainWindow::saveFile()
{
    QString fileName = m_currentFile;

    if (fileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(
            this, "Save File", "", "Text Files (*.txt);;All Files (*)"
            );

        if (fileName.isEmpty())
        {
            return;
        }
    }
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(
            this,
            "Error",
            "Failed to save file"
            );

        return;
    }
    QTextStream out(&file);
    out << ui->textEditor->toPlainText();
    file.close();

    m_currentFile = fileName;
    m_statusLabel->setText("File saved successfully");
}

void MainWindow::updateWordCount()
{
    QString text = ui->textEditor->toPlainText();

    int characterCount = text.length();

    QStringList words = text.split(
        QRegularExpression("\\s+"),
        Qt::SkipEmptyParts
        );

    int wordCount = words.count();

    m_wordCountLabel->setText(
        QString("Words: %1 | Characters: %2")
            .arg(wordCount)
            .arg(characterCount)
        );
}
