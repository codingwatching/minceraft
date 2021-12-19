#include <gui/title.hpp>
#include <gui/elements/label.hpp>
#include <gui/elements/button.hpp>
#include <gui/elements/image.hpp>
#include <gui/elements/customtick.hpp>
#include <utils.hpp>
#include <iostream>

#define calccentrepos(strlength) screensz_x/2-(strlength/2*32)-(strlength/2*4)
#define calctoppos(pos) pos+((screensz_y-640)/640)*640
extern double scrnoffx;
extern double scrnoffy;

extern guielement* ingame[];
extern     int mx,my;
extern     int bmx,bmy;

void invbarachangehan(){    if(mx>ingame[1]->x&&my>ingame[1]->y){
        if(mx<(ingame[1]->x+137*4)&&my<ingame[1]->y+18*4){
            ingame[1]->transparency=128;
            ingame[2]->transparency=128;

        }
        else{
            ingame[1]->transparency=255;
            ingame[2]->transparency=255;

        }

    }
    else {
        ingame[1]->transparency=255;
        ingame[2]->transparency=255;

    }
    extern int current_invbar_idx;

    ingame[2]->x=((screensz_x/2)-274)+(current_invbar_idx*18*4)-current_invbar_idx*4;
    int modmx=(mx+(scrnoffx*64));
    ingame[3]->x=mx-modmx%64;
    int modmy=(my+(scrnoffy*64));
    ingame[3]->y=my-modmy%64;

}

image invbar("guitex/ingame_invbar.png",screensz_x/2-274,calctoppos(500),137*4,18*4,137,18,255);
image invbar_selection("guitex/ingame_invbar_selection.png",screensz_x/2-274,calctoppos(500),18*4,18*4,18,18,255);
image block_selection("guitex/ingame_invbar_selection.png",0,0,16*4,16*4,18,18,255);


customtick invbaralphachange(invbarachangehan);



guielement* ingame[]={
    &invbaralphachange,&invbar,&invbar_selection,&block_selection,(guielement*) 0

};
