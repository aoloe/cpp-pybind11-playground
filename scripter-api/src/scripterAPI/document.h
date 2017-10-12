#ifndef SCRIPTERAPIDOCUMENT_H
#define SCRIPTERAPIDOCUMENT_H

#include "sample/document.h"
#include "scripterAPI/margin.h"
#include "scripterAPI/page.h"

namespace ScripterAPI {
    class Document {
        public:
            void setDocument(Sample::Document* d) {
                document = d;
            }
            Margin getMargin() { return Margin(document); }
            Page getPage(int i) { return Page(i, document); }
        private:
            Sample::Document* document;
    };
}
#endif
