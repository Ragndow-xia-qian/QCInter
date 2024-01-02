//
// Created by 37237 on 2024/1/1.
//

#ifndef QCINTER_WINDOW_H
#define QCINTER_WINDOW_H

#include <QMainWindow>

namespace QCInter {
    QT_BEGIN_NAMESPACE
    namespace Ui { class Window; }
    QT_END_NAMESPACE

    class Window : public QMainWindow {
    Q_OBJECT

    public:
        explicit Window(QWidget *parent = nullptr);

        ~Window() override;

    private:
        Ui::Window *ui;
    };
} // QCInter

#endif //QCINTER_WINDOW_H
