#ifndef SCRIPTERAPIDOCUMENT_H
#define SCRIPTERAPIDOCUMENT_H

#include <memory>
#include "sample/document.h"

namespace ScripterAPI {
    class Document {
        public:
            Document() {}
            void setDocument(Sample::Document* d) { document = d; }
            int getA() { return document->a; }
            void setA(int a) { document->a = a; }
        private:
            Sample::Document* document;
    };
}
#endif
