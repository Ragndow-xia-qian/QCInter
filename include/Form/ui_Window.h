/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

namespace QCInter {

class Ui_Window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QCInter_Window)
    {
        if (QCInter_Window->objectName().isEmpty())
            QCInter_Window->setObjectName(QString::fromUtf8("QCInter__Window"));
        QCInter_Window->resize(400, 300);
        centralwidget = new QWidget(QCInter_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QCInter_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QCInter_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 17));
        QCInter_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(QCInter_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QCInter_Window->setStatusBar(statusbar);

        retranslateUi(QCInter_Window);

        QMetaObject::connectSlotsByName(QCInter_Window);
    } // setupUi

    static void retranslateUi(QMainWindow *QCInter_Window)
    {
        QCInter_Window->setWindowTitle(QCoreApplication::translate("QCInter::Window", "Window", nullptr));
    } // retranslateUi

};

} // namespace QCInter


namespace QCInter::Ui {
    class Window: public Ui_Window {};
} // namespace QCInter::Ui


#endif // UI_WINDOW_H
