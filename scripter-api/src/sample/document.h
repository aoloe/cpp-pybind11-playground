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
            Margin margin;
            std::vector<Page> page;
    };

}
#endif
