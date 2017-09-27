#include <iostream>
#include "mainwindow.h"
#include "scripter.h"

#include <QtWidgets>
#include <QDebug>
#include <QString>

MainWindow::MainWindow()
{
    createActions();
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *exitAct = fileMenu->addAction(tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);

    QMenu *scriptMenu = menuBar()->addMenu(tr("&Script"));
    QAction *runAct = scriptMenu->addAction(tr("&Run"), this, &MainWindow::scriptRun);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    // add an help entry that responds to F1
}

void MainWindow::scriptRun()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		// tr("Open Image"), QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last(), tr("Image Files (*.py *.png *.jpg *.bmp)"));
		tr("Open Script"), SCRIPTS_DIRECTORY, tr("Python Files (*.py)"));
    qDebug() << "fileName" << fileName;
    std::cout << "filename: " << fileName.toStdString() << std::endl;

    Scripter scripter;
    scripter.runFile(fileName.toStdString());
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About this sample"),
        tr("This <i>Sample</i> creates a window with a menu bar."));
}
