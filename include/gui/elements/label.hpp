#include <gui/guielement.hpp>
#include <vector>

class label:public guielement{
    public:
        void tick();
        label(const char* text,u32 x,u32 y);
        label(const char* text,u32 x,u32 y,float xsc,float ysc,u8 r,u8 g,u8 b);
        void setText(const char* text);
    private:
        char text[999];
        float xsc,ysc;
        u8 r,g,b;

};
