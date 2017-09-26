#ifndef SCRIPTERAPIDOCUMENT_H
#define SCRIPTERAPIDOCUMENT_H

#include <memory>
#include "sample/document.h"

namespace ScripterAPI {
    class Document {
        public:
            // void setDocument(std::unique_ptr<Sample::Document> d) {/* document = std::move(d);*/}
            // std::unique_ptr<Sample::Document> getDocument() {/*return std::move(document);*/}
			int a{42};
        private:
            // std::unique_ptr<Sample::Document> document;
    };
}
#endif

