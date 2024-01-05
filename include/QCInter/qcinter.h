/**
  ******************************************************************************
  * @file           : qcinter.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2024/1/2
  ******************************************************************************
  */
#ifndef QCINTER_QCINTER_H
#define QCINTER_QCINTER_H

#include <QApplication>
#include <QString>
#include <QIcon>
#include <QScreen>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLayout>

#include "window.h"

namespace QCInter {
    class Object {
        friend class Qc;

        virtual void show() = 0;
    };

    class Qc {
    public:
        Qc(int argc, char *argv[]) : a(argc, argv), window{} {}

        ~Qc() = default;

        int winfo_width() {
            return window.x() - window.x();
        }

        int winfo_height() {
            return window.y() - window.y();
        }

        int winfo_x() {
            return window.x();
        }

        int winfo_y() {
            return window.y();
        }

        static int winfo_screenwidth() {
            QRect windowRect = QGuiApplication::primaryScreen()->geometry();

            return windowRect.width();
        }

        static int winfo_screenheight() {
            QRect windowRect = QGuiApplication::primaryScreen()->geometry();

            return windowRect.height();
        }

        static QList<int> winfo_screens_width() {
            QList<QScreen *> screens = QGuiApplication::screens();

            QList<int> list;
            for (auto &&screen: screens) {
                list.append(screen->size().width());
            }

            return list;
        }

        static QList<int> winfo_screens_height() {
            QList<QScreen *> screens = QGuiApplication::screens();

            QList<int> list;
            for (auto &&screen: screens) {
                list.append(screen->size().height());
            }

            return list;
        }

        void geometry(const QString &geometry) {
            QPoint _leftTop, _rightBottom;

            QStringList list = geometry.split("x");
            if (list.size() != 2) {
                throw std::runtime_error("geometry format error");
            }

            QStringList list2 = list[1].split("+");
            if (list2.size() == 1) {
                _rightBottom = QPoint(_leftTop.x() + list[0].toInt(), _leftTop.y() + list[1].toInt());
                setGeo(_leftTop, _rightBottom);
                return;
            }
            if (list2.size() != 3) {
                throw std::runtime_error("geometry format error");
            }

            QStringList list3 = {list[0], list2[0], list2[1], list2[2]};
            _leftTop = QPoint(list3[2].toInt(), list3[3].toInt());
            _rightBottom = QPoint(_leftTop.x() + list3[0].toInt(), _leftTop.y() + list3[1].toInt());

            setGeo(_leftTop, _rightBottom);
        }

        void title(const QString &title) {
            window.setWindowTitle(title);
        }

        int mainloop() {
            window.show();

            for (auto &&item: objects) {
                item->show();
            }

            return QApplication::exec();
        }

    private:
        friend class Button;

        void setGeo(QPoint _leftTop, QPoint _rightBottom) {
            QRect geo;

            geo.setTopLeft(_leftTop);
            geo.setBottomRight(_rightBottom);

            window.setGeometry(geo);
        }

        QApplication a;

        QCInter::Window window;

        QVector<Object *> objects;
    };

    class Button : Object {
    public:
        template<typename F = void(*)()>
        explicit Button(Qc &window, const QString &text = "", F &&f = []{}) : window(window), button(&window.window) {
            window.objects.append(this);
            button.setText(text);
            button.connect(&button, &QPushButton::clicked, std::forward<F>(f));
        }

        void pack(const QString &side = "top") {
            if (side == "top") {
                button.setGeometry((window.winfo_width() - button.width()) / 2, 0, button.width(), button.height());
            } else if (side == "bottom") {
                button.setGeometry((window.winfo_width() - button.width()) / 2, window.winfo_height() - button.height(),
                                   button.width(), button.height());
            } else if (side == "left") {
                button.setGeometry(0, (window.winfo_height() - button.height()) / 2, button.width(), button.height());
            } else if (side == "right") {
                button.setGeometry(window.winfo_width() - button.width(), (window.winfo_height() - button.height()) / 2,
                                   button.width(), button.height());
            } else if (side == "center") {
                button.setGeometry((window.winfo_width() - button.width()) / 2,
                                   (window.winfo_height() - button.height()) / 2, button.width(), button.height());
            } else if (side == "fill") {
                button.setGeometry(0, 0, window.winfo_width(), window.winfo_height());
            } else if (side == "topleft") {
                button.setGeometry(0, 0, button.width(), button.height());
            } else if (side == "topright") {
                button.setGeometry(window.winfo_width() - button.width(), 0, button.width(), button.height());
            } else if (side == "bottomleft") {
                button.setGeometry(0, window.winfo_height() - button.height(), button.width(), button.height());
            } else if (side == "bottomright") {
                button.setGeometry(window.winfo_width() - button.width(), window.winfo_height() - button.height(),
                                   button.width(), button.height());
            } else {
                throw std::runtime_error("pack error");
            }
        }

        void grid(int row = 0, int column = 0) {
            auto *layout = new QGridLayout;
            layout->addWidget(&button, row, column);
        }

        void place(int x, int y, int width, int height) {
            button.setGeometry(x, y, width, height);
        }

        void rel_place(int rel_x, int rel_y, int rel_width, int rel_height) {
            int abs_x = rel_x * window.winfo_width();
            int abs_y = rel_y * window.winfo_height();
            int abs_width = rel_width * window.winfo_width();
            int abs_height = rel_height * window.winfo_height();
            button.setGeometry(abs_x, abs_y, abs_width, abs_height);
        }

    private:
        void show() override {
            this->button.show();
        }

        Qc &window;
        QPushButton button;
    };
}

#endif //QCINTER_QCINTER_H
