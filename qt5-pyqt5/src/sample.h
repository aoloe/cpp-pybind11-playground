#ifndef SAMPLE_H
#define SAMPLE_H

#include<QApplication>

class Sample : public QApplication
{
    Q_OBJECT
public:
    explicit Sample(int &argc, char *argv[]);

};
#endif
