/**
 * @file QTmock.hh
 * @author Swan BaiLei27 (https://github.com/Baiyi27)
 * @brief  QTmock test
 * @version 0.1
 * @date 2024-08-22
 *
 * @copyright Copyright (c) 2024 Swan BaiLei27 <SwanBaiLei2Seven@foxmail.com>
 *
 */

#ifndef _MOCK_HH_
    #define _MOCK_HH_

    #include "qwidget.h"
    #include "qdebug.h"

class Widget: public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent= nullptr);

    ~Widget() {}

signals:
    void sig_inch();
};

#endif /* _MOCK_HH_ */

// Date:24/08/22/00:43