#ifndef SCRIPTERAPIMARGIN_H
#define SCRIPTERAPIMARGIN_H

#include "sample/document.h"
#include "sample/margin.h"

namespace ScripterAPI {
    class Margin {
        public:
            Margin(Sample::Document* d): document{d} {}
            double getTop() { return document->margin.top; }
            void setTop(double t) { document->margin.top = t; }
            double getRight() { return document->margin.right; }
            void setRight(double r) { document->margin.right = r; }
            double getBottom() { return document->margin.bottom; }
            void setBottom(double b) { document->margin.bottom = b; }
            double getLeft() { return document->margin.left; }
            void setLeft(double l) { document->margin.left = l; }
        private:
            Sample::Document* document;
    };
}
#endif
