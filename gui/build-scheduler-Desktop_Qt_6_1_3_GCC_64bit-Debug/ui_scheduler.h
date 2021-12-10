/********************************************************************************
** Form generated from reading UI file 'scheduler.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULER_H
#define UI_SCHEDULER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scheduler
{
public:
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionImport_People;
    QAction *actionClear_Shifts;
    QAction *actionClear_People;
    QAction *actionAssign_Shifts;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab_view_placement;
    QTableWidget *tableWidget_2;
    QWidget *tab_edit_people;
    QTableWidget *tableWidget;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Scheduler)
    {
        if (Scheduler->objectName().isEmpty())
            Scheduler->setObjectName(QString::fromUtf8("Scheduler"));
        Scheduler->resize(800, 600);
        actionExport = new QAction(Scheduler);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionExit = new QAction(Scheduler);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionImport_People = new QAction(Scheduler);
        actionImport_People->setObjectName(QString::fromUtf8("actionImport_People"));
        actionClear_Shifts = new QAction(Scheduler);
        actionClear_Shifts->setObjectName(QString::fromUtf8("actionClear_Shifts"));
        actionClear_People = new QAction(Scheduler);
        actionClear_People->setObjectName(QString::fromUtf8("actionClear_People"));
        actionAssign_Shifts = new QAction(Scheduler);
        actionAssign_Shifts->setObjectName(QString::fromUtf8("actionAssign_Shifts"));
        centralwidget = new QWidget(Scheduler);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 771, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_view_placement = new QWidget();
        tab_view_placement->setObjectName(QString::fromUtf8("tab_view_placement"));
        tableWidget_2 = new QTableWidget(tab_view_placement);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_2->rowCount() < 1)
            tableWidget_2->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem4);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(0, 0, 761, 451));
        tabWidget->addTab(tab_view_placement, QString());
        tab_edit_people = new QWidget();
        tab_edit_people->setObjectName(QString::fromUtf8("tab_edit_people"));
        tableWidget = new QTableWidget(tab_edit_people);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 761, 451));
        tabWidget->addTab(tab_edit_people, QString());

        verticalLayout->addWidget(tabWidget);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        Scheduler->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Scheduler);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        Scheduler->setMenuBar(menubar);
        statusbar = new QStatusBar(Scheduler);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Scheduler->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionImport_People);
        menuEdit->addAction(actionAssign_Shifts);
        menuEdit->addAction(actionClear_Shifts);
        menuEdit->addAction(actionClear_People);

        retranslateUi(Scheduler);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Scheduler);
    } // setupUi

    void retranslateUi(QMainWindow *Scheduler)
    {
        Scheduler->setWindowTitle(QCoreApplication::translate("Scheduler", "MainWindow", nullptr));
        actionExport->setText(QCoreApplication::translate("Scheduler", "Export", nullptr));
        actionExit->setText(QCoreApplication::translate("Scheduler", "Exit", nullptr));
        actionImport_People->setText(QCoreApplication::translate("Scheduler", "Import People", nullptr));
        actionClear_Shifts->setText(QCoreApplication::translate("Scheduler", "Clear Shifts", nullptr));
        actionClear_People->setText(QCoreApplication::translate("Scheduler", "Clear People ", nullptr));
        actionAssign_Shifts->setText(QCoreApplication::translate("Scheduler", "Assign Shifts", nullptr));
        pushButton->setText(QCoreApplication::translate("Scheduler", "Load People", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Scheduler", "Assign Shifts", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Scheduler", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Scheduler", "Building", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Scheduler", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Scheduler", "Seconday", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Scheduler", "1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_view_placement), QCoreApplication::translate("Scheduler", "Shifts", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Scheduler", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Scheduler", "Building", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Scheduler", "Days of Week Cannot Work", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Scheduler", "Specific Dates Cannot Work", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Scheduler", "1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_edit_people), QCoreApplication::translate("Scheduler", "Edit People File", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Scheduler", "Export to Disk", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Scheduler", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Scheduler", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scheduler: public Ui_Scheduler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULER_H
