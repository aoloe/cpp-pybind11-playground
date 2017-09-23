#ifndef SAMPLEDMARGIN_H
#define SAMPLEDMARGIN_H

namespace Sample
{
    class Margin
    {
        public:
            double top{0};
            double bottom{0};
            double left{0};
            double right{0};
            void set(double t, double r, double b, double l) {
                top = t;
                right = r;
                bottom = b;
                left = l;
            }
    };
}
#endif
