#include "widget.h"


PrimeGen::PrimeGen(QWidget *parent)
    : QWidget(parent)
{


    borderLabel = new QLabel("素数表边界");
    styleLabel = new QLabel("素数表样式");
    booleanLabel = new QLabel("布尔数组");
    arrayLabel = new QLabel("素数数组");
    numberLabel = new QLabel("素数总个数");

    borderSpinBox = new QSpinBox();
    styleComboBox = new QComboBox();

    boolValue = new QTextEdit();
    arrayValue = new QTextEdit();
    numberValue = new QTextEdit();

    generatePushButton = new QPushButton("生成！");

    borderSpinBox->setMinimum(10);
    borderSpinBox->setMaximum(1000000);
    borderSpinBox->setValue(10);

    styleComboBox->addItem("{}");
    styleComboBox->addItem("()");
    styleComboBox->addItem("[]");
    styleComboBox->setCurrentText("{}");

    connect(generatePushButton, SIGNAL(pressed()), this, SLOT(generatePushButtonPressed()));

    QVBoxLayout *borderLayout = new QVBoxLayout();
    borderLayout->addWidget(borderLabel);
    borderLayout->addWidget(borderSpinBox);

    QVBoxLayout *styleLayout = new QVBoxLayout();
    styleLayout->addWidget(styleLabel);
    styleLayout->addWidget(styleComboBox);

    QHBoxLayout *settingsLayout = new QHBoxLayout();
    settingsLayout->addLayout(borderLayout);
    settingsLayout->addLayout(styleLayout);
    settingsLayout->addWidget(generatePushButton);

    QHBoxLayout *booleanLayout = new QHBoxLayout();
    booleanLayout->addWidget(booleanLabel);
    booleanLayout->addWidget(boolValue);

    QHBoxLayout *arrayLayout = new QHBoxLayout();
    arrayLayout->addWidget(arrayLabel);
    arrayLayout->addWidget(arrayValue);

    QHBoxLayout *numberLayout = new QHBoxLayout();
    numberLayout->addWidget(numberLabel);
    numberLayout->addWidget(numberValue);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(settingsLayout);
    mainLayout->addLayout(booleanLayout);
    mainLayout->addLayout(arrayLayout);
    mainLayout->addLayout(numberLayout);

    resize(800,600);
    this->setLayout(mainLayout);
}

void PrimeGen::generatePushButtonPressed()
{
    int boundary = borderSpinBox->value() + 1;
    QVector<int>prime(boundary,1);
    prime[1] = 0;
    prime[0] = 0;
    for (int i = 4; i < boundary; i++)
    {
        if (prime[i] == 0)
            continue;
        for (int j = 2; j <= (int)sqrt(i); j++)
        {
            if (i % j == 0)
            {
                prime[i] = 0;
                break;
            }
            else if (j == (int)sqrt(i))
            {
                for (int k = 2; k * i <= boundary-1; k++)
                {
                    prime[k * i] = 0;
                }
            }
        }
    }

    QString value;
    int sum=0;
    QString style = styleComboBox->currentText();
    QString output;
    if ( style == "{}") output = "{",value = "{";
    else if ( style == "()") output = "(",value = "(";
    else if ( style == "[]") output = "[",value = "[";
    for ( int i=0 ; i<(boundary-1) ; i++ )
        {
            if ( prime[i] == 1)
            {
                sum++;
                value = value + QString::number(i);
                if ( i != boundary-2 ) value+=",";
            }
            output = output + QString::number(prime[i]);

            if ( i != boundary-2 ) output+=",";
        }
    if ( style == "{}") output+="}",value += "}";
    else if ( style == "()") output+=")",value += ")";
    else if ( style == "[]") output+="]",value += "]";

    boolValue->setText(output);
    arrayValue->setText(value);
    numberValue->setText(QString::number(sum));
}


