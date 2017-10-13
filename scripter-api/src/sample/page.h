#ifndef SAMPLEPAGE_H
#define SAMPLEPAGE_H
#include "margin.h"
namespace Sample
{
    class Page
    {
        public:
            Page() {
                margin = new Margin();
            }
            ~Page() {
                delete margin;
            }
            Margin* margin;
    };

}
#endif

