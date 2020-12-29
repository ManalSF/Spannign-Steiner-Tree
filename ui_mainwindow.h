/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open;
    QAction *save;
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *working_widget;
    QHBoxLayout *horizontalLayout_9;
    QWidget *utils;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *button_layout;
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_5;
    QWidget *verticalWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *som;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *are;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *reset;
    QPushButton *Generate;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QTextEdit *textEdit;
    QFrame *pushButton_6;
    QSpacerItem *verticalSpacer;
    QWidget *graphLayout_2;
    QVBoxLayout *graphLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 792);
        MainWindow->setMinimumSize(QSize(720, 540));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 255, 255);"));
        open = new QAction(MainWindow);
        open->setObjectName(QString::fromUtf8("open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open->setIcon(icon);
        open->setIconVisibleInMenu(true);
        save = new QAction(MainWindow);
        save->setObjectName(QString::fromUtf8("save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        working_widget = new QWidget(centralWidget);
        working_widget->setObjectName(QString::fromUtf8("working_widget"));
        working_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_9 = new QHBoxLayout(working_widget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        utils = new QWidget(working_widget);
        utils->setObjectName(QString::fromUtf8("utils"));
        utils->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(utils);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(utils);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        button_layout = new QVBoxLayout(widget);
        button_layout->setSpacing(6);
        button_layout->setContentsMargins(11, 11, 11, 11);
        button_layout->setObjectName(QString::fromUtf8("button_layout"));
        button_layout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalWidget_2 = new QWidget(widget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        verticalWidget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(verticalWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        pushButton_4 = new QPushButton(verticalWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 20));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 127);"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(verticalWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setMinimumSize(QSize(0, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(170, 255, 127);"));
        pushButton_2->setAutoDefault(false);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        pushButton = new QPushButton(verticalWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 20));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(170, 255, 255);"));

        horizontalLayout_5->addWidget(pushButton);

        pushButton_3 = new QPushButton(verticalWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 20));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 127);"));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(verticalWidget_2);


        button_layout->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalWidget_3 = new QWidget(widget);
        verticalWidget_3->setObjectName(QString::fromUtf8("verticalWidget_3"));
        verticalWidget_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(verticalWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(verticalWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_3);

        som = new QSpinBox(verticalWidget_3);
        som->setObjectName(QString::fromUtf8("som"));
        som->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        som->setMaximum(100);

        horizontalLayout_3->addWidget(som);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(verticalWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(label_2);

        are = new QSpinBox(verticalWidget_3);
        are->setObjectName(QString::fromUtf8("are"));
        are->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        are->setMaximum(300);

        horizontalLayout_4->addWidget(are);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        reset = new QPushButton(verticalWidget_3);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 127);"));

        horizontalLayout_21->addWidget(reset);

        Generate = new QPushButton(verticalWidget_3);
        Generate->setObjectName(QString::fromUtf8("Generate"));
        Generate->setEnabled(true);
        Generate->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_21->addWidget(Generate);


        horizontalLayout_20->addLayout(horizontalLayout_21);


        verticalLayout_14->addLayout(horizontalLayout_20);


        verticalLayout_4->addLayout(verticalLayout_14);


        verticalLayout_5->addWidget(verticalWidget_3);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255 255, 255);"));

        verticalLayout_5->addWidget(label_6);


        button_layout->addLayout(verticalLayout_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 20));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(pushButton_9);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 127);"));

        horizontalLayout_16->addWidget(pushButton_5);


        horizontalLayout_15->addLayout(horizontalLayout_16);


        verticalLayout_11->addLayout(horizontalLayout_15);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 127);"));

        horizontalLayout_18->addWidget(pushButton_7);


        horizontalLayout_17->addLayout(horizontalLayout_18);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(170, 255, 127);"));

        horizontalLayout_17->addWidget(pushButton_8);


        verticalLayout_12->addLayout(horizontalLayout_17);


        verticalLayout_11->addLayout(verticalLayout_12);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setMinimumSize(QSize(10, 10));
        label->setMaximumSize(QSize(50, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/Qrc/Capture2.PNG")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setWordWrap(false);

        horizontalLayout_22->addWidget(label);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_22->addWidget(label_9);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/new/Qrc/Capture1.PNG")));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_22->addWidget(label_8);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_22->addWidget(label_7);


        verticalLayout_15->addLayout(horizontalLayout_22);


        verticalLayout_11->addLayout(verticalLayout_15);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 87 9pt \"Arial Black\";"));
        textEdit->setReadOnly(true);

        verticalLayout_11->addWidget(textEdit);


        button_layout->addLayout(verticalLayout_11);

        pushButton_6 = new QFrame(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFrameShape(QFrame::HLine);
        pushButton_6->setFrameShadow(QFrame::Sunken);

        button_layout->addWidget(pushButton_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        button_layout->addItem(verticalSpacer);


        verticalLayout->addWidget(widget);


        horizontalLayout_9->addWidget(utils);

        graphLayout_2 = new QWidget(working_widget);
        graphLayout_2->setObjectName(QString::fromUtf8("graphLayout_2"));
        graphLayout_2->setStyleSheet(QString::fromUtf8(""));
        graphLayout = new QVBoxLayout(graphLayout_2);
        graphLayout->setSpacing(6);
        graphLayout->setContentsMargins(11, 11, 11, 11);
        graphLayout->setObjectName(QString::fromUtf8("graphLayout"));
        graphLayout->setContentsMargins(6, -1, -1, -1);

        horizontalLayout_9->addWidget(graphLayout_2);


        horizontalLayout->addWidget(working_widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"selection-color: rgb(170, 255, 255);\n"
"selection-background-color: rgb(170, 255, 255);\n"
"\n"
""));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 255, 127);\n"
"selection-color: rgb(170, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        menuFile->setTearOffEnabled(false);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(open);
        menuFile->addAction(save);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "&Open Graph", nullptr));
#if QT_CONFIG(shortcut)
        open->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+X", nullptr));
#endif // QT_CONFIG(shortcut)
        label_4->setText(QCoreApplication::translate("MainWindow", "Construction manuelle :", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Add Node", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Remove Item ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Contruction Al\303\251atoire :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "           Node", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "           Edge", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        Generate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Algorithmes :", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Steiner Tree", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Terminals", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Kruskal", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        label->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Terminals", nullptr));
        label_8->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Steiner vertices", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
