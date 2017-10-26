- https://github.com/cpp11nullptr/lsignal: lsignal (or lightweight signal) is a very little and fast C++ thread-safe implementation of signal and slot system which is based on modern C++11 code.
- https://github.com/dgovil/PySignal: A purely Python implementation of the Qt signal system with no QObject dependencies

how scribus manages the menus:

- `scribus/menumanager.cpp`: seems to be managing the menus through strings
- `ActionManager::createDefaultMenuNames()` fills defMenuNames
  -  `static QVector< QPair<QString, QStringList> > defMenuNames;`
  - `static QVector< QPair<QString, QStringList> > defMenus;`
  - `scrActions` seems to contain the real actions
  - `scrActions` is a vector filled by the functions called in `ActionManager::createActions()`
- `scribus/scribus.cpp` connects the `scrActions` with real actions
