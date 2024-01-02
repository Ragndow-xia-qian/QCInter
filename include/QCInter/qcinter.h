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

#include "window.h"

namespace QCInter {
    class Qc {
    public:
        Qc(int argc, char *argv[]): a(argc, argv), window{} {}

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

        QList<int> winfo_screens_width() {
            QList<QScreen *> screens = QGuiApplication::screens();

            QList<int> list;
            for (auto &&screen: screens) {
                list.append(screen->size().width());
            }

            return list;
        }

        QList<int> winfo_screens_height() {
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

            return QApplication::exec();
        }

    private:
        void setGeo(QPoint _leftTop, QPoint _rightBottom) {
            QRect geo;

            geo.setTopLeft(_leftTop);
            geo.setBottomRight(_rightBottom);

            window.setGeometry(geo);
        }

        QApplication a;

        QCInter::Window window;
    };
}

#endif //QCINTER_QCINTER_H
