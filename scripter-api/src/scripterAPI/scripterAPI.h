#ifndef SCRIPTERAPI_H
#define SCRIPTERAPI_H
#include <memory>

#include "sample/document.h"
#include "scripterAPI/document.h"

namespace ScripterAPI {
    class ScripterAPI {
        public:
            ScripterAPI() {}
            int a = 1;
            void setDocument(const Sample::Document* d) { documentAPI.setDocument(d);}
            Document documentAPI;
    };
}
#endif
