/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLineEdit *lineEditDataDirectory;
    QPushButton *pushButtonBrowseForDataDir;
    QLabel *label;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QStringLiteral("Preferences"));
        Preferences->resize(475, 340);
        buttonBox = new QDialogButtonBox(Preferences);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Preferences);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 441, 81));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(360, 30, 51, 17));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(360, 50, 70, 17));
        checkBox_2->setChecked(true);
        lineEditDataDirectory = new QLineEdit(groupBox);
        lineEditDataDirectory->setObjectName(QStringLiteral("lineEditDataDirectory"));
        lineEditDataDirectory->setGeometry(QRect(10, 30, 241, 23));
        pushButtonBrowseForDataDir = new QPushButton(groupBox);
        pushButtonBrowseForDataDir->setObjectName(QStringLiteral("pushButtonBrowseForDataDir"));
        pushButtonBrowseForDataDir->setGeometry(QRect(260, 30, 75, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 10, 61, 16));

        retranslateUi(Preferences);
        QObject::connect(buttonBox, SIGNAL(accepted()), Preferences, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Preferences, SLOT(reject()));

        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "RoboPatch Preferences", 0));
        groupBox->setTitle(QApplication::translate("Preferences", "Directory to save autopatcher trial data", 0));
        checkBox->setText(QApplication::translate("Preferences", "CSV", 0));
        checkBox_2->setText(QApplication::translate("Preferences", "MATLAB", 0));
        pushButtonBrowseForDataDir->setText(QApplication::translate("Preferences", "Browse", 0));
        label->setText(QApplication::translate("Preferences", "File Format", 0));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
