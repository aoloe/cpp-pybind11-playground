#include "sample.h"

#include <QDebug>

Sample::Sample(int &argc, char *argv[]) :
    QApplication(argc, argv)
{
    setApplicationName("Application Sample");
    setApplicationVersion("0.1");
}
