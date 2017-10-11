#ifndef SCRIPTERAPIMARGIN_H
#define SCRIPTERAPIMARGIN_H

#include "sample/document.h"
#include "sample/margin.h"

namespace ScripterAPI {
    class Margin {
        public:
            Margin(Sample::Document* d): document{d} {}
            double getTop() { return document->margin.top; }
            double setTop(double t) { document->margin.top = t; }
            double getRight() { return document->margin.right; }
            double setRight(double r) { document->margin.right = r; }
            double getBottom() { return document->margin.bottom; }
            double setBottom(double b) { document->margin.bottom = b; }
            double getLeft() { return document->margin.left; }
            double setLeft(double l) { document->margin.left = l; }
        private:
            Sample::Document* document;
    };
}
#endif

