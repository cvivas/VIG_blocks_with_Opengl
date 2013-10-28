/********************************************************************************
** Form generated from reading UI file 'materials.ui'
**
** Created: Mon Oct 28 14:33:54 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALS_H
#define UI_MATERIALS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_materials
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QGroupBox *groupBox_8;
    QPushButton *BotonA;
    QGroupBox *groupBox_9;
    QPushButton *BotonD;
    QGroupBox *groupBox_10;
    QPushButton *BotonE;
    QSlider *sliderSH;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QPushButton *BotonV;
    QPushButton *BotonC;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *materials)
    {
        if (materials->objectName().isEmpty())
            materials->setObjectName(QString::fromUtf8("materials"));
        materials->resize(374, 386);
        verticalLayout = new QVBoxLayout(materials);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(materials);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(materials);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(311, 281));
        groupBox->setMaximumSize(QSize(311, 281));
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(30, 40, 121, 81));
        BotonA = new QPushButton(groupBox_8);
        BotonA->setObjectName(QString::fromUtf8("BotonA"));
        BotonA->setGeometry(QRect(0, 20, 121, 61));
        groupBox_9 = new QGroupBox(groupBox);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(170, 40, 121, 81));
        BotonD = new QPushButton(groupBox_9);
        BotonD->setObjectName(QString::fromUtf8("BotonD"));
        BotonD->setGeometry(QRect(0, 20, 121, 61));
        groupBox_10 = new QGroupBox(groupBox);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(90, 150, 121, 81));
        BotonE = new QPushButton(groupBox_10);
        BotonE->setObjectName(QString::fromUtf8("BotonE"));
        BotonE->setGeometry(QRect(0, 20, 121, 61));
        sliderSH = new QSlider(groupBox);
        sliderSH->setObjectName(QString::fromUtf8("sliderSH"));
        sliderSH->setGeometry(QRect(100, 250, 160, 16));
        sliderSH->setMaximum(128);
        sliderSH->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 250, 71, 16));
        label_6->setMinimumSize(QSize(71, 16));

        verticalLayout->addWidget(groupBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label = new QLabel(materials);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        BotonV = new QPushButton(materials);
        BotonV->setObjectName(QString::fromUtf8("BotonV"));

        horizontalLayout_6->addWidget(BotonV);

        BotonC = new QPushButton(materials);
        BotonC->setObjectName(QString::fromUtf8("BotonC"));

        horizontalLayout_6->addWidget(BotonC);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(17, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(materials);
        QObject::connect(BotonC, SIGNAL(clicked()), materials, SLOT(close()));

        QMetaObject::connectSlotsByName(materials);
    } // setupUi

    void retranslateUi(QWidget *materials)
    {
        materials->setWindowTitle(QApplication::translate("materials", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("materials", "Editar Material", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("materials", "Componente", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("materials", "Ambient", 0, QApplication::UnicodeUTF8));
        BotonA->setText(QString());
        groupBox_9->setTitle(QApplication::translate("materials", "Difus", 0, QApplication::UnicodeUTF8));
        BotonD->setText(QString());
        groupBox_10->setTitle(QApplication::translate("materials", "Especular", 0, QApplication::UnicodeUTF8));
        BotonE->setText(QString());
        label_6->setText(QApplication::translate("materials", "Shininess:", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        BotonV->setText(QApplication::translate("materials", "&Validar", 0, QApplication::UnicodeUTF8));
        BotonC->setText(QApplication::translate("materials", "&Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class materials: public Ui_materials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALS_H
