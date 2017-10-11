#ifndef SCRIPTERAPIDOCUMENT_H
#define SCRIPTERAPIDOCUMENT_H

#include "sample/document.h"
#include "scripterAPI/margin.h"

namespace ScripterAPI {
    class Document {
        public:
            void setDocument(Sample::Document* d) {
                document = d;
            }
            Margin getMargin() { return Margin(document); }
        private:
            Sample::Document* document;
    };
}
#endif
