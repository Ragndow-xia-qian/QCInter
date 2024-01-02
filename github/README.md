# QCInter Library

### The **QCInter** library provides a class called Qc which offers functionality similar to the tkinter.Tk in Python. The implementation of this class is found in the file qcinter.h. The Qc class includes the following member functions:
- -**title(const QString # QCInter Library

The **QCInter** library provides a class called `Qc` which offers functionality similar to the `tkinter.Tk` in Python. The implementation of this class is found in the file `qcinter.h`. The `Qc` class includes the following member functions:

- `title(const QString &title)`: Sets the title of the window.
- `geometry(const QString &geometry)`: Sets the geometry of the window.
- `winfo_x()`: Returns the x-coordinate of the window.
- `winfo_y()`: Returns the y-coordinate of the window.
- `winfo_width()`: Returns the width of the window.
- `winfo_height()`: Returns the height of the window.
- `winfo_screenwidth()`: Returns the screen width.
- `winfo_screenheight()`: Returns the screen height.

Additionally, the library provides a `build.bat` script for building the static library.

## Building the Library
To build the static library, run the `build.bat` script.

## Example Usage
```cpp
#include <QCInter/qcinter.h>

int main(int argc, char *argv[]) {
    QCInter::Qc app(argc, argv);
    app.title("My Application");
    app.geometry("800x600+100+100");
    return app.mainloop();
}
```
Please refer to the documentation in qcinter.h for detailed information on how to use the Qc class and its member functions.

## License
This project is licensed under the [insert license name] License - see the [LICENSE](LICENSE) file for details.

## Contributing
Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Acknowledgments
- Hat tip to anyone whose code was used

If you have any questions or need further assistance, feel free to contact us.

