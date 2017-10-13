#ifndef SCRIPTERAPIMARGIN_H
#define SCRIPTERAPIMARGIN_H

#include "sample/document.h"
#include "sample/margin.h"

namespace ScripterAPI {
    class Margin {
        public:
            Margin(Sample::Margin* m): margin{m} {}
            double getTop() { return margin->top; }
            void setTop(double t) { margin->top = t; }
            double getRight() { return margin->right; }
            void setRight(double r) { margin->right = r; }
            double getBottom() { return margin->bottom; }
            void setBottom(double b) { margin->bottom = b; }
            double getLeft() { return margin->left; }
            void setLeft(double l) { margin->left = l; }
        private:
            Sample::Margin* margin;
    };
}
#endif
