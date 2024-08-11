/**
 * @file Qt5Test.cc
 * @author Swan BaiLei27 (https://github.com/Baiyi27)
 * @brief simple test demo for Qt5 adn fmt
 * @version 0.1
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024 Swan BaiLei27 <SwanBaiLei2Seven@foxmail.com>
 * 
 */

#include "qapplication.h"
#include "qpushbutton.h"
#include "qstring.h"
#include "fmt/format.h"

class MainWindow: public QWidget {
public:
    MainWindow(QWidget *parent= nullptr)
        : QWidget(parent)
    {
        auto testMsg= fmt::format("This is {1} test: {0},{1}\n", "Hello", "Qt5");
        pButton_= new QPushButton(QString::fromStdString(testMsg), this);
        resize(1000, 800);
    }

protected:
    void resizeEvent(QResizeEvent *event) override
    {
        int buttonWidth = width() / 4;
        int buttonHeight= height() / 4;

        pButton_->setGeometry((width() - buttonWidth) / 2,
                            (height() - buttonHeight) / 2,
                            buttonWidth,
                            buttonHeight);

        QWidget::resizeEvent(event);
    }

private:
    QPushButton *pButton_ {nullptr};
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
