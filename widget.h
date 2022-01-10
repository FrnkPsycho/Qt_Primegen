#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <queue>


class PrimeGen : public QWidget
{
    Q_OBJECT

public:
    PrimeGen(QWidget *parent = nullptr);

private slots:
    void generatePushButtonPressed();
private:
    QLabel *borderLabel;
    QLabel *styleLabel;
    QLabel *booleanLabel;
    QLabel *arrayLabel;
    QLabel *numberLabel;

    QSpinBox *borderSpinBox;

    QComboBox *styleComboBox;

    QTextEdit *boolValue;
    QTextEdit *arrayValue;
    QTextEdit *numberValue;

    QPushButton *generatePushButton;
};
#endif // WIDGET_H
