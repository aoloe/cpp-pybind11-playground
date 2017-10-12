#ifndef SCRIPTERAPIPAGE_H
#define SCRIPTERAPIPAGE_H

#include "sample/document.h"
#include "sample/margin.h"

namespace ScripterAPI {
    class Page {
        public:
            Page(Sample::Document* d): document{d} {}
            double getMargin() { return document->margin; }
            void setMargin(Margin m) { document->margin = m; }
        private:
            Sample::Document* document;
    };
}
#endif
