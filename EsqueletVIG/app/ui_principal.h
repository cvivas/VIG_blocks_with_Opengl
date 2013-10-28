/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created: Mon Oct 28 14:34:54 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QHBoxLayout *horizontalLayout;
    GLWidget *gLWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_2;
    QSpinBox *spinBox;
    QLabel *label;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSpinBox *spinBox_3;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->resize(618, 425);
        horizontalLayout = new QHBoxLayout(Principal);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gLWidget = new GLWidget(Principal);
        gLWidget->setObjectName(QString::fromUtf8("gLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gLWidget->sizePolicy().hasHeightForWidth());
        gLWidget->setSizePolicy(sizePolicy);
        gLWidget->setMinimumSize(QSize(400, 400));
        gLWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(gLWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_4 = new QPushButton(Principal);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(70);
        sizePolicy1.setVerticalStretch(70);
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(70, 70));
        pushButton_4->setMaximumSize(QSize(70, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../imatges/cub.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(Principal);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(70, 70));
        pushButton_5->setMaximumSize(QSize(70, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../imatges/door.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(Principal);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(70, 70));
        pushButton_6->setMaximumSize(QSize(70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../imatges/prisma.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(Principal);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(70, 70));
        pushButton_7->setMaximumSize(QSize(70, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../imatges/pyramid.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon3);
        pushButton_7->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(Principal);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMinimumSize(QSize(70, 70));
        pushButton_8->setMaximumSize(QSize(70, 70));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../imatges/window.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon4);
        pushButton_8->setIconSize(QSize(64, 64));

        verticalLayout->addWidget(pushButton_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_3 = new QPushButton(Principal);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(80, 0));
        pushButton_3->setMaximumSize(QSize(80, 16777215));

        verticalLayout_2->addWidget(pushButton_3);

        groupBox = new QGroupBox(Principal);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(80, 80));
        groupBox->setMaximumSize(QSize(80, 16777215));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 30, 82, 21));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(0, 50, 82, 21));

        verticalLayout_2->addWidget(groupBox);

        checkBox = new QCheckBox(Principal);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(80, 0));

        verticalLayout_2->addWidget(checkBox);

        pushButton_9 = new QPushButton(Principal);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(80, 0));
        pushButton_9->setMaximumSize(QSize(80, 16777215));

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(Principal);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(80);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy2);
        pushButton_10->setMinimumSize(QSize(80, 0));
        pushButton_10->setMaximumSize(QSize(80, 16777215));

        verticalLayout_2->addWidget(pushButton_10);

        checkBox_3 = new QCheckBox(Principal);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy2.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy2);
        checkBox_3->setMinimumSize(QSize(80, 0));
        checkBox_3->setMaximumSize(QSize(80, 16));
        checkBox_3->setChecked(true);

        verticalLayout_2->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(Principal);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(80, 15));
        checkBox_2->setMaximumSize(QSize(80, 15));
        checkBox_2->setChecked(true);

        verticalLayout_2->addWidget(checkBox_2);

        groupBox_2 = new QGroupBox(Principal);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 100));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(0, 20, 50, 22));
        spinBox->setMinimum(10);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(10);
        spinBox->setValue(100);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 22, 52, 16));
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(0, 48, 50, 22));
        spinBox_2->setMinimum(10);
        spinBox_2->setMaximum(1000);
        spinBox_2->setSingleStep(10);
        spinBox_2->setValue(100);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 50, 52, 16));
        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(0, 75, 50, 22));
        spinBox_3->setMinimum(10);
        spinBox_3->setMaximum(1000);
        spinBox_3->setSingleStep(10);
        spinBox_3->setValue(100);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 77, 52, 16));

        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(35, 96, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(Principal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(80);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMinimumSize(QSize(80, 0));
        pushButton->setMaximumSize(QSize(80, 16777215));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Principal);
        QObject::connect(pushButton, SIGNAL(clicked()), Principal, SLOT(close()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), gLWidget, SLOT(reset()));
        QObject::connect(radioButton, SIGNAL(clicked()), gLWidget, SLOT(solid()));
        QObject::connect(radioButton_2, SIGNAL(clicked()), gLWidget, SLOT(wired()));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), gLWidget, SLOT(activaPA(bool)));
        QObject::connect(pushButton_4, SIGNAL(clicked()), gLWidget, SLOT(CargaObjetocub()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), gLWidget, SLOT(CargaDoor()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), gLWidget, SLOT(CargaPrisma()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), gLWidget, SLOT(CargaPiramide()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), gLWidget, SLOT(CargaWindow()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), gLWidget, SLOT(escalaX(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), gLWidget, SLOT(escalaY(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), gLWidget, SLOT(escalaZ(int)));
        QObject::connect(gLWidget, SIGNAL(setValue(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(gLWidget, SIGNAL(setValue(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(gLWidget, SIGNAL(setValue(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(pushButton_10, SIGNAL(clicked()), gLWidget, SLOT(mats()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), gLWidget, SLOT(editaL()));
        QObject::connect(pushButton, SIGNAL(clicked()), gLWidget, SLOT(cerrarTodo()));
        QObject::connect(checkBox_3, SIGNAL(clicked(bool)), gLWidget, SLOT(activaLuces(bool)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), gLWidget, SLOT(verLuces(bool)));

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QWidget *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "Principal", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_3->setText(QApplication::translate("Principal", "Init Camera", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Principal", "Render Mode", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Principal", "Solid", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Principal", "WireFrame", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Principal", "Plan-Elev", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("Principal", "Luces", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Principal", "Materiales", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Principal", "Iluminacio", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Principal", "VerLuces", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Principal", "Escalado", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Principal", "X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Principal", "Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Principal", "Z", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Principal", "&Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
