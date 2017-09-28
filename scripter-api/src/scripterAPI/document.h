#ifndef SCRIPTERAPIDOCUMENT_H
#define SCRIPTERAPIDOCUMENT_H

#include <memory>
#include "sample/document.h"

namespace ScripterAPI {
    class Document {
        public:
            Document() {}
            void setDocument(const Sample::Document* d) { document = d; }
			int a{42};
        private:
            const Sample::Document* document;
    };
}
#endif
