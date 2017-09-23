#ifndef SCRIPTERAPI_H
#define SCRIPTERAPI_H
#include <iostream>
#include <memory>

#include "sample/document.h"

namespace ScripterAPI {
    class ScripterAPI {
        public:
            int a = 1;
            void setDocument(std::unique_ptr<Sample::Document> d) {document = std::move(d);}
            std::unique_ptr<Sample::Document> getDocument() {return std::move(document);}
        private:
            std::unique_ptr<Sample::Document> document;
    };
}
#endif
