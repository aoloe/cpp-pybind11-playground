#ifndef SCRIPTERAPI_H
#define SCRIPTERAPI_H
#include <memory>

#include "sample/document.h"
#include "scripterAPI/document.h"

namespace ScripterAPI {
    class ScripterAPI {
        public:
            int a = 1;
            void setDocument(std::unique_ptr<Sample::Document> d) {/* documentAPI.setDocument(std::move(d));*/}
            // std::unique_ptr<Sample::Document> getDocument() {return std::move(documentAPI.getDocument());}
            Document documentAPI;
    };
}
#endif
