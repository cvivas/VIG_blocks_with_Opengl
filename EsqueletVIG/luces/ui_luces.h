/********************************************************************************
** Form generated from reading UI file 'luces.ui'
**
** Created: Mon Oct 28 14:34:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUCES_H
#define UI_LUCES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_luces
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QCheckBox *boxAct;
    QCheckBox *boxSel;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *BotonA;
    QGroupBox *groupBox_3;
    QPushButton *BotonD;
    QGroupBox *groupBox_4;
    QPushButton *BotonE;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *BotonC;

    void setupUi(QWidget *luces)
    {
        if (luces->objectName().isEmpty())
            luces->setObjectName(QString::fromUtf8("luces"));
        luces->resize(353, 398);
        verticalLayout = new QVBoxLayout(luces);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(luces);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(luces);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        boxAct = new QCheckBox(luces);
        boxAct->setObjectName(QString::fromUtf8("boxAct"));

        horizontalLayout->addWidget(boxAct);

        boxSel = new QCheckBox(luces);
        boxSel->setObjectName(QString::fromUtf8("boxSel"));

        horizontalLayout->addWidget(boxSel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(luces);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(311, 281));
        groupBox->setMaximumSize(QSize(311, 281));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 40, 121, 81));
        BotonA = new QPushButton(groupBox_2);
        BotonA->setObjectName(QString::fromUtf8("BotonA"));
        BotonA->setGeometry(QRect(0, 20, 121, 61));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(170, 40, 121, 81));
        BotonD = new QPushButton(groupBox_3);
        BotonD->setObjectName(QString::fromUtf8("BotonD"));
        BotonD->setGeometry(QRect(0, 20, 121, 61));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(90, 150, 121, 81));
        BotonE = new QPushButton(groupBox_4);
        BotonE->setObjectName(QString::fromUtf8("BotonE"));
        BotonE->setGeometry(QRect(0, 20, 121, 61));

        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(17, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        BotonC = new QPushButton(luces);
        BotonC->setObjectName(QString::fromUtf8("BotonC"));

        horizontalLayout_2->addWidget(BotonC);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(luces);
        QObject::connect(BotonC, SIGNAL(clicked()), luces, SLOT(close()));

        QMetaObject::connectSlotsByName(luces);
    } // setupUi

    void retranslateUi(QWidget *luces)
    {
        luces->setWindowTitle(QApplication::translate("luces", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("luces", "Llum:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("luces", "Llum Ambient", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("luces", "Llum 7", 0, QApplication::UnicodeUTF8)
        );
        boxAct->setText(QApplication::translate("luces", "Activa", 0, QApplication::UnicodeUTF8));
        boxSel->setText(QApplication::translate("luces", "Seleccionar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("luces", "Color", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("luces", "Ambient", 0, QApplication::UnicodeUTF8));
        BotonA->setText(QString());
        groupBox_3->setTitle(QApplication::translate("luces", "Difus", 0, QApplication::UnicodeUTF8));
        BotonD->setText(QString());
        groupBox_4->setTitle(QApplication::translate("luces", "Especular", 0, QApplication::UnicodeUTF8));
        BotonE->setText(QString());
        BotonC->setText(QApplication::translate("luces", "&Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class luces: public Ui_luces {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUCES_H
