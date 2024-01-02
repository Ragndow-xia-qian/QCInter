//
// Created by 37237 on 2024/1/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "../QCInter/window.h"
#include "../Form/ui_Window.h"

namespace QCInter {
    Window::Window(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::Window) {
        ui->setupUi(this);
    }

    Window::~Window() {
        delete ui;
    }
} // QCInter
