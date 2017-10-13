#ifndef SAMPLEDOCUMENT_H
#define SAMPLEDOCUMENT_H
#include <vector>
#include "margin.h"
#include "page.h"
namespace Sample
{
    class Document
    {
        public:
            Document() {
                margin = new Margin();
            }
            ~Document() {
                delete margin;
            }
            Margin* margin;
            std::vector<Page> page;
    };

}
#endif
