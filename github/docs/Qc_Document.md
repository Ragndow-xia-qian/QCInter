# Qc Class Documentation

## Constructor
- `Qc(int argc, char *argv[])` : Initializes with the given parameters.

## Member Functions
- `int winfo_width()` : Returns the window width.
- `int winfo_height()` : Returns the window height.
- `int winfo_x()` : Returns the window x coordinate.
- `int winfo_y()` : Returns the window y coordinate.
- `static int winfo_screenwidth()` : Returns the width of the primary screen.
- `static int winfo_screenheight()` : Returns the height of the primary screen.
- `static QList<int> winfo_screens_width()` : Returns a list of widths of all screens.
- `static QList<int> winfo_screens_height()` : Returns a list of heights of all screens.
- `void geometry(const QString &geometry)` : Sets the window geometry.
- `void title(const QString &title)` : Sets the window title.
- `int mainloop()` : Enters the event loop.

## Private Members
- `friend class Button` : Button class is a friend of the Qc class.
- `void setGeo(QPoint _leftTop, QPoint _rightBottom)` : Sets the window position and size.

## Member Variables
- `QApplication a` : Manages global resources for the application.
- `QCInter::Window window` : Window object.
- `QVector<Object *> objects` : Vector that storing controls.

## Usage example
```cpp
#include <format>
#include "QCInter/qcinter.h"

int main(int argc, char *argv[]) {
    QCInter::Qc root(argc, argv);
    
    root.title("QCInter");
    
    int width = 1800;
    int height = 1000;
    int x = (QCInter::Qc::winfo_screenwidth() - width) / 2;
    int y = (QCInter::Qc::winfo_screenheight() - height) / 2;
    
    root.geometry(std::format("{}x{}+{}+{}", width, height, x, y).c_str());
    
    return root.mainloop();
}
```
In this example, the code first creates a root window named root and uses `Qc::title(const QString &title)` to change the window name to *QCInter*, then uses variables to store the x coordinate, y coordinate, width and height of the window, calls `Qc::geometry(const QString &geometry)` to modify the position and size of the window, and finally calls `Qc::mainloop()` to display the window.
