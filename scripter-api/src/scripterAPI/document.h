#ifndef SCRIPTERAPIDOCUMENT_H
#define SCRIPTERAPIDOCUMENT_H

#include "sample/document.h"
#include "sample/page.h"
#include "scripterAPI/margin.h"
#include "scripterAPI/page.h"

namespace ScripterAPI {
    class Document {
        public:
            void setDocument(Sample::Document* d) {
                document = d;
            }
            Margin getMargin() { return Margin(document->margin); }
            Page getPage(int i) { return Page(document, i); }
            void addPage() {
                Sample::Page page;
                document->page.push_back(page);
            }
        private:
            Sample::Document* document;
    };
}
#endif
