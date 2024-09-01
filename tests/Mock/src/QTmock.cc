#include "qspinbox.h"
#include "qpushbutton.h"
#include "qboxlayout.h"
#include "qapplication.h"

#include "QTmock.hh"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto layout= new QVBoxLayout();
    auto button= new QPushButton(tr("button"));
    auto spin  = new QSpinBox();
    connect(button, &QPushButton::clicked, [spin]() { spin->setValue(spin->value() + 1); });
    connect(button, &QPushButton::clicked, this, &Widget::sig_inch);
    layout->addWidget(spin);
    layout->addWidget(button);
    this->setLayout(layout);
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    Widget w;
    QObject::connect(&w, &Widget::sig_inch, []() {
        qDebug() << "Widget signal";
    });

    w.show();
    a.exec();
}