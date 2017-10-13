#ifndef SCRIPTERAPIPAGE_H
#define SCRIPTERAPIPAGE_H

#include "sample/document.h"
#include "sample/margin.h"
#include "scripterAPI/margin.h"

namespace ScripterAPI {
    class Page {
        public:
            Page(Sample::Document* d, int pageNumber): pageNumber{pageNumber}, document{d} {}
            Margin getMargin() { return Margin(document->page.at(pageNumber -1).margin); }
        private:
            int pageNumber;
            Sample::Document* document;
    };
}
#endif
